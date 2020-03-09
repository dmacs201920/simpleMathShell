chari: main.o functions.o dllfunc.o #./a.out
	gcc -o $@ main.o functions.o dllfunc.o -lreadline -lm

main.o: main.c functionheader.h 
	gcc -c -g main.c

dllfunc.o: dllfunc.c functionheader.h
	gcc -c -g dllfunc.c

functions.o: functions.c functionheader.h
	gcc -c -g functions.c -lm 

clean: 
	rm -f *.o *~

#./a.out:
#	gcc -g try.c
