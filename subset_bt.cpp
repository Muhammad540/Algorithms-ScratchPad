/** get all distinct subsets of a given list with unique elms */
#include <iostream>
#include <vector>

using namespace std;

class GetSubsets{
    public:
        vector<vector<int>> subsets(vector<int> &nums){
            vector<vector<int>> subsets{};
            vector<int> curset{};
            int idx = 0;
            helper(idx,nums,curset,subsets);
            return subsets;
        }

    private:
        // helper to get subsets from list wihtout any duplicates O(n^2^n) Time, O(n) space 
        void helper(int idx,vector<int>& input_list, vector<int> &curset, vector<vector<int>>& subsets){
            if (idx >= input_list.size()){
                // base case: if idx == size of input list, we cant go any furthur store the curset into subsets 
                subsets.push_back(curset);
                return;
            }

            // push the val @ cur idx into the curset 
            curset.push_back(input_list[idx]);
            helper(idx+1, input_list, curset, subsets);
            // backtrack to get the sets without the value that was last added to subsets 
            curset.pop_back();

            helper(idx+1, input_list,curset,subsets);
        }
};

int main(int argc, char** argv){
    std::vector<int> nums = {1, 2, 3};
    GetSubsets gsb; 
    vector<vector<int>> result = gsb.subsets(nums);
    for (int i = 0; i < result.size(); i++){
        std::cout << "[ ";
        for (int j = 0 ; j<result[i].size(); j++){
            std::cout << result[i][j];
        }
        std::cout << " ]";
    }
    std::cout << std::endl;
    return 0;
}



