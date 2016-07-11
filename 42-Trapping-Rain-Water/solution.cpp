class Solution {
public:
    int trap(vector<int>& height) {
        int maxn = 0;
        int i = 0, j = height.size() - 1;
        while(i < j){
            int minn = min(height[i], height[j]);
            if(height[i] == minn){
                ++i;
                while(i < j && height[i] < minn){
                    maxn += (minn - height[i]);
                    ++i;
                }
            }else{
                --j;
                while(i < j && height[j] < minn){
                    maxn += (minn - height[j]);
                    --j;  
                }
            }
        }
        return maxn;
    }
};