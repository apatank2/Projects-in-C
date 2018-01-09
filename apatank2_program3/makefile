P=program3B
CFLAGS = -g -Wall -std=gnu11
all: defuseTheBomb checkmem clean
defuseTheBomb: defuseMe.o bomb.o hidden.o
	gcc $(CFLAGS) defuseMe.o bomb.o hidden.o -o defuseTheBomb
defuseMe.o: defuseMe.c
	gcc $(CFLAGS) -c defuseMe.c -o defuseMe.o
bomb.o: bomb.c
	gcc $(CFLAGS) -c bomb.c -o bomb.o
checkmem: $(P).c
	gcc $(P).c -o $(P)
	valgrind ./$(P)
clean:
	chmod 777 trash.sh
	./trash.sh *.o defuseTheBomb program3B
