/*
  use bottom up dp to solve this 
  The obstacle is represented by 1 and the empty space is represented by 0.
*/

#include <iostream>
#include <vector> 

using namespace std;

class Twodp_bottom_up {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int row = obstacleGrid.size();
            int col = obstacleGrid[0].size();
            
            vector<int> dp(col, 0);

            for (int i = row-1; i >= 0; i--){
                for (int j = col-1; j >= 0; j--){
                    
                    if (obstacleGrid[i][j] == 1){
                        dp[j] = 0;
                    }
                    else if (i== row-1 && j== col-1){
                        dp[j] = 1;
                    }
                    else {
                        long right = j+1 < col ? dp[j+1] : 0;
                        long down = i+1 < row ? dp[j] : 0;
                        dp[j] = right + down;
                    }
                }
            }
            return dp[0];
        }
};

int main(void){
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    Twodp_bottom_up twodp_bottom_up;
    cout << twodp_bottom_up.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}