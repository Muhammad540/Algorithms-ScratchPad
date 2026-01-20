/*
 * in single number 1 my learnings were that if we have two numbers that are identical
 * like 2 and 2, their binary is also same ofcourse, when you do xor it just results in 0
 * Xor:
 * o o - 0
 * o 1 - 1
 * 1 o - 1
 * 1 1 - 0
 *
 * so we took xor of the entire nums 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      vector<int> result;
      int xor_out_all = 0;
      // get the different bits
      for (const auto& num: nums){
        xor_out_all ^= num;
      }
      int diff_bit = 1;
      while (!(xor_out_all & diff_bit)){
        diff_bit = diff_bit << 1;
      }
      // found the diff bit now segregate based on that
      int a = 0;
      int b = 0;
      for (const auto& num: nums){
        if (diff_bit & num){
          a ^= num;
        } else {
          b ^= num;
        }
      }

      result.push_back(a);
      result.push_back(b);
      return result;
    }
};

// time complexity: linear complexity
/* nums   = [1,1,2,3,2,4]
 * output = [3,4] 
              
         8 4 2 1

      1: 0 0 0 1
      1: 0 0 0 1
      2: 0 0 1 0
      2: 0 0 1 0
      3: 0 0 1 1
      4: 0 1 0 0  
 */
int main(){
  std::vector<int> nums = {1,1,2,3,2,4};
  Solution s;
  auto result = s.singleNumber(nums);
  for (auto const& v: result){
    std::cout << v << " ";
  }
  std::cout << std::endl;
  return 0;
}
