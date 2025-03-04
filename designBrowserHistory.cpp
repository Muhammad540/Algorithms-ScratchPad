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
            ListNode* current = tail->next;
            while (current != nullptr){
                ListNode* temp = current;
                current = current->next;
                delete temp;
            }
            tail->next = nullptr;

            ListNode* newNode = new ListNode(url, nullptr, tail);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;

            currentIndex++;
            // why not size ++ ?  cuz in the clean up the forward history when we visit a new url
            // this means the size is now not the total number of urls we have visited
            // it is the number of urls we have visited since the current url + 1 (for the current url)
            size = currentIndex + 1;
        }

        string back(int steps) {
            if (currentIndex - steps < 0){
                steps = currentIndex;
            }
            ListNode* temp = tail;
            while (temp->prev != nullptr && steps > 0){
                temp = temp->prev;
                currentIndex--;
                steps--;
            }
            tail = temp;
            return temp->url;
        }

        string forward(int steps) {
            if (currentIndex + steps >= size){
                steps = size - currentIndex - 1;
            }
            ListNode* temp = tail;
            while (temp->next != nullptr && steps > 0){
                temp = temp->next;
                currentIndex++;
                steps--;
            }
            tail = temp;
            return temp->url;
        }
        ~BrowserHistory(){
            ListNode* current = head;
            while ( current != nullptr){
                ListNode* temp = current;
                current = current->next;
                delete temp;
            }
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