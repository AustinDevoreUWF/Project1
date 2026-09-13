#include "parse.h"
#include "Param.h"
#include "cstdio"
#include <cstring>

void parse(char* line){
    //call it once so we can start the loop
    char* token = strtok(line, " \n\t");

    while(token != nullptr){
        addArgument(token);
        
        token = strtok(input, " \n\t");
    }
}

