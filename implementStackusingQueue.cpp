#include <queue>
#include <iostream>
using namespace std;

class Stack{
    public:
        Stack(){}
        void push(int x) {
            q.push(x);
            for (int i=0; i<q.size()-1;i++){
                q.push(q.front());
                q.pop();
            }
        }
        int top() {
            return q.front();
        }
        int pop() {
            int val = q.front();
            q.pop();
            return val;
        }
        std::string empty() {
            std::string val = q.empty() ? "true": "false";
            return val;
        }
    
    private:
        std::queue<int> q;
};

int main(){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.top() << endl;
    cout << stack.pop() << endl;
    cout << stack.empty() << endl;
    stack.push(4);
    cout << stack.top() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.empty() << endl;
    return 0;
}