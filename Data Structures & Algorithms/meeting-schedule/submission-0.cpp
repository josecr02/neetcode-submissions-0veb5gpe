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
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
       // consider the sorted order by start time. 
       // Then any overlap means that one interval ends after the next start time.
       // so we compare start time with ending of last interval.
       sort (intervals.begin(), intervals.end(), [](auto& x, auto& y){
        return x.start < y.start;
       });
       for (int i = 1; i < intervals.size(); ++i){
        if (intervals[i].start < intervals[i-1].end){
            return false;
        }
       } 
       return true;
    }
};
