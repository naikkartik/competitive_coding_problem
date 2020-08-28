#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int min_find(int b,list<int>l,int value[]){
    int min_value = value[b-1];
    
    for(auto node:l){
        int k = value[node-1];
        if(k<min_value){
            min_value = k;
        }
    }
    return min_value;
}
void impute_value(int b,list<int>l,int c,int value[]){
    value[b-1] = c;
    for(auto node:l){
        value[node-1] =c;
    }
}
int main(){
    int N,Q;
    cin>>N>>Q;
    map<int,list<int>>arr;
    for(int i=1;i<N;i++){
        int u,v;
        cin>>u>>v;
        arr[v].push_back(u);
    }
    int value[N];
    for(int i=0;i<N;i++){
        cin>>value[i];
    }
    //followed by q query
    while(Q--){
        int a,b,c;
        cin>>a;
        if(a==1){
            cin>>b;
            cout<<min_find(b,arr[b],value)<<endl;
        }
        else{
            cin>>b>>c;
            impute_value(b,arr[b],c,value);
        }
    }


}