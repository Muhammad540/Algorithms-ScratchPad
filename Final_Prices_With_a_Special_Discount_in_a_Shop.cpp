#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
      vector<int> v(prices.size(),0);
      int p1 = 0, p2 = 1;
      int counter = 0;
      while (counter < prices.size()){
        if (p2 >= prices.size()){
            v[p1] = prices[p1];
            p1++;
            counter++;
            p2 = p1 + 1;
        } else if ((p2 > p1) && (prices[p2] <= prices[p1])){
          v[p1] = prices[p1]-prices[p2];
          p1++;
          counter++;
          p2 = p1 + 1;
        } else {
          p2++;
        }
      }
      return v; 
    }
};

/* size = 10
 * counter = 5
 * 8,7,4,2,8,1,7,7,10,1
 *           ^ 
 *                 ^
 * 
 * 1,3,2,1,7,0,0,6,9,1
 */
int main(){
  Solution s;
  vector<int> prices = {10,1,1,6};
  auto result = s.finalPrices(prices);
  assert(result[0] == 9);
  assert(result[1] == 0);
  assert(result[2] == 1);
  assert(result[3] == 6);

  return 0;
}
