/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
 
 struct  {
    bool operator()(const Interval& in1, const Interval& in2) {
        return in1.start < in2.start;
    }
 }MyComparator;
 
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        intervals.push_back(newInterval);
        std::sort(intervals.begin(), intervals.end(), MyComparator);
        
        vector<Interval> ans;
        Interval* pLast = NULL;
        for (auto& cur : intervals) {
            if (!pLast) {
                pLast = &cur;
                continue;
            }
            
            if (cur.start >= pLast->start && cur.start <= pLast->end) {
                pLast->end = ::max(pLast->end, cur.end);
            } else {
                ans.push_back(Interval(pLast->start, pLast->end));
                pLast = &cur;
            }
        }
        
        ans.push_back(Interval(pLast->start, pLast->end));
        return ans;
    }
};
