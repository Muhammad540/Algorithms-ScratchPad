#include <iostream>
#include <vector>

using namespace std;

void bucketSort(vector<int>& nums, int range){
    std::vector<int> counts(range,0);

    // first loop fills in the buckets with counts 
    for (int n: nums){
        counts[n] += 1;
    }

    // fill in the arr with sorted values
    int i = 0;
    for (int n=0; n<range;n++){
        for (int j=0; j<counts[n]; j++){
            nums[i] = n;
            i++; 
        }
    }
}

int main() {
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    cout << "Before sorting (Example 1): ";
    for (int n : nums1) {
        cout << n << " ";
    }
    bucketSort(nums1, 3);
    cout << "\nAfter sorting (Example 1): ";
    for (int n : nums1) {
        cout << n << " ";
    }
    cout << endl;

    vector<int> nums2 = {2, 0, 1};
    cout << "Before sorting (Example 2): ";
    for (int n : nums2) {
        cout << n << " ";
    }
    bucketSort(nums2, 3);
    cout << "\nAfter sorting (Example 2): ";
    for (int n : nums2) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}

