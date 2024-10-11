#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> kClosest(vector<pair<int, int>> &pts, int n, int k) {
    // max heap to store points based on their distance from the origin
    priority_queue<pair<int, pair<int, int>>> pq;
    
    for(auto &p : pts) {
        // Calculate squared distance to avoid floating point issues
        int dist = p.first * p.first + p.second * p.second;
        pq.push(make_pair(dist, p));
        
        // Keep only the closest 'k' points
        if(pq.size() > k) {
            pq.pop(); // removing the farthest point from the heap
        }
    }

    // Result vector to store k closest points
    vector<pair<int, int>> res;
    
    while(!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }

    // Since the heap will give us points in reverse order (farthest to closest),
    // we need to reverse the result vector.
    reverse(res.begin(), res.end());

    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> pts(n);

    for(auto &p : pts) {
        cin >> p.first >> p.second;
    }

    // Get the k closest points
    vector<pair<int, int>> closestPts = kClosest(pts, n, k);

    // Output the result
    for(auto p : closestPts) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
