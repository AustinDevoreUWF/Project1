/**
 * This file implements the Param class, which stores parsed command
 * information including arguments, input and output redirection,
 * and background execution status
 *
 * @author Austin Devore, Stephen Byrd
 * @date 9/22/2026
 * @info Course COP4634
 */

#ifndef _PARAM_CPP
#define _PARAM_CPP
#include <iostream>
#include "param.hpp"
using  namespace std;

//constructs an empty Param object
Param::Param() 
{
	inputRedirect = outputRedirect = NULL;
	background = 0;
	argumentCount = 0;
	argumentVector[0] = NULL;
}

/**
 * Adds an argument to the argument vector.
 *
 * @param newArgument argument string to add; if NULL, nothing is added
 */
void Param::addArgument(char *newArgument)
{
    if (newArgument == NULL)
        return;

    if (argumentCount >= MAXARGS - 1) {
        cerr << "Error: too many arguments\n";
        return;
    }

    argumentVector[argumentCount] = newArgument;
    argumentCount++;

    argumentVector[argumentCount] = NULL;
}

/**
 * Returns the argument vector stored in this object.
 *
 * The final element of the returned array is NULL.
 *
 * @return pointer to the array of command arguments
 */
char** Param::getArguments()
{	
	return argumentVector;
}

/**
 * Returns the number of arguments stored in the object.
 *
 * @return number of command arguments
 */
int Param::getArgumentCount(){
	return argumentCount;
}

/**
* Sets the filename for input redirection.
*
* @param newInputRedirect a string specifying the input redirect
filename
*/
void Param::setInputRedirect(char *newInputRedirect)
{
	inputRedirect = newInputRedirect;
}

/**
* Sets the filename for output redirection.
*
* @param newOutputRedirect a string specifying the output redirect
filename
*/
void Param::setOutputRedirect(char *newOutputRedirect)
{
	outputRedirect = newOutputRedirect;
}

/**
* Sets whether or not the command should be executed in the background.
*
* @param newBackground 1 if the command should execute in the 
background (true), or 0 if it should not execute in the background (false)
*/
void Param::setBackground(int newBackground)
{
	background = newBackground;
}

/**
* Returns the filename for input redirection.
*
* @return a string representing a filename
*/
char* Param::getInputRedirect()
{
	return inputRedirect;
}
		
/**
* Returns the filename for output redirection.
*
* @return a string representing a filename
*/		
char* Param::getOutputRedirect()
{
	return outputRedirect;
}

/**
* Returns whether or not the command should execute in the background.
*
* @return 1 if executed in the background, 0 if it's not
*/
int Param::getBackground()
{
    return background;
}

/**
* Prints the information in the specified structure to standard out.
*/
void Param::printParams() {
	cout << "InputRedirect: [" 
	     << (inputRedirect != NULL ? inputRedirect : "NULL");
	cout << "]" 
	     << endl 
		 <<	"OutputRedirect: [" 
		 << (outputRedirect != NULL ? outputRedirect : "NULL");
	cout << "]" 
	     << endl 
		 << "Background: [" 
		 << background 
		 << "]" 
		 << endl 
		 << "ArgumentCount: [" 
		 << argumentCount 
		 << "]" 
		 << endl;
	for (int i = 0; i < argumentCount; i++)
		cout << "ArgumentVector[" 
			 << i 
			 << "]: [" 
			 << argumentVector[i] 
			 << "]" 
			 << endl;
};

#endif

