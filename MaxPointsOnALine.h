/*
 Author:     Matthew Jin, marthew777@gmail.com : King, higuige@gmail.com
 Date:       Dec 03, 2014
 Problem:    Max Points On a Line
 Difficulty: Easy
 Notes:
 Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 Solution: 1. hashmap. Time: O(n^2), Space: O(n);
           2. high precision.
*/

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
    struct pt {
        int dx, dy;
        pt(){dx = 0; dy = 0;}
        pt(int x, int y) {
            int g = gcd(abs(x), abs(y));
            if (x==0 && y==0) dx=0,dy=0;
            else if(x==0) dx=0,dy=1;
            else if(y==0) dx=1,dy=0;
            else if(y>0) dx=x/g,dy=y/g;
            else if(y<0) dx=-x/g,dy=-y/g;
        }
        int gcd(int a, int b) {
            if(b == 0) return a;
            else return gcd(b, a%b);
        }
        bool operator==(const pt &b) const {
            return dx == b.dx && dy == b.dy;
        }
        bool operator<(const pt &b) const {
            if(dx == b.dx) return dy < b.dy;
            return dx < b.dx;
        }
    };

    int maxPoints_1(vector<Point> &points) {
        int N = points.size(), res(0);
        unordered_map<double, int> m;
        for (int i =0; i < N; ++i) {
            m.clear();
            int ss(1), sp(0);// ss: points with same slope, sp: same points.
            for (int j = i + 1; j < N; ++j) {
                double slope = std::numeric_limits<double>::infinity();
                if (points[i].x != points[j].x) {
                    slope = 1.0*(points[i].y-points[j].y)/(points[i].x-points[j].x);
                } else if (points[i].y == points[j].y) {
                    ++sp; continue;
                }
                int tmp = 0;
                if(m.find(slope) != m.end()) tmp = ++m[slope];
                else tmp = m[slope] = 2;
                ss = max(ss, tmp);
            }
            res = max(res, ss + sp);
        }
        return res;
    }

    int maxPoints_2(vector<Point> &points) {
        int N = points.size(), res(0);
        pt zero(0,0);
        map<pt, int> m;
        for (int i=0; i < N; ++i) {
            m.clear();
            int ss(0), sp(0);
            for (int j = 0; j < N; ++j) {
                pt slope(points[i].x-points[j].x, points[i].y-points[j].y);
                if (slope == zero) ++sp;
                else {
                    ss = max(ss, ++m[slope]);
                }
            }
            res = max(res, ss + sp);
        }
        return res;
    }
};