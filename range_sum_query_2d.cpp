/*    calculate the sum of elements inside a matrix defined by a rectangle with bounds (r1,c1 & r2,c2) 
 *    
 */

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> prefix_sum_array {};

    NumMatrix(vector<vector<int>>& matrix) {
        prefix_sum_array.resize(matrix.size(), vector<int>(matrix[0].size()));
        int total = 0;
        for (int row=0; row < matrix.size(); row++){
          for (int col=0; col < matrix[0].size(); col++){
            // rec above and rect to left is to be considered but the top left corner is considered twice 
            if (row == 0 && col == 0){
              prefix_sum_array[row][col] = matrix[row][col];
            } else if (row == 0 && col > 0){
              prefix_sum_array[row][col] = matrix[row][col] + prefix_sum_array[row][col-1];
            } else if (row > 0 && col == 0){
              prefix_sum_array[row][col] = matrix[row][col] + prefix_sum_array[row-1][col];
            } else {
              prefix_sum_array[row][col] = matrix[row][col] + prefix_sum_array[row-1][col] + prefix_sum_array[row][col-1] - prefix_sum_array[row-1][col-1];
            }
          }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      int val = prefix_sum_array[row2][col2];
      if (row1 > 0){
        val -= prefix_sum_array[row1-1][col2];
      }
      if (col1 > 0){
        val -= prefix_sum_array[row2][col1-1];
      }
      if (row1 > 0 && col1 > 0){
        val += prefix_sum_array[row1-1][col1-1];
      }
      return val;
    }
};

int main(void){
  vector<vector<int>> matrix {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
  NumMatrix* obj = new NumMatrix(matrix);
  int param_1 = obj->sumRegion(2,1,4,3);
  std::cout << param_1 << std::endl;
  return 0;
}
