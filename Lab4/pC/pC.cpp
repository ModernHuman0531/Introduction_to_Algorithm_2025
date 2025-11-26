#include<bits/stdc++.h>
using namespace std;
const int MAXN=501;
long long arr[MAXN];
long long prefix[MAXN];
long long dp[MAXN][MAXN];


int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        long long wi;
        cin>>wi;
        arr[i]=wi;
    }

    // Calculate prefix sum
    long long sum=0;
    arr[0]=0LL;
    prefix[0]=0LL;
    for(int i=1;i<=n;++i){
       sum+=arr[i];
       prefix[i]=sum; 
    }

    // Initialize dp[i][i]
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=LLONG_MAX;
            }
        }
    }
    // dp[i][j]=min(dp[i][k]+dp[k+1][j]+sum arr[l] ,for l=i to j)
    for(int len=2;len<=n;++len){
        for(int i=1;i+len-1<=n;++i){
            int j=len+i-1;
            for(int k=i;k<j;++k){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+(prefix[j]-prefix[i-1]));
            }
        }
    }
    cout<<dp[1][n]<<"\n";
    return 0;
}