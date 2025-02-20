#include <vector>
#include <iostream>

std::vector<int> getConcatenation(std::vector<int>& nums) {
    int length = nums.size();
    std::vector<int> ans(2*length);
    for (int i=0; i<length; i++){
        ans[i] = nums[i];
        ans[i+length] = nums[i];
    }
    return ans;
}

int main(){
    std::vector<int> nums = {1,2,3};
    std::vector<int> ans = getConcatenation(nums);
    for (int i=0; i<ans.size(); i++){
        std::cout << ans[i] << " ";
    }
}