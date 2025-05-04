#include <iostream> 
#include <vector>
#include <queue> 
#include <utility> 

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid){
    // quick exist in case of block at start or end 
    if (grid[0][0] == 1 || grid[grid.size()-1][grid[0].size()-1] == 1){
        return -1;
    }
    
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(),false));
    
    queue<pair<int,int>> q;
    q.push({0,0});

    visited[0][0] = true;
    int layer_count = 0;

    while(!q.empty()){
        layer_count ++;
        int qlength = q.size();
        // this loop runs layer by layer basis 
        for (int i=0; i<qlength;i++){
            auto val = q.front();
            int row = val.first;
            int col = val.second;
            q.pop(); // pop returns void
            
            if ( (row == grid.size()-1) && (col == grid[0].size()-1) ){
               return layer_count;
            }
            vector<pair<int,int>> neighbors = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{-1,-1},{1,-1}};
            for(auto &p: neighbors){
                /* Conditions 2 check:
                 *  1. if row and col are outside bounds 
                 *  2. if the value at the grid location is 1 
                 *  3. if there is 1 at the the neighboring position that we are currently checking  
                 *  4. if the position is already visited
                 */
                if (row+p.first < 0
                    || col+p.second < 0 
                    || row+p.first >= grid.size() 
                    || col+p.second >= grid[0].size() 
                    || visited[row+p.first][col+p.second] == true 
                    || grid[row+p.first][col+p.second] == 1){
                    continue;
                }
                q.push({row+p.first,col+p.second});
                visited[row+p.first][col+p.second] = true;
             }
        } 
    }
    return -1; // if we are not able to reach the goal position 
}


int main(void){
    std::vector<std::vector<int>> grid ={{0,0,0}, 
                                         {1,1,0},
                                         {1,1,0}};
  
    std::vector<std::vector<int>> grid2 ={{0,1}, 
                                          {1,0}};
    int result1 = shortestPathBinaryMatrix(grid);
    std::cout << result1 << std::endl;

    int result2 = shortestPathBinaryMatrix(grid2);
    std::cout << result2 << std::endl;
    return 0;
}
