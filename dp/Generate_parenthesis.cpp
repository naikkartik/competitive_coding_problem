#include <bits/stdc++.h>
using namespace std; 
void generate_parenthesis(int m,int n,vector<string>&result,string cur){
    if(m==0 and n==0){
        result.push_back(cur);
        return;
    }
    
    if(m<0 or n<0){
        return;
    }
    if(m>=n){
        generate_parenthesis(m-1,n,result,cur+'(');
        return;
    }
    generate_parenthesis(m-1,n,result,cur+'(');
    generate_parenthesis(m,n-1,result,cur+')');
    return;
    
    
}
int main(){
    int n;
    cin>>n;
    vector<string>result;
    generate_parenthesis(n,n,result,"");
    cout<<result.size()<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}