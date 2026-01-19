#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class ManageHeap {  
public:  
    vector<int> heap;  
    /*
        For a specific node 'i', its:
        1. parent is at: (i-1)/2
        2. left child is at: (2*i + 1)
        3. right child is at: (2*i + 2)
        Space: O(n)
        insertion: O(logn)
        deletion: O(logn)
        peak: O(1)
        heapify: O(n)
    */
    void heapify(vector<int>& stones) {
        heap = stones;
        heap.insert(heap.begin(),0); // dummy value at index 0
        int current_pointer = ((heap.size()-1)/2);
        while (current_pointer>0){
            // percolate down
            int i = current_pointer;
            while(2*i < heap.size()){ // check if there exists a left child 
                if ((2*i+1 < heap.size()) && (heap[2*i+1]>heap[2*i]) && (heap[i]<heap[2*i+1])){ // check if there exists a right child, check if the right child is greater than the left, check if the right child is greater than the parent
                    // swap right child 
                    int temp = heap[i];
                    heap[i] = heap[2*i+1];
                    heap[2*i+1] = temp;
                    i = 2*i+1; // move the pointer to right child 
                }
                else if (heap[i] < heap[2*i]){
                    int temp = heap[i];
                    heap[i] = heap[2*i];
                    heap[2*i] = temp;
                    i = 2*i; // move the pointer to left child 
                } else {
                    break;
                }
            }
            current_pointer -= 1;
        }
    }  

    void pop_max() {
        // swap root↔last, pop_back, percolate‑down
        if (heap.size()==1){
            return;
        }
        if (heap.size()==2){
            heap.pop_back();
            return;
        }
        // move the last value to root
        heap[1]=heap[heap.size()-1];
        heap.pop_back();
        int i=1;
        // percolate down 
        while (2*i < heap.size()){
            if ((2*i+1<heap.size()) && (heap[2*i+1]>heap[2*i]) && (heap[2*i+1]>heap[i])){
                // swap right child 
                int temp = heap[i];
                heap[i] = heap[2*i+1];
                heap[2*i+1] = temp;
                i=2*i+1;
            } else if (heap[i]<heap[2*i]){
                int temp = heap[i];
                heap[i] = heap[2*i];
                heap[2*i] = temp;
                i = 2*i;
            }
            else{
                break;
            }
        }
    }  

    void insert_to_heap(int val) {  
        heap.push_back(val);
        int i = heap.size()-1;
        // percolate up (continue as long as current pointer(i) does not fall below 1 pos and the parent of current node is smaller)
        while (i>1 && heap[i] > heap[i/2]){
            int temp = heap[i];
            heap[i] = heap[i/2];
            heap[i/2] = temp;
            i = i/2; // move the pointer to parent
        }
    }  

    int lastStoneWeight(vector<int>& stones) {  
        heapify(stones);  
        while (heap.size() > 2) {  
            int w1 = heap[1];
            pop_max();
            int w2 = heap[1];
            pop_max(); 
            if (w1 != w2) {
                insert_to_heap(abs(w1 - w2));  
            }  
        } 
        if (heap.size()==2){
            return heap[1];
        } else {
            return 0;
        }
    }
};

int main(){
    vector<int> stones = {2,7,4,1,8,1};
    ManageHeap mh;
    cout << mh.lastStoneWeight(stones) << endl;

    return 0;
}