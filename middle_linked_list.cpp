// use fast and slow pointers approch to get the middle of a linked list 
// we know the position of the head of the linked list but get the middle 
// trivial way is to get just traverse the entire ll to get the size and than half that would be the middle position
// if cuz of even num of nodes
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class FastandSlow {
public:
    ListNode* middleNode(ListNode* head) {
      ListNode *fastptr = head; 
      ListNode *slowptr = head; 
      while (fastptr != nullptr && fastptr->next != nullptr){
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
      }
      return slowptr;
    }
};

int main(void){
  ListNode node1(1);
  ListNode node2(2);
  ListNode node3(3);
  ListNode node4(4);
  ListNode node5(5);

  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = &node5;

  FastandSlow test;
  ListNode *result = test.middleNode(&node1);
  std::cout << result->val << std::endl;

  return 0;
}
