#include<bits/stdc++.h>
using namespace std;
int m,n;
char grid[m+1][n+1];
int dist[m+1][n+1];
int fx[4]={1,-1,0,0};
int fy[4]={0,0,1,-1};
void BFS(int sx,int sy){
    queue<pair<int,int>> q;
    // Put the first point into queue
    q.push_back({sx,sy});
    dist[sx][sy]=0;
    while(!q.empty()){
        // Have four direction can go, but have some restriction
        // 1. Can't out of range 2. Can't encounter # 3. Can't the point have been walked
        auto [x,y]=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            int fx=x+fx[i],fy=y+fy[i];
            if(fx<1||fx>m||fy<1||fy>n) continue;
            if(grid[fx][fy]=='#') continue;
            if(dist[fx][fy]!=-1) continue;
            dist[fx][fy]=dist[x][y]+1;
            q.push({fx,fy});

        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>m>>n;
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    // Handle the input,from (1,1)
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            char x;
            cin>>x;
            grid[i][j]=x;
        }
    }
    // Initialize dist to -1 as unvisited
    memset(dist,-1,sizeof(dist));
    BFS(sx,sy);
    if(dist[tx][ty]==-1){
        cout<<-1<<"\n";
    }
    else{
        cout<<dist[tx][ty]<<"\n";
    }
    return 0;

}