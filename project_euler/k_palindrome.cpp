#include <bits/stdc++.h>
using namespace std;
int solution(string str1,string str2,int m,int n){
    if(m==0){
        return n;
    }
    if(n==0){
        return m;

    }
    if(str1[m-1]==str2[n-1]){
        return solution(str1,str2,m-1,n-1);
    }
    int ans1 = solution(str1,str2,m-1,n)+1;
    int ans2 = solution(str1,str2,m,n-1)+1;
    return min(ans1,ans2);
}
int longest_palindromic_ss(string str,int i,int j){
    if(i>j){
        return 0;
    }
    if(str[i]==str[j]){
        return 2+longest_palindromic_ss(str,i+1,j-1);
    }
    int ans1 = longest_palindromic_ss(str,i+1,j);
    int ans2 = longest_palindromic_ss(str,i,j-1);
    return max(ans1,ans2);
}
int dp_solution(string str1,string str2){
    int dp[str1.length()+1][str2.length()+1];
    //fill all row
    for(int i=0;i<=str1.length();i++){
        dp[i][0]=i;
    }
    for(int i=0;i<=str2.length();i++){
        dp[0][i] = i;
    }
    for(int i=1;i<=str1.length();i++){
        for(int j=1;j<=str2.length();j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
            }
        }
    }
    return dp[str1.length()][str2.length()];
}
int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    string rev = str;
    reverse(rev.begin(),rev.end());
    int ans = solution(str,rev,str.length(),str.length());
    if(ans<=2*k){
        cout<<"Yes it is Possible"<<endl;
    }
    else{
        cout<<"Its not possible"<<endl;
    }
    int ans2 = dp_solution(str,rev);
    if(ans2<=2*k){
        cout<<"Yes it is Possible"<<endl;
    }
    else{
        cout<<"Its not possible"<<endl;
    }
    int ans3 = longest_palindromic_ss(str,0,str.length()-1);
    cout<<ans3<<endl;
}
