/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<int, int> mp = {{0, -1}, {1, -1}, {2, -1}}; 
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            mp[s[i] - 'a'] = i; 

            if (mp[0] != -1 && mp[1] != -1 && mp[2] != -1) {
                cnt += 1 + min(mp[0], min(mp[1], mp[2])); 
            }
        }

        return cnt;
    }
};
