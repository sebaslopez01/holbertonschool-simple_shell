# holbertonschool-simple_shell

### Description

This repository contains the files to simulate a basic Unix Shell with its respective commands. C - Simple Shell project at Holberton School.

This simple shell is a Shell interface written in C programming language that gives to the user a prompt 
> #cisfun$ 
This repository holds all the code necessary for our custom simple shell to run. Our shell currently handles the executions of executables found in the environmental variable PATH, with or without their full paths. Sample commands that our shell supports include ls (/bin/ls), pwd, echo, which, whereis, etc. We've also created the following builtins.

### Purpose

The purpose of the simple shell project is to understand:

* How a shell works
* PID and PPIDs
* How processes are created
* the three prototypes of main
* How the shell uses the PATH to find and execute programs
* The EOF/"end-of-file" condition


### Builtins Supported

	env - list the current environment variables

	exit - exit the shell

### Install and Compile

	(your_terminal)$ git clone https://github.com/sebaslopez01/holbertonschool-simple_shell.git
	(your_terminal)$ cd holbertonschool-simple_shell
	(your_terminal)$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

### Invocation

hsh can be invoked both interactively an non-interactively. 
If hsh is invoked with standard input not connected to a terminal, it reads and executes received commands in order.
	(your_terminal)$ ./hsh
	#cisfun$

## Interactive mode, example:

	(your_terminal)$ ./hsh
	#cisfun$ /bin/ls
	hsh main.c shell.c
	#cisfun$ 
	#cisfun$ exit
	(your_terminal)$ 

## Non-interactive mode:

	#cisfun$ echo "/bin/ls" | ./hsh
	hsh main.c shell.c test_ls_2
	#cisfun$

### Flowchat

This flowchart shows the elaboration process after a whiteboarding session to understand how the simple shell will work.

![flowchart picture](https://i.ibb.co/k1Gtc4t/flowchart-shell.jpg)

### Environment

    Language: C
    OS: Ubuntu 14.04 LTS
    Compiler: gcc 4.8.4
    Style guidelines: Betty style

### Authors

This program was created by:

> * Sebastian Lopez
> * Rodrigo Duque

### License

This project is free to use without permission. However, it is provided as-is and with absolutely no warranties.
