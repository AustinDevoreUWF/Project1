#include "parse.hpp"
#include "param.hpp"
#include "cstdio"
#include <cstring>

void parse(char* line){
    //call it once so we can start the loop
    char* token = strtok(line, " \n\t");

    while(token != nullptr){
        addArgument(token);
        
        token = strtok(line, " \n\t");
    }
}

