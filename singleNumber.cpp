#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
	std::unordered_map<int, int> hashmap = {};
	int result;
	int min = 10000;

	size_t int_size = sizeof(int);
	for (int i = 0; i < nums.size(); i++){
		hashmap[nums[i]]++;
	}
	
	for (auto it: hashmap){
		if (it.second < min){
			min = it.second;
			result = it.first;
		}
	}
	return result;
    }
};
*/
// xor basically allows you to find duplicate number, for any two same numbers, doing xor results in 0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
	int result = 0;
	for (auto number:nums){
		result = result ^ number;
	}
	return result;
    }
};

/*
 	Input: nums = [3,2,3]
	Output: 2
 */
int main(){
	Solution sol;
	std::vector<int> nums = {3,2,3};
	int ret = sol.singleNumber(nums);
	std::cout << ret <<  std::endl;
	return 0;
}
