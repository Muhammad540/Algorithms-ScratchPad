/* given an array of integers, return true if there are two distinct indices i and j in the array such that arr[i] == arr[j] and abs(i-j) <= k 
    e.g 
    > nums = [1,2,3,1], k = 3
              i j 
      output: true
    i'll use a brute force sliding window approach and a hashset to check for duplicates
*/
#include <iostream> 
#include <vector> 
#include <unordered_set>
#include <cmath>

using namespace std; 

class BruteForceApproach{
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            int n = nums.size();
            for (int i = 0; i < n; i++){
                for (int j = i+1 ; j < n && abs(i-j) <= k; j++){
                    if (nums[i] == nums[j]){
                        return true;
                    }
                }
            }
            return false;
        }
};
/*
    L   R
    1 2 3 1 2 3
    size = 6, k = 2
    store 1,2,3 in the hashset {1,2,3}
    Lpointer = 0, Rpointer = k

    while (Rpointer < nums.size()) 
        increment Rpointer
        if nums[Rpointer] is in the hashset, return true
        else add nums[Rpointer] to the hashset
        increment Lpointer 
        remove nums[Lpointer] from the hashset
*/
class HashSetApproach{
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            int size = nums.size();
            unordered_set<int> window;
            int Lpointer = 0;
            int Rpointer = 0;
            while (Rpointer < size){
                if (window.count(nums[Rpointer])){
                    return true;
                }
                window.insert(nums[Rpointer]);
                Rpointer++;
                if (Rpointer - Lpointer > k){
                    window.erase(nums[Lpointer]);
                    Lpointer++;
                }
            }
            return false;
        }
};

int main(void){
    vector<int> nums  = {1,2,3,1};
    vector<int> nums2 = {2,1,2};
    vector<int> nums3 = {1,2,3,1,2,3};
    vector<int> nums4 = {99,99};
    vector<int> nums5 = {1,2,1};
    int k = 2;
    BruteForceApproach bfa;
    std::cout << "Brute Force Approach" << std::endl;
    cout << bfa.containsNearbyDuplicate(nums, k) << endl;
    cout << bfa.containsNearbyDuplicate(nums2, k) << endl;
    cout << bfa.containsNearbyDuplicate(nums3, k) << endl;
    cout << bfa.containsNearbyDuplicate(nums4, k) << endl;
    cout << bfa.containsNearbyDuplicate(nums5, k) << endl;
    HashSetApproach hsa;
    std::cout << "HashSet Approach" << std::endl;
    cout << hsa.containsNearbyDuplicate(nums, k) << endl;
    cout << hsa.containsNearbyDuplicate(nums2, k) << endl;
    cout << hsa.containsNearbyDuplicate(nums3, k) << endl;
    cout << hsa.containsNearbyDuplicate(nums4, k) << endl;
    cout << hsa.containsNearbyDuplicate(nums5, k) << endl;  
    return 0;
}