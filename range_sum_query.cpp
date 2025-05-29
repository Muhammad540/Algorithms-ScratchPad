/* prefix sum 
 * -2, 0, 3, -5, 2, -1
 *  L     R
 */ 
#include <iostream>
#include <vector> 

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int total = 0;
        for (int num: nums){
          total+=num;
          prefix_.push_back(total);
        }
    }
    
    int sumRange(int left, int right) {
      int preRight = prefix_[right];
      int preLeft  = left > 0 ? prefix_[left - 1] : 0;
      return preRight - preLeft;
    }
private:
    vector<int> prefix_;
};

int main(void){
  vector<int> nums {-2, 0, 3, -5, 2, -1};
  NumArray* obj = new NumArray(nums);
  int param_1 = obj->sumRange(0,2);
  std::cout << param_1 << std::endl;
  delete obj;
  return 0;
} 

