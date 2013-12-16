/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

 bool cmp(Interval a, Interval b)
 {
     return a.start < b.start;
 }

class Solution {
public:
    bool overlap(int ax, int ay, int bx, int by)
    {
        if (ax <= bx)
            return bx <= ay;
        else
            return ax <= by;
    }
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {

        int start = newInterval.start;
        int end = newInterval.end;

        for (vector<Interval>::iterator iter = intervals.begin(); iter != intervals.end();)
        {
            int cur_start = iter->start;
            int cur_end = iter->end;
            if (overlap(cur_start, cur_end, start, end))
            {
                intervals.erase(iter);
                if (cur_start < start)
                    start = cur_start;
                if (cur_end > end)
                    end = cur_end;
            }
            else
                iter++;
        }
        intervals.push_back(Interval(start, end));
        sort(intervals.begin(), intervals.end(), cmp);
        return intervals;
    }
};
