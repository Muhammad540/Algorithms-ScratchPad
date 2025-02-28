// we have two sorted ll, we need to merge them into one sorted ll
// aim o(n+m) time and o(1) space
#include <iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}   
};

class MergeLinkedList{
    public:
        ListNode* mergetwolists(ListNode* list1, ListNode* list2){
            // dummt node is used as an anchor to the merge list
            ListNode dummy;
            ListNode* tail = &dummy;

            while(list1 && list2){
                if(list1->val < list2->val){
                    tail->next = list1;
                    list1 = list1->next;                    
                } else{
                    tail->next = list2;
                    list2 = list2->next;
                }
                tail = tail->next;
            }

            // if any of the list is not null, we need to attach the remaining list to the tail
            if(list1) tail->next = list1;
            if(list2) tail->next = list2;

            return dummy.next;
        }
        
        void printlist(ListNode* head){
            while(head){
                cout << head->val << " ";
                head = head->next;
            }
        }
 
};

int main(){
    MergeLinkedList ml;
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* mergedList = ml.mergetwolists(list1, list2);
    ml.printlist(mergedList);
    
    ListNode* current = mergedList;
    while(current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}