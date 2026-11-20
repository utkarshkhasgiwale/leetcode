class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size() - 1;
        int left = 0;
        // int minHeight = INT_MAX;
        // int width = 0;
        int ans = 0;

        while(left < right){
         int minHeighet = min(height[left], height[right]);
         int width = right - left;

         int area = minHeighet*width;

         if(area > ans) ans = area;

         if(minHeighet == height[left]) left++;
         else right--;
          
        }
        return ans;

    }
};