#include <bits/stdc++.h>
using namespace std; 
int string_to_atoi(string str){
    int i=0;
    while(i<str.length() and str[i]==' '){
        i++;
    }
    
    char sign ='+';
    //there will be the sign 
    if(str[i]=='-'){
        sign='-';
        i++;
    }
    if(str[i]=='+'){
        sign='+';
        i++;
    }
    if(str[i]>='a' and str[i]<='z'){
        return 0;
    }
    int count =0;
    int ans=0;
    int pow =10;
    while(i<str.length()){
        if(str[i]>='a' and str[i]<='z'){
            break;
        }
        else{
            ans= ans*pow;
            int temp =str[i]-'0';
            ans+=temp;
            count++;
            
            
        }
        i++;
    }
    if(count>=9 and sign=='-'){
        return INT_MIN;
    }
    if(count>=9 and sign=='+'){
        return INT_MAX;
    }
    if(sign=='-'){
        return -1*ans;
    }
    return ans;


    
}

int main(){
    string str;
    cin>>str;
    int ans = string_to_atoi(str);
    cout<<ans<<endl;
}