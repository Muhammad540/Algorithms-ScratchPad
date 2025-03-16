#include <iostream>
#include <vector>


void merge(std::vector<int> &arr, int start, int mid, int end){
    // store the left and right sub arrays 
    std::vector<int> left(arr.begin()+start, arr.begin()+mid+1);
    std::vector<int> right(arr.begin()+mid+1, arr.begin()+end+1);

    int i = 0, j = 0, k = start;

    // merge the two arrays until any one of them is empty
    while (i<left.size() && j<right.size()){
        if (left[i] <= right[j]){
            arr[k++] = left[i++];
        }else {
            arr[k++] = right[j++];
        }
    }

    // copy if any elements are left in the left array
    while (i<left.size()){
        arr[k++] = left[i++];
    }

    // copy if any elements are left in the right array
    while (j<right.size()){
        arr[k++] = right[j++];
    }
}

void mergesortHelper(std::vector<int> &arr, int start, int end){
    // base case: if the size of sub array is 1 or 0, it is already sorted
    if (end-start+1 <=1){
        return;
    }

    // get the middle index, this will be used to split the array into two halves
    int mid = start + (end-start)/2;

    // sort the left and right sub arrays
    mergesortHelper(arr, start, mid);
    mergesortHelper(arr, mid+1, end);

    // merge the two sorted sub arrays
    merge(arr, start, mid, end);
}

void mergesort(std::vector<int> &arr){
    // simply return if the array is empty or has only one element  
    if (arr.size() <=1){
        return;
    }
    // initialize the recursion 
    mergesortHelper(arr, 0, arr.size()-1);
}

int main(void){
    std::vector<std::vector<int>> testCases = {
        {5, 2, 3, 1, 10},
        {10, 9, 8, 7, 6},
        {1, 2, 3, 4, 5},
        {3, 1, 4, 1, 5, 9, 2, 6},
        {0, -1, 2, -3, 4, -5},
        {100, 50, 75, 25, 0, -25, -50, -75, -100},
        {1, 1, 1, 1, 1},
        {5},
        {}, 
        {2, 1},
        {1, 2},
        {3, 2, 1, 4, 5, 0, -1, -2},
        {1000, 500, 250, 125, 62, 31, 15, 7, 3, 1}
    };

    for (const auto& arr : testCases) {
        std::vector<int> copyArr = arr; 
        mergesort(copyArr);

        std::cout << "Sorted array: ";
        for (int i = 0; i < copyArr.size(); i++) {
            std::cout << copyArr[i] << (i < copyArr.size() - 1 ? ", " : "\n");
        }
    }
    return 0;
}