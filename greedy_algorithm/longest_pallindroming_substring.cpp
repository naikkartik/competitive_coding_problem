#include <bits/stdc++.h>
using namespace std;
bool check_palindrome(int i,int j,string str){
    while(i<=j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int find_long(string str,int i,int j,map<pair<int,int>,int>&dp_length){
    //base case
    if(i>j){
        return 0;
    }
    if(i==j){
        return 1;
    }

    if(i==j+1 and str[i]==str[j]){
        return 2;
    }
    pair<int,int>tmp = make_pair(i,j);
    
    //check for pallindrome
    if(check_palindrome(i,j,str)){
        return (j-i+1);
    }
    if(dp_length.find(tmp)!=dp_length.end()){
        return dp_length[tmp];
    }
    int op1 =find_long(str,i+1,j,dp_length);
    int op2 =find_long(str,i,j-1,dp_length);
    return dp_length[tmp] = max(op1,op2);
}
string find_string(string str,int i,int j,map<pair<int,int>,string>&dp_string){
    if(i>j){
        return "";
    }
    if(i==j){
        string s;
        return (s+str[i]);
    }
    if(i==j+1 and str[i]==str[j]){
        return str.substr(i,j);
    }
    pair<int,int>tmp =make_pair(i,j);
    if(dp_string.find(tmp)!=dp_string.end()){
        return dp_string[tmp];
    }
    if(check_palindrome(i,j,str)){
        string result ;
        for(int k=i;k<=j;k++){
            result+=(str[k]);
        }
        return result;
    }
    string ans1 = find_string(str,i+1,j,dp_string);
    string ans2 = find_string(str,i,j-1,dp_string);
    if(ans1.length()>ans2.length()){
        return dp_string[tmp]=ans1;
    }
    return dp_string[tmp]=ans2;
}


if(s.length()<=0){
    return 0;
}
//make a map
map<pair<int,int>,string>dp;
string ans =find_string(s,0,s.length()-1,dp);
return ans;

int main(){
    string str;
    cin>>str;
    map<pair<int,int>,int>dp_length;
    map<pair<int,int>,string>dp_string;
    int ans = find_long(str,0,str.length()-1,dp_length);
    string ans_string =find_string(str,0,str.length()-1,dp_string);
    cout<<ans<<endl;
    cout<<ans_string<<endl;
}