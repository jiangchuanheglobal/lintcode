/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int start, end, mid;
        start = 1;
        end = n;
        
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (SVNRepo::isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        return SVNRepo::isBadVersion(start) ? start : end;
    }
};
