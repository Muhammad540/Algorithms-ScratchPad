#include <functional>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class NetworkDelayTime {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            // int refers to the node
            // vector of pair(int,int) are its neighbors/adjacent nodes
            // first int is the target, second is its time
            unordered_map<int, vector<pair<int, int>>> graph;
            for (int i=1; i <= n; i++){
                graph[i] = vector<pair<int, int>>();
            }
            
            // complete the adjacency list
            for (const auto& time : times){
                int src = time[0], dest = time[1], cost = time[2];
                graph[src].push_back(make_pair(dest,cost));
            }

            unordered_map<int, int> shortest;
            // in the min heap each element is a pair of int (node_identity, cost to reach)
            // pq(data type, container, comparator(by default it resoirts to max heap))
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
            // node identity with the associated cost
            // Min heap: pair<cost, node> - cost first for proper comparison
            minHeap.push(make_pair(0,k));
            while (!minHeap.empty()){
                // get the minimum val
                pair<int, int> min_cost_node = minHeap.top();
                minHeap.pop();
                int cost1 = min_cost_node.first, node1 = min_cost_node.second;

                // due to greedy nature we only add the minimum cost to the node
                /*
                Once we've found a path to a node, any future path must go 
                through other nodes that haven't been processed yet, which means longer distances 
                Skip if we've already found shortest path to this node*/
                if (shortest.count(node1) > 0){
                    continue;
                }
                // if node's min cost not present add it
                shortest[node1] = cost1;
                // add rest of the neighbors to the list 
                for(auto &adj: graph.at(node1)){
                    int node2 = adj.first, cost2 = adj.second;
                    if (shortest.count(node2) == 0){
                        minHeap.push({cost1+cost2, node2});
                    }
                }
            }
            // check to see if all nodes are reachable 
            if (shortest.size() != n){
                return -1;
            }
            // find the maximum time among all nodes (it is the minimum possible time to deliever all messages to the nodes on the network)
            int maxTime = 0;
            for (auto &p: shortest){
                maxTime = max(maxTime, p.second);
            }

            return maxTime;
        }
};

int main(){
    vector<vector<int>> test_time1 = {{1,2,1},{2,3,1},{1,4,4},{3,4,1}};
    int n = 4;
    int k = 1;
    vector<vector<int>> test_time2 = {{1,2,1},{2,3,1}};
    int n2 = 3;
    int k2 = 2;
    NetworkDelayTime networkDelayTime;
    int result1 = networkDelayTime.networkDelayTime(test_time1, n, k);
    int result2 = networkDelayTime.networkDelayTime(test_time2, n2, k2);
    cout << result1 << endl;
    cout << result2 << endl;

    return 0;
}
