class Solution {
public:
    int trap1(vector<int>& height) {
        int maxn = 0;
        int leftmax = 0, rightmax = 0;
        int i = 0, j = height.size() - 1;
        while(i <= j){
            leftmax = max(leftmax, height[i]);
            rightmax = max(rightmax, height[j]);
            if(leftmax < rightmax){
                maxn += (leftmax - height[i]);
                ++i;
            }else{
                maxn += (rightmax - height[j]);
                --j;
            }
        }
        return maxn;
    }
    int trap(vector<int>& height) {
        int maxn = 0;
        //int leftmax = 0, rightmax = 0;
        int i = 0, j = height.size() - 1;
        while(i < j){
            int minn = min(height[i], height[j]);
            std::cout << i << ' ' << j << std::endl;
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