#include "stdafx.h"
#include "Operation.h"

Operation::Operation(double op1, double op2, char op)
{
	this->op = op;
	this->op1 = op1;
	this->op2 = op2;
}


double Operation::getResult()
{
	double result;
	switch(op)
	{
	case '+':
		result = op1 + op2;
		break;
	case '-':
		result = op1 - op2;
		break;
	case '*':
		result = op1 * op2;
		break;
	case '/':
		if (op2< 1e-15 && op2>-1e-15)	
		{
			//“Ï≥£¥¶¿Ì
			return 0;
		}
		result = op1/op2;
		break;
	}

	return result;
}
