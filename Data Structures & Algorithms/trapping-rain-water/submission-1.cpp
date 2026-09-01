class Solution {
public:
    int trap(vector<int>& height) {
        int l_max = 0, r_max = 0, l = 0, r = height.size() - 1, trapped = 0;
        while (l < r){
            if (height[l] < height[r]){
                l_max = max(l_max, height[l]);
                trapped += l_max - height[l];
                l++;
            }else {
                r_max = max(r_max, height[r]);
                trapped += r_max - height[r];
                r--;
            }
        }
        return trapped;
    }
};
