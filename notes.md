# Notes for part 2
scan each element in the argumentVector and find which one input failed on, return unknown cmd "whateverItWas"
## Implementation
**Each of these things must be implemented**
- *ls –l* shows a listing of files in the current directory
- *ls –l >testfile.txt* writes a listing of files into the text file testfile.txt
- *grep –i shell testfile.txt* list many lines containing the word shell in the previous file
- *cat <myshell.cpp* displays the source code of the program on the screen
- *cat <myshell.cpp &* as above except the output will be displayed in the background causing the prompt of the shell to be mixed with the output of the file
- *cat testfile.txt &* displays the content of the text file testfile.txt on the screen in the background
- *./slow &* runs the program slow from the current working directory in the background
- *exit* terminates the shell; all child processes must be terminated for the shell to close avoiding creation of zombie processe

## Needed Commands and explainations:
**The exec() calls take (argument[0],arguments), executable first then args to call with**(info from man pages)
The arguments[0] points to the first, so we will call with exec, im probably not using the calls with path as arg[0];
**Some explaination on suffix:**
Functions in the exec() family have different behaviours:

    l : arguments are passed as a list of strings to the main()
    v : arguments are passed as an array of strings to the main()
    p : path/s to search for the new running program
    e : the environment can be specified by the caller


- int execlp(const char *file, const char *arg, ...
    , (char *) NULL */);
- int execvp(const char *file, char *const argv[]);
- int execvpe(const char *file, char *const argv[], char *const envp[]);

**This looks like what we need**
int execvp(const char *file, char *const argv[]);

How do you run something in the background??
