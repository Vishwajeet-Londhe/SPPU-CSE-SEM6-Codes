#include<iostream>
#include<list>
#include<map>
#include<queue>

using namespace std;

class Graph{
    public:

    map<int, list<int>> adjList;
    map<int, bool> visited;
    queue<int> q;
    
    //Copy Constructor
    // Graph(const Graph &g){
    // }
    
    void addEdge(int src, int dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void DFS(int node){
        //Mark Node as visited
        visited[node] = true;
        //Print Node
        cout << node << " ";
        //Vist its neighbours and recurse
        for(int i : adjList[node]){
            //If node is not visited
            if(!visited[i]) DFS(i);
        }
    }

    void BFS(){
        //Recurse until queue is empty
        if(q.empty()) return;
        //Pop and assign 1st node in queue
        int node = q.front();
        q.pop();
        //Print node
        cout << node << " ";
        for(int i : adjList[node]){
            //If neighbour is not visited add it to queue
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
        BFS();
    }
};



int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,6);
    
    int ch;
    cout << "Enter 0 to perform DFS and 1 to perform BFS: ";
    cin >> ch;
    if(!ch){
        cout << "DFS on the given graph is :";
        g.DFS(0);
    }
    else{
        cout << "BFS on the given graph is: ";
        g.q.push(0);
        g.visited[0] = true;
        g.BFS();    
    }
    return 0;
}