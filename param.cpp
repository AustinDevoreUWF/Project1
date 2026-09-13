#ifndef _PARAM_CPP
#define _PARAM_CPP
#include <iostream>
#include "param.hpp"
using  namespace std;

Param::Param() 
{
	inputRedirect = outputRedirect = NULL;
	background = 0;
	argumentCount = 0;
}
//work on getting the token into the argument vector
void Param::addArgument (char* newArgument)
{
	argumentVector[argumentCount] = newArgument;	
	argumentCount++;
}
//return the arguments in the argumentVector
char** Param::getArguments()
{	
	return argumentVector;
}

void Param::setInputRedirect(char *newInputRedirect)
{
	//finish this
}

void Param::setOutputRedirect(char *newOutputRedirect)
{
	//finish this
}
		
void Param::setBackground(int newBackground)
{
	//finish this
}

char* Param::getInputRedirect()
{
	//finish this
	return NULL;
}
		
		
char* Param::getOutputRedirect()
{
	//finish this
	return NULL;
}
		
int Param::getBackground()
{
	// finish this
    return 0;
}


void Param::printParams() {
	cout << "InputRedirect: [" 
	     << (inputRedirect != NULL) ? inputRedirect : "NULL";
	cout << "]" 
	     << endl 
		 <<	"OutputRedirect: [" 
		 << (outputRedirect != NULL) ? outputRedirect : "NULL";
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

