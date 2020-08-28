#include <iostream>
using namespace std;

//make the two given string of same length 
int makeLengthEqual(string &s1,string &s2){
    int len1 = s1.length();
    int len2 = s2.length();
    if(len1<len2){
        for(int i=0;i<(len2-len1);i++){
            s1 = '0'+s1;
        }
        return len2;
    }
    for(int i=0;i<(len1-len2);i++){
        s2 ='0'+s2;
    }
    return len1;
}
//add two string 
string addTwobits(string a,string b){
    string result;
    int carry =0;
    int len = makeLengthEqual(a,b);
    for(int i=len-1;i>=0;i++){
        int firstBit = a.at(i) - '0';
        int secondBit =b.at(i) - '0';
        int sum = (firstBit^secondBit^carry) +'0';
        int carry = (firstBit&secondBit) | (firstBit &carry) |(secondBit &carry);
        result = (char) sum +result;
    }
    if(carry){
        result ='1'+result;
    }
    return result;
    
}
int multiplySingleBit(string a,string b){
    return (a[0]-'0')*(b[0]-'0');
}
long int multiply(string s1,string s2){
    //make the two string same 
    int len = makeLengthEqual(s1,s2);
    if(len==0) return 0;
    if(len==1) return multiplySingleBit(s1,s2);
    int a = len/2;
    int b = len -a;
    string Xl = s1.substr(0,a);
    string Xr =s1.substr(a,b);
    string Yl = s2.substr(0,a);
    string Yr =s2.substr(a,b);
    long int P1 = multiply(Xl,Yl);
    long int P2 =multiply(Xr,Yr);
    long int P3 = multiply(addTwobits(Xl,Xr),addTwobits(Yl,Yr));
    return (P1*(1<<(2*a)))+(P3 -P1-P2)*(1<<a) +P2;

}
int main(){
    int T;
    cin>>T;
    while(T--){
        string s1,s2;
        cin>>s1>>s2;
        cout<<multiply(s1,s2)<<endl;
    }
    return 0;
}