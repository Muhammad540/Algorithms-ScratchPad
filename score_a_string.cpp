#include <string>
#include <iostream>
using namespace std;

class Solution{
    public:
        int scoreOfString(string s){
            for (auto chr: s){
                std::cout << chr << std::endl;
            }
        }
};

int main() {
    std::string name = "neetcode";
    Solution s;
    s.scoreOfString(name);

    return 0;
}