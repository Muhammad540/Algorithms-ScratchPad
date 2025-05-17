/*
 * solving it using top down dp (recursive) 
 * m by n grid
 * unique number of paths from the top (0,0) to the bottom right (r-1,c-1)
 */

#include <iostream> 
#include <vector> 

using namespace std;

class TwoDp_top_down{
  public:
    int dp(int current_row, int current_col){
      // If we go out of bounds
      if (current_row == row || current_col == col){
        return 0;
      }
      // if the value is already in the cache then go for it 
      if (cache_map[current_row][current_col] > 0){
        return cache_map[current_row][current_col];
      }
      // If we are on the same row or col as the find destination, 
      // there is only one way to reach the destination in that case 
      if (current_row == row-1 || current_col == col-1){   
        return 1; 
      } 

      //        store in the cache                    go down                +              go right 
      cache_map[current_row][current_col] = dp(current_row+1, current_col)   +   dp(current_row, current_col+1);
      return cache_map[current_row][current_col];
    } 

    int uniquePaths(int m, int n){ 
      row = m;
      col = n;
      cache_map.resize(row, vector<int>(col, 0));
      return dp(0,0);
    } 

  private: 
    int row; 
    int col; 
    std::vector<std::vector<int>> cache_map{};
};

class TwoDp_bottom_up{
  public:
    int uniquePaths(int row, int col){
      // this is the previous row that we are going to use to calculate the current row
      vector<int> previous_row(col, 0);
      // this is the current row that we are going to use to calculate the next row
      vector<int> current_row(col, 0);

      // this outer loop is to move from the bottom row to the top row 
      for (int i = row-1; i >= 0; i--){
        current_row[col-1] = 1;
        // this inner loop is to move from the right most col to the left most col
        for (int j = col-2; j >=0 ; j--){
          current_row[j] = current_row[j+1] + previous_row[j];
        }
        previous_row = current_row;
      }
      return previous_row[0];
    }
};


int main(void){
  TwoDp_top_down twoDp;
  cout << twoDp.uniquePaths(3,6) << endl;
  TwoDp_bottom_up twoDp_bottom_up;
  cout << twoDp_bottom_up.uniquePaths(3,6) << endl;
  return 0;
}
