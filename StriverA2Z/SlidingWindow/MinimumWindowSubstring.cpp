/*Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        unordered_map<char, int> mp;
        for (int i = 0; i < m; i++) {
            mp[t[i]]++;
        }
        
        int l = 0, r = 0;
        int sIdx = -1, minLen = INT_MAX;
        int cnt = 0;
        
        while (r < n) {
            if (mp[s[r]] > 0) {
                cnt++;
            }
            mp[s[r]]--;
            
            while (cnt == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIdx = l;
                }
                
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        
        return sIdx == -1 ? "" : s.substr(sIdx, minLen);
    }
};