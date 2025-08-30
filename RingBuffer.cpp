#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <string> 

struct Image{
  std::string filename;
  int timestamp;
  Image(): filename(""), timestamp(0){}
  Image(const std::string& name, int ts): filename(name), timestamp(ts) {}
};

template<typename T>
class RingBuffer {
    private:
        // this will default construct vector of type T type (if we allocat cap size in the constructor which is not ideal)
        std::vector<T> buffer;
        // maximum cap
        size_t capacity;
        // current number of elements
        size_t size;
        // Points to the next write position
        size_t head;
        // Points to the oldest element
        size_t tail;
    public:
        explicit RingBuffer(size_t cap): head(0), tail(0), size(0), capacity(cap) {
            if (cap == 0){
                throw std::invalid_argument("Buffer Capacity must bre greater than 0");
            }
            buffer.resize(capacity);
        }

        void add(const T& element){
            buffer[head] = element;

            if (size < capacity){
                size++;
            } else {
                tail = (tail + 1) % capacity;
            }

            head = (head + 1) % capacity;
        }
        
        // index=0 oldest element
        // index=size-1 newest element
        const T& getElement(size_t index) const {
            if (index >= size){
                throw std::out_of_range("Index out of range");
            }
            return buffer[(tail+index)%capacity];
        }

        const T& getNewestElement() const {
            if (empty()){
                throw std::runtime_error("Buffer is empty");
            }
            // note: capacity is added for the case where head is 0
            return buffer[(head-1+capacity) % capacity];
        }

        const T& getOldestElement() const {
            if (empty()){
                throw std::runtime_error("Buffer is empty");
            }
            return buffer[tail];
        }

        bool empty() const {
            return size == 0;
        }

        bool full() const {
            return size == capacity;
        }

        size_t getSize() const {
            return size;
        }

        void getAllElements(std::vector<T> &out) const {
            out.clear();
            out.reserve(size);
            for (size_t i=0; i<size; i++){
                out.push_back(buffer[(tail+i)%capacity]);
            }
        }

        void clear(){
            head=tail=size=0;
        }
};

int main(){
  RingBuffer<Image> imageBuffer(5);

  std::cout << "Loading image sequence..."<< std::endl;
  for (int i=0; i<=10; i++){
    Image newImage("image_"+std::to_string(i)+".jpg",i*100);
    imageBuffer.add(newImage);

    std::cout << "Loaded: " << newImage.filename << ", Buffer size: "<< imageBuffer.getSize() << std::endl;
    std::cout << " Current Images in the Buffer: ";
    for (size_t j=0; j<imageBuffer.getSize(); j++){
      std::cout << imageBuffer.getElement(j).filename << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
