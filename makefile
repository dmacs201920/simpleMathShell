chari: main.o functions.o characterStack.o doubleStack.o tokenizer.o
	gcc -o $@ main.o functions.o characterStack.o doubleStack.o tokenizer.o -lreadline -lm

main.o: main.c functionheader.h 
	gcc -c -g main.c

doubleStack.o: doubleStack.c functionheader.h
	gcc -c -g doubleStack.c

characterStack.o: characterStack.c functionheader.h
	gcc -c -g characterStack.c

tokenizer.o: tokenizer.c functionheader.h
	gcc -c -g tokenizer.c

hello:	trial.o functions.o
	gcc -o $@ functions.o -lreadline

functions.o: functions.c functionheader.h
	gcc -c -g functions.c  

clean: 
	rm -f *.o *~ chari

