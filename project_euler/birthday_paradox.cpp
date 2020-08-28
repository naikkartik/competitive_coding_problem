#include <bits/stdc++.h>
using namespace std; 

int main(){
    float p =1;
    float num = 365;
    float denom =365;
    int people = 0;
    while(p>0.5){
        p*=(num/denom);
        num--;
        people++;
    }
    cout<<"total number of people's are = "<<people<<endl;
}
