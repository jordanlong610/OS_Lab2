/*
 * enviro.c
 * Prints all the enviroment variables in the program.
 *
 *  Created on: Feb 6, 2018
 *      Author: jl1361
 */


#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
//int main(int argc, char **argv, char **envp)
//{
//
//	//Prints all the commands in the program.
//	for (int i = 0; i < argc; i++)
//	{
//		printf("%s\n", argv[i]);
//	}
//
//
//
//	//Prints all the environment commands. Stops when null.
//	for (char **env = envp; *env != 0; env++)
//	  {
//	    char *thisEnv = *env;
//	    printf("%s\n", thisEnv);
//	  }
//
//
//
//}
