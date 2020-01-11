# LPT2MIDI
- LPT2MIDI is a parallel printer port (LPT) to MIDI adapter.
- Autodesk Eagle PCB files are included.
- Uses Arduino IRQ to trigger pin reads and forwards the data to MIDI serial buffer (MIDI uses 31250 bps).
- A simple port trapping code for MS-DOS is included. This for the time being works for direct midi commands to port 330h only.
- Should be fairly easy to enable full MPU-401 compatibility through software (like SOFTMPU for example).
- Tested with Roland MT-32 and Supaplex (an old MS-DOS game, requires minor modification to the code).

Youtube link of the device in action: https://www.youtube.com/watch?v=MyJpt-w3Oao
