#include "parse.hpp"
#include "param.hpp"
#include "cstdio"
#include <iostream>
#include <cstring>

bool parse(char* line, Param& p){
    //call it once so we can start the loop
    char* token = strtok(line, " \n\t");

    while(token != nullptr){
        char* nextToken = strtok(nullptr, " \n\t");
        if(token[0] == '<'){
           if (token[1] == '\0') {
                std::cout << "Error: input filename required\n";
                return false;
            }
            p.setInputRedirect(token+1);
        }else if(token[0]=='>'){
            if (token[1] == '\0') {
                std::cout << "Error: output filename required\n";
                return false;
            }
            p.setOutputRedirect(token+1);
        }else if(token[0]=='&' && nextToken == nullptr){
            p.setBackground(1);
        }else{
            p.addArgument(token);
        }
        token = nextToken;
    }return true;
    
}

