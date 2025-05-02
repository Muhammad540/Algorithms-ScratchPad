/*
Basically i wanted to implement DFS(backtracking) for a graph problem 
1 is land 
0 is water 

GET THE # OF ISLANDS  
map = [
    ["0","1","1","1","0"],
    ["0","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
  ]

map = [
    ["0","0","1","1","0"],
    ["0","0","0","1","0"],
    ["1","0","0","0","0"],
    ["0","0","0","0","0"]
  ]


all ones surrounded by zeros are islands, connected ones form island. 
how will i move through the grid  ? 

row+1, col (down) 
row-1, col (up)
row, col+1 (right)
row, col-1 (left)

*/
#include <iostream>
#include <vector> 

using namespace std;

int dfs(vector<vector<char>> &grid, int row, int column){
    // base case: when should you stop and rethink your life choices 
    if (row < 0 || column < 0 || row >= grid.size() || column >= grid[0].size() || grid[row][column]=='0'){
        return 0;
    }
    grid[row][column] = '0';
    dfs(grid, row+1, column);
    dfs(grid, row-1, column);
    dfs(grid, row, column+1);
    dfs(grid, row, column-1);
    return 1;
}

int numIslands(vector<vector<char>> &grid){
    int count = 0;
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[0].size(); j++){
            if (grid[i][j] == '1'){
                count += dfs(grid, i, j);
            }
        }
    }
    return count;
}

int main(void){
    
    std::vector<std::vector<char>> grid = {
        {'1','1','0','0','1'},
        {'1','1','0','0','1'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };  
    cout << numIslands(grid) << endl;
    
    return 0;
}

