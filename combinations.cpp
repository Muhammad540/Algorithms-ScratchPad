#include <iostream> 
#include <vector>

using namespace std;

class findcombination {
    public:
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> combinations{};
            vector<int> currentCombination{};
            int start = 1;
            generateCombinations(n, k, start, currentCombination, combinations);
            return combinations;
        }
        void generateCombinations(int n, int k, int index, vector<int> &currentCombination, vector<vector<int>> &combinations){
            // base case
            if (currentCombination.size() == k){
                combinations.emplace_back(currentCombination);
                return;
            }

            if (index > n){
                return;
            }

            // We could either go the subset route (O(k*2^n)) or a more efficient route that is O(k*(n!/((n-k)!*k!)))
            for (int i = index; i<=n; i++){
                currentCombination.push_back(i);
                generateCombinations(n, k, i+1, currentCombination, combinations);
                currentCombination.pop_back();
            }
        }
};

void print(const vector<vector<int>> &result){
    for(auto &row: result){
        for(auto &col: row){
            cout << col << " ";
        }
        cout << endl;
    }
}
int main(){
    findcombination fc;
    int n = 3;
    int k = 2;
    vector<vector<int>> result = fc.combine(n, k);
    print(result);
    n = 3;
    k = 3;
    result = fc.combine(n, k);
    print(result);
    return 0;
}