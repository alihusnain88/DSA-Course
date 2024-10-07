#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;
class VariableNode
{
private:
    string variable;
    int value;
    VariableNode *next;

public:
    //  VariableNode(string s, int v): variable(s), value(v), next(nullptr) { }
    VariableNode(string s, int v, VariableNode *n = nullptr) : variable(s), value(v), next(n) {}

    friend VariableNode *insertNode(VariableNode *head, string str, int val);
    friend bool isPresent(VariableNode *head, string str);
    friend void printAllVariables(VariableNode *head);
    friend int findValue(VariableNode *head, string str);
};

string infixToPostfix(string expression);
VariableNode *extractVariables(string expression);
double evaluatePostfix(VariableNode *head, string postfix);

// Sub Functions
bool isDigit(char c);
bool isOperator(char c);
int precedence(char c);
bool isAlphabet(char c);
VariableNode *insertNode(VariableNode *head, string str, int val);
bool isPresent(VariableNode *head, string str);
void printAllVariables(VariableNode *head);
int findValue(VariableNode *head, string str);

// -------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------
int main()
{

    int choice = 1;
    string expression;

    while (choice != 2)
    {
        cout << "\nMenu:\n";
        cout << "1. Evaluate Expression\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\nEnter an infix expression: ";
            cin.ignore();
            getline(cin, expression);

            VariableNode *head = extractVariables(expression);
            string postfix = infixToPostfix(expression);

            cout << "\nInfix Expression: \t" << expression << endl;
            cout << "Postfix Expression:\t" << postfix << endl;

            if (head != nullptr)
            {
                cout << "\nVariables:\n";
                printAllVariables(head);
            }

            double answer = evaluatePostfix(head, postfix);
            cout << "\nAnswer: \t\t" << fixed << setprecision(4) << answer << endl;
            break;
        }
        case 2:
            cout << "    Exiting....     ";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }
    }

    return 0;
}
// -------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------
string infixToPostfix(string expression)
{
    stack<char> s;
    string postfix;
    string temp;

    for (int ch = 0; ch < expression.length(); ch++)
    {
        if (isDigit(expression[ch]))
        {
            while (isDigit(expression[ch]))
            {
                postfix += expression[ch];
                ch++;
            }
            ch--;
            postfix += ' ';
        }
        else if (isOperator(expression[ch]))
        {
            while (!s.empty() && precedence(s.top()) >= precedence(expression[ch]))
            {
                postfix += s.top();
                postfix += ' ';
                s.pop(); 
            }
            s.push(expression[ch]);
        }
        else if (isAlphabet(expression[ch]))
        {
            while (isAlphabet(expression[ch]))
            {
                postfix += expression[ch];
                ch++;
            }
            ch--;
            postfix += ' ';
        }
        else if (expression[ch] == '(')
        {
            s.push(expression[ch]);
        }
        else if (expression[ch] == ')')
        {
            while (s.top() != '(')
            {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.pop();
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }
    return postfix;
}
VariableNode *extractVariables(string expression)
{
    string temp;
    VariableNode *head = nullptr;
    for (int i = 0; i < expression.length(); i++)
    {
        temp = "";
        if (isAlphabet(expression[i]))
        {
            while (isAlphabet(expression[i]))
            {
                temp += expression[i];
                i++;
            }

            if (!isPresent(head, temp))
            {
                cout << "Enter value of variable \"" << temp << "\" : ";
                int val;
                cin >> val;
                head = insertNode(head, temp, val);
            }
        }
    }
    return head;
}
double evaluatePostfix(VariableNode *head, string postfix)
{
    stack<double> s;
    double operand1, operand2;
    string temp;

    for (int i = 0; i < postfix.length(); i++)
    {
        if (isDigit(postfix[i]))
        {
            string digit = "";
            while (isDigit(postfix[i]))
            {
                digit += postfix[i];
                i++;
            }
            s.push(double(stoi(digit)));
        }
        else if (isOperator(postfix[i]))
        {
            operand2 = s.top();
            s.pop();
            operand1 = s.top();
            s.pop();

            if (postfix[i] == '*')
            {
                s.push(operand1 * operand2);
            }
            else if (postfix[i] == '/')
            {
                s.push(operand1 / operand2);
                // Check for division by 0 remaining
            }
            else if (postfix[i] == '+')
            {
                s.push(operand1 + operand2);
            }
            else if (postfix[i] == '-')
            {
                s.push(operand1 - operand2);
            }
        }
        else if (isAlphabet(postfix[i]))
        {
            while (isAlphabet(postfix[i]))
            {
                temp += postfix[i];
                i++;
            }
            s.push(findValue(head, temp));
            temp = "";
        }
    }
    return s.top();
}
void printAllVariables(VariableNode *head)
{
    if (head == nullptr)
    {
        cout << "\n*** No variables provided! ***\n";
        return;
    }
    VariableNode *temp = head;
    while (temp != nullptr)
    {
        cout << "(" << temp->variable << ", " << temp->value << ") \n";
        // cout <<setw(20) <<temp->variable <<" "<<temp->value <<endl;
        temp = temp->next;
    }
}

// Sub-Functions
bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int precedence(char c)
{
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1;
}
bool isAlphabet(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
VariableNode *insertNode(VariableNode *head, string str, int val)
{
    if (head == nullptr)
    {
        head = new VariableNode(str, val);
    }
    else
    {
        VariableNode *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new VariableNode(str, val);
    }
    return head;
}
int findValue(VariableNode *head, string str)
{
    VariableNode *temp = head;
    while (temp)
    {
        if (temp->variable == str)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}
bool isPresent(VariableNode *head, string str)
{
    VariableNode *temp = head;
    while (temp != nullptr)
    {
        if (temp->variable == str)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}