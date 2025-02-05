#include<bits/stdc++.h>
using namespace std;
int const N = 1e3;

void insertMinHeap(int minHeap[] , int &size , int value){
    size++;
    minHeap[size] = value;
    int curr = size;

    while(curr/2 > 0 && minHeap[curr/2] < minHeap[curr]){
        swap(minHeap[curr/2] , minHeap[curr]);
        curr = curr/2;
    }
}

void insertMaxHeap(int maxHeap[] , int &size , int value){
    size++;
    maxHeap[size] = value;
    int curr = size;

    while(curr/2 > 0 && maxHeap[curr/2] < maxHeap[curr]){
        swap(maxHeap[curr/2] , maxHeap[curr]);
        curr = curr/2;
    }
}

void removeMinHeap(int minHeap[] , int& size){
    minHeap[1] = minHeap[size];
    size--;
    int curr = 1;

    while(2*curr <= size){ //looping till curr node has child nodes 
        int left = 2*curr;
        int right = 2*curr + 1;
        int minChild = left;
        if(right <= size && arr[right] < arr[left]){
            minChild = right;
        }

        if(arr[minChild] >= arr[curr]){
            return;
        }

        swap(arr[minChild] , arr[curr]);
        curr = minChild;
    }
}

int main(){
    int minHeap[N] = {-1,10,20,30,40,50};
    int size = 5;
    int value = 5;
    insertMinHeap(minHeap , size , value);
    for(int i = 0 ; i <= size ; i++){
        cout<<minHeap[i]<<" ";
    }cout<<endl;

    int maxHeap[N] = {-1,60,50,40,30,20,10,5};
    int size = 7;
    int value = 100;
    insertMaxHeap(maxHeap , size , value);
    for(int i = 0 ; i <= size ; i++){
        cout<<maxHeap[i]<<" ";
    }cout<<endl;

}