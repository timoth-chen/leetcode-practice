class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> seen = {};
        for (int i = 0; i < n; i++){
            auto it = seen.find(target - nums[i]);
            if (it != seen.end()){
                return {it->second, i};
            }
            seen.insert({nums[i], i});
        }
        return {-1, -1};
    }
};
