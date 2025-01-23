/*Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
*/

class Solution {
public:
    int f(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;

        int count = 0;

        unordered_map<int, int> hm;

        while (right < nums.size()) {
            hm[nums[right]]++;

            while (hm.size() > k) {
                hm[nums[left]]--;
                if (hm[nums[left]] == 0)
                    hm.erase(nums[left]);
                left++;
            }

            count += right-left+1;
            right++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};