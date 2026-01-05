/*
Notes:
number of consecutive ways to pick an item: n - k + 1
*/
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
            int max_satisfied_count = -1000;
            int len = grumpy.size();
            int num_picks = len - minutes + 1;
            std::vector<int> non_grumpy_ids(minutes,0);

            for (int i = 0; i < num_picks; i++){
                int temp_sum_1 = 0;
                int temp_sum_2 = 0;
                for (int x=0; x<minutes;x++){
                    non_grumpy_ids[x] = i+x;
                    temp_sum_1 += customers[i+x];
                }
                for (int j = 0; j < len; j++) {
                    bool accounted = (std::find(non_grumpy_ids.begin(), non_grumpy_ids.end(), j) != non_grumpy_ids.end());
                    if (accounted || grumpy[j]) {
                        continue;
                    } else {
                        temp_sum_2 += customers[j];
                    }
                }
                if ((temp_sum_1 + temp_sum_2) > max_satisfied_count){
                    max_satisfied_count = temp_sum_1 + temp_sum_2;
                }
            }
            return max_satisfied_count;
        }
};

//  customers = [1,0,1,2,1,1,7,5], minutes = 3
//  grumpy    = [0,1,0,1,0,1,0,1]
//                 0,0,0
// 4 + 7 
// 1+1+ 1+1+7+5  = 16

// customers = [10,1,7], minutes = 2
// grumpy    = [0,0,0]
// 10+1+7 = 18
int main(){
    Solution s;
    // TEST 1
    std::vector<int> customers0 = {1,0,1,2,1,1,7,5};
    std::vector<int> grumpy0 = {0,1,0,1,0,1,0,1};
    int minutes0 = 3;
    int max_satisfied_customers0 = s.maxSatisfied(customers0, grumpy0, minutes0);
    assert(max_satisfied_customers0 == 16);
    // TEST 2
    std::vector<int> customers1 = {10,1,7};
    std::vector<int> grumpy1 = {0,0,0};
    int minutes1 = 2;
    int max_satisfied_customers1 = s.maxSatisfied(customers1, grumpy1, minutes1);
    assert(max_satisfied_customers1 == 18);
    return 0;
}