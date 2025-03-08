// i will implement a browser history using a doubly linked list 
// you can visit a url, go back, and go forward 

#include <iostream>
#include <string>

using namespace std;

class BrowserHistory {
    public: 
        BrowserHistory(string homepage) {
            head = new ListNode(homepage, nullptr, nullptr);
            tail = head;
            currentIndex = 0;
            size = 1;
        }

        void visit(string url) {
            ListNode* newNode = new ListNode(url, nullptr, tail);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;

            currentIndex++;
            // why size = current index + 1 and not size ++? e.g start with [google] size = 1, currIdx=0
            // [google] -> [youtube] size = 2 , currIdx=1
            // [google] -> [youtube] -> [X] size =3, currIdx=2
            // back track two steps so at google again and visit github
            // [googl] -> [github] size = 4 currIdx = 1 HERE is the error it should be 2 but we get 4 !
            size = currentIndex + 1;
        }

        string back(int steps) {
            if (currentIndex - steps < 0){
                steps = currentIndex;
            }
            if (tail->prev != nullptr){
                for(int i=0; i<steps; i++){
                        tail = tail->prev;
                        currentIndex--;
                }
            }
            return tail->url;
        }

        string forward(int steps) {
            if (currentIndex + steps >= size){
                steps = size - currentIndex;
            }
            if (tail->next != nullptr){
                for (int i = 0; i < steps; i++){
                    tail = tail->next;
                    currentIndex++;
                    if (tail->next == nullptr) {  
                        break;  
                    }
                }
            }
            return tail->url;
        }

    private:
        struct ListNode {
            string url;
            ListNode* next;
            ListNode* prev;
            ListNode(string url, ListNode* next, ListNode* prev) : url(url), next(next), prev(prev) {}
        };
        int size;
        int currentIndex;
        ListNode* head;
        ListNode* tail;
};

int main(){
    BrowserHistory browser("leetcode.com");
    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");
    cout << browser.back(1) << endl;
    cout << browser.back(1) << endl;
    cout << browser.forward(1) << endl;
    browser.visit("linkedin.com");
    cout << browser.forward(2) << endl;
    cout << browser.back(2) << endl;
    cout << browser.back(7) << endl;
    return 0;
}