#include <iostream> 


// following struct defined the structure of a single node in the tree 
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}   
    ~TreeNode(){
        delete left;
        delete right;
    }
};

TreeNode* findMinNode(TreeNode* root){
    TreeNode* curr_root = root;
    while (curr_root && curr_root->left){ // why left ? because the  most left position in the BST has the minimum value of any sub tree
        curr_root = curr_root->left;
    }
    return curr_root;
}

TreeNode* deleteNode(TreeNode* root, int val){
    if (!root){
        return nullptr;
    }

    if (val > root->val){
        root->right = deleteNode(root->right, val);
    } else if ( val < root-> val){
        root->left = deleteNode(root->left, val);
    } else { // this is the value 
        // check for case 1 where the root node has 1 or 0 children
        if (!root->left){
            return root->right;
        } else if (!root->right){
            return root->left;
        } else { // case 2 check where the root has more than 1 children ( so we will find the minimum in the right subtree)
            TreeNode* minNode = findMinNode(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
    }
    return root;
}

void printInorder(TreeNode* root){
    if (!root) return;
    printInorder(root->left);
    std::cout << root->val << " ";
    printInorder(root->right);
}

int main(void){
    //       5
    //      / \
    //     3   7
    //    / \   \
    //   2   4   8
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    std::cout << "Original BST (inorder): ";
    printInorder(root);
    std::cout << std::endl;
    
    std::cout << "\nAfter deleting 2 (leaf node): ";
    root = deleteNode(root, 2);
    printInorder(root);
    std::cout << std::endl;

    std::cout << "After deleting 7 (one child): ";
    root = deleteNode(root, 7);
    printInorder(root);
    std::cout << std::endl;

    std::cout << "After deleting 3 (two children): ";
    root = deleteNode(root, 3);
    printInorder(root);
    std::cout << std::endl;

    std::cout << "After deleting 5 (root node): ";
    root = deleteNode(root, 5);
    printInorder(root);
    std::cout << std::endl;

    std::cout << "After trying to delete 10 (non-existent): ";
    root = deleteNode(root, 10);
    printInorder(root);
    std::cout << std::endl;

    delete root;    
    return 0;
}