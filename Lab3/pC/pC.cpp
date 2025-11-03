#include <bits/stdc++.h>
using namespace std;
int n,m,k;
class Edge{
    public:
        int vi,wi,ti;
        Edge(int _vi,int _wi,int _ti):vi{_vi},wi{_wi},ti{_ti}{}
};
vector<list<Edge>> adj;
void addEdge(int ui,int vi,int wi,int ti){
    adj[ui].push_back(Edge(vi,wi,ti));
    adj[vi].push_back(Edge(ui,wi,ti));
}

long long wait_time(long long current_time,int ti,int wi){
    if(ti==-1){
        return 0;
    }
    int current_mod=current_time%k;
    int start=(ti-wi+1+k)%k;
    int finish=ti;
    bool in_range=false;
    if(ti==-1){
        return 0;
    }
    if(start<=finish)
        in_range=(start<=current_mod&&current_mod<=finish);
    else
        in_range=(start<=current_mod||current_mod<=finish);
    if(!in_range)
        return 0;
    else
        return (ti+1-current_mod+k)%k;
}

void Dijkstra(){
    const long long inf=LLONG_MAX/4;
    // Create container for Q and dist
    vector<long long> dist(n+1,inf);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
    // Initialize the distance
    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        auto [current_time,v]=pq.top();
        pq.pop();

        if(v==n){
            cout<<dist[n]<<"\n";
            return;
        }

        for(auto [u,w,t]:adj[v]){
            // Check if the road time is larger than the wait period
            if(w>=k&&t!=-1) continue;
            long long wait=wait_time(current_time,t,w);
            long long arrival_time=current_time+wait+w;
            if(dist[u]>arrival_time){
                dist[u]=arrival_time;
                pq.push({arrival_time,u});
            }
        }
    }
    cout<<-1<<"\n";
    return;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>n>>m>>k;
    adj.resize(n+1);
    // Handle input
    for(int i=0;i<m;++i){
        int ui,vi,wi,ti;
        cin>>ui>>vi>>wi>>ti;
        addEdge(ui,vi,wi,ti);
    }
    Dijkstra();
    return 0;
    
}