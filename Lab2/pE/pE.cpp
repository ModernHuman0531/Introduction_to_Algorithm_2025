#include<bits/stdc++.h>
using namespace std;
class spaceNode{
    public:
        int x,y,z;
        int idx;
        spaceNode(int x_,int y_,int z_,int idx_):x{x_},y{y_},z{z_},idx(idx_){}
};
bool cmp(spaceNode x1,spaceNode x2){
    return x1.x>x2.x;
}
vector<spaceNode> vec;
vector<int> ans;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    // Input
    int N;
    cin>>N;
    for(int i=1;i<=N;++i){
        int x,y,z;
        cin>>x>>y>>z;
        vec.push_back(spaceNode(x,y,z,i));
    }
    sort(vec.begin(),vec.end(),cmp);
    ans.resize(N+1);
    ans.push_back(0);
    // Use double pointer to calculate the repeat number
    int i=0;
    while(i<N){
        int j=i;
        while(j<N&&vec[i].x==vec[j].x){
            ++j;
        }
        // The interval of same x value is [i,j)
        for(int k=i;k<j;++k){
            ans[vec[k].idx]=i;
        }
        i=j;
    }
    // Print out the ans vector
    for(int i=1;i<=N;++i){
       cout<<ans[i]<<"\n";
    }
    return 0;
}