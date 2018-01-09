P=program6
Q=bst
all: $(P)
$(P): $(Q).o $(P).o
	gcc $(Q).o $(P).o -o $(P)
$(P).o: $(P).c
	gcc -c $(P).c -o $(P).o
$(Q).o: $(Q).c
	gcc -c $(Q).c -o $(Q).o
run: $(P)    
	./$(P)
checkmem: $(P)
	valgrind ./$(P)	
clean:
	rm -rf $(P) $(Q) *.o
