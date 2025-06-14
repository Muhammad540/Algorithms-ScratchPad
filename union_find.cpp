// Union find is useful if you want to group a set of items into disjoint non-overlapping sets. 
// given ? connected undirected graph with n nodes 
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class UnionFind {
  public:
      std::unordered_map<int, int> par;
      std::unordered_map<int, int> rank;
      int n{};
      vector<int> result; 
      
      void initialize(int n) {
        for (int i=1; i<n; i++){
           par[i] = i; // every vertex is its own parent initially
          rank[i] = 0;
        }
      }
      
      int find(int x){
        if (x != par[x]) {
          par[x] = find(par[x]);
        }

        return par[x];
      }
      
      // decides if a union can be performed or not 
      bool union_sets(int n1, int n2){
        int p1 = find(n1);
        int p2 = find(n2);
        if (p1 == p2){
          return false;
        }

        if (rank[p1] > rank[p2]){
          par[p2] = p1;
        } else if (rank[p1] < rank[p2]){
          par[p1] = p2;
        } else {
          par[p1] = p2;
          rank[p2] += 1;
        }

        return true;
      }

      vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        initialize(n+1);

        for (auto vec: edges){
          int n1 = vec[0];
          int n2 = vec[1];
          
          if (!union_sets(n1,n2)){
            result = {n1,n2};
          }
        }
        
        return result;
      }
};

int main(void) {
    vector<vector<int>> edges{{1,2},{1,3},{1,4},{3,4},{4,5}};
    
    UnionFind uf;  // Create instance
    vector<int> res = uf.findRedundantConnection(edges);  // Call on instance
    
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i];
        if (i < res.size() - 1) std::cout << ",";
    }
    std::cout << std::endl;
    
    return 0;
}
