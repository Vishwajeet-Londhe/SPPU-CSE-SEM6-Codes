#include<iostream>
#include<map>   
#include<list>
#include<queue>

using namespace std;


// Implement depth first search algorithm and Breadth First Search algorithm, Use an undirected graph and develop a recursive algorithm for searching all the vertices of a graph or tree data structure.

template <typename T>
class Graph{
    // Adjacency List
    map<T, list<T>> adjList;

    public:
        // Add Edge
        void addEdge(T src, T dest){
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }

        void bfs(queue<T>& q, map<T, bool>& visited){
            if(q.empty()) return;
            T node = q.front();
            q.pop();
            cout << node << " ";
            for(T n : adjList[node]){
                if(!visited[n]){
                    q.push(n);
                    visited[n] = true;
                }
            }

            bfs(q, visited);
        }

        void dfs(T v, map<T, bool>& visited){
            visited[v] = true;
            cout << v << " ";
            for(T n: adjList[v]){
                if(!visited[n]){
                    dfs(n, visited);
                }
            }
        }
};


int main(){
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    queue<int> q;
    map<int, bool> visited;
    
    int ch;
    cout << "Enter 1 for BFS, 2 for DFS:";
    cin >> ch;

    for(int i = 0; i < 6; i++){
        visited[i] = false;
    }
    
    if(ch == 1){
        for(int i = 0; i < 6; i++){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                g.bfs(q, visited);
            }
        }
    cout << '\n';
    }
    else{
        for(int i = 0; i < 6; i++){
            if(!visited[i]){
                g.dfs(i, visited);
            }
        }
    }
    return 0;
}
