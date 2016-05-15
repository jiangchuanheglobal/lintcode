/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        if (airplanes.size() == 0) return 0;
        vector<pair<int, bool>> nodes;
        // vector<ScanLineNode> nodes(airplanes.size()*2);
        for (auto &i  : airplanes) {
            nodes.push_back(make_pair(i.start, true));
            nodes.push_back(make_pair(i.end, false));
        }
        
        std::sort(nodes.begin(), nodes.end());
        
        int max_num = 0;
        int cnt = 0;
        for (auto &i : nodes) {
            if (i.second == 1) cnt += 1;
            else cnt -= 1;
            max_num = ::max(max_num, cnt);
        }
        return max_num;
    }
};
