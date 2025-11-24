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
const int MAXN=200005;
long long dp[MAXN];
vector<int> topoOrder;

void DFS(int u){
    adj[u].is_visited=true;
    for(auto v:adj[u].li){
        if(!adj[v].is_visited){
            DFS(v);
        }
    }
    topoOrder.push_back(u);
}

void addEdge(int vi,int ui){
    adj[vi].li.push_back(ui);
}

int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>N>>M;
    adj.resize(N+1);
    // 【修正點：刪除不必要的 resize，讓 vector 動態增長】
    // topoOrder.resize(N+1); 
    
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

    for(int i=1;i<=N;++i){
        if(!adj[i].is_visited){
            DFS(i);
        }
    }

    long long ans=0;
    //reverse(topoOrder.begin(),topoOrder.end());
    for(int v:topoOrder){
        // DP 邏輯 (已確認正確 for DAG):
        dp[v]=adj[v].a_i;
        long long max_successor_dp=0;
        for(int u:adj[v].li){
            max_successor_dp=max(max_successor_dp,dp[u]);
        }
        dp[v]+=max_successor_dp;
        ans=max(ans,dp[v]);
    }
    cout<<ans<<"\n";
    return 0;
}