#include <iostream>
#include <cassert> 
/*
 * mask could be: mask = 1 << i; 
 * or maybe move n ? n >>= 1;
 * 
 */ 
class Solution {
public:
    int hammingWeight(uint32_t n) {
      int counter = 0;
      int bit_position = 0;
      uint32_t one_check = 1;
      while (bit_position <= 32){
        if (n & one_check){
          counter++;
        }
        one_check = one_check << 1;
        bit_position++;
      }
      return counter;
    }
};

/* OTHER SOL 
     int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if ((1 << i) & n) {
                res++;
            }
        }
        return res;
    }

    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0) {
            res += (n & 1) ? 1 : 0;
            n >>= 1;
        }
        return res;
    }

    :while

*/ 
int main(){
  Solution s;
  // int n = 00000000000000000000000000010111;
  uint32_t n2 = 0b1111111111111111111111111111101;
  int result = s.hammingWeight(n2);
  assert(result == 30);

  return 0;
}
