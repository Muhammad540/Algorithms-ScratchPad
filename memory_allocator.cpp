#include <iostream>
#include <vector>

class CustomObject{
    public:
      CustomObject(int id): m_id(id){
        std::cout << "CustomObject constructor called for ID " << m_id << std::endl; 
      }
      
      ~CustomObject(){
        std::cout << "CustomObject destructor called for ID " << m_id << std::endl; 
      }

      void print(){
        std::cout << " CustomObject at address " << this << " with id " << m_id << std::endl; 
      }

    private:
      int m_id;
};

struct FreeBlock{
  FreeBlock* next;
};

class MemoryPool{
    public:
        MemoryPool(size_t object_count): m_object_count(object_count) {
            const size_t block_size = std::max(sizeof(CustomObject), sizeof(FreeBlock));
            m_pool_start = new char[block_size*m_object_count];
            m_free_list = nullptr;
            // say 100 CustomObjects 
            // size of single block is 10 
            //
            // pool_start = addr1
            // free_list  = null 
            // free_block_1 = [addr1 + 0* 10]
            // free_block_1->next = free_list
            // free_list  = free_block_1 
            // 
            // free_block_2 = [addr1 + 10]
            // free_block_2->next = free_block_1
            // free_list = free_block_2
            //
            // free_block_3 = [addr + 20]
            // free_block_3->next = free_block_2
            // free_list = free_block_3 
            //
            // so we get smthlik: NULL <- [f1] <- [f2] <- [f3] 
            for (size_t i = 0; i < m_object_count; i++){
                FreeBlock* block = reinterpret_cast<FreeBlock*>(m_pool_start + i * block_size);
                block->next = m_free_list;
                m_free_list = block;
            }

            std::cout << "MemoryPool created. Pre-allocated " << m_object_count * block_size << "bytes." << std::endl;
        }

        ~MemoryPool(){
          std::cout << "MemoryPool destroyed. Freeing entire memory block." << std::endl;
          delete[] m_pool_start;
        }
        
        void* allocate(){
            if (m_free_list == nullptr){
              std::cout << "Error: memory pool is full" << std::endl;
              return nullptr;
            }
            void* allocated_block = m_free_list;
            m_free_list = m_free_list->next;
            std::cout << " Allocated block at " << allocated_block << std::endl;
            return allocated_block;
        }

        void deallocate(void* ptr){
          if (ptr == nullptr){
            return ;
          }
          std::cout << "Deallocating block at " << ptr << std::endl;
          FreeBlock* received_block = reinterpret_cast<FreeBlock*>(ptr);
          received_block->next = m_free_list;
          m_free_list = received_block;
        }

    private:
        size_t m_object_count;
        char* m_pool_start;
        FreeBlock* m_free_list;
};

int main(){
  int count = 5;
  MemoryPool pool(count);
  std::vector<CustomObject*> objects; 
  std::cout << "\n -- Allocating objects from the pool --" << std::endl;
  for (int i=0; i < count; i++){
      void *memory = pool.allocate();
      if (memory){
          objects.push_back(new (memory) CustomObject(i));
      }
  }
  std::cout << "\n-- Deallocating some objects --" << std::endl;
  objects[2]->~CustomObject();
  pool.deallocate(objects[2]);
  objects[3]->~CustomObject();
  pool.deallocate(objects[3]);
  // to re-adjust 
  objects.erase(objects.begin() + 2, objects.begin()+4);
  std::cout << "\n-- Allocating new objects (should reuse old memory) --" << std::endl;
  void* memory = pool.allocate();
  if (memory){
    objects.push_back(new (memory) CustomObject(100));
  }
  memory = pool.allocate();
  if (memory){
    objects.push_back(new (memory) CustomObject(101));
  }
  
  std::cout << "\n-- Final state of objects --" << std::endl;
  for (const auto& obj: objects){
    obj->print();
  }

  std::cout << "\n --Calling destructors for remaining objects --" << std::endl;
  for (const auto& obj: objects){
    obj->~CustomObject();
  }

  std::cout << "\n End of main function. The pool will be destroyed." << std::endl;
  return 0;
}

