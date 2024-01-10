prog: message_hider.o encrypt.o
	gcc *.o -o prog

message_hider.o: message_hider.c encrypt.c encrypt.h
	gcc -c *.c

encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c

clean:
	rm *.o
	rm prog
