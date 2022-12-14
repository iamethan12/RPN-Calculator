//============================================
//Ethan Scott
//November 28th, 2022
//calculator.cpp
//implementation of a stack calculator
//============================================
#include <iostream>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>
using namespace std;
void Calculate(const string& input, stack<double>& cStack);
bool isOperator(const string& input);
int main()
{
    cout << "Welcome to RPN Calculator: " << endl;
    cout << "Please enter Input\n";
    stack<double> cStack;
    string input;
        while(input != "0")
        {
            //Terminate program when 0 is entered by user
            while(input != "=")
            {
            // get input
            cin >> input;
            // check for being numeric value
            double num;
                if(istringstream(input) >> num)
                {
                    //use push function
                    cStack.push(num);
                }
                // check for operator
                else if(isOperator(input))
                {
                   Calculate(input, cStack);
                }
                
             
                // If user enters 0 on a line followed by a new line, the program 
exits
                else if(input == "END")
                {
                    return 0;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }
            }
            }
}
//============================================
// Calculate
// PURPOSE:
// preforms operations add, subtract, multiply, divide, and exponentation 
// PARAMETERS:
// input : it's whatever the user inputs
// cStack: our stack
// RETURN VALUE:
// no return value, just prints the result
//============================================
void Calculate(const string& input, stack<double>& cStack)
{
    double result = 0;
    // Keep popping operands from the stack until there are none left
    while (!cStack.empty())
    {
        double operand = cStack.top();
        cStack.pop();
        if (input == "-")
        {
            result -= operand;
        }
        else if (input == "*")
        {
            result *= operand;
        }
        else if (input == "+")
        {
            result += operand;
        }
        else if (input == "^")
        {
            result = pow(result, operand); 
        }
        else // input == "/"
        {
            result /= operand;
        }
    }
    cout << result << endl;
    cStack.push(result);
}
//============================================
// bool isOperator
// PURPOSE:
// checks to see if the user input is a operator or not
// PARAMETERS:
// input : it's whatever the user inputs
// RETURNS:
// if char not operator, returns false
// if char is operator, return true
//============================================
    bool isOperator(const string& input)
    {
        string operators[] = {"-", "+", "*", "/", "^"};
        for(int i=0; i<5; i++)
        {
            if(input == operators[i])
            {
                return true;
            }
        }
        return false;
    
    }
