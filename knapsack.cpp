/*
Knapsack (0/1) binary decision add or not add the item in the bag
Top Down: Recusrive solution
Bottom Up: DP solution
*/
#include <iostream>
#include <vector>

using namespace std;

class KnapSack {
    public:
        int computeSum(vector<int>& nums){
            int sum = 0;
            for(const auto& n: nums){
                sum+=n;
            }
            return sum;
        }

        bool canPartition(vector<int>& nums) {
            int N = nums.size();
            int totalSum = computeSum(nums);
            
            // if total sum if odd we cant create two equal subsets 
            if (totalSum % 2 ==1){
                return false;
            }
            int target = totalSum / 2;
            vector<bool> dp(target+1,false);

            // base case: we can always achieve 0 sum be skipped the current val
            dp[0] = true;
            
            // filling the first row 
            if(nums[0]<=target){
                dp[nums[0]] = true;
            }
            
            for (int i=1; i<N; i++){
                vector<bool> currRow(target+1, 0);

                for (int sum=0; sum<=target; sum++){
                    bool skip = dp[sum];
                    bool include = false;
                    if (sum >= nums[i]){
                        // if in the previous row after subtracting the current nums, were we able to reach sum ? 
                        include = dp[sum-nums[i]];
                    }
                    currRow[sum] = skip || include;
                }
                dp = currRow;
            }
            return dp[target];
        }
};

int main(){
    vector<int> nums {1,2,3,4,5};
    KnapSack ks;
    std::cout << (ks.canPartition(nums) ? "true" : "false") << std::endl;
    return 0;
}
    