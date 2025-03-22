// constraint: the array given to binary search must be sorted
#include <iostream>
#include <vector> 

using namespace std;

int binarySearch(vector<int> &arr, int target) {
    int left = 0;
    int right = arr.size() - 1; 
    
    while (left <= right) {
        int mid = left + ((right - left) / 2);

        if (target > arr[mid]) {
            left = mid + 1;
        } else if (target < arr[mid]) {
            right = mid - 1;
        } else {
            return mid; // target found
        }
    }

    return -1; // target not found
}

int main() {
    vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int target1 = 5;
    int result1 = binarySearch(sortedArray, target1);
    cout << "Searching for " << target1 << ": " << (result1 != -1 ? "Found at index " + to_string(result1) : "Not found") << endl;

    int target2 = 11;
    int result2 = binarySearch(sortedArray, target2);
    cout << "Searching for " << target2 << ": " << (result2 != -1 ? "Found at index " + to_string(result2) : "Not found") << endl;

    int target3 = 1;
    int result3 = binarySearch(sortedArray, target3);
    cout << "Searching for " << target3 << ": " << (result3 != -1 ? "Found at index " + to_string(result3) : "Not found") << endl;

    int target4 = 10;
    int result4 = binarySearch(sortedArray, target4);
    cout << "Searching for " << target4 << ": " << (result4 != -1 ? "Found at index " + to_string(result4) : "Not found") << endl;

    int target5 = -1;
    int result5 = binarySearch(sortedArray, target5);
    cout << "Searching for " << target5 << ": " << (result5 != -1 ? "Found at index " + to_string(result5) : "Not found") << endl;

    return 0;
}