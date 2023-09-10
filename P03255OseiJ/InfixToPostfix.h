// TO BE COMPLETED:
//		postfix()

// SOLUTION: InfixToPost.h
#ifndef INFIX_TO_POSTFIX
#define INFIX_TO_POSTFIX

#include <iostream>
#include <string>
#include "MyStack.h"
#include <ctype.h>

#include "ExpressionSymbol.h"	// expressionSymbol class
#include "CS255Exceptions.h"	// for expressionError exception

using namespace std;

// labels designating the parentheses characters
const char lParen = '(';
const char rParen = ')';

class InfixToPostfix
{
public:
	// default constructor. infix expression is NULL string
	InfixToPostfix();

	// initialize the infix expression
	InfixToPostfix(const string& infixExp);

	// change the infix expression
	void setInfixExp(const string& infixExp);

	// return a string that contains the equivalent postfix expression.
	//   The function throws ExpressionError if an error occurs during conversion
	string postfix();

private:
	// the infix expression to convert
	string infixExpression;

	// built to contain the postfix equivalent of infixExpression
	string postfixExpression;

	// stack of expressionSymbol objects
	myStack<ExpressionSymbol> operatorStack;

	// The expressionSymbol object op holds the current symbol.
	//   Pop the stack and output as long as the symbol
	//   on the top of the stack has a precedence >= that of
	//   the current operator
	void outputHigherOrEqual(const ExpressionSymbol& op);

	// is ch one of '+','-','*','/', '^'
	bool isOperator(char ch) const;
};

// Determine which operators need to be popped from stack
//	before adding the new operator, "op"
//  Determines whether operator left on the stack should be output before
//  pushing operator right on the stack
void InfixToPostfix::outputHigherOrEqual(const ExpressionSymbol& op) {
	ExpressionSymbol op2;

	while (!operatorStack.isEmpty() && (op2 = operatorStack.top()) >= op) {
		operatorStack.pop();
		postfixExpression += op2.getOp();
		postfixExpression += ' ';
	}
}

bool InfixToPostfix::isOperator(char ch) const {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

InfixToPostfix::InfixToPostfix() {}

InfixToPostfix::InfixToPostfix(const string& infixExp) : infixExpression{ infixExp } {}

void InfixToPostfix::setInfixExp(const string& infixExp) {
	// assign a new infix expression
	infixExpression = infixExp;
	// make postfixExpression the NULL string
	postfixExpression = "";
}

string InfixToPostfix::postfix() {
	/**** TO BE COMPLETED *****/
	postfixExpression = " ";
	while (!operatorStack.isEmpty()) {
		operatorStack.pop();
	}
	int increment = 0;
	for (size_t i = 0; i < infixExpression.length(); i++) {
		char x = infixExpression[i];
		if (isspace(x)) {
			continue;
		}
		else if (isdigit(x)) {
			string result = " ";
			while (i < infixExpression.length() && isdigit(infixExpression[i])) {
				result += infixExpression[i];
				i++;
			}
			i--;
			postfixExpression += result;
			postfixExpression += ' ';
		}
		else if (x == lParen) {
			operatorStack.push(ExpressionSymbol(lParen));
			increment++;
		}
		else if (x == rParen) {
			if (increment == 0) {
				throw ExpressionError("infix2Postfix: Missing '('");
			}
			increment--;
			while (!operatorStack.isEmpty() && operatorStack.top().getOp() !=lParen) {
				postfixExpression += operatorStack.top().getOp();
				postfixExpression += ' ';
				operatorStack.pop();
			}
			if (operatorStack.isEmpty()) {
				throw ExpressionError("infix2Postfix: Missing '(");
			}
			operatorStack.pop();
		}
		else if (isOperator(x)) {
			ExpressionSymbol op(x);

			outputHigherOrEqual(op);
			operatorStack.push(op);
		}
		else {
			throw ExpressionError("Invalid character");
		}

	}
	while (!operatorStack.isEmpty()) {
		if (operatorStack.top().getOp() == lParen) {
			throw ExpressionError("infix2Postfix: Missing ')'");

		}
		postfixExpression += operatorStack.top().getOp();
		postfixExpression += ' ';
		operatorStack.pop();
	}

	if (increment > 0) {
		throw ExpressionError("infix2Postfix: Missing ')'");
	}

	if (postfixExpression.length() > 0) {
		postfixExpression.pop_back();
	}

	return postfixExpression;
}
//end postfix()



#endif	// INFIX_TO_POSTFIX
