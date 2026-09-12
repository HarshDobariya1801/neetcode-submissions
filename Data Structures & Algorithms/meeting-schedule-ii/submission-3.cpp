/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
private:
    static bool comp(const Interval &a, const Interval &b){
      
        return (a.start < b.start);
    }
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);

        int n = intervals.size();

        if(n == 0) return 0;

       priority_queue<int, vector<int>, greater<int>> pq;
       pq.push(intervals[0].end);

       for(int i = 1; i < n; i++){
            if(intervals[i].start >= pq.top()){
                pq.pop();
            }

            pq.push(intervals[i].end);
       }

       return pq.size();
        
    }
};
