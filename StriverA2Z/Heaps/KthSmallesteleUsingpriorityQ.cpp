/*Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array.

Follow up: Don't solve it using the inbuilt sort function.

Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output:  7
Explanation: 3rd smallest element in the given array is 7.
Input: arr[] = [2, 3, 1, 20, 15], k = 4 
Output: 15
Explanation: 4th smallest element in the given array is 15.*/

int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> maxHeap;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            maxHeap.push(arr[i]);
            while(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }