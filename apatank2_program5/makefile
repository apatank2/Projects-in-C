P=program5
Q=profile
V=vector
L=list
all: $(P)
$(P): $(L).o $(V).o $(Q).o $(P).o
	gcc $(L).o $(V).o $(Q).o $(P).o -o $(P)
$(P).o: $(P).c
	gcc -c $(P).c -o $(P).o
$(Q).o: $(Q).c
	gcc -c $(Q).c -o $(Q).o		
$(V).o: $(V).c
	gcc -c $(V).c -o $(V).o
$(L).o: $(L).c
	gcc -c $(L).c -o $(L).o	
run: $(P)    
	./$(P)
checkmem: $(P)
	valgrind ./$(P)	
clean:
	rm -rf $(P) $(Q) $(V) $(L) *.o
