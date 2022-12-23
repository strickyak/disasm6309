# disasm6309
A quick hack to disassemble a scrap of 6809 code.

The scrap is hardcoded into main.c,
but it would be easy to change it to load it from somewhere.

```
$ make
gcc -g main.c 6309dasm.c
$ ./a.out
0000:  1f 10       == tfr   x,d
0002:  f7 ff 01       == stb   $FF01
*** add_code_label:  -5.
0005:  20 f9       == bra   _fffffffb
0007:  10 ce fd fe       == lds   #$FDFE
000b:  ce 00 00       == ldu   #$0000
000e:  10 ae c1       == ldy   ,u++
0011:  10 8c 00 00       == cmpy  #$0000
*** add_code_label:  6.
0015:  27 04       == beq   _0006
0017:  ad a4       == jsr   ,y
*** add_code_label:  -11.
0019:  20 f3       == bra   _fffffff5
001b:  1c af       == andcc #$00AF
001d:  bd 00 00       == jsr   $00
0020:  ce 00 00       == ldu   #$0000
0023:  10 ae c1       == ldy   ,u++
0026:  10 8c 00 00       == cmpy  #$0000
*** add_code_label:  6.
002a:  27 04       == beq   _0006
002c:  ad a4       == jsr   ,y
*** add_code_label:  -11.
002e:  20 f3       == bra   _fffffff5
0030:  7e 00 00       == jmp   $00
0033:  3b       == rti
$
```
