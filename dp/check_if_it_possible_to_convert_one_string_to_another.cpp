#include <bits/stdc++.h>
#define max 1000 
using namespace std;

bool check(string s1,string s2,int i,int j,int m,int n){
    //base case 
    if(j>=n){
        // i reached to end of second string 
        return true;
    }
    if(i>=m){
        return false;
    }
    if(toupper(s1[i])==s2[j]){
        return check(s1,s2,i+1,j+1,m,n);
    }
    return check(s1,s2,i+1,j,m,n);
}
bool dp_solution(string s1,string s2,int i,int j,int m,int n,int dp[][max]){
    //base case 
    if(j>=n){
        return true;
    }
    if(i>=m){
        return false;
    }
    if(s1[i]!=s2[j] and isupper(s1[i])){
        return false;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    if(toupper(s1[i])==s2[j]){
        return dp[i][j] = dp_solution(s1,s2,i+1,j+1,m,n,dp);
    }
    return dp[i][j]=dp_solution(s1,s2,i+1,j,m,n,dp);
}
int main()
{
    string s1 = "argaju";
    string s2 = "RAJ";
    int dp[s1.length()][max];
    memset(dp, -1, sizeof(dp));
    if (dp_solution(s1, s2,0,0,s1.length(),s2.length(),dp))
    cout << "YES";
    else
    cout << "NO";
    return 0;
}
