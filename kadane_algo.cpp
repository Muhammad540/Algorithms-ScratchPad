/* find the maximum subarray given an array of integers 
    nums = [2,-3,4,-2,2,1,-1,4]
    by subarray we mean a contiguous part of the array
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class BruteForce {
    public:
        int maxSubArray(vector<int>& nums) {
            // arbitrarily set the first element as the max sum
            int max_sum = nums[0];
            int current_sum = 0;

            for (int i=0; i<nums.size();i++){
                current_sum = 0;
                for (int j=i; j<nums.size();j++){
                    current_sum += nums[j];
                    max_sum = max(max_sum, current_sum);
                }
            }            
            return max_sum;
        }
};

class KadaneAlgo {
    public:
        int maxSubArray(vector<int>& nums) {
            int max_sum = nums[0];
            int current_sum = 0;

            for (int i=0; i<nums.size();i++){
                if (current_sum < 0){
                    current_sum = 0;
                }
                current_sum += nums[i];
                max_sum = max(max_sum, current_sum);
            }
            return max_sum;
        }
};


int main(void) {
    // brute force
    vector<int> nums = {2,-3,4,-2,2,1,-1,4};
    BruteForce brute_force;
    cout << brute_force.maxSubArray(nums) << endl;

    KadaneAlgo kd_algo;
    cout << kd_algo.maxSubArray(nums) << endl;
    return 0;
}
