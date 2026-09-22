/**
 * This file implements the parse function, which separates a shell
 * command into arguments and identifies input redirection, output
 * redirection, and background execution
 * 
 * @author Austin Devore, Stephen Byrd
 * @date 9/22/2026
 * @info Course COP4634
 */

#include "parse.hpp"
#include "param.hpp"
#include "cstdio"
#include <iostream>
#include <cstring>

/**
 * Parses a command line and stores the information in a Param object.
 *
 * @param line command line entered by the user
 * @param p Param object that receives the parsed command information
 *
 * @return true if the command is parsed successfully, false if not
 */
bool parse(char* line, Param& p){
    //call it once so we can start the loop
    char* token = strtok(line, " \n\t");

    while(token != nullptr){
        /*
         * Get the next token so that '&' can be read as a
         * background operator only when it is the final token
         */
        char* nextToken = strtok(nullptr, " \n\t");
        if(token[0] == '<'){
           //structure must match that of "<input.txt"
           if (token[1] == '\0') {
                std::cout << "Error: input filename required\n";
                return false;
            }
            p.setInputRedirect(token+1);
        }else if(token[0]=='>'){
            //structure must match that of ">output.txt"
            if (token[1] == '\0') {
                std::cout << "Error: output filename required\n";
                return false;
            }
            p.setOutputRedirect(token+1);
        }else if(token[0]=='&' && nextToken == nullptr){
            /*
             * '&' indicates background execution only when it is the
             * final token in the command
             */
            p.setBackground(1);
        }else{
            p.addArgument(token);
        }
        token = nextToken;
    }return true;
    
}

