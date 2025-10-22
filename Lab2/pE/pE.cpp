#include<bits/stdc++.h>
using namespace std;
int N;

class spaceNode{
    public:
        int x,y,z;
        int idx;
        spaceNode(int x_,int y_,int z_,int idx_):x{x_},y{y_},z{z_},idx(idx_){}
};

vector<spaceNode> vec;
vector<int> ans;
vector<int> BIT;
bool cmp(spaceNode x1,spaceNode x2){
    if(x1.x!=x2.x)
        return x1.x>x2.x;
    return x1.y<x2.y;
}
// lowbit,update,query and insert are the implement of BIT in 2d case.
int lowbit(int num){
    return (num)&(-num);
}
void update(int pos,int value){
    for(;pos<=N;pos+=lowbit(pos)){
        BIT[pos]+=value;
    }
    return;
}
int query(int pos){
    int ans=0;
    for(;pos>0;pos-=lowbit(pos)){
        ans+=BIT[pos];
    }
    return ans;
}
void insert(int value){
    update(value,1);
}
int count_greater(int pos){
    // The point has been insert
    int total=query(N); //Total number of point have been inserted
    int lq=query(pos);
    int greater=total-lq;
    return greater;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    // Input
    cin>>N;
    for(int i=1;i<=N;++i){
        int x,y,z;
        cin>>x>>y>>z;
        vec.push_back(spaceNode(x,y,z,i));
    }
    sort(vec.begin(),vec.end(),cmp);
    // Use double pointer to handle the same x
    ans.resize(N+1,0);
    BIT.resize(N+1,0);
    int j=0;
    while(j<N){
        int k=j;
        // Find the range where x is equal in [j,k)
        while(vec[j].x==vec[k].x){
            ++k;
        }
        // Handle range j to k-1 first
        for(int l=j;l<k;++l){
            int greater_num=count_greater(vec[l].y);
            ans[vec[l].idx]=greater_num;
        }
        // Insert y's number as position into BIT
        for(int l=j;l<k;++l){
            insert(vec[l].y);
        }
        j=k;
    }
    
    for(int i=1;i<=N;++i){
       cout<<ans[i]<<"\n";
    }
    return 0;
}