class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxn = 0, h;
        int i = 0, j = height.size() - 1;
        while(i < j){
            h = min(height[i], height[j]);
            maxn = max(maxn, (j - i) * h);
            while(i < j && height[i] <= h) ++i;
            while(i < j && height[j] <= h) --j;
        }
        return maxn;
    }
};