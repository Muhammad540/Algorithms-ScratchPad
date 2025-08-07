#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <utility> // for std::pair 
#include <functional> // for std::greater
#include <tuple> 
#include <queue>

using namespace std;

class prims {
    public:
        int minimumSpanningTree(vector<vector<int>>& edges, int n) {
            int sum = 0;
            std::vector<std::pair<int,int>> minspantree = mst(edges, n, &sum);
            return sum;
        }

        std::vector<std::pair<int,int>> mst(vector<vector<int>>& edges, int n, int* sum){
            std::unordered_map<int, std::vector<std::pair<int,int>>> adj;
            for (int i=0;i<n;i++){
                adj[i] = std::vector<std::pair<int,int>>();
            }
            for (std::vector<int>& edge: edges){
                int n1=edge[0], n2=edge[1], weight=edge[2];
                adj[n1].push_back(std::make_pair(n2,weight));  
                adj[n2].push_back(std::make_pair(n1,weight));
            }
            priority_queue<std::tuple<int,int,int>, std::vector<std::tuple<int,int,int>>, std::greater<std::tuple<int,int,int>>> minheap; 
            for (std::pair<int,int> &neighbor: adj[0]){
                int weight = neighbor.second, node = neighbor.first;
                minheap.push({weight, 0, node});
            }

            std::vector<std::pair<int,int>> mst;
            std::unordered_set<int> visit;
            visit.insert(0);
            while(visit.size()<n && !minheap.empty()){
                std::tuple<int,int,int> curr = minheap.top();
                minheap.pop();
                int w1 = std::get<0>(curr), n1 = std::get<1>(curr), n2 = std::get<2>(curr);

                if (visit.count(n2) > 0){
                    continue;
                }

                mst.push_back({n1,n2});
                *sum += w1;
                visit.insert(n2);

                for (std::pair<int,int> pair: adj[n2]){
                    int neighbor= pair.first, weight = pair.second;
                    if (visit.count(neighbor) == 0){
                        minheap.push({weight,n2,neighbor});
                    }
                }
            }
            if (visit.size() != n){
                *sum = -1;
            }
            return mst;
        }
};

int main(){
    int n = 5;
    vector<vector<int>> edges = {{0,1,10}, {0,2,3}, {1,3,2}, {2,1,4}, {2,3,8}, {2,4,2}, {3,4,5}};
    prims solver;
    std::cout << "Total weight of the MST: " << solver.minimumSpanningTree(edges,n) << std::endl;

    return 0;
}