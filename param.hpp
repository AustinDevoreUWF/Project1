#ifndef _PARAM_HPP
#define _PARAM_HPP
/* Don't test program with more than this many tokens for input */
#define MAXARGS 32
/* Class to hold input data */
class Param
{
private:
char *inputRedirect; /* file name or NULL */
char *outputRedirect; /* file name or NULL */
int background; /* either 0 (false) or 1 (true) */
int argumentCount; /* same as argc in main() */
char *argumentVector[MAXARGS]; /* array of strings */
public:
/**
* Constructs an empty Param object.
*/
Param();
/**
* Adds an argument string to the argument list in this object. This
function
* does not create a string copy of the original string.
*
* @param newArgument a new argument to be added to the argument list;
* if NULL nothing will be added
*/
void addArgument (char* newArgument);
/**
* Returns an argument list referencing char* strings. The last element
in the
* list is NULL to mark the end of list elements. This makes the size
of
* the list one larger than the number of arguments added to this
object.
*
* Note:
* Caller must deallocate memory for the list.
*/
char** getArguments();
// getter & setter functions
/**
* Sets the filename for input redirection.
*
* @param newInputRedirect a string specifying the input redirect
filename
*/
int getArgumentCount();

void setInputRedirect(char *newInputRedirect);
/**
* Sets the filename for output redirection.
*
* @param newOutputRedirect a string specifying the output redirect
filename
*/
void setOutputRedirect(char *newOutputRedirect);
/**
* Sets whether or not the command should be executed in the background.
*
* @param newBackground 1 if the command should execute in the 
background (true), or 0 if it should not execute in the background (false)
*/void setBackground(int newBackground);
/**
* Returns the filename for input redirection.
*
* @return a string representing a filename
*/
char* getInputRedirect();
/**
* Returns the filename for output redirection.
*
* @return a string representing a filename
*/
char* getOutputRedirect();
/**
* Returns whether or not the command should execute in the background.
*
* @return 1 if executed in the background, 0 if it's not
*/
int getBackground();
/**
* Prints the information in the specified structure to standard out.
*/
void printParams();
};
#endif
