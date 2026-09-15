#include "parse.hpp"
#include "param.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>


int main(int argc, char* argv[]){
    char* line = nullptr;
    size_t size = 0;

while(true){
  printf("myshell> ");
  getline(&line, &size, stdin);
  Param p{};
  //line represents the user chars, &line give us adress of line
  // adress of line is needed to point to it with strtok.
  parse(line,p);
  char** arguments = p.getArguments();
  int arguments = p.getArgumentCount();

  if(arguments > 0 && strcmp(arguments[0],"exit")==0)break;
  
  if(argc > 1 && (strcmp(argv[1],"-Debug") ==0 || strcmp(argv[1],"-debug")==0)){
    p.printParams();
  }
}
 return 0;
}
