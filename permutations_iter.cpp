#include <vector>
#include <iostream> 
#include <algorithm>
using namespace std;

class GetAllUniquePerm {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) { // {1,1,3}
            vector<vector<int>> permutations {{}};

            for (int num: nums){
                vector<vector<int>> current;
                for (vector<int> permutation: permutations){
                    for (int i=0; i<=permutation.size(); i++){
                        vector<int> new_permutation{permutation};
                        new_permutation.insert(new_permutation.begin() + i, num);
                        auto it = find(current.begin(), current.end(), new_permutation);
                        if (it == current.end()){
                            current.push_back(new_permutation);
                        }
                    }
                }
                permutations = current;
            }
            return permutations;
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
    std::vector<int> nums {1,1,3};
    GetAllUniquePerm gau;
    auto result = gau.permuteUnique(nums);
    cout << "result: " << endl;
    print_vector(result);
    return 0;
}