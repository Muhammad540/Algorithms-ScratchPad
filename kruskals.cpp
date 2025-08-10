#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class UnionFind {
    std::vector<int> parent;
    std::vector<int> size;
    public:
        UnionFind(int n){
            parent.resize(n);
            for (int i=0; i<n; i++){
                parent[i] = i;
            }

            size.resize(n,1);
        }

        int find(int i){
            int root = parent[i];
            if (parent[root] != root){
                return parent[i] = find(root);
            }

            return root;
        }

        bool unite(int i, int j){
            int irep = find(i);
            int jrep = find(j);

            if (irep == jrep){
                return false;
            }

            int isize = size[irep];
            int jsize = size[jrep];

            if (isize < jsize){
                parent[irep] = jrep;
                size[jrep] += size[irep];
            } else {
                parent[jrep] = irep;
                size[irep] += size[jrep];
            }

            return true;
        }
};

int mst(vector<vector<int>> &edges, int n){

    std::sort(edges.begin(), edges.end(), [](const vector<int>& a,const vector<int>& b){
        return a[2] < b[2];
    });


    UnionFind uf(n);
    int total_weight{0};
    int edgesUsed{0};
    std::vector<std::pair<int,int>> mst;

    for(auto &edge: edges){
        int n1 = edge[0], n2 = edge[1], w = edge[2];

        if (uf.unite(n1,n2)){
            total_weight += w;
            mst.push_back({n1,n2});
            edgesUsed++;

            if (edgesUsed == n-1){
                break;
            }
        }
    }
    return (edgesUsed == n-1) ? total_weight: -1;
}

int main(){
    int n = 5;
    vector<vector<int>> edges = {{0,1,10}, {0,2,3}, {1,3,2}, {2,1,4}, {2,3,8}, {2,4,2}, {3,4,5}};
    std::cout << "Total weight of the MST: " << mst(edges,n) << std::endl;

    return 0;
}