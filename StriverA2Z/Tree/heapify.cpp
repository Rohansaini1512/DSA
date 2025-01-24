#include<bits/stdc++.h>
using namespace std;
int const N = 1e3;

void heapify(int arr[] , int &size , int curr){
    while(2*curr <= size){
        int left = 2*curr;
        int right = 2*curr+1;
        int minChild = left;
        if(right <= size && arr[right] < arr[minChild]){
            minChild = right;
        }
        if(arr[minChild] >= arr[curr]){
            return;
        }
        swap(arr[minChild] , arr[curr]);
        curr = minChild;
    }
}

void heapifyMaxHeap(int arr[] , int &size , int curr){
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

int main(){
    int arr[N] = {-1,60,10,80,50,5,20,70};
    int size = 7;
    for(int i = size/2 ; i>0 ; i--){
        // i --> parent node
        heapify(arr , size , i); 
        heapifyMaxHeap(arr , size , i);
    }

    for(int i = 1 ; i <= size ; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}