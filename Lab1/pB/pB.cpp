#include <bits/stdc++.h>
using namespace std;
int binary_search(int N,int x){
    // Ask at most 20 times
    int l=0,r=N+1;
    while(l+1<r){
        int mid=(l+r)/2;
        cout<<"? "<<mid<<"\n";
        cout.flush();

        int input;
        cin>>input;
        if(input<x)
            l=mid;
        else
            r=mid;
    }
    if(r<=N)
        return r;
    return -1;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int N,x,index;
    cin>>N>>x;
    index=binary_search(N,x);
    cout<<"! "<<index<<"\n";
    return 0;
}