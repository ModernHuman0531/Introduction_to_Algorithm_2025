#include<bits/stdc++.h>
using namespace std;
class vertex{
    public:
        string status; // unvisit or visited
        int dist;
        vertex(){
            status="unvisit";
        }
};
vector<list<int>> G;
vector<vertex> vertices;
void addEdge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
void DFS(int v,int dist){
    // Mark vertex's distance as dist
    vertices[v].dist=dist;
    vertices[v].status="visited";
    for(int n:G[v]){
        if(vertices[n].status=="unvisit"){
            DFS(n,dist+1);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int N;
    cin>>N;
    G.resize(N+1);
    // Next N-1 line describe the relationship between vertices
    for(int i=0;i<N-1;++i){
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }
    // Input the verticers from 1 to N
    for(int i=0;i<=N;++i){
        vertices.push_back(vertex());
    }
    // Randomally choose start vertex to do DFS, i always choose vertex 1
    DFS(1,0);
    // Find the largest distance vertex as the new start point of new dfs
    int maxdist_vertex;
    int max_dist=0;
    for(int i=1;i<=N;++i){
        if(vertices[i].dist>max_dist&&vertices[i].status=="visited"){
            max_dist=vertices[i].dist;
            maxdist_vertex=i;
        }
        vertices[i].dist=0;
        vertices[i].status="unvisit";
    }
    max_dist=0;
    DFS(maxdist_vertex,0);
    for(int i=1;i<=N;++i){
        if(vertices[i].dist>max_dist&&vertices[i].status=="visited"){
            max_dist=vertices[i].dist;
            maxdist_vertex=i;
        }
    }
    cout<<max_dist<<"\n";
    return 0;
}