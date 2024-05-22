all:
	gcc *.c *.h -o main

run: 
	./main

debug:
	gcc *.c *.h -g main


zip:
	
	zip trab1.zip *.c *.h