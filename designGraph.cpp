// my simplistic design for a directed graph 
/*
 * Graph class must have the following features:
 * constructor: sets up an empty directed graph 
 * 
 * - add edge given the source and destination 
 * - remove edge between a source and destination if an edge exists. tell the user if an edge existed or not. 
 * - inform whether a path exists from the source to destination (assumption is both the src and dest exist in the graph) 
 *
 *   some constraints:
 *   - each vertex has a unique integer val 
 *   - a vertex cannot have an edge to itself (cycles are allowed) 
 *   - graph is not connected (there can be disconnected components)
*/

#include <iostream> 
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
    public:
        Graph(){}

        void addEdge(int src, int dst) {
            if (src == dst) {
                return;
            }
            // check if src and dst already exists, if not add them and create an edge between 
            // adding the two nodes is diff from having an edge btw them 
            if (adjlist.find(src) == adjlist.end()){
                adjlist[src] = {};
            }
            if (adjlist.find(dst) == adjlist.end()){
                adjlist[dst] = {};
            }
            // add the edge
            auto it = std::find(adjlist[src].begin(),adjlist[src].end(),dst);
            if (it == adjlist[src].end()){
                // so dst is not already attached to the src so add an edge
                adjlist[src].push_back(dst);
            }
        }
        
        bool removeEdge(int src, int dst) {
            if (adjlist.find(src) == adjlist.end() || adjlist.find(dst) == adjlist.end()) {
                return false;
            }
            for (auto it = adjlist[src].begin(); it != adjlist[src].end(); ++it){
                if (*it == dst){
                    adjlist[src].erase(it);
                    return true;
                }
            }
            return false; // edge not found 
        }

        bool hasPath(int src, int dst) {
            // if the src or dst node doesnot exist, return false  
            if (adjlist.find(src) == adjlist.end() || adjlist.find(dst) == adjlist.end()) {
                return false;
            }
       
            std::vector<int> visited {};

            return dfs(src,dst, visited);
        }

    private:
        // each node in the graph has a value and a list of nbhr 
        std::unordered_map<int,list<int>> adjlist{};
        
        bool dfs(int src, int dst, std::vector<int> &visited){
            // base case 1 
            if (src==dst){
                return true;
            }
            // base case 2: src matches dest directly (has a direct connection)  
            if (std::find(adjlist[src].begin(),adjlist[src].end(),dst) != adjlist[src].end()) {
                return true;
            }
            // base case 3: the node is already visited 
            if (std::find(visited.begin(),visited.end(),src) != visited.end()) {
                return false;
            } 

            visited.push_back(src); 
            
            for (auto it = adjlist[src].begin(); it != adjlist[src].end(); ++it){
                if (dfs(*it, dst, visited)){
                    return true;
                }
            }
            
            return false;
        }

};

int main(){
  Graph g;
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(3,1);

  cout << g.hasPath(1,3) << "\n"; // 1
  cout << g.hasPath(3,1) << "\n"; // 1

  g.removeEdge(1,2);
  cout << g.hasPath(1,3) << "\n"; // 0

  return 0;
}

