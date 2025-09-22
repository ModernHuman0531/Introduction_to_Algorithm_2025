#include <bits/stdc++.h>
using namespace std;
vector<double> score;
bool cmp(double num1, double num2){
    return num1<num2;
}
int countkthnum(double mid){
    // Count one dish
    int count=0, n=score.size();
    for(int i=0;i<n;++i){
        if(score[i]>mid)
            count+=1;
    }
    // Use double pointer to enumerate combo dishes
    int l=0,r=n-1;
    double sum=(score[l]+score[r])/2.;
    for(;l<r;++l){
        int r_start=r;
        while(sum>mid&&r>l){
            sum-=score[r]/2.;
            r-=1;
            sum+=score[r]/2.;
        }
        count+=(r_start-r);
    }
    return count;
}
double binary_search(int k){
    // Return wi that is the kth large score
    int n=score.size();
    double l=score[0],r=score[n-1];
    double error=1e-5;
    while(r-l>error){
        double mid=(l+r)/2;
        int count=countkthnum(mid);
        if(count<k-1){
            r=mid;
        }
        else
            l=mid;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    int p,q;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        score.push_back(num);
    }
    sort(score.begin(),score.end(),cmp);
    double ans=binary_search(k);

    // Search the answer that is <=ans's biggest to the ans in possible answer query
    double true_ans=-INT_MAX;
    for(auto const& element: score){
        if(element<=ans){
            true_ans=max(element,true_ans);
        }
    }
    // double pointer loop through the combo
    int l=0,r=score.size()-1;
    double sum=(score[l]+score[r])/2.;
    for(;l<r;l++){
        while(sum>ans&&r>l){
            sum-=score[r]/2.;
            r-=1;
            sum+=score[r]/2.;
        }
        true_ans=max(true_ans,sum);
    }
    cout<<"ans="<<ans<<"\n";
    if(true_ans<0){
        int int_ans=ceil(true_ans);
        if(int_ans-true_ans<0.1)
            p=true_ans,q=1;
        else
            p=true_ans*2,q=2;
    }
    else{
        int int_ans=ceil(true_ans);
        if(int_ans-true_ans<0.1)
            p=true_ans,q=1;
        else  
            p=true_ans*2,q=2;
    }
    cout<<p<<"\n"<<q<<"\n";
    return 0;
}    

   
