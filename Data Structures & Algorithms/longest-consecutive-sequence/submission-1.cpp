class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> nums_set(nums.begin(), nums.end());
        int max_seq = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums_set.contains(nums[i]-1)){
                continue;
            }
            int n = 0;
            while (nums_set.contains(nums[i] + n)){
                n++;
            }
            max_seq = max(n, max_seq);
        }
        return max_seq;
    }
};
