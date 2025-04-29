/*
 my custom implementation for hash table 
 HT internally implemented as a vector 

 Collisions handling ? move to the next free space continue until free space found also known as open addressing (chaining could be implemented)
*/
#include <vector>
#include <string>
#include <optional>
#include <iostream>

struct Pair{
    Pair(int key_, int value_): key(key_), value(value_){};
    Pair(){};
    int key;
    int value;
};

using namespace std;

class HashTable {

    public:
        /*
        Initialize an empty hash table with a certain capcaity (> 1)
        */
        HashTable(int capacity_): capacity(capacity_), size(0){
            hashmap.resize(capacity);
        }

        /*
        insert the key-value into hashtable. 
        Note: if the key is already present replace the original value with new value
        */
        void insert(int key, int value){
            if ((size+!)>=capacity/2){ // load balancing
                rehash();
            }
            auto key_index = getHash(key);
            while (true){
                // cond 1: index not occupied 
                if (hashmap[key_index] == std::nullopt){
                    hashmap[key_index] = Pair(key,value);
                    size+=1;
                    return;
                }
                // cond 2: similar key already 
                else if (hashmap[key_index]->key == key){
                    hashmap[key_index]->value = value; // replace the old val with new one 
                    return;
                }
                // cond 3: occupied move to next available space 
                key_index += 1;
                key_index = key_index % capacity;
            }

        }

        /*
        return the value associated with the key, if key is not present in the HT return -1
        */
        int get(int key){
            auto key_index = getHash(key);

            while (hashmap[key_index]){ // continue until next std::nullopt or empty positionn
                if (hashmap[key_index]->key == key){
                    return hashmap[key_index]->value;
                }
                key_index += 1; // open addressing approach (if chaining was used we would move to the next linked node)
                key_index = key_index % capacity;
            }
            return -1;
        }

        /*
        Remove the key-value pair with the given key-> 
        If the key is not present return False else return True
        */
        bool remove(int key){
            if (get(key) == -1){
                return false;
            }

            auto key_index = getHash(key);
            while (true){
                if (hashmap[key_index]->key == key){
                    // open addressing causes bugs cause we create a hole in the map and our get method may stop early when it sees an empty space 
                    hashmap[key_index] = std::nullopt;
                    size -= 1;
                    return true;
                }
                key_index += 1;
                key_index = key_index % capacity;
            }
        }

        /*
        return the number of keys in the HT
        */
        int getSize() const {
            return size;
        }

        /*
        return the capacity of the hashtable 
        */
        int getCapacity() const {
            return capacity;
        }

    private:
        int size {0}; // to keep track how big the array is
        int capacity {2};
        vector<std::optional<Pair>> hashmap{};

        int getHash(std::string key){
            int index = 0;
            for (char k: key){
                index += (int)k;
            }
            return index % capacity;
        }

        int getHash(int key){
            return key % capacity;
        }

        void rehash(){
            capacity = 2 * capacity;
            vector<std::optional<Pair>> newHashmap{};
            newHashmap.resize(capacity);

            auto oldmap = hashmap;
            hashmap = newHashmap;
            size = 0;
            for (auto p: oldmap){
                if (p){
                    insert(p->key,p->value);
                }
            }
        }
};

int main(){
    HashTable ht(4);
    ht.insert(1,2);
    
    std::cout << "Get 1: " << ht.get(1) << std::endl;

    ht.insert(1,3);

    std::cout << "Get 1: " << ht.get(1) << std::endl;

    std::cout << "Remove 1: " << ht.remove(1) << std::endl; 

    std::cout << "Get 1: " << ht.get(1) << std::endl;
}