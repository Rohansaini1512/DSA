#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    unordered_map<char, int> p1;

    // Check if the sizes are different
    if (s1.size() != s2.size()) {
        cout << "False";
        return 0;
    }

    // Count frequency of characters in s1
    for (char c : s1) {
        p1[c]++;
    }

    // Check characters in s2
    for (char c : s2) {
        if (p1.find(c) == p1.end() || p1[c] == 0) {
            cout << "False";
            return 0;
        }
        p1[c]--;
    }

    // Check if all counts are zero
    for (auto ele : p1) {
        if (ele.second != 0) {
            cout << "False";
            return 0;
        }
    }

    cout << "True";
    return 0;
}
