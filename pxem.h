#pragma once

#include <stdio.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <time.h>
#include <stdlib.h>
#include <math.h>

class Pxem{
private:
	std::stack<int>	pStack;		// stack
	char		*fName;		// file name
	char		*fCont;		// file contents
	int		temp;		// temporary area
	bool		used;		// used temp?
	void	print();		// print stack
	bool	out();			// output
	void	numOut();		// output(number)
	void	input();		// input
	void	numInput();		// number input
	void	copy();			// x,y,z -> x,x,y,z
	void	throwAway();		// x,y,z -> y,z
	void	inverse();		// x,y,z -> z,y,x
	void	fileRead();		// input from file contents
	void	emu();			// run pxem using file contents
	void	getRand();		// create random number from stack[0]
	void	toTemp();		// temp = stack[0];
	void	fromTemp();		// if(used) stack.push(temp);
	void	addition();		// x,y,z -> (x+y),z
	void	subtraction();		// x,y,z -> abs(x-y),z
	void	multiplication();	// x,y,z -> (x*y),z
	void	getQuotient();		// x,y,z -> (x>y?int(x/y):int(y/x)),z
	void	getSurplus();		// x,y,z -> (x>y?int(x%y):int(y%x)),z
	void	addStr(char*);		// addStr("ab"); -> pStack.push(98);pStack.push(97);
public:
	Pxem(char* ,char*);			// constructor from main()
	Pxem(char* ,char*,std::stack<int>);		// constructor from Pxem
	void	run();				// run pxem
	std::stack<int>	getStack() const;	// get stack
};
