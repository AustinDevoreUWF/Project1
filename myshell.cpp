/**
 * This program implements a simple shell that parses user commands,
 * supports input and output redirection, and background processes
 *
 * @author Austin Devore, Stephen Byrd
 * @date 9/22/2026
 * @info Course COP4634
 */

#include "parse.hpp"
#include "param.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>

/**
 * Runs the main loop for the shell program
 *
 * The shell repeatedly prompts the user for a command, parses the
 * command, handles the exit command, optionally prints debugging
 * information, and creates a child process to execute the command.
 *
 * @param argc number of command-line arguments
 * @param argv array of command-line arguments
 *
 * @return 0 when the shell exits normally
 */
int main(int argc, char* argv[]){
    char* line = nullptr;
    size_t size = 0;
    std::vector<pid_t> backgroundPids{};

while(true){
  printf("myshell> ");
  getline(&line, &size, stdin);
  Param p{};
  //line represents the user chars, &line give us address of line
  //address of line is needed to point to it with strtok.
  //continue stops this run and continues from top,(different from break which ends all loops)
  if(!parse(line,p))
    continue;

  char** arguments = p.getArguments();
  int argumentCount = p.getArgumentCount();

  /*
   * If the first argument is "exit", all background processes
   * must finish before terminating the shell
   */
  if(argumentCount > 0 && strcmp(arguments[0],"exit")==0){
    for(int i=0;i<backgroundPids.size();i++){
     int status{};
     waitpid(backgroundPids[i], &status, 0);
    }
    break;
  }
  /*
   * Print parsed command information when the user starts the
   * shell with either the -Debug or -debug command-line option
   */
  if(argc > 1 && (strcmp(argv[1],"-Debug") ==0 || strcmp(argv[1],"-debug")==0)){
    p.printParams();
    }

  pid_t pid;
  pid = fork();
  if(pid == 0){
    /*
     * The child process handles input and output redirection
     * before replacing itself with the requested command
     */
    char* iDirect = p.getInputRedirect();
    char* oDirect = p.getOutputRedirect();
    if(iDirect != NULL){
      freopen(iDirect, "r", stdin);
    }
    if(oDirect != NULL){
      freopen(oDirect, "w",stdout);
    }
    //run execvp(argVectr[0],argVector) to run the new process
    if(execvp(arguments[0],arguments)== -1){;
      perror("execvp error");
      exit(1);
    }
  }else if(pid > 0){
    //parent proccess
    if(p.getBackground() == 1){
        backgroundPids.push_back(pid);
    }else{
      int status{};
      waitpid(pid,&status,0); 
    }
  }else{
    perror("fork erro");
  }
}
 return 0;
}
