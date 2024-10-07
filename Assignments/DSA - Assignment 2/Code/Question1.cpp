#include <iostream>
#include <stack>
using namespace std;
class String
{
private:
 string raw_string;
public: 
 String(string s = "") : raw_string(s) { }

 const string removeConsecutiveDuplicates()
 {
    if(raw_string == "")
    {
        return "";
    }
    string duplicates_removed;
    stack <char> char_stack;
    for(char ch:raw_string)
    {
        if(char_stack.empty() || (ch != char_stack.top() && abs(ch - char_stack.top()) != 32)) 
        {
            char_stack.push(ch);
        }
    }
    char c;
    while(!char_stack.empty())
    {
        c = char_stack.top();
        duplicates_removed = c + duplicates_removed;
        char_stack.pop();
    }
    return duplicates_removed;
 }
 const string getString()
 {
    return raw_string;
 }
};

int main(){
    
    cout <<"\n********************************\n";
    cout <<"\nRemoving Consecutive Duplicates\n";
    cout <<"\n********************************\n";

    cout <<"\nEnter your string to remove consecutive duplicates:\n";
    string input_string;
    getline(cin, input_string);

    while(input_string == "") 
    {
        cout <<"Empty string! You entered nothing...\n";
        cout <<"Enter string again: \n";
        getline(cin, input_string);
    }

    String s(input_string);

    cout <<"\nOriginal String:\n";
    cout <<s.getString() <<endl;

    string resultant = s.removeConsecutiveDuplicates();

    cout <<"\nResultant String:\n";    
    cout <<resultant <<endl;    

    return 0;
}
