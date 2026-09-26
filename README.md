myshell - A Simple Unix Shell
Authors: Austin Devore, Stephen Byrd
Course: COP4634 Sys & Net I, Project 1: Processes
Date: 9/22/2026

PURPOSE
-------
myshell is a simplified command-line shell implemented in C++. It reads a
command line from the user, parses it into a command name, arguments,
optional input/output redirection, and an optional background execution
flag, then creates a new process to execute the requested program. The
shell demonstrates the basics of process creation (fork), process
replacement (exec), input/output redirection (freopen), and process
synchronization (waitpid), while avoiding the creation of zombie
processes.

FILES
-----
myshell.cpp   - main program; runs the prompt/read/parse/execute loop
parse.hpp     - declares the parse() function
parse.cpp     - implements parse(), which tokenizes a command line and
                fills in a Param object
param.hpp     - declares the Param class, which stores a parsed command
param.cpp     - implements the Param class (constructor, getters,
                setters, printParams())
Makefile      - builds the myshell executable
README        - this file

BUILDING
--------
From the project directory, run:

    make

This compiles all source files with -g -Wall and produces an executable
named myshell. To remove all compiled objects and the executable, run:

    make clean

USAGE
-----
Run the shell with:

    ./myshell

Optionally, start the shell in debug mode to print the parsed contents
of every command entered:

    ./myshell -Debug

(the option -debug, lowercase, is also accepted)

At the myshell> prompt, enter a command exactly as you would in a normal
shell. Supported features:

  - Running a program with arguments:
        myshell> ls -l

  - Input redirection (no space allowed between < and the filename):
        myshell> cat <myshell.cpp

  - Output redirection (no space allowed between > and the filename):
        myshell> ls -l >testfile.txt

  - Combined input and output redirection:
        myshell> grep -i shell <testfile.txt >results.txt

  - Background execution (& must be the last token on the line):
        myshell> ./slow &

  - Exiting the shell:
        myshell> exit

    All background processes started during the session are guaranteed
    to finish before the shell terminates when exit is entered.

ERROR HANDLING
--------------
- If a command name is invalid or not found (e.g. a misspelled command),
  execvp fails, an error message is printed, and the child process exits
  without affecting the parent shell.
- If < or > is given with no filename attached, an error message is
  printed and the line is not executed.
- If an input or output redirection file cannot be opened (e.g. the file
  does not exist, or permissions are wrong), an error message is printed
  and the child process exits without running the requested command.
- Blank lines (pressing Enter with no input) are ignored and simply
  re-prompt the user.

NOTES
-----
- The shell does not use system(3) or any other shell to do its work;
  all process creation and execution is done directly with fork() and
  execvp().
- Zombie processes are avoided by waiting on every foreground process
  immediately after it is launched, and by waiting on all remaining
  background processes before the shell exits on the exit command.
