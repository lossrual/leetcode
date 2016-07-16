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
    int maxPoints(vector<Point>& points) {
        int maxn = 0;
        for(int i = 0; i < points.size(); i++){
            int res = 0, same = 0, inf = 0;
            unordered_map<float, int> mp;
            for(int j = i + 1; j < points.size(); j++){
                if(points[i].x == points[j].x){
                    if(points[i].y != points[j].y)
                        ++inf;
                    else
                        ++same;
                    continue;
                }
                float slope = (float)(points[j].y - points[i].y) / (float)(points[j].x - points[i].x);
                mp[slope]++;
                res = max(res, mp[slope]);
            }
            res = max(res, inf) + same + 1;
            maxn = max(maxn, res);
        }
        return maxn;
    }
};