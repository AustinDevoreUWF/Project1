#include "parse.hpp"
#include "param.hpp"
#include "cstdio"
#include <cstring>

void parse(char* line, Param& p){
    //call it once so we can start the loop
    char* token = strtok(line, " \n\t");

    while(token != nullptr){
        char* nextToken = strtok(nullptr, " \n\t");
        if(token[0] == '<'){
            p.setInputRedirect(token+1);
        }else if(token[0]=='>'){
            p.setOutputRedirect(token+1);
        }else if(token[0]=='&' && nextToken == nullptr){
            p.setBackground(1);
        }else{
            p.addArgument(token);
        }{

        }
        token = nextToken;
    }
    
}

