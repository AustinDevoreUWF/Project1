#include "parse.hpp"
#include "param.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(){
    char* line = nullptr;
    size_t size = 0;
    Param p{};

while(true){
  printf("Test Output");
  
  getline(&line, &size, stdin);
  //line represents the user chars, &line give us adress of line
  // adress of line is needed to point to it with strtok.
  parse(line,p);
 }
 return 0;
}
