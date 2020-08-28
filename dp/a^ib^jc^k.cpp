#include <bits/stdc++.h>
using namespace std; 
int count_ans(string str){
    int a_count,b_count,c_count;
    a_count=b_count=c_count =0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='a'){
            a_count =(1+2*a_count);
        }
        else if(str[i]=='b'){
            b_count=(a_count+2*b_count);
        }
        else if(str[i]=='c'){
            c_count =(b_count+2*c_count);
        }
    }
    return c_count;
}
int main(){
    string str;
    cin>>str;
    int ans =count_ans(str);
    cout<<ans<<endl;
}