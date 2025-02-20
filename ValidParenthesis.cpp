#include <stack>
#include <iostream>
using namespace std;
bool isValid(string s){
    stack<char> stack;
    for (char c : s){
        if (c == '(' || c == '{' || c == '['){
            stack.push(c);
        } else {
            if (stack.empty()) return false;
            if (c == ')' && stack.top() != '(') return false;
            if (c == '}' && stack.top() != '{') return false;
            if (c == ']' && stack.top() != '[') return false;
            stack.pop();
        }
    }
    return stack.empty();
}

int main(){
    string s = "()";
    bool result = isValid(s);
    cout << result << endl;
    string s2 = "()[]{}";
    bool result2 = isValid(s2);
    cout << result2 << endl;
    string s3 = "(]";
    bool result3 = isValid(s3);
    cout << result3 << endl;
    
    return 0;
}