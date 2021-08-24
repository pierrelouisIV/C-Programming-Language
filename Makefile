run: prog
	./prog

debug:
	valgrind ./prog

prog: main.o matrix.o
	gcc -Wall main.o matrix.o -o prog

matrix.o: matrix.c matrix.h
	gcc -c -Wall matrix.c

main.o: main.c
	gcc -c -Wall main.c

clean:
	rm -f prog
	rm -f main.o
	rm -f matrix.o