chari: main.o functions.o 
	gcc -o $@ main.o functions.o -lreadline -lm

main.o: main.c functionheader.h 
	gcc -c -g main.c

hello:	trial.o functions.o
	gcc -o $@ functions.o -lreadline

functions.o: functions.c functionheader.h
	gcc -c -g functions.c  

clean: 
	rm -f *.o *~ chari

