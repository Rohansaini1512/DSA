/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/

class Solution {
    void heapify(vector<int>& nums, int n, int curr) {
        int largest = curr;
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;

        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }
        if (largest != curr) {
            swap(nums[curr], nums[largest]);
            heapify(nums, n, largest);
        }
    }

    void removeTop(vector<int>& nums, int& size) {
        swap(nums[0], nums[size - 1]);
        size--;
        heapify(nums, size, 0);
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }
        for (int i = 0; i < k - 1; i++) {
            removeTop(nums, n);
        }
        return nums[0];
    }
};
