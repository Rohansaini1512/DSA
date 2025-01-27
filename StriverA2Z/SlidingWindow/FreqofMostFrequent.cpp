/*The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

 

Example 1:

Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.
Example 2:

Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
Example 3:

Input: nums = [3,9,6], k = 2
Output: 1*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long maxFreq = 0, l = 0, tot = 0, n = nums.size();

        for (long long r = 0; r < n; r++) {
            tot += nums[r]; // Add the current element to the total

            // Check if the current range is valid
            while (nums[r] * (r - l + 1) > tot + k) {
                tot -= nums[l]; // Remove the contribution of nums[l] as l is moved forward
                l++;
            }

            // Update the maximum frequency
            maxFreq = max(maxFreq, r - l + 1);
        }

        return maxFreq;
    }
};
