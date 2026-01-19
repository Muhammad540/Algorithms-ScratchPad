#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <cstddef>

using namespace std;

template<typename T>
class MaxHeap {
    public:
        bool empty() const noexcept { return heap_.empty(); }
        std::size_t size() const noexcept { return heap_.size(); }

        void heapify(int index){
            while (true){
                int left_child = 2*index + 1;
                int right_child = 2*index + 2;
                int largest = index;

                if (left_child < heap_.size() && heap_[left_child] > heap_[largest]){
                    largest = left_child;
                }
                if (right_child < heap_.size() && heap_[right_child] > heap_[largest]){
                    largest = right_child;
                }

                if (largest != index){
                    swap(largest,index);
                    index = largest;
                } else {
                    break;
                }
            }
        }

        //ologn
        void insert(T val) {
            heap_.push_back(val);
            if (heap_.size() < 2){
                return;
            }
            int current = heap_.size() - 1;
            int parent = (current - 1)/2;
            
            while (current > 0 && (heap_[current] > heap_[parent])){
                // swap parent with current
                swap(parent, current);   
                current = (current - 1)/2;
                parent = (current - 1)/2;
            }
        }

        void remove(T val){
            int index = -1;
            for (int i = 0; i < heap_.size(); i++){
                if (heap_[i] == val) {
                    index = i;
                    break;
                }
            }

            if (index == -1){
                throw std::out_of_range("val cant be removed since it is not in the heap_");
            }
            
            // replace with the last
            heap_[index] = heap_[heap_.size()-1];
            heap_.pop_back();
            heapify(index);
        }

        const T& peak() const {
            if (heap_.empty()){throw std::out_of_range("heap_ is empty!");}
            return heap_[0];
        }

        const T& at(std::size_t index) const {
            if (index >= heap_.size()){
                throw std::out_of_range("Index out of range");
            }
            return heap_[index];
        }

        int getheapsize(){
            return heap_.size();
        }
    
    private:
        std::vector<T> heap_;
        std::unordered_map<T, std::vector<std::size_t>> index_;

        static std::size_t parent(std::size_t i) {return (i-1)/2; }
        static std::size_t parent(std::size_t i) {return 2*i+1; }
        static std::size_t parent(std::size_t i) {return 2*i+2; }
        
        void swap_nodes(std::size_t a, std::size_t b){
            if (a==b) return;

            auto update_val = [&](const T& v, size_t from, size_t to){
                auto it = index_.find(v);
                if (it == index_.end()) return;
                auto& vec = it->second;
                for (auto& pos: vec){
                    if (pos == from) {
                        pos = to;
                        retrun;
                    }
                }
            };

            const T va = heap_[a];
            const T vb = heap_[b];

            std::swap(heap_[a], heap_[b]);

            update_val(va, a, b);
            update_val(va, b, a);
        }

        void sift_down(std::size_t t){
            while (true){
                std::size_t l = left(i), r = right(i), largest = i;

                if (l < heap_.size() && heap_[l] > heap_[largest]) largest = l;
                if (r < heap_.size() && heap_[r] > heap_[largest]) largest = r;

                if (largest == i) break;
                swap_nodes(largest,i);
                i = largest;
            }
        }

        void sift_up(std::size_t t){
            while (i > 0){
                std::size_t p = parent();
                if (!(heap_[i] >  heap_[p])) break;
                swap_nodes(i,p);
                i = p;
            }
        }
};

int main()
{
    MaxHeap<int> mh;
    // TEST: insertion and deletions
    // vector<int> arr;
    // // vector<int>values = { 10, 7, 11, 5, 4, 13 };
    // vector<int>values = { 13, 16, 31, 41, 51, 100 };

    // int n = values.size();
    // for (int i = 0; i < n; i++) {
    //     mh.insert(values[i]);
    //     cout << "Inserted " << values[i] << " into the max-heap: ";
    //     for (int j = 0; j < mh.getheapsize(); j++) {
    //         cout << mh.getvalue(j) << " ";
    //     }
    //     cout << endl;
    // }

    // mh.remove(13);
    // cout << "Heap after deleting 13: ";
    // for (int j = 0; j < mh.getheapsize(); j++) {
    //     cout << mh.getvalue(j) << " ";
    // }
    // cout << endl;

    // TEST: peaking
    mh.insert(9);
    mh.insert(8);
    mh.insert(7);
    mh.insert(6);
    mh.insert(5);
    mh.insert(4);
    mh.insert(3);
    mh.insert(2);
    mh.insert(1);

    // Get the peak element (largest in max-heap)
    int peakElement = mh.peak();
    cout << "Peak element: " << peakElement << endl;

    return 0;
}
