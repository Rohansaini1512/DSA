/*Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<int>st;
        int length = 0;
        int maxi = 0;

        for(int i = 0 ; i < n ; i++){
            if(st.count(s[i]) == 0){
                st.insert(s[i]);
                maxi = max(maxi , i-length+1);
            }else{
                while(st.count(s[i])){
                    st.erase(s[length]);
                    length++;
                }
                st.insert(s[i]);
            }
        }
        return maxi;
    }
};