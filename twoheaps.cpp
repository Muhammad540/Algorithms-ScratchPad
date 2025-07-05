#include <algorithm>
#include <iostream> 
#include <iterator>
#include <vector>

using namespace std;

class MedianFinder {
    public:
        MedianFinder() {
            // do nothing
        }
        
        void addNum(int num) {
            // insert into the small heap (by default the makeheap in algorithm creates a max heap)
            std::cout << "adding num: " << num << std::endl;
            small.push_back(num);
            push_heap(small.begin(), small.end());
            // check if the max element in smallHeap is smaller than the min element in the maxHeap 
            if (small.size() > 0 && large.size()>0){
                int max_small_heap = small.front();
                int min_large_heap = -large.front();
                if (max_small_heap > min_large_heap){
                    // move the largest element in small to large heap
                    large.push_back(-max_small_heap); 
                    push_heap(large.begin(), large.end());
                    pop_heap(small.begin(), small.end());
                    small.pop_back();
                }
            }
            // check the size condition
            if (small.size() > large.size()+1){
                pop_heap(small.begin(), small.end());
                large.push_back(-small.back());
                push_heap(large.begin(), large.end());
                small.pop_back();
            } else if (large.size() > small.size()+1){
                pop_heap(large.begin(), large.end());
                small.push_back(-large.back());
                push_heap(small.begin(), small.end());
                large.pop_back();
            }
        }
        
        double findMedian() {
            if (small.size() > large.size()){
                return small.front();
            } else if (small.size() < large.size()){
                return -large.front();
            } else {
                return (small.front() + (-large.front())) / 2.0;
            }
        }
        void printHeaps(){
            std::cout << "small heap: ";
            for (int i = 0; i < small.size(); i++){
                std::cout << small[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "large heap: ";
            for (int i = 0; i < large.size(); i++){
                std::cout << -large[i] << " ";
            }
            std::cout << std::endl;
        }
    
    private:
        vector<int> small{};
        vector<int> large{};
};
    
int main(){
    // ["MedianFinder", "addNum", "1", "findMedian", "addNum", "2", "findMedian", "addNum", "3", "findMedian", "addNum", "4", "findMedian"]
    MedianFinder* mdf = new MedianFinder();
    mdf->addNum(1);
    mdf->printHeaps();
    std::cout << "median: " << mdf->findMedian() << std::endl;
    mdf->addNum(2);
    mdf->printHeaps();
    std::cout << "median: " << mdf->findMedian() << std::endl;
    mdf->addNum(3);
    mdf->printHeaps();
    std::cout << "median: " << mdf->findMedian() << std::endl;
    mdf->addNum(4);
    mdf->printHeaps();
    std::cout << "median: " << mdf->findMedian() << std::endl;
    return 0;
}