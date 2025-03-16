// similar to fibonacci sequence
#include <iostream>

int climbStairs(int n){
    int val1 = 1;
    int val2 = 1;

    for (int i=0; i< n-1; i++){
        int temp = val2;
        val2 = temp + val1;
        val1 = temp;
    }
    return val2;;
}

int main(void){
    int val = climbStairs(5);
    std::cout  << val << std::endl;
    return 0;
}

// another approach to use a cache with recursion

// public:
//     int climbStairs(int n) {
//         cache = vector<int>(n+1,0);
//         int ways = helper(n);
//         return ways;
//     }

//     int helper(int n){
//         // base case 
//         if (n<=2){
//             return n;
//         }
//         // if in cache return from cache
//         if (cache[n]!=0){
//             return cache[n];
//         }
//         cache[n] = helper(n-1) + helper(n-2);
//         return cache[n];
//     }
// private:
//     vector<int> cache;