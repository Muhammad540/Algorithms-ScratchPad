/* two pointer approach */ 
#include <iostream>
#include <string> 
#include <vector> 
/*    1 2 3 4
 *    L   R
 *    1+4 = 5 > 3 ?
 *    1+3 = 4 > 3 ? 
 *    1 2 3 4 
 *    L R
 *    1+2 = 3 > 3 ? 3<3 ? 3=3 
 *
 */
using namespace std;

class TwoInteger {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      vector<int> result {};
      int left_pointer = 0;
      int right_pointer = numbers.size() - 1;
      while (left_pointer < right_pointer){
        // check if the value @ pos of lp + value @ pos of rp > target, if so dec rp
        if (numbers[left_pointer]+numbers[right_pointer] > target){
          right_pointer--;
        }
        // check if the value @ pos of lp + value @ pos of rp < target, if so inc rp
        else if (numbers[left_pointer]+numbers[right_pointer] < target){
          left_pointer++;
        }
        else {
          result.push_back(left_pointer+1);
          result.push_back(right_pointer+1);
          return result;
        }
      }
    }
};

int main(void){
  TwoInteger ti;
  vector<int> numbers{1,2,3,4};
  int target = 3;

  vector<int> vec = ti.twoSum(numbers, target);
  
  for (int i=0; i<2; i++){
    std::cout << vec[i] << std::endl;
  }

  return 0;
}

