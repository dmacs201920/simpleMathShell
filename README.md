# mathShell.3bsc
A novice implementation of a simple math Shell

	MATH SHELL: By Hariharan and Abhiishek S Chugh
		-173209		-171201		
		-III B.Sc. Mathematics (Honours)




	ABOUT:
	The project is a Simple Math Shell project that enables the
	User to perform the operations of addition, multiplication,
	division and subtraction of both variables(declared by the user)
	and of numerical values entered by the User.

	The shell can also open perform the functions that a usual
	shell can except 'alias'.

	The shell first tokenizes the input string taken using the
	readline library and adds it to the history of commands
	entered. Then it goes to the 'function check' which
	returns an integer which transfers the control to a switch
	case which calls the functions. Before calling the function
	the program fork a new process and executes all the new
	functions in that new process.

	FILES:
	characterStack.c -> This file has all the functions that help to 
			    initialize, Push, Pop and return the Topvalue
			    of the character pointer stack.
	
	doubleStack.c -> This file has all the functions that help to 
			 initialize, Push, Pop and return the Topvalue
			 of the stack of type double.

	functionheader.h -> This file houses the definitions of all the 
			    functions used in the project.

	functions.c -> This file contains the functions written to aid the
			addition, conversion from Infix to Suffix, Evaluation
			of Expressions, declaration of dynamic variables, and
			their operations, etc.
	
	main.c -> This is the main file has the program written.

	makefile -> This is the build used to compile the project


		
