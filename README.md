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

	functions.c -> This file contains functions that return values pertaining
			to the processes that the shell performs.

	infixToSuffix.c -> This file contains the functions to convert the entered 
			   expression (in the form of tokens) into a Suffix expression.
			   For eg. <99><+><88><*><77></><66> --> <99><88><77><66></><*><+>

	dynamicDeclare.c -> This file contains the functions that dynamically declare variables
			    in the shell. The input is again a tokenized input which stores all 
			    the declared variables in string format and then call the values of 
			    the variables by inputing "all variables" command on the shell.
			    Moreover, for the variables that are defined by the User, the User
			    can then opt to perform arithematic operations with those declared 
			    variables too.
			    For eg. ~/cherry_shell:)/>>> x=3
			    	    ~/cherry_shell:)/>>> all variables
				    x=3
				    ~/cherry_shell:)/>>> y=4
				    ~/cherry_shell:)/>>> all variables
				    y=4
				    x=3
				    ~/cherry_shell:)/>>> x+y
				    7
				    ~/cherry_shell:)/>>> 
	
	main.c -> This is the main file has the program written.

	makefile -> This is the build used to compile the project


		
