EXEproject: functions_project.o main.o
		gcc -o EXEproject functions_project.o main.o

functions_project.o: functions_project.c header.h
			gcc -c -g functions_project.c
main.o: main.c header.h
		gcc -c -g main.c
clean:
	rm -f *.o  *~ EXEproject

		
