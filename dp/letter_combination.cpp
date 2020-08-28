#include <bits/stdc++.h>
using namespace std; 
void combination(int i,int j,string cur,string s,vector<string>&result,map<int,string>mp){
    if(cur.length()==s.length()){
        result.push_back(cur);
        return;    
    }
    if(i>=s.length()){
        return;
    }
    if(j>=mp[s[i]-'0'].length()){
        return;
    }
    combination(i+1,0,(cur+mp[s[i]-'0'][j]),s,result,mp);
    combination(i,j+1,cur,s,result,mp);
    return;
    

}
int main(){
    string s;
    cin>>s;
    map<int,string>mp;
    mp[2]="abc";
    mp[3]="def";
    mp[4]="ghi";
    mp[5]="klm";
    mp[6]="nop";
    mp[7]="qrs";
    mp[8]="tuv";
    mp[9]="wxyz";
    vector<string>result;
    combination(0,0,"",s,result,mp);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ,";
    }
    cout<<endl;
}