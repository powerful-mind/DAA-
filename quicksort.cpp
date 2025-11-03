#include <bits/stdc++.h>
using namespace std;
int partition(vector <int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i] <= pivot && i<=high-1){
            i++;
        }
        while(arr[j] > pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void quicksort(vector<int> &arr,int low,int high){
    if(low<high){
        int pindex=partition(arr,low,high);
        quicksort(arr,low,pindex-1);
        quicksort(arr,pindex+1,high);
    }

}
int main(){
    vector<int> arr={45,56,34,52,67,54};
    cout<<"Original array:";
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    quicksort(arr,0,n-1);
    cout<<"Sorted array:";
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}