/*
Return the Kth largest  (using min heap)
The idea is to never let the heap grow more than K, 
So out of those K , the Kth element is the Kth largest or you can say the min
So if we store the elements in a min heap just returning the root would suffice as long as the root is the min of the heap
and heap follows both the structural and order constraints. 
*/
#include <iostream> 
#include <vector> 

using namespace std;

class KthLargest {
private:
    int kth_val;
    vector<int> heap{0}; // heap starts with a dummy val
    // heap.reserve() before push_back 
public:
    // note: we are designing a min heap
    void push_into_heap(int val){
        // add the incoming value at the end
        heap.push_back(val);
        int current_idx = heap.size()-1; 

        // percolate up (if current node val smaller than its parent so swap)
        while (current_idx>1 && heap[current_idx] < heap[current_idx/2]){  
            int temp = heap[current_idx/2];
            heap[current_idx/2] = heap[current_idx];
            heap[current_idx] = temp;
            current_idx /= 2;
        }
    }

    void pop_from_heap(){
        // this method would make sure that the # of elements in the heap are at max k 
        if (heap.size() == 1){
            return;
        }
        if (heap.size() == 2){
            // int res = heap[1];
            heap.pop_back();
            return;
        }

        // int res = heap[1]; 
        heap[1] = heap.back();
        heap.pop_back(); // we replaced the root with the last val in the heap and removed the last val 

        int i=1;
        // percolate down 
        while(2*i < heap.size()){ // check if the node has a left child 
            if((2*i+1 < heap.size()) && 
                (heap[2*i+1]<heap[2*i]) && 
                    (heap[i] > heap[2*i+1])){
                        // since right child is smaller than the left one (swap)
                        int temp = heap[i];
                        heap[i] = heap[2*i+1];
                        heap[2*i+1] = temp;
                        i = 2*i+1;
                    }
            else if (heap[i] > heap[2*i]){
                // swap the left child since that is the smaller compared to the parent 
                int temp = heap[i];
                heap[i] = heap[2*i];
                heap[2*i] = temp;
                i = 2*i;
            }
            else {
                break;
            }
        }
    }

    KthLargest(int k, vector<int>& nums): kth_val{k} {
        heap.reserve(k+1);
        for (int val: nums){
            push_into_heap(val);
            if (heap.size() > kth_val+1){
                pop_from_heap();
            }
        }
    }
    
    int add(int val) {
        push_into_heap(val);
        if (heap.size() > kth_val+1){
            pop_from_heap();
        }        
        return heap[1]; // the top of the heap tree is the smallest value (or the Kth largest)
    }
};


int main(){
    vector<int> nums {1,2,3,3};
    KthLargest stream(3, nums);
    std::cout << stream.add(3) << std::endl;
    std::cout << stream.add(3) << std::endl;
    std::cout << stream.add(3) << std::endl;
    std::cout << stream.add(5) << std::endl;
    std::cout << stream.add(6) << std::endl;
    std::cout << stream.add(7) << std::endl;
    std::cout << stream.add(8) << std::endl;
    
    return 0;
}