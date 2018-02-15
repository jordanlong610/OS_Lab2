/*
* forkex.c - an example of using fork to create processes and execute new tasks
* Author: Jordan Long
*
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>



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


    int i = 0;
    char *p = strtok (commandLine, " ");
    char *array[10];

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, " ");
    }

}



/*
 * Takes in the command and arguments and forks the parent process.
 */
void createForkedProcess(char *arguments)
{

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
		execute(arguments);
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
}

/*
 * Takes the command and arguments and executes it.
 */
void execute(const char *arguments)
{
	if(execvp(arguments[0], arguments) < 0)
	{
		perror("Could not execute command.");
	}
}


/*
 * Main class for the project. Takes in user input and stores it in a char array. Then calls the fork method.
 */
int main(int argc, char **argv, char **envp)
{
	//Ask user for command and arguments

	char commandLine[40];

	printf ("Enter a command and arguments to run: ");
	scanf ("%s", commandLine);

	buildCommandLine(commandLine);


return 0;
}
