#include <bits/stdc++.h>
using namespace std;

void fib(int n){
    int a =0;
    int b=1;
    int i=2;
    cout<<a<<" ";
    bool to_print =true;
    for(int i=3;i<=n;i++){
        int temp =a;
        a =b;
        b =a+temp;
        if(to_print){
            cout<<b<<" ";
            to_print=false;
        }
        else{
            to_print=true;
        }
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    fib(n);
}