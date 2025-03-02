#include <iostream>
// my custom doubly linked list implementation
class CustomLinkedList{
    public:
        CustomLinkedList(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        int get(int index){
            if (index < 0 || index >= size){
                return -1;
            }
            // get the pointer to the head
            Node* current = head;
            // traverse the list until the index
            for (int i = 0; i < index; i++){
                current = current->next;
            }
            return current->val;
        }
        void addAtHead(int val){
            Node* newNode = new Node(val, nullptr, nullptr);
            // if the list is empty, the new node is both the head and tail
            if (head == nullptr){
                head = newNode;
                tail = newNode;
            }
            // if the list is not empty, the new node is the head
            else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            size++;
        }
        void addAtTail(int val){
            Node* newNode = new Node(val, nullptr, nullptr);
            // if the list is empty, the new node is both the head and tail
            if (tail == nullptr){
                tail = newNode;
                head = newNode;
            }
            // if the list is not empty, the new node is the tail
            else{
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        }
        void addAtIndex(int index, int val){
            // if the index is out of bounds, return
            if (index < 0 || index > size){
                return;
            }
            // if the index is the size of the list, add the node to the tail
            if (index == size){
                addAtTail(val);
                return;
            }
            // if the index is 0, add the node to the head
            if (index == 0){
                addAtHead(val);
                return;
            }
            Node* newNode = new Node(val, nullptr, nullptr);
            Node* current = head;
            for (int i = 0; i < index; i++){
                current = current->next;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
            size++;
        }
        void deleteAtIndex(int index){
            if (index < 0 || index >= size){
                return;
            }
            Node* current = head;
            for (int i =0 ; i < index; i++){
                current = current->next;
            }
            // if the node to delete is the head
            if (current == head){
                head = current->next;
                if (head != nullptr){
                    head->prev = nullptr;
                }
            }
            // if the node to delete is the tail
            else if (current == tail){
                tail = current->prev;
                if (tail != nullptr){
                    tail->next = nullptr;
                }
            }
            // if the node to delete is in the middle of the list
            else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            size--;
        }
        void printList(){
            Node* current = head;
            while (current != nullptr){
                std::cout << current->val << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    private:
        struct Node{
            int val;
            Node* next;
            Node* prev;

            Node(int val, Node* next, Node* prev) : val(val), next(next), prev(prev){}
        };
        Node* head;
        Node* tail;
        int size;
};

int main(){
    CustomLinkedList list;
    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2);
    list.printList();
    list.deleteAtIndex(1);
    list.printList();
    list.addAtHead(6);
    list.addAtTail(4);
    list.addAtIndex(2, 5);
    list.printList();
    list.deleteAtIndex(5);
    list.printList();
    return 0;
}