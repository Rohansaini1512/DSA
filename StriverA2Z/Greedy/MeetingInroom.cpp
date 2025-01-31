/*You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Examples :

Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
Input: start[] = [10, 12, 20], end[] = [20, 25, 30]
Output: 1
Explanation: Only one meetings can be held with given start and end timings.
Input: start[] = [1, 2], end[] = [100, 99]
Output: 1*/

class Solution {
public:
    struct Data {
        int start, end;
    };

    static bool cmp(Data val1, Data val2) {
        return val1.end < val2.end; // Sorting by ending time
    }

    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<Data> a(n);
        
        for (int i = 0; i < n; i++) {
            a[i] = {start[i], end[i]};
        }

        sort(a.begin(), a.end(), cmp); // Sorting based on end time

        int cnt = 1, freeTime = a[0].end; // First meeting is selected

        for (int i = 1; i < n; i++) {
            if (a[i].start > freeTime) { // If meeting starts after last selected meeting
                cnt++;
                freeTime = a[i].end;
            }
        }
        
        return cnt;
    }
}