/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        return bruteForce(points);
    }
    
    int bruteForce(vector<Point>& points) {
        int n = points.size();
        if (n < 2) return n;
        
        int max_points = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // get a line
                // (points[i], points[j])
                int line_points = 0;
                for (auto& p : points) {
                    if (sameSpot(points[i], points[j])) {
                        if (sameSpot(p, points[i])) {
                            line_points += 1;
                        }
                    } else {
                        if (pointOnLine(points[i], points[j], p)) {
                            line_points += 1;
                        }
                    }
                }
                max_points = ::max(max_points, line_points);
            }
        }
        return max_points;
    }
    
    bool pointOnLine(const Point& p1, const Point& p2, const Point& p) {
        return (p.x - p1.x) * (p2.y - p1.y) == (p.y - p1.y) * (p2.x - p1.x);
    }

    bool sameSpot(const Point& p1, const Point& p2) {
      return p1.x == p2.x && p1.y == p2.y;
    }
};
