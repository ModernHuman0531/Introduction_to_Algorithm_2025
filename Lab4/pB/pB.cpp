#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    long long ans=0;
    priority_queue<long long,vector<long long>,greater<>> pq;
    cin>>n;
    for(int i=0;i<n;++i){
        long long fi;
        cin>>fi;
        pq.push(fi);
    }

    // Use greedy algorithm to build the tree and calculate freq*l
    // Greedy strategy is to choose to merge the lowest 2 freq letter into new node and 
    // put it into pq until the pq only have 1 number
    while(pq.size()>1){
        long long f1=pq.top();
        pq.pop();
        long long f2=pq.top();
        pq.pop();
        ans+=(f1+f2);
        pq.push(f1+f2);
    }
    cout<<ans<<"\n";
    return 0;
}