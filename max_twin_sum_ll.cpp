/* ll of size n, where n is even. It is zero indexed 
 * ll[i] = ll[n-1-i] where  0 <= i <= (n/2)-1
 *  so if n = 4, 
 * ll[0] = ll[4-1-0] = ll[3]
 * ll[1] = ll[4-1-1] = ll[2]
 * ll[2] = ll[4-1-2] = ll[1]
 * ll[3] = ll[4-1-3] = ll[0]
 * 0 1 2 3 
 * 3 2 1 0
 *
 * twin sum ? sum of a node and its twin
 *            *
 *   [5,4,2,1]
 *   reverse the second half 
 *   [5,4,
 *    1,2]
 * S:   *
 * F:       *
 * R: * 
 * After F reachedd last and S reached mid - 1
 * curr_sum = 5
 * max_sum  = 0
 */
#include <iostream> 

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class FastSlowptr {
public:
    int pairSum(ListNode* head) {
      // step1: find the middle using fast/slow pointers
      ListNode *slowptr = head;
      ListNode *fastptr = head;

      int curr_twin_sum {};
      int max_twin_sum {-1000};
      // get the fast and slow ptrs in the right position
      while (fastptr != nullptr && fastptr->next != nullptr){
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
      }
      // now the slowptr points to the start of the second half
      //  5 4 2 1 
        
      // step2: reverse the second half of the ll
      ListNode *prev = nullptr;
      ListNode *curr = slowptr;
      ListNode *next = nullptr; 

      while (curr != nullptr){
        // store the next 
        next = curr->next;

        // reverse the current nodes pointer 
        curr->next = prev;
        // move pointer one position ahead
        prev = curr; 
        curr = next;
      }
      // prev has the head of the reverse linked list 

      // compute the twin sums and find the maximum
      ListNode *firsthalf  = head;
      ListNode *secondhalf = prev; 

      while (secondhalf != nullptr){
        curr_twin_sum = firsthalf->val + secondhalf->val;
        max_twin_sum  = max(max_twin_sum, curr_twin_sum);
        firsthalf     = firsthalf->next;
        secondhalf    = secondhalf->next;
      }

      return max_twin_sum;
    }
};

int main(void){
  ListNode node1(5);
  ListNode node2(4);
  ListNode node3(2);
  ListNode node4(1);
  
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
 
  FastSlowptr test;
  int res = test.pairSum(&node1);
  std::cout << res << std::endl;
};
