/*
    Trie helps in organizing words based on the first few characters (prefixes) 
    As evident from its name, it is  a tree data structure 
    commonly used in auto search applications 
*/

#include <iostream> 
#include <string> 
#include <unordered_map>

using namespace std;

class TrieNode {
  public:
    unordered_map<char, TrieNode*> children;
    bool is_word = false;
};

class PrefixTree {
  public:
    TrieNode root;

    PrefixTree() {
        root = TrieNode();
    }
    
    void insert(string word) {
      TrieNode *current = &root; 
      
      for (char c: word){  
        if (current->children.count(c) == 0) {
          current->children[c] = new TrieNode();
        }
        current = current->children[c];
      }
      current->is_word  = true;
    }
    
    bool search(string word) {
      TrieNode *current = &root;

      for (char c: word){
        if (current->children.count(c) == 0){
          return false;
        }
        current = current->children[c];
      }

      return current->is_word;
    }
    
    bool startsWith(string prefix) { 
      TrieNode *current = &root;

      for (char c: prefix){
        if (current->children.count(c) == 0){
          return false;
        }
        current = current->children[c];
      }

      return true;
    }
};

int main(void){
    PrefixTree *prefixTree = new PrefixTree();
    prefixTree->insert("dog");
    if(prefixTree->search("dog")){
        cout << "dog is found" << endl;
    }
    if(prefixTree->search("do")){
        cout << "do is found" << endl;
    }
    else{
        cout << "do is not found" << endl;
    }
        
    if(prefixTree->startsWith("do")){
        cout << "do is found" << endl;
    }
    else{
        cout << "do is not found" << endl;
    }
        
    prefixTree->insert("do");
    if(prefixTree->search("do")){
        cout << "do is found" << endl;
    } 
  
    return 0;
}
