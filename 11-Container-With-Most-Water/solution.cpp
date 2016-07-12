class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0) return 0;
        int i = 0, j = height.size() - 1;
        int maxn = INT_MIN;
        while(i <= j){
            int h = min(height[i], height[j]);
            maxn = max(maxn, (j - i) * h);
            while(i <= j && height[i] <= h) i++;
            while(i <= j && height[j] <= h) j--;
        }
        return maxn;
    }
};