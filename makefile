chari: main.o functions.o characterStack.o doubleStack.o tokenizer.o dynamicDeclare.o infixToSuffix.o
	gcc -o $@ main.o functions.o characterStack.o doubleStack.o tokenizer.o dynamicDeclare.o infixToSuffix.o -lreadline -lm

main.o: main.c functionheader.h 
	gcc -c -g main.c

doubleStack.o: doubleStack.c functionheader.h
	gcc -c -g doubleStack.c
	
dynamicDeclare.o: dynamicDeclare.c functionheader.h
	gcc -c -g dynamicDeclare.c

characterStack.o: characterStack.c functionheader.h
	gcc -c -g characterStack.c

tokenizer.o: tokenizer.c functionheader.h
	gcc -c -g tokenizer.c

infixToSuffix.o: infixToSuffix.c functionheader.h
	gcc -c -g infixToSuffix.c

functions.o: functions.c functionheader.h
	gcc -c -g functions.c  

clean: 
	rm -f *.o *~ chari

