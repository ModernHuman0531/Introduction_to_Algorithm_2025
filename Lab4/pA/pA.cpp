#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4;
const int MAXW=100;
const long long INF=MAXN*1000000000ll;

long long dp[MAXW];
int ai[MAXN],bi[MAXN],ci[MAXN];
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n,w;
    cin>>n>>w;
    for(int i=1;i<=n;++i){
        cin>>ai[i]>>bi[i]>>ci[i];
    }
    // Initialization, dp[0][0] means put nothing in it, the current used space is 0
    dp[0]=0;
    // 0 item can't have i size
    for(int i=1;i<=w;++i){
        dp[i]=-INF;
    }
    int now=1;
    for(int i=1;i<=n;++i){
        // ci[i]=0 means complete bag core code
        if(ci[i]==0){
            for(int j=ai[i];j<=w;++j){
                dp[j]=max(dp[j],dp[j-ai[i]]+bi[i]);
            }
        }
        // 0/1 bag and multiple bag can handle together
        else{
            for(int j=w;j>=ai[i];--j){
                for(int k=1;k<=ci[i]&&k*ai[i]<=j;++k){
                    dp[j]=max(dp[j],dp[j-k*ai[i]]+k*bi[i]);
                }
            }
        }
    }
    // Choose the maximum value consider the first n element
    cout<<*max_element(dp,dp+w+1)<<"\n";
    return 0;
}