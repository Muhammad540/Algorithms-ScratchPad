#include <string>
#include <iostream>
#include <vector>

using namespace std;

// solution 1: time: On2 space: On (14.1 Mb with 7ms)
// class Solution{
//     public:
//         vector<int> smallerNumbersThanCurrent(vector<int>& nums){
//             vector<int> counts((int)nums.size(), 0);
//             int pos = 0;
//             for (auto val: nums){
//                 for (int i=0; i < nums.size(); i++){
//                     if (val != nums[i]){
//                         if (nums[i] < val){
//                             counts[pos] += 1;
//                         }
//                     }
//                 }
//                 pos++;
//             }
//             return counts;
//         }
// };

// Solution 2: o(n) 0ms
class Solution{
    public:
        vector<int> smallerNumbersThanCurrent(vector<int>& nums){
            vector<int> running_sum(101, 0);
            vector<int> result((int)nums.size(), 0);
            // counting the occurence
            for (int i=0; i < nums.size(); i++){
                running_sum[nums[i]] += 1;
            }

            // compute the running sum (prefix sum) this will give us number of elements less than the current element
            for (int i=1; i <= 100; i++){
                running_sum[i] += running_sum[i-1];
            }

            for (int i=0; i < nums.size(); i++){
                if (nums[i] == 0){
                    result[i] = 0;
                } else {
                    result[i] = running_sum[nums[i]-1];
                }
            }

            return result;
        }
};

int main() {
    /*
    nums: 6 5 4 8
    bucket:  0 0 0 1 1 1 0 1
    running: 0 0 0 1 2 3 3 4  
    
    res: 
    */
    vector<int> nums = {6,5,4,8};
    Solution s;
    auto result = s.smallerNumbersThanCurrent(nums);
    for (auto v: result){
        std::cout << v << " ";
    }
    std::cout << std::endl;
    return 0;
}