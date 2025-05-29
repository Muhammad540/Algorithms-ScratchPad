/* 
    two pointer approach 
    Input: s = "Was it a car or a cat I saw?"
    Output: true
    wasitacaroracatisaw
    L                 R

    Madam, in Eden, I'm Adam
    madam,ineden,i'madam
          L   R
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class validPalindrome {
public:
    bool isPalindrome(string s) {
      // convert string to lower 
      std::transform(s.begin(), s.end(), s.begin(), ::tolower);
      // remove the white space
      s.erase(remove(s.begin(), s.end(), ' '), s.end());
      // if there is a question mark at the end, remove it 
      if (!s.empty() && s.back()=='?') {
        s.pop_back();
      }
      // remove other unnecessary stuff
      s.erase(std::remove(s.begin(), s.end(), ','), s.end());
      s.erase(std::remove(s.begin(), s.end(), '\''), s.end());
      s.erase(std::remove(s.begin(), s.end(), '.'), s.end());
      s.erase(std::remove(s.begin(), s.end(), ':'), s.end());

      int left_pointer  = 0;
      int right_pointer = s.size()-1;
      while (left_pointer < right_pointer){
        if (s[left_pointer] != s[right_pointer]){
          return false;
        }
        left_pointer++;
        right_pointer--;
      }

      return true;
    }
};

int main(void){
  std::string s = "Was it a car or a cat I saw?";
  validPalindrome vp;
  std::cout<< vp.isPalindrome(s) << std::endl;
  return 0;
}
