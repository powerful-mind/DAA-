#include<bits/stdc++.h>
using namespace std;
// O(n2) 
void insertion_sort(int arr[],int n){
    for(int i=1;i<=n-1;i++){
        for(int j=i;j>0;j--){
            if(arr[j-1]>arr[j]) swap(arr[j-1],arr[j]);;
        }
    }

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertion_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}