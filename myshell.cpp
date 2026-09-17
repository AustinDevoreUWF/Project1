#include "parse.hpp"
#include "param.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    char* line = nullptr;
    size_t size = 0;

while(true){
  printf("myshell> ");
  getline(&line, &size, stdin);
  Param p{};
  //line represents the user chars, &line give us adress of line
  // adress of line is needed to point to it with strtok.
  //continue stops this run and continues from top,(different from break which ends all loops)
  if(!parse(line,p))
    continue;

  char** arguments = p.getArguments();
  int argumentCount = p.getArgumentCount();

  if(argumentCount > 0 && strcmp(arguments[0],"exit")==0)break;
  if(argc > 1 && (strcmp(argv[1],"-Debug") ==0 || strcmp(argv[1],"-debug")==0)){
    p.printParams();
    }

  pid_t pid;
  pid = fork();
  if(pid == 0){
    char* iDirect = p.getInputRedirect();
    char* oDirect = p.getOutputRedirect();
    if(iDirect != NULL){
      FILE* ifp;
      ifp = freopen(iDirect, "r", stdin);
    }
    if(oDirect != NULL){
      FILE* ofp;
      ofp = freopen(oDirect, "w",stdout);
    }
    //run execvp(argVectr[0],argVector) to run the new process
    execvp(arguments[0],arguments);
  }else if(pid != 0){
    //parent proccess
    if(p.getBackground() == 1){
      //needs implenting
    }else{
      int status{};
      waitpid(pid,&status,0);
      
    }
  }

  }
 return 0;
}
