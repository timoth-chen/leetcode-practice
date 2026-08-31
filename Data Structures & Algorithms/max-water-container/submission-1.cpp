class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area= 0;
        int l = 0, r = heights.size()-1;
        while (l < r){
            int cur_area = min(heights[l], heights[r]) * (r - l);
            max_area = max(max_area, cur_area);
            if(heights[l] > heights[r]){
                r--;
            }else{
                l++;
            }
        }
        return max_area;
    }
};
