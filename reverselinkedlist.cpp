// our goal is to reverse the ll, and return the new beginning of the list 
// aim o(n) time and o(1) space

// sll comprises of nodes called ListNode object
class ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class reverselinkedlist{
    public:
        ListNode* reverseList(ListNode* head){
            // beginning becomes the end, and end becomes the beginning
            ListNode* prev = nullptr;
            ListNode* curr = head;
            while(curr != nullptr){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;    
            }
            return prev;
        }
};
