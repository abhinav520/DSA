#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')')
    {
        return 0;
    }
    return 1;
}

int outPrecedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 3;
    }
    else if (x == '^')
    {
        return 6;
    }
    else if (x == '(')
    {
        return 7;
    }
    else if (x == ')')
    {
        return 0;
    }
    return -1;
}

int inPrecedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 2;
    }
    else if (x == '*' || x == '/')
    {
        return 4;
    }
    else if (x == '^')
    {
        return 5;
    }
    else if (x == '(')
    {
        return 0;
    }
    return -1;
}

char *convert(char *infix)
{
    char *postfix = new char[strlen(infix) + 1];

    stack<char> stk;

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (stk.empty() || outPrecedence(infix[i]) > inPrecedence(stk.top()))
            {
                stk.push(infix[i++]);
            }
            else if (outPrecedence(infix[i]) == inPrecedence(stk.top()))
            {
                stk.pop();
            }
            else
            {
                postfix[j++] = stk.top();
                stk.pop();
            }
        }
    }

    while (!stk.empty() && stk.top() != ')')
    {
        postfix[j++] = stk.top();
        stk.pop();
    }

    postfix[j] = '\0';

    return postfix;
}
int calculate(char c, int op1, int op2)
{
    switch (c)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '%':
        return op1 % op2;
    case '^':
        return op1 ^ op2;
    default:
        return -1;
    }
}

int evaluation(char *postfix)
{
    stack<int> stac;
    int res;
    int op1 = 0, op2 = 0;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            stac.push((postfix[i] - '0'));
        }
        else
        {
            op2 = stac.top();
            stac.pop();
            op1 = stac.top();
            stac.pop();

            res = calculate(postfix[i], op1, op2);
            stac.push(res);
        }
    }
    res = stac.top();
    stac.pop();
    return res;
}

int main()
{

    // char infix[] = "((a+b)*c)-d^e^f";
    char s[] = "3*5+6/2-4";
    cout << convert(s) << endl;
    cout << evaluation(convert(s));
}