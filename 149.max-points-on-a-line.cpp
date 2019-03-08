/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (15.55%)
 * Total Accepted:    113.2K
 * Total Submissions: 727.6K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[2,2],[3,3]]
 * Output: 3
 * Explanation:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 * Explanation:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 * 
 * 
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
class Solution
{
  public:
    int maxPoints(vector<Point> &points)
    {
        if (points.size() < 1)
            return 0;
        if (points.size() == 1)
            return 1;
        for (int i = 1; i < points.size(); i++)
        {
            if ((points[0].x == points[1].x) && (points[0].y == points[1].y))
            {
                swap(points[1], points[i]);
            }
        }
        vector<tuple<Point&, Point&, int>> m;
        m.push_back(forward_as_tuple(points[0], points[1], 2));
        for (int i = 2; i < points.size(); i++)
        {
            vector<pair<Point&, Point&>> tmp;
            for (auto &j : m)
            {
                auto &[p0, p1, num] = j;
                if (p1.y - p0.y == 0 && points[i].y - p0.y == 0)
                {
                    num++;
                    continue;
                }
                if ((p0.x == points[i].x && p0.y == points[i].y) || (p1.x == points[i].x && p1.y == points[i].y))
                {
                    num++;
                    continue;
                }
                if ((p1.y - p0.y == 0 && points[i].y - p0.y != 0) || (p1.y - p0.y != 0 && points[i].y - p0.y == 0))
                {
                    tmp.push_back(pair<Point&, Point&>(p0, points[i]));
                    tmp.push_back(pair<Point&, Point&>(p1, points[i]));
                    continue;
                }
                if (1.0 * (p1.x - p0.x) / (p1.y - p0.y) == 1.0 * (points[i].x - p0.x) / (points[i].y - p0.y))
                {
                    num++;
                }
                else
                {
                    tmp.push_back(pair<Point&, Point&>(p0, points[i]));
                    tmp.push_back(pair<Point&, Point&>(p1, points[i]));
                }
            }
            for (auto &j : tmp)
            {
                m.push_back(forward_as_tuple(j.first, j.second, 2));
            }
        }
        int res = 0;
        for (auto &i : m)
        {
            res = max(get<2>(i), res);
        }
        return res;
    }
    void swap(Point &a, Point &b)
    {
        auto tmpx = a.x;
        a.x = b.x;
        b.x = tmpx;
        auto tmpy = a.y;
        a.y = b.y;
        b.y = tmpy;
    }
};
