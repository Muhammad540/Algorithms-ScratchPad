// pick a number between 1-n (the picked number will be fixed for this example say 3)
// this algo will guess the number you picked based on a guess machine 

#include <iostream> 

int guess(int num){
    const int target = 77;
    if (num > target){
        return -1;
    } else if (num < target) {
        return 1;
    } else {
        return 0;
    }
}

int guessNumber(int n){
    int left = 1; 
    int right = n;
    
    while (left <= right){
        int mid = left + (right-left) / 2;
        int result = guess(mid);

        if (result == 0){
            return mid;
        } else if (result == -1){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    int n = 100;
    std::cout << "I'm thinking of a number between 1 and " << n << std::endl;

    int result = guessNumber(n);

    if (result != -1){
        std::cout << "The number is: " << result << std::endl;
    } else {
        std::cout << "couldnt find the number" << std::endl;
    }

    return 0;
}