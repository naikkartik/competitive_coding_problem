#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count =0;
    for(int i=3;i<n;i++){
        if(i%3==0 | i%5==0){
            count+=i;
        }
    }
    cout<<count<<endl;
    return 0;
}
