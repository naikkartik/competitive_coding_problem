#include <bits/stdc++.h>
using namespace std;
int count_way(int cap,int person){
    if(person>cap){
        return 0;
    }
    int count =1;
    for(int i=cap;cap>person;cap--){
        count=count*i;
    }
    return count;
}
int main(){
    int n;
    cout<<count_way(4,3)<<endl;
    
}