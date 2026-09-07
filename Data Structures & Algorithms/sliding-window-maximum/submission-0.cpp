class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> local_max;
        vector<int> ans;
        int l = 0;
        
        for (int r = 0; r < nums.size(); r++){
            while (!local_max.empty() and nums[local_max.back()] < nums[r]){
                local_max.pop_back();
            }

            local_max.push_back(r);

            if (local_max.front() < l){
                local_max.pop_front();
            }

            if (r - l + 1 == k){
                ans.push_back(nums[local_max.front()]);
                l++;
            }
        }
        return ans;
    }
};
