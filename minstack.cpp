// a minstack impl 
// the only goal is that every operation should be O(1) time complexity
// so following features will be added 
// 1. push: pushes elem val onto the stack
// 2. pop: removes elem from the top of stack
// 3. top: get the top elem of stack
// 4. getMin: gets you the min elem in the stack in O(1) time

// something that we consciously not design:
// 1. we dont handle the case when the ops like pop,top,getMin are called on non-empty stack
// 2. we handle only int type of stack

#include <vector>
#include <iostream>

using namespace std;

class MinStack{
    public:
        MinStack(){}

        void push(int val){
            stack.push_back(val);
            if(minstack.empty() || val <= minstack.back()){
                minstack.push_back(val);
            }
        }

        void pop(){
            if(stack.back() == minstack.back()){
                minstack.pop_back();
            }
            stack.pop_back();
        }

        int top(){
            // read: https://en.cppreference.com/w/cpp/container/vector/back
            return stack.back();
        }

        int getMin(){
            return minstack.back();
        }

    private:
        // main stack
        vector<int> stack;
        // this stack just keeps track of the min elem at any point in the main stack
        vector<int> minstack;
        

};   


int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
}