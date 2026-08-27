class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int max_seq = 0;
        for (int num: nums){
            if (nums_set.contains(num - 1)){
                continue;
            }
            int n = 0;
            while (nums_set.contains(num + n)){
                n++;
            }
            max_seq = max(n, max_seq);
        }
        return max_seq;
    }
};
