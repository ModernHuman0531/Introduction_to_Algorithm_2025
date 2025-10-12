#include <bits/stdc++.h>
using namespace std;
#define map_size 8 
int max_num = -1e9;
int weights[map_size][map_size];
vector<int> state;
bool check(int row,int col){

    for(int prev_row=0;prev_row<row;prev_row++){
        int prev_col=state[prev_row];
        // Check the column
        if(prev_col==col) return false;
        // Check main diagonal
        if((prev_row-prev_col)==(row-col)) return false;
        // Check sub diagonal
        if((prev_row+prev_col)==(row+col)) return false;
    }
    return true;

}
void solve(int row,int current_state){
    if(row==8){
        if(current_state>max_num)
            max_num=current_state;
        return;
    }
    for(int col=0;col<=7;++col){
        if(check(row,col)){
            state.push_back(col); //Put queen at (row,col)
            solve(row+1,current_state+weights[row][col]); // Keep going for row+1
            state.pop_back(); // Retreat queen at (row,col)
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    // Input
    //cout<<"Reading input..."<<"\n";
    for(int i=0;i<map_size;++i){
        for(int j=0;j<map_size;++j){
            int num;
            cin>>num;
            weights[i][j]=num;
        }
    }
    // cout<<"Solving..."<<"\n";
    solve(0,0);
    //cout<<"Done!"<<"\n";
    cout<<max_num<<"\n";
}