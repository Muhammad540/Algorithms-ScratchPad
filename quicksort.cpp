// quick sort like merge sort is a divide and conquer algorithm
// pick an element as pivot and create subarrays of elements < pivot and >= pivot
// of course it is done recursively

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pair{
    public:
        int key;
        string value;

        Pair(int key, string value) : key(key), value(value) {};
};

void quickSortHelper(vector<Pair>& pairs, int start, int end){
    // base case check ( if array is of length = 1 return it)
    if (end-start+1 <=1){
        return; // we are modifying in place so we don't need to return anything
    }

    int left_pointer = start;
    Pair pivot = pairs[end];

    // iterate over the sub array (NOTE: use the start and end indices [recursive behavior])    
    for (int i=start; i<end;i++){ // i is used to iterate through the array 
        if (pairs[i].key < pivot.key){
            swap(pairs[left_pointer], pairs[i]);
            // after swapping the elements move the left pointer
            left_pointer++;
        }
    }

    // at this point the sub array's have been properly swapping into left and right 
    // now swap the pivot with the position at left ptr+1
    swap(pairs[left_pointer], pairs[end]);

    quickSortHelper(pairs, start, left_pointer-1);
    quickSortHelper(pairs, left_pointer+1, end);
}

vector<Pair> quickSort(vector<Pair>& pairs){
    if (pairs.size() <= 1){
        return pairs;
    }

    quickSortHelper(pairs, 0, pairs.size()-1);
    return pairs;
}

int main() {
    vector<Pair> pairs = {
        Pair(3, "three"),
        Pair(1, "one"),
        Pair(4, "four"),
        Pair(2, "two"),
        Pair(5, "five")
    };

    cout << "Before sorting:" << endl;
    for (const auto& p : pairs) {
        cout << p.key << ": " << p.value << endl;
    }

    quickSort(pairs);

    cout << "\nAfter sorting:" << endl;
    for (const auto& p : pairs) {
        cout << p.key << ": " << p.value << endl;
    }

    return 0;
}

