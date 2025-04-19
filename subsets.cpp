// computing all possible subsets of a given sequence 
// e.g for [1,2,3] -> [] [1] [2] [3] [1,2] [1,3] [2,3] [1,2,3]
// will be using backtracking using dfs 
#include <iostream> 
#include <vector> 

using namespace std;

void dfs(int idx,
         const vector<int> &nums,
         vector<int> &subset,
         vector<vector<int>> &results){
    if (idx == nums.size()){
        results.push_back(subset);
        return;
    }

    // include the current val
    subset.push_back(nums[idx]);
    // explore the path if the current value is included 
    dfs(idx+1, nums, subset, results);

    // exclude the included value and explore that path
    subset.pop_back();
    dfs(idx+1, nums, subset, results);
}

vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> results;
    vector<int> subset;

    dfs(0, nums, subset, results);
    return results;
}


int main(){
    vector<int> a {1,2,3};
    auto result = subsets(a);

    for (const auto& s : result) {
        cout << "[";
        for (size_t i = 0; i < s.size(); ++i) {
            cout << s[i];
            if (i + 1 < s.size()) cout << ",";
        }
        cout << "]\n";
    }
    return 0;
}