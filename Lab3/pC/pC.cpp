#include<bits/stdc++.h>
using namespace std;
int n,m,k;
#define NUM_MAX 200001
class roadinfo{
    public:
        int wi,ti;
        roadinfo(int _wi,int _ti):wi{_wi},ti{_ti}{}

};
vector<list<pair<int,roadinfo>>> e;

void addEdge(int ui,int vi,int wi,int ti){
    e[ui].push_back({vi,roadinfo(wi,ti)});
    e[vi].push_back({ui,roadinfo(wi,ti)});
}
long long find_next_maintenance(long long start_time,int ti,int k){
    int current_mod=start_time%k;
    if(current_mod<=ti){
        return start_time+(ti-current_mod);
    }
    else{
        // Have to wait until next cycle
        return start_time+(k+ti-current_mod);
    }
}
// Find the next can departure time
long long find_next_departure_time(long long current_time,int wi,int ti,int k){
    if(ti==-1){ // Means the road don't have to be maintainced
        return current_time;
    }
    // At most wait k times, because the maintenance is a k-cycle
    long long next_maintenance=find_next_maintenance(current_time,ti,k);
    if(wi>=k){
        if(next_maintenance>=current_time+wi)
            return current_time;
        else
            return -1;
    }
    if(next_maintenance>=current_time+wi)
        return current_time;
    else
        return next_maintenance+1;
    return -1;
}
void Dijkstra(){
    int max_states_per_node = (m == n - 1) ? min(k, 1000) : k;
    // set s to store the vertex have found shortest path, store (vertex,T_mod_k)
    set<pair<int,int>> S;

    // Priority_queue Q is to store the unfounded shortest path vertex, and sort by the distance
    // in ascending order, (distance,(vertex,T_mod_k))
    priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<>> pq;

    // Use map to store the shortest distance for every (vertex,T_mod_k) status
    map<pair<int,int>,long long> dist;

    // Initialize the distance
    dist[{1,0}]=0;
    // Push vertex 1 into pq
    pq.push({0,{1,0}});
    while(!pq.empty()){
        // Extract_min
        auto [current_time,state]=pq.top();
        auto [v,time_mod]=state;
        pq.pop();

        // If this status is in S already then continue
        if(S.count({v,time_mod}))
            continue;
        
        S.insert({v,time_mod});

        if(v==n){
            cout<<current_time<<"\n";
            return;
        }
        for(auto& [u,info]:e[v]){
            // u: pair(vertex,RoadInfo(wi,ti))
            int w=info.wi;
            int t=info.ti;

            // Calculate the earilest can departure time
            long long departure_time=find_next_departure_time(current_time,w,t,k);
            if(departure_time==-1) continue;

            long long arrive_time=departure_time+w;
            int arrive_mod=arrive_time%k;
            // If this status are in the S, skip it
            if(S.count({u,arrive_mod})) continue;

            // Update the distance
            auto new_state=make_pair(u,arrive_mod);
            // !dist.count(new_state) means dist[new_state] haven't been arrived yet, means distance is INF, correspond to the original version of dijkstra
            if(!dist.count(new_state)||arrive_time<dist[new_state]){
                dist[new_state]=arrive_time;
                pq.push({arrive_time,{u,arrive_mod}});
            }
        }
    }
    cout<<-1<<"\n";
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>n>>m>>k;
    e.resize(n+1);
    // Handle roadinfo input
    for(int i=0;i<m;++i){
        int ui,vi,wi,ti;
        cin>>ui>>vi>>wi>>ti;
        addEdge(ui,vi,wi,ti);
    }
    // Apply dijkstra's algorithm to find the shortest time from vertex 1 to vertex n
    Dijkstra();
    return 0;
    
}