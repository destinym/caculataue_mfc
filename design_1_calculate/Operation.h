#ifndef OPERATORTION_H
#define OPERATORTION_H
class Operation
{
public:
	Operation(double op1, double op2, char op);
	double getResult();
private:
	double op1;
	double op2;
	char op;
};

#endif