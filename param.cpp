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
	inputRedirect = newInputRedirect;
}

void Param::setOutputRedirect(char *newOutputRedirect)
{
	outputRedirect = newOutputRedirect;
}
		
void Param::setBackground(int newBackground)
{
	background = newBackground;
}

char* Param::getInputRedirect()
{
	return inputRedirect;
}
		
		
char* Param::getOutputRedirect()
{
	return outputRedirect;
}
		
int Param::getBackground()
{
    return background;
}


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

