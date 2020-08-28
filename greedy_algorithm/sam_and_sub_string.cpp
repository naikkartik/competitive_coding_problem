#include <bits/stdc++.h>
using namespace std;

int find_sum(int i,string str,int cur_sum){
    int sum =cur_sum;
    int total_sum=0;
    while(i<str.length()){
        sum*=10;
        sum+=(str[i]-'0');
        total_sum+=sum;
        i++;
    }
    return total_sum;

}
int main(){
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        int total_sum =0;
        for(int i=0;i<str.length();i++){
            total_sum+=(str[i]-'0');
            total_sum+=(find_sum(i+1,str,str[i]-'0'));
        }
        cout<<total_sum<<endl;
    }
}