#include "parse.hpp"
#include "param.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>

int main(int argc, char* argv[]){
    char* line = nullptr;
    size_t size = 0;
    std::vector<pid_t> backgroundPids{};

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

  if(argumentCount > 0 && strcmp(arguments[0],"exit")==0){
    for(int i=0;i<backgroundPids.size();i++){
     int status{};
     waitpid(backgroundPids[i], &status, 0);
    }
    break;
  }
  if(argc > 1 && (strcmp(argv[1],"-Debug") ==0 || strcmp(argv[1],"-debug")==0)){
    p.printParams();
    }

  pid_t pid;
  pid = fork();
  if(pid == 0){
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
