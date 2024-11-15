#include<bits/stdc++.h>
#include<list>
using namespace std;

vector<list<int>> graph;
unordered_set<int>visited;
vector<vector<int>>result;
int v; // no of vertices
void add_edge(int src , int dest , bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void bfs(int src , int dest , vector<int>&dist){
    queue<int>q;
    visited.clear();
    dist.resize(v,INT_MAX);
    dist[src] = 0;
    q.push(src);
    while(not q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neigh : graph[curr]){
            if(not visited.count(neigh)){
                q.push(neigh);
                visited.insert(neigh);
                dist[neigh] = dist[curr] + 1;
            }
        }
    }
    cout<<"\n";
}

int main(){
    cin>>v;
    graph.resize(v,list<int>());
    visited.clear();
    int e;
    cin>>e;
    while(e--){
        int s , d;
        cin>>s>>d;
        add_edge(s,d);
    }
    int x , y;
    cin>>x>>y;
    vector<int>dist;
    bfs(x, y , dist);
    for(int i = 0 ; i < dist.size() ; i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}