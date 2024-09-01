#include <bits/stdc++.h>
using namespace std;

bool checkIsomorphic(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    
    unordered_map<char, char> map1, map2;
    
    for (int i = 0; i < s1.length(); ++i) {
        if (map1.find(s1[i]) == map1.end()) {
            map1[s1[i]] = s2[i];
        } else {
            if (map1[s1[i]] != s2[i]) {
                return false;
            }
        }
        
        if (map2.find(s2[i]) == map2.end()) {
            map2[s2[i]] = s1[i];
        } else {
            if (map2[s2[i]] != s1[i]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    cout << (checkIsomorphic(s1, s2) ? "Is Isomorphic" : "Not Isomorphic") << endl;

    return 0;
}
