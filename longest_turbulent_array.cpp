/*
given the array of integers, find the length of maximum turbulent subarray
A subarray is called turbulent if the comparison sign flips between each adjacent pair of elements in the subarray 
*/
#include <vector>
#include <iostream>
using namespace std;

class getTurbulentArray {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() == 1) return 1;
        bool prev_comp = arr[0] > arr[1];
        int count;

        if (arr[0] == arr[1]) count = 1;
        else count = 2;

        int max_count = 1;
        bool curr_comp;
        bool have_flipped = true;

        if (arr.size() == 2){
            return count;
        }

        for (int i=1; i<arr.size()-1;i++){
            if (arr[i] == arr[i+1]){
                count = 1;
                have_flipped = false;
                continue;            
            }
            
            curr_comp = arr[i] > arr[i+1];
            if (!have_flipped || curr_comp == prev_comp){
                count = 2;
            }
            else {
                count++;
            }
            prev_comp = curr_comp;
            have_flipped = true;
            max_count = max(max_count, count);
        }
        return max_count;
    }
};

int main(void) {
    vector<int> arr = {9,4,2,10,7,8,8,1,9};
    vector<int> arr2 = {4,8,12,16};
    vector<int> arr3 = {100};
    vector<int> arr4 = {1,1,1,1,1};
    vector<int> arr5 = {8,8,9,10,6,8,2,4,2,2,10,6,6,10,10,2,3,5,1,2,10,4,2,0,9,4,9,3,0,6,3,2,3,10,10,6,4,6,4,4,2,5,1,4,1,1,9,8,9,5,3,5,5,4,5,5,6,5,3,3,7,2,0,10,9,7,7,3,5,1,0,9,6,3,1,3,4,4,3,6,3,2,1,4,10,2,3,4,4,3,6,7,6,2,1,7,0,6,8,10};
    vector<int> arr6 = {5,5,3,4,2};
    vector<int> arr7 = {37,199,60,296,257,248,115,31,273,176};
    vector<int> arr8 = {4,5};
    getTurbulentArray gt;
    cout << gt.maxTurbulenceSize(arr8) << endl;
    cout << gt.maxTurbulenceSize(arr7) << endl;
    cout << gt.maxTurbulenceSize(arr) << endl;
    cout << gt.maxTurbulenceSize(arr2) << endl;
    cout << gt.maxTurbulenceSize(arr3) << endl;
    cout << gt.maxTurbulenceSize(arr4) << endl;
    cout << gt.maxTurbulenceSize(arr5) << endl;
    cout << gt.maxTurbulenceSize(arr6) << endl;
    return 0;
}