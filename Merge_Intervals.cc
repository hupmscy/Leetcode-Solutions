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
     if (a.start != b.start)
        return a.start < b.start;
    return a.end < b.end;
 }

class Solution {
public:

    bool overlap(Interval &a, int start, int end)
    {
        if (a.start < start)
            return start <= a.end;
        else
            return a.start <= end;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        int i = 0, j, n = intervals.size();
        int start, end;
        if (n == 0)
            return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        while (i < n)
        {
            start = intervals[i].start;
            end = intervals[i].end;
            j = i+1;
            while (j < n && overlap(intervals[j], start, end))
            {
                if (intervals[j].start < start)
                    start = intervals[j].start;
                if (intervals[j].end > end)
                    end = intervals[j].end;
                j++;
            }
            ans.push_back(Interval(start, end));
            i = j;
        }
        sort(ans.begin(), ans.end(), cmp);
        return ans;
    }
};
