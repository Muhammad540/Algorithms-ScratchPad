/* 
Input: target = 10, nums = [2,1,5,1,5,3]
Output: 3

get the minimum size of a sub array whose sum is greater than or equal to target
if no such sub array return 0
*/

#include <iostream> 
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class slidingWindow {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int length = INT_MAX;
            int left_pointer = 0;
            int sum = 0;
            /*
                    L
                2 1 5 1 5 3
                        R       
            */
            for (int rpointer = 0;rpointer < nums.size(); rpointer++){
                sum += nums[rpointer];
                while (sum >= target){
                    length = min(rpointer-left_pointer+1,length);
                    sum -= nums[left_pointer];
                    left_pointer ++;
                }
            }
            if (length == INT_MAX) return 0;
            return length;
        }
};


int main(void){
    vector<int> nums = {2,1,5,1,5,3};
    int target = 10;
    vector<int> nums2 = {1,2,1};
    int target2 = 5;
    slidingWindow sw;
    cout << sw.minSubArrayLen(target, nums) << endl;
    cout << sw.minSubArrayLen(target2, nums2) << endl;
    return 0;
}