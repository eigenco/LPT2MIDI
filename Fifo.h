#pragma once

/// Simple FIFO implementation.
///
/// @param[in] T is the base type of the elements
/// @param[in] S is the capacity of the buffer
///
/// The buffer can be configured to hold up to 255 elements.
/// If this size will be not enough, the implementation of
/// class has to be witched to int size, however this would
/// mean performance penalty on the 8-bit MCU.
template <typename T, byte S>
class Fifo {
  public:

    /// Checks if the buffer is empty.
    bool empty() const {
      return m_size == 0;
    }

    /// Checks if the buffer is full.
    bool full() const {
      return m_size >= S;
    }

    /// Adds an element to the end of the buffer.
    ///
    /// @param[in] element is the element to add
    /// @return false if the buffer is already full
    bool push(const T& element) {
      if (full()) {
        return false;
      }
      // Check for buffer wrap around. We could use modulo here, but
      // this code is very time critical and will be called from an
      // interrupt routine. Since modulo is basically a devision the
      // operation is just too expensive.
      const auto rest = S - m_first;
      const auto pos = (m_size < rest) ? (m_first + m_size) : (m_size - rest);
      m_buffer[pos] = element;
      m_size++;
      return true;
    }

    /// Removes an element from the head of the buffer.
    /// @return The first element, if available
    T pop() {
      // If this function was called on an empty buffer, it's the
      // fault of the user. Normal implementation would throw
      // an exception, but we don't do such things here, so let's
      // simply return something;
      if (empty()) {
        return T{};
      }

      const auto result = m_buffer[m_first];
      m_size--;
      if (++m_first >= S) {
          m_first -= S;
      }
      return result;
    }

  private:
    T m_buffer[S];
    byte m_first{0};
    byte m_size{0};
};
