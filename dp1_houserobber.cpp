
/* DT: 2  9  8  3  6
 * Top Down
 *             
 *           9   2
 *            3   8
 *                 6
 *               
 *                
 */
#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std;

class DpOneD {
  public:
    int dfs(int i, const vector<int>& vnums){
      // Base case
      if (i >= sz){
        return 0;
      }
      if (memory[i] != -1){
        return memory[i];
      }
      int rob_this_one = vnums[i] + dfs(i+2, vnums);  // 0, dfs(2) | 2, dfs(4) | 
      int skip_this_one = dfs(i+1, vnums); // dfs(1) | 1, dfs(3) | 3, dfs(5)
      memory[i] = std::max(rob_this_one, skip_this_one);
      return memory[i];
    }

    int rob(vector<int>& nums) {
      sz = nums.size();    
      memory.resize(sz, -1); // -1 means not calculated yet
      return dfs(0, nums); // dfs(0)
    }
  private:
    int sz {};
    vector<int> memory;
};

int main(void){
                    //0 1 2 3 4
  vector<int> nums = {2,9,8,3,6};  
  DpOneD robber{};
  int res = robber.rob(nums);
  std::cout << res << std::endl;
  return 0;
}
