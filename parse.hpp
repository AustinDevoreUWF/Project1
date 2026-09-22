/**
 * This file declares the parse function used to process command-line
 * input for the shell program
 *
 * @author Austin Devore, Stephen Byrd
 * @date 9/22/2026
 * @info Course COP4634
 */

#ifndef PARSE_HPP
#define PARSE_HPP
#include "param.hpp"

/**
 * Parses a command line and stores the information in a Param object.
 *
 * @param line command line entered by the user
 * @param p Param object that receives the parsed command information
 *
 * @return true if the command is parsed successfully, false if not
 */
bool parse(char* line, Param& p);

#endif
