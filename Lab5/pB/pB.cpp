#include<bits/stdc++.h>
using namespace std;
const int MAX_TOTAL_CHARS=1e6+5;
// next[i][j] means node i through chars j (`a`+j) to next node index
int trie_next[MAX_TOTAL_CHARS][26];
// count[i] means number of string pass node i
int trie_count[MAX_TOTAL_CHARS];
int node_count=0;

// Build trie
struct Trie{
    Trie(){
        node_count=0;
        // Initialization
        memset(trie_next[0],0,sizeof(trie_next[0]));
        trie_count[0]=0;
    }
    // Insert the reverse string
    vector<int> insert_and_get_path(const string reversed_s){
        int curr=0;
        vector<int> path;
        path.push_back(0); //Because root node is empty(0)
        // Run through string by char
        for(char c:reversed_s){
            // Calculate index
            int index=c-'a';

            // If index doesn't exist, build one
            if(trie_next[curr][index]==0){
                node_count++;
                // Initialize new node's path and count
                memset(trie_next[node_count], 0, sizeof(trie_next[node_count]));
                trie_count[node_count]=0;

                trie_next[curr][index]=node_count;
            }
            // Move to next node
            curr=trie_next[curr][index];
            // Add count to that node
            trie_count[curr]++;
            path.push_back(curr);
        }
        return path;
    }

};
vector<vector<int>> string_paths;
// Check function for length k to judge whether k is suit or not

bool check(int k, int N){
    unordered_map<int,int> count_map;
    for(int i=0;i<N;++i){
        // If string's length<k, then don't consider it
        if((int)string_paths[i].size()-1<k){
            // But trie_count still counts those strings, so i use another unordered_map to store those strings
            continue;
        }
        // Go along the reversed string for walk k steps
        int node_at_k=string_paths[i][k];
        count_map[node_at_k]++;
        // If at deep k, count>1 means more than 1 string have same end
        if(count_map[node_at_k]>1){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    Trie trie;
    int N;
    cin>>N;
    int max_length=0;
    for(int i=0;i<N;++i){
        string x;
        cin>>x;
        if(x.length()>max_length){
            max_length=x.length();
        }
        reverse(x.begin(),x.end());
        string_paths.push_back(trie.insert_and_get_path(x));
    }

    // Use binary search to find k
    int l=1,r=max_length+1;
    int ans=r;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid,N)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    if(N==1){
        ans=0;
    }
    cout<<ans<<"\n";
    return 0;
    
    
}