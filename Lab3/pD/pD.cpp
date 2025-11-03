#include<bits/stdc++.h>
using namespace std;
int N,M;

class Vertex{
    public:
        int a_i;
        list<int> li;
        bool is_visited;
        Vertex(){
            is_visited=false;
        }
};

vector<Vertex> adj;
long long BFS(int start_vertex){
    long long total_award=0;
    queue<int> q;
    total_award+=adj[start_vertex].a_i;
    adj[start_vertex].is_visited=true;
    q.push(start_vertex);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto u:adj[v].li){
            if(!adj[u].is_visited){
                adj[u].is_visited=true;
                total_award+=adj[u].a_i;
                q.push(u);
            }
        }
    }
    // Clean the visited
    for(auto &v:adj){
        v.is_visited=false;
    }
    return total_award;
}
void solve(){
    long long max_award=0;
    for(int i=1;i<=N;++i){
        max_award=max(max_award,BFS(i));
    }
    cout<<max_award<<"\n";
    return;
}

void addEdge(int vi,int ui){
    adj[vi].li.push_back(ui);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>N>>M;
    adj.resize(N+1);
    // Handle vertex award input
    for(int i=1;i<=N;++i){
        int ai;
        cin>>ai;
        adj[i].a_i=ai;
    }

    // Handle directed edwge
    for(int i=0;i<M;++i){
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }
    solve();
    return 0;


}