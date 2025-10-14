#include<bits/stdc++.h>
using namespace std;
class spaceNode{
    public:
        int x,y,z;
        spaceNode(int x_,int y_,int z_):x{x_},y{y_},z{z_}{}
};
vector<spaceNode> vec;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    // Input
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        int x,y,z;
        cin>>x>>y>>z;
        vec.push_back(spaceNode(x,y,z));
    }
    for(int i=0;i<N;++i){
        int count=0;
        for(int j=0;j<N;++j){
            // Can write operator overloading
            if((vec[i].x<vec[j].x)&&(vec[i].y<vec[j].y)&&(vec[i].z<vec[j].z))
                count++;
        }
        cout<<count<<"\n";
    }
    return 0;

}