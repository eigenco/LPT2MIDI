DEL SOFTMPU.EXE
REM DEL *.OBJ
REM CL /c /W2 /BATCH /Ox /FoMPU401.obj MPU401.C
CL /c /W2 /BATCH /Ox /FoMIDI.obj MIDI.C
REM CL /c /W2 /BATCH /Ox /FoPIC.obj PIC.C
REM ML /c /Cx /W2 /WX /nologo /FoSOFTMPU.obj SOFTMPU.ASM
LINK /NOI /BATCH /FAR /NODEFAULTLIBRARYSEARCH mpu401.obj midi.obj pic.obj softmpu.obj,softmpu.exe,,,,,
