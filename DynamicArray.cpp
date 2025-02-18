// write something like a vector class in c++, quite simple just for practice 
#include <iostream>
#include <stdexcept>

// currently only supports int values but can be templated to support other types
class DynamicArray {
    public: 
        DynamicArray(int capacity) {
            this->capacity = capacity;
            this->array = new int[capacity];
        }

        ~DynamicArray(){
            delete[] this->array;
        }

        int get(int index) {
            if (index >= 0 && index < this->size) {
                return this->array[index];
            }
            else {
                throw std::out_of_range("Index is out of bounds");
            }
        }

        void set(int index, int value){
            if (index >= 0 && index < this->size) {
                this->array[index] = value;
            }
            else {
                throw std::out_of_range("Index is out of bounds");
            }
        }

        void pushback(int value){
            if (this->size < this->capacity){
                this->array[this->size] = value;
                this->size++;
            }
            else {
                this->resize();
                this->array[this->size] = value;
                this->size++;
            }
        }

        int popback(){
            if (this->size > 0){
                this->size--;
                return this->array[this->size];
            }
            else{
                throw std::out_of_range("Array is empty");
            }
        }

        // calling this function will double the capacity of the dynamic array
        void resize(){
            this->capacity *= 2;
            int *new_array = new int[this->capacity];
            for (int i=0; i<this->size;i++){
                new_array[i] = this->array[i];
            }
            delete[] this->array;
            this->array = new_array;
        }

        // this will return the number of elements in the dynamic array
        int getsize(){
            return this->size;
        }

        // this will return the capacity of the dynamic array
        int getcapacity(){
            return this->capacity;
        }

    private:
        int* array;
        int capacity {0};
        int size {0};
};

int main(){
    DynamicArray d_array(3);
    d_array.pushback(1);
    d_array.pushback(2);
    
    std::cout << "Element at index 0: " << d_array.get(0) << std::endl;
    std::cout << "Element at index 1: " << d_array.get(1) << std::endl;
    std::cout << "Size of the array: " << d_array.getsize() << std::endl;
    std::cout << "Capacity of the array: " << d_array.getcapacity() << std::endl;

    d_array.popback();
    std::cout << "Element at index 0 after popback: " << d_array.get(0) << std::endl;

    d_array.resize();
    std::cout << "Capacity of the array after resize: " << d_array.getcapacity() << std::endl;
    return 0;
}