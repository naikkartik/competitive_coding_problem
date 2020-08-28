#include <iostream>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr1[n];
	    int arr2[n];
	    for(int i=0;i<n;i++){
	        cin>>arr1[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>arr2[i];
	    }
	    int p1 =0;
	    int p2 =0;
	    int i=0;
	    int arr[2*n] ={0};
	    while(p1<n and p2<n){
	        if(arr[p1]<arr[p2]){
	            arr[i] =arr1[p1];
	            i++;
	            p1++;
	        }
	        else{
	            arr[i] = arr2[p2];
	            p2++;
	            i++;
	        }
	    }
	    while(p1<n){
	        arr[i] = arr1[p1];
	        p1++;
	        i++;
	    }
	    while(p2<n){
	        arr[i] = arr2[p2];
	        p2++;
	    }
	    for(int i=0;i<2*n;i++){
	        cout<<arr[i]<<" ";
	    }
	   
	} 
	return 0;
}