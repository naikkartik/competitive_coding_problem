#include <bits/stdc++.h>
using namespace std; 
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.first>p2.first;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>luck_imp_pair;
    for(int i=0;i<n;i++){
        int luck,imp;
        cin>>luck>>imp;
        luck_imp_pair.push_back(make_pair(luck,imp));
    }
    sort(luck_imp_pair.begin(),luck_imp_pair.end(),compare);
    int total_luck =0;
    for(int i=0;i<luck_imp_pair.size();i++){
        if(luck_imp_pair[i].second==0){
            total_luck+=luck_imp_pair[i].first;
        }
        if(luck_imp_pair[i].second==1){
            if(k>0){
                k--;
                total_luck+=luck_imp_pair[i].first;
            }
            else{
                total_luck-=luck_imp_pair[i].first;
            }
            
        }
    }
    cout<<total_luck<<endl;
}