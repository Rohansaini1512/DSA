#include<bits/stdc++.h>
using namespace std;
int const N = 1e3;

void heapify(int arr[] , int &size , int curr){
    while(2*curr+1 <= size){
        int left = 2*curr+1;
        int right = 2*curr+2;
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

void remove(int arr[] , int &size){
    arr[0] = arr[size - 1];
    size--;
    heapify(arr , size , 0);
}

int KthSmallest(int arr[] , int size , int k){
    for(int i = size/2-1 ; i>=0 ; i--){
        // i --> parent node
        heapify(arr , size , i); 
    }
     k -= 1;
    while(k--){
        remove(arr , size);
    }
    return arr[0];
}

int main(){
    int arr[N] = {60,10,80,50,5,20,70};
    int size = 7;
    cout<<KthSmallest(arr , size , 3)<<endl;
}