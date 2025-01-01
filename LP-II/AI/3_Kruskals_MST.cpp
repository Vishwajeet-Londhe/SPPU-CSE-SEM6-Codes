/*
Afnan Attar
F19112003
*/

#include<bits/stdc++.h>
using namespace std;

struct node{
    int parent;
    int rank;
};

struct edge{
    int src;
    int dest;
    int wt;
};

vector<node> dsuf;
vector<edge> mst;

bool comparator(edge a, edge b){
    return a.wt < b.wt;
}

int find(int v){
    if (dsuf[v].parent == -1){
        return v;
    }
    return dsuf[v].parent = find(dsuf[v].parent);
}

void union_op(int fromP, int toP){
    if(dsuf[fromP].rank > dsuf[toP].rank){
        dsuf[toP].parent = fromP;
        dsuf[fromP].rank++;
    }
    else if(dsuf[fromP].rank < dsuf[toP].rank){
        dsuf[fromP].parent = toP;
        dsuf[toP].rank++;
    }
    else{
        dsuf[fromP].parent = toP;
        dsuf[toP].rank++;
    }
}

void Kruskals(vector<edge>& edge_list, int V, int E){
    sort(edge_list.begin(), edge_list.end(), comparator);
    int i = 0, j = 0;
    while(i < (V - 1) && j < E){
        int fromP = find(edge_list[j].src);
        int toP = find(edge_list[j].dest);
        if(fromP == toP){
            j++;
            continue;
        }
        union_op(fromP, toP);
        mst.push_back(edge_list[j]);
        i++;
    }
}

void printMST(vector<edge> MST){
    for(auto edge : MST){
        cout << '\n'
             << "src : " << edge.src << '\n'
             << "dest : " << edge.dest << '\n'
             << "wt : " << edge.wt << '\n'
             << '\n';
    }
}

int main(){
    int E; // number of edges
    int V; // number of vertices
    cout << "Enter the number of edges and vertices: ";
    cin >> E >> V;
    dsuf.resize(V);
    for(int i = 0; i < V; i++){
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }
    vector<edge> edge_list;
    edge temp;
    
    for(int i = 0; i < E; i++){
        int s,d,w;
        cin >> s >> d >> w;
        temp.wt = w;
        temp.dest = d;
        temp.src = s;
        edge_list.push_back(temp);
    }

    Kruskals(edge_list, V, E);
    printMST(mst);

    return 0;


}

/* OUTPUT:
Enter the number of edges and vertices: 14 9
0 1 4
0 7 8
7 1 11
1 2 8
7 8 7
7 6 1
2 3 7
2 8 2
2 5 4
8 6 6
6 5 2
5 3 14
5 4 10
3 4 9

src : 7
dest : 6
wt : 1


src : 2
dest : 8
wt : 2


src : 6
dest : 5
wt : 2


src : 0
dest : 1
wt : 4


src : 2
dest : 5
wt : 4


src : 2
dest : 3
wt : 7


src : 0
dest : 7
wt : 8


src : 3
dest : 4
wt : 9

*/

