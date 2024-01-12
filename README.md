************************Simple Shell Program************************



-Overview-

This repository contains a simple shell program implemented in C. The shell allows users to enter commands interactively and executes them in child processes. It supports basic features such as command execution, tokenization, and exiting the shell.

-Features-

+Command Execution: The shell can execute commands entered by the user in child processes.

+Tokenization: User input is tokenized into an array of strings, making it possible to parse and execute commands.

+Exit Command: The shell can be exited by entering the command "exit."

-How to Use-

1-Compile the Program: "using gcc you can use this command"
gcc Core_Main.c Functions_1.c Functions_2.c -o hsh

2-Run the Shell:
./hsh

3-Enter commands
Enter commands interactively, and the shell will execute them

Exit the Shell:
To exit the shell, enter the command "exit."


-Code Structure-

Core_Main.c: Contains the main function and the shell execution loop.

Functions_1.c: Implements functions related to command execution, process handling, and string manipulation.

Functions_2.c: Implements functions related to path searching, environment variable retrieval, and memory management.

-Notes-

=>This shell is a basic implementation suitable for educational purposes. It lacks advanced features and error handling.

=>The code follows the C90 standard and uses comments to explain the functionality of each function.
