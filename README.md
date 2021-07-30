# LPT2MIDI
- LPT2MIDI is a parallel printer port (LPT) to MIDI adapter.
- Autodesk Eagle PCB files are included.
- Uses Arduino IRQ to trigger pin reads and forwards the data to MIDI serial buffer (MIDI uses 31250 bps).
- A simple port trapping code for MS-DOS is included. This for the time being works for direct midi commands to port 330h only.
- Quickly modified version of SOFTMPU for MPU-401 compatibility.
- Tested with Roland MT-32 and Supaplex (an old MS-DOS game, requires minor modification to the code).
- Requires power through USB while operating.

Youtube link of the device in action: https://www.youtube.com/watch?v=MyJpt-w3Oao

![LPT2MIDI](https://user-images.githubusercontent.com/42321684/127677789-1f42574a-1fe5-411d-8408-9c0afb767f73.jpg)
