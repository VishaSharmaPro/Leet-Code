// microsft google amazon meta bloomberg goldman flipkart nvidia oracle adobe visa zoho walmart uber yandex tesla samsung
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n,0);
        int maxheight = 0;
        for(int i = 0;i<n;i++){
            leftmax[i] = maxheight;
            if(height[i]>maxheight){
                maxheight = height[i];
            }
        }
        maxheight = 0;
        vector<int> rightmax(n,0);
        for(int i = n-1;i>=0;i--){
            rightmax[i] = maxheight;
            if(height[i]>maxheight){
                maxheight = height[i];
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            int size = min(rightmax[i],leftmax[i]);
            int water = size - height[i];
            if(water > 0){
                ans += water;
            }
        }
        return ans;
    }
};
