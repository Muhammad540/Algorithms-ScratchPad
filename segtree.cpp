/*
    [    ]
     L  R
get sum of values btw range [L-R]
time: Olog(n)
space:Olog(n)

break up the array by a factor of 2
each node will contain the range sum for its 'range'
*/
#include <vector> 
#include <iostream> 

using namespace std;

class Segtree {
    private:
        int sum_ {};
        Segtree *left_;
        Segtree *right_;
        int left_bound_;
        int right_bound_;
    
    public:
        Segtree(int sum, int lb, int rb): sum_(sum), left_bound_(lb), right_bound_(rb){
            left_ = nullptr;
            right_ = nullptr;
        }
    
    // build the seg tree with the seg nodes 
    static Segtree* build(vector<int> &nums, int lb, int rb){
        if (lb == rb){
            return new Segtree(nums[lb], lb, rb);
        }

        int M = (lb + rb) / 2;
        Segtree *root  = new Segtree(0, lb, rb);
        root->left_    = Segtree::build(nums, lb, M);
        root->right_   = Segtree::build(nums, M+1, rb);
        root->sum_     = root->left_->sum_ + root->right_->sum_;
        return root;
    }

    // update a node in the seg tree
    void update(int idx, int val) {
        if (left_bound_ == right_bound_){
            sum_ = val;
            return;
        }

        int M = (left_bound_ + right_bound_) / 2;
        if (idx > M){
            right_->update(idx, val);
        } else {
            left_->update(idx, val);
        }
        sum_ = left_->sum_ + right_->sum_;
    }

    // perform range query 
    int rangeQuery(int ll, int rl) {
        if (ll == left_bound_ && rl == right_bound_) {
            return sum_;
        }

        int M = (left_bound_ + right_bound_) / 2;
        if (ll > M){
            return right_->rangeQuery(ll, rl);
        } else if (rl <= M){
            return left_->rangeQuery(ll, rl);
        } else {
            return left_->rangeQuery(ll, M) + right_->rangeQuery(M+1, rl);
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Segtree *root = Segtree::build(nums, 0, nums.size() - 1);
    cout << root->rangeQuery(0, 4) << endl;
    root->update(2, 10);
    cout << root->rangeQuery(0, 4) << endl;
    return 0;
}