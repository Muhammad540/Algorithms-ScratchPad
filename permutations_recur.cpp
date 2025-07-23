/* Recursive impl 
order matters, for each perm we use all elems of the input 
*/
/*
1 2 3 4 5 

1. 12345 . . . . = 24*5
2- 2345  . . . . = 24
3- 345 . . . . . = 6
4- 45 54         = 2
5- 5             = 1
*/
#include <iostream> 
#include <vector>

using namespace std;

class GetAllPerm {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> permutations;
            return helper(0, nums);
        }

        vector<vector<int>> helper(int val, vector<int>& nums){
            // base case: continue until last 
            if (val == nums.size()) {
                return {{}};
            }

            vector<vector<int>> result_permutations;
            vector<vector<int>> sub_permutations = helper(val + 1, nums);

            for (vector<int> sub_permutation : sub_permutations) {
                for (int j=0; j<=sub_permutation.size(); j++) {
                    vector<int> new_permutation{sub_permutation};
                    new_permutation.insert(new_permutation.begin() + j, nums[val]);
                    result_permutations.push_back(new_permutation);
                }
            }
            return result_permutations;
        }
};

void print_vector(vector<vector<int>> vec){
    for (vector<int> v : vec) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main(){
    std::vector<int> nums {1,2,3};
    GetAllPerm gam;
    auto result = gam.permute(nums);
    cout << "result: " << endl;
    print_vector(result);
    return 0;
}