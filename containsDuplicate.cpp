// check duplicates in an array and flag if any 
// i'll use a hashmap
// it wil O(n) time since O(1) search for each element in the array 
// also O(n) space for hashmap storage 
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class heap{
    public:
        unordered_map<int,int> countMap;

        heap(vector<int> &nums){
            for (int num: nums){
                if(countMap.count(num) == 0){
                    countMap[num] = 1;
                } else {
                    countMap[num] += 1;
                }
            }
        }

        bool hasDuplicate(vector<int> &nums){
            for (int num: nums){
                if(countMap[num] > 1){
                    return true;
                }
            }
            return false;
        }
};



int main(void){
    vector<int> test1 = {1,2,3,3};
    vector<int> test2 = {1,2,3,4};
    
    heap Test1(test1);
    std::cout << Test1.hasDuplicate(test1) << std::endl;
    
    heap Test2(test2);
    std::cout << Test2.hasDuplicate(test2) << std::endl;

    return 0;
}