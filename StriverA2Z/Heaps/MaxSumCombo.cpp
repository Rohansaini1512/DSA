/*Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.


Example Input
Input 1:

 A = [3, 2]
 B = [1, 4]
 C = 2
Input 2:

 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
 C = 4


Example Output
Output 1:

 [7, 6]
Output 1:

 [10, 9, 9, 8]*/


 vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
sort(A.begin(), A.end());
sort(B.begin(), B.end());
int n = A.size();
priority_queue<pair<int,pair<int,int>>> pq;
for(int i=0; i<n; i++) {
pq.push({A[i]+B[n-1], {i, n-1}});
}
vector<int> ans;
while(C--) {
auto topNode = pq.top();
pq.pop();
int sum = topNode.first;
int x = topNode.second.first;
int y = topNode.second.second;
ans.push_back(sum);
pq.push({A[x]+B[y-1], {x, y-1}});
}
return ans;
}