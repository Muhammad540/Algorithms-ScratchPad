// use binary search to basically find the minimum speed bananas/hour that koko can eat before the zoo keeper comes 
// xoo keeper will come after h hours so we have to hurry (p875)
#include <cmath> 
#include <vector> 
#include <iostream> 
#include <algorithm>


using namespace std;

int minEatingspeed(std::vector<int>& piles, int hours_before_housekeeper_return){

    auto feasible = [&](int val)-> bool{
        int hours_taken_by_koko = 0;
        for(int pile: piles) {
            hours_taken_by_koko += (pile + val - 1)/val; // ceil division trick 
        }
        return hours_taken_by_koko <= hours_before_housekeeper_return;
    };  

    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
     
    int mid; 

    while (left < right) {
        mid = left + (right - left)/2;

        if (feasible(mid)) {// anything above will also be feasible
            right = mid;
        } else { // anything below will be uselesss
            left = mid + 1;
        }
    }
    return left;
}

int main(void){
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Test Case 1:" << endl;
    cout << "Piles: [3,6,7,11], Hours: " << h1 << endl;
    cout << "Minimum eating speed: " << minEatingspeed(piles1, h1) << " (Expected: 4)" << endl << endl;

    vector<int> piles2 = {30};
    int h2 = 5;
    cout << "Test Case 2:" << endl;
    cout << "Piles: [30], Hours: " << h2 << endl;
    cout << "Minimum eating speed: " << minEatingspeed(piles2, h2) << " (Expected: 6)" << endl << endl;

    vector<int> piles4 = {30, 11, 23, 4, 20};
    int h4 = 6;
    cout << "Test Case 4:" << endl;
    cout << "Piles: [30,11,23,4,20], Hours: " << h4 << endl;
    cout << "Minimum eating speed: " << minEatingspeed(piles4, h4) << " (Expected: 23)" << endl << endl;
    return 0;
}