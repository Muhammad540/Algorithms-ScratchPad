#include <iostream>
#include <vector> 

//  I  insertion pointer 
// [5, 2, 3, 1, 10] 
//  J, J+1 swapping pointer 
// compare J and J+1 to swap 

void insertionSort(std::vector<int> &arr){
    for (int i=1; i<arr.size();i++){ // move through the vector 
        int j = i-1;
        while (j>=0 && arr[j+1] < arr[j]){
            int temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main(){
    std::vector<std::vector<int>> testCases = {
        {5, 2, 3, 1, 10},
        {10, 9, 8, 7, 6},
        {1, 2, 3, 4, 5},
        {3, 1, 4, 1, 5, 9, 2, 6},
        {0, -1, 2, -3, 4, -5},
        {100, 50, 75, 25, 0, -25, -50, -75, -100}
    };

    for (const auto& arr : testCases) {
        std::vector<int> copyArr = arr; 
        insertionSort(copyArr);

        std::cout << "Sorted array: ";
        for (int i = 0; i < copyArr.size(); i++) {
            std::cout << copyArr[i] << (i < copyArr.size() - 1 ? ", " : "\n");
        }
    }
    return 0;
}