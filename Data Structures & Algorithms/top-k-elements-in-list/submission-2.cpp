class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);
        for(int num: nums){
            count[num]++;
        }
        
        int max_freq = 0;
        for (const auto& entry: count){
            freq[entry.second].push_back(entry.first);
            max_freq = max(entry.second, max_freq);
        }

        vector<int> ans;
        for (int i = max_freq; max_freq >= 0; max_freq--){
            for (int num: freq[max_freq]){
                ans.push_back(num);
                if (ans.size() == k){
                    return ans;
                }
            }
        }
        return ans;
    }
};
