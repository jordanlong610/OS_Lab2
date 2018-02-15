/*
* forkex.c - an example of using fork to create processes and execute new tasks
*
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
/*
* execute - execute the given command with the given arguments, and the given environment
* const char *binary - the name of the binary file to load (e.g. /bin/ls)
* char *const arguments[] - the argv array - remember, argv[0] must be the command name
* char *const envp[] - the array of environment variables for this session
*
* note:
*	const char *variable - a string whose contents won't be changed
*	char *const variable[] - a array of pointers (strings) whose content's won't be changed
*	- but the things the pointers point at may be changed.
*/
void execute(const char *binary, char *const arguments[], char *const envp[])
{
	if (execve(binary, arguments, envp) < 0)
	{
		perror("Could not execute command.");
	}
}

/**
 * count the number of arguments.
 */
int countArguments(const char *commandLine)
{
	int num=0;


	return num;
}

/**
 * given a pointer to a string, find the start of the next argument and the end of the argument,
 * malloc a new string of that length, and return it the new string.
 */
const char *nextArgument(const char *currentString)
{


}


/**
 * given a command line string, call on countArguments to count the # of arguments present,
 * mallocate an array of pointers to hold that # of string pointers, call on
 * nextArgument that number of times, storing the resulting pointer to a string into each element of the array.
 */

char **buildCommandLine(const char *commandLine)
{




}





int main(int argc, char **argv, char **envp)
{
	//Ask user for command and arguments

	char input[40];

	printf ("Enter a command and arguments to run: ");
	scanf ("%s", input);

	printf(input);







	//Fork child process from parent
	pid_t pid = fork( );
	//If pid goes negative, fork has failed. Throws error and exits.
	if (pid < 0)
	{
		perror("Error: fork failed.");
		exit(-1);
	}




	// pid is 0? a new process was created, and this copy is it
	if (pid == 0)
	{
		// null terminator is important - when a "null string" is encountered
		// it signals the end of the array of strings
		char *arguments[3] = { "/bin/ls", "-l", 0x00 };
		// execute the new command, with the new arguments, and the environment
		execute("/bin/ls", arguments, envp);
		// this should never return - so if it doesn't, something bad happened.
		abort( );
	}



	// pid is not 0? then it is the pid of the child
	else
	{
		int status;
		printf("Waiting for command to finish.\n");
		waitpid(pid, &status, 0);
		printf("This is still the parent: child exited with status %x\n",
		status);
	}
	return 0;
}
