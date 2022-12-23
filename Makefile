a.out: main.c 6309dasm.c hd6309.h
	gcc -g main.c 6309dasm.c

clean:
	rm -f a.out
