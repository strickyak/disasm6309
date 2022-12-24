# disasm6309
A quick hack to disassemble raw scraps of 6809/6309 code,
based on code by tim lindner, Sean Riddle, and possibly others.

See `6309dasm.c` for license info.

The raw 6809/6309 machine code, starting at address 0, is stdin.

```
$ hd /tmp/raw.out
00000000  34 40 33 e4 8e 00 64 35  c0 34 40 33 e4 35 c0 34  |4@3...d5.4@3.5.4|
00000010  40 32 7e 33 e4 af c4 17  ff e6 1e 01 e3 c4 1e 01  |@2~3............|
00000020  32 62 35 c0 34 40 32 7e  33 e4 af c4 ae c4 1e 01  |2b5.4@2~3.......|
00000030  e3 c4 1e 01 1e 01 e3 46  1e 01 32 62 35 c0 34 40  |.......F..2b5.4@|
00000040  32 7e 33 e4 af c4 17 ff  b7 32 62 35 c0 17 00 03  |2~3......2b5....|
00000050  17 ff eb 34 40 33 e4 8e  00 07 35 c0              |...4@3....5.|
0000005c
$ make && ./a.out < /tmp/raw.out
gcc -g main.c 6309dasm.c
0000:  3440          pshs  u
0002:  33e4          leau  ,s
0004:  8e0064        ldx   #$0064
0007:  35c0          puls  u,pc
0009:  3440          pshs  u
000b:  33e4          leau  ,s
000d:  35c0          puls  u,pc
000f:  3440          pshs  u
0011:  327e          leas  -2,s
0013:  33e4          leau  ,s
0015:  afc4          stx   ,u
0017:  17ffe6        lbsr  _0000
001a:  1e01          exg   d,x
001c:  e3c4          addd  ,u
001e:  1e01          exg   d,x
0020:  3262          leas  2,s
0022:  35c0          puls  u,pc
0024:  3440          pshs  u
0026:  327e          leas  -2,s
0028:  33e4          leau  ,s
002a:  afc4          stx   ,u
002c:  aec4          ldx   ,u
002e:  1e01          exg   d,x
0030:  e3c4          addd  ,u
0032:  1e01          exg   d,x
0034:  1e01          exg   d,x
0036:  e346          addd  6,u
0038:  1e01          exg   d,x
003a:  3262          leas  2,s
003c:  35c0          puls  u,pc
003e:  3440          pshs  u
0040:  327e          leas  -2,s
0042:  33e4          leau  ,s
0044:  afc4          stx   ,u
0046:  17ffb7        lbsr  _0000
0049:  3262          leas  2,s
004b:  35c0          puls  u,pc
004d:  170003        lbsr  _0053
0050:  17ffeb        lbsr  _003e
0053:  3440          pshs  u
0055:  33e4          leau  ,s
0057:  8e0007        ldx   #$0007
005a:  35c0          puls  u,pc
$
```
