#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}

int main(){
    int n,s,e;
    cin>>n;
    vector<pair<int,int>>arr;
    while(n--){
        cin>>s>>e;
        arr.push_back(make_pair(s,e));

    }
    sort(arr.begin(),arr.end(),compare);
    int res =1;
    int bin =arr[0].second;
    for(int i=1;i<arr.size();i++){
        if(bin<=arr[i].first){
            res++;
            bin =arr[i].second;
        }
    }
    cout<<res<<endl;
    return 0;
}