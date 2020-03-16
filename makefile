chari: main.o functions.o dllfunc.o hello 
	gcc -o $@ main.o functions.o dllfunc.o -lreadline -lm

main.o: main.c functionheader.h 
	gcc -c -g main.c

dllfunc.o: dllfunc.c functionheader.h
	gcc -c -g dllfunc.c

hello:	trial.o functions.o
	gcc -o $@ trial.o functions.o -lreadline

trial.o: trial.c functionheader.h
	gcc -c -g trial.c 

functions.o: functions.c functionheader.h
	gcc -c -g functions.c  

clean: 
	rm -f *.o *~ chari

#./a.out:
#	gcc -g try.c
