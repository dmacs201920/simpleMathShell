files= dllfunc.c dllcode.c
object= dllfunc.o dllcode.o
head= *.h

dll: $(object)
	gcc -o $@ $(object)

$(object): $(files) $(head)
	gcc -c -g $(files)

clean:
	rm -f *~ *.o
