/*Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.*/

class Solution {
    int f(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0 , r = 0 , odd = 0 , cnt = 0;
        while(r < n){
            if(k < 0) return 0;
            if(nums[r]%2 != 0) odd++;
            while(odd > k){
                if(nums[l]%2 != 0) odd--;
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = f(nums , k) - f(nums , k-1);
        return ans ;
    }
};