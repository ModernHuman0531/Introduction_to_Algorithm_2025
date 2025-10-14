#include <bits/stdc++.h>
using namespace std;
#define lc 2*id
#define rc 2*id+1
int n;
vector<long long> vec;
vector<long long> ex;
void build(int L,int R,int id);
long long query(int l,int r,int L,int R,int id);
void modify(int p,int x,int L,int R,int id);
void operation(int i,int j,int k){
    // i is operation,j and k are the input of Update/Query
    if(i==1) return modify(j,k,1,n,1);
    if(i==2){
        long long ans=query(j,k,1,n,1);
        cout<<ans<<"\n";
        return;
    } 

}
void build(int L,int R,int id){
    if(L==R){// Base case
        ex[id]=vec[L];
        return;
    }
    int M=(L+R)/2;
    build(L,M,lc); // Build left subtree
    build(M+1,R,rc); //Build right subtree
    ex[id]=ex[lc]^ex[rc];
}

long long query(int l,int r,int L,int R,int id){
    int M=(L+R)/2;
    if(l<=L&&R<=r){ // binary tree node are in the target range, just take that node's info
         return ex[id];
    }
    if(r<=M){
        return query(l,r,L,M,lc);   
    }
    if(M<l){
        return query(l,r,M+1,R,rc);
    }
    else{
        return (query(l,r,L,M,lc)^query(l,r,M+1,R,rc));
    }
}
void modify(int p,int x,int L,int R,int id){
    if(L==R){
        ex[id]=x;
        return;
    }
    int M=(L+R)/2;
    if(p<=M){
        modify(p,x,L,M,lc);
    }
    if(M<p){
        modify(p,x,M+1,R,rc);
    }
    ex[id]=ex[lc]^ex[rc];
}
int main(){
    int q;
    cin>>n;
    vec.push_back(0);// Let the position start from 1
    // Input handle
    for(int i=0;i<n;++i){
        long long input;
        cin>>input;
        vec.push_back(input);
    }
    ex.resize(4*n+1); //Segment tree size normally need 4*n space to store data
    build(1,n,1);
    
    cin>>q;
    for(int i=0;i<q;++i){
        int op,j,k;
        cin>>op>>j>>k;
        operation(op,j,k);
    }
    return 0;
}