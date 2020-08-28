#include <bits/stdc++.h>
using namespace std;
bool check_presence(map<string,int>&dp,string query){
    string temp;
    for(int i=0;i<query.size();i++){
        temp+=query[i];
        if(dp.find(temp)!=dp.end()){
            temp="";
        }
    }
    if(temp!=""){
        return false;
    }
    return true;
}
int main(){
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                            "go","i","like","ice","cream"};
    map<string,int>dp;
    for(int i=0;i<13;i++){
        dp[dictionary[i]]=1;
    }
    string query;
    cin>>query;
    cout<<check_presence(dp,query)<<endl;


}