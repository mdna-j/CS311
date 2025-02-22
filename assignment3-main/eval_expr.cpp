/**
 *Implementation of the functions to evaluate arithmetic expressions
 *The implementation should use the Stack data structure
 */
//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
//You should always comments to each function to describe its PURPOSE and PARAMETERS
#include "stack.h"
#include "eval_expr.h"
#include <iostream>
#include <cmath>

/**
 *@brief Evaluate a postfix expression
 *@param postfix_expr The input expression in the postfix format.
 *@param result gets the evaluated value of the expression (by reference).
 *@return true if expression is a valid postfix expression and evaluation is done without error, otherwise false.
 */

bool evalPostfixExpr(string postfix_expr, float &result){
	// TODO: Add your code here
	 Stack<float> s;

    for (char c : postfix_expr) {
        if (isdigit(c)) {
            s.push(c - '0'); // Convert char to int and push onto the stack
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (s.isEmpty()) return false;

            float operand2;
            s.pop(operand2); // Pop operand2

            if (s.isEmpty()) return false;

            float operand1;
            s.pop(operand1); // Pop operand1

            float tempResult;
            switch (c) {
                case '+': tempResult = operand1 + operand2; break;
                case '-': tempResult = operand1 - operand2; break;
                case '*': tempResult = operand1 * operand2; break;
                case '/': 
                    if (operand2 == 0) return false; // Division by zero
                    tempResult = operand1 / operand2; 
                    break;
                default: return false;
            }
            s.push(tempResult);
        } else {
            return false; // Invalid character
        }
    }

    if (s.isEmpty()) return false;

    float res;
    s.pop(res); // Pop the final result
    result = round(res * 10) / 10; // Round to one decimal place
    return s.isEmpty(); // Stack should be empty if evaluation is successful
}

int precedence(char op) {
    if (op == '*' || op == '/'){
        return 2;
    } else if(op == '+' || op == '-'){
        return 1;
    }else{
        return 0;
    }
}

/**
 *@brief Convert an infix expression to an equivalent postfix expression
 *@param infix_expr The input expression in the infix format.
 *@return the converted postfix expression. If the input infix expression is invalid, return an empty string "";
 */
string convertInfixToPostfix(string infix_expr){
	// TODO: Add your code here
	Stack <float> s;
    string postfix = "";

    for (int i = 0; i < infix_expr.size(); i++){
        char c = infix_expr[i];

        if(isalnum(c)){
            postfix += c;
        }else if(c == '('){
            s.push('(');
        }else if(c == ')'){
            while(s.top() != '('){
                postfix += s.top();
                s.top();
            }
            s.top();
        }else{
            while(!s.isEmpty() && precedence(c) <= precedence(s.top())){
                postfix += s.top();
                s.pop(s.top());
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()){
        postfix += s.top();
        s.pop(s.top());
    }
    return postfix;
}



/**
 *@brief Evaluate an infix expression. It's converted to a postfix expression first and then evaluated
 *@param infix_expr The input expression in the infix format.
 *@param result gets the evaluated value of the expression (by reference).
 *@return true if expression is valid and evaluation is done without error, otherwise false.
 */
bool evalInfixExpr(string infix_expr, float &result){
	// TODO: Add your code here
    string postfix_expr = convertInfixToPostfix(infix_expr);

    if (postfix_expr == "") {
        return false; // Invalid infix expression
    }
    
    return evalPostfixExpr(postfix_expr, result);
}

