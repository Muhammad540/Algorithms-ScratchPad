// cond: acyclic, directed graph
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
// Input: numCourses = 6, prerequisites = [[2,1],[3,2],[4,2],[5,3]]
// 1->2->3->5
//     ->4
// [5,3,4,2,1] -> [1,2,4,3,5]
class TopoSort {
    public:
        bool dfs(int src, std::unordered_map<int, vector<int>>&adj, 
            std::unordered_set<int>& visit, std::vector<int>& topSort, std::unordered_set<int>& path){
                // path is used to identify cycles
                if (path.count(src)>0){
                    return false;
                }
                if (visit.count(src)>0){
                    return true;
                }
                path.insert(src);
                visit.insert(src);

                for (int neigh: adj[src]){
                    if(!dfs(neigh, adj, visit, topSort, path)){
                        return false; // we cant take that course
                    }
                }
                topSort.push_back(src);
                path.erase(src);
                return true;
            }

        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            std::unordered_map<int, std::vector<int>> adj;
            for (int i=0; i<numCourses; i++){
                adj[i] = std::vector<int>();
            }
            for (std::vector<int> edge: prerequisites) {
                int n1 = edge[0], n2 = edge[1];
                // reverse order since the pre req is @ second position
                adj[n2].push_back(n1);
            }
            std::vector<int> topologicalSort;
            std::unordered_set<int> visit;
            std::unordered_set<int> path;
            for (int i=0; i<numCourses; i++){
                if (!dfs(i, adj, visit, topologicalSort, path)){
                    return false;
                }
            }
            return true;;
            // std::reverse(topologicalSort.begin(),topologicalSort.end());
            // if (topologicalSort.size()==numCourses-1){
            //     return true;
            // } else{
            //     return false;
            // }
        }
};

int main(){
    int numCourses = 2;
    std::vector<std::vector<int>> prerequisites = {{0,1},{1,0}};
    TopoSort tsort;
    std::cout << tsort.canFinish(numCourses, prerequisites) << std::endl;
    return 0;
}