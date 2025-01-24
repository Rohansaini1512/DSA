#include<bits/stdc++.h>
using namespace std;
int const N = 1e3;

void heapify(int arr[] , int n , int curr){
    while(2*curr <= n){
        int left = 2*curr;
        int right = 2*curr+1;
        int maxChild = right;
        if(right <= n && arr[right] > arr[maxChild]){
            maxChild = right;
        }
        if(arr[maxChild] <= arr[curr]){
            return;
        }
        swap(arr[maxChild] , arr[curr]);
        curr = maxChild;
    }
}

void remove(int arr[] , int &size){
    swap(arr[1] , arr[size]);
    size--;
    heapify(arr,size,1);
}

void heapsort(int arr[] , int n){
    // 1. heapify all parent nodes into max heap
    for(int i = n/2 ; i > 0 ; i--){
        heapify(arr,n,i);
    }

    // 2. keep deleting elements from max heap until size becomes 0

    while(n > 0){
        remove(arr,n);
    }
}

int main(){
    int n = 7;
    int arr[N] = {-1,60,10,80,50,5,20,70};
    heapsort(arr,n);
    

    for(int i = 1 ; i <= n ; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}