#include<bits/stdc++.h>
using namespace std;
class function_parm{
    public:
        int a,b;
        function_parm(int a_,int b_):a{a_},b{b_}{}
};
double function1(vector<function_parm>& parm_list, double x){
    double max=0;
    for(const auto& element: parm_list){
        double ans=abs(element.a*x+element.b);
        if(max<ans){
            max=ans;
        }
    }
    return max;
}
double ternary_search(vector<function_parm>& parm_list){
    double l=-1e3,r=1e3;
    double best_value=1e18;
    while(r-l>1e-11){
        double ml=l+(r-l)/3.0;
        double mr=r-(r-l)/3.0;
        double f_ml = function1(parm_list, ml);
        double f_mr = function1(parm_list, mr);
        best_value=min(best_value,min(f_ml,f_mr));
        if(f_ml<f_mr){
            r=mr;
        }
        else
            l=ml;
    }
    return best_value;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int N;
    double ans;
    vector<function_parm> parm_list;
    cin>>N;
    // Input parameter
    for(int i=0;i<N;++i){
        int a,b;
        cin>>a>>b;
        parm_list.push_back(function_parm(a,b));
    }
    ans=ternary_search(parm_list);
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;

}