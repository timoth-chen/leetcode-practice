class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int num: nums){
            count[num]++;
        }
        unordered_map<int, vector<int>> value_at_count;
        int max_freq = 0;
        for (const auto &[key, value] : count){
            value_at_count[value].push_back(key);
            max_freq = max(value, max_freq);
        }

        vector<int> ans;
        while(k > 0){
            for (int i = 0; i < value_at_count[max_freq].size(); i ++){
                ans.push_back(value_at_count[max_freq][i]);
                k--;
                if (k <= 0){
                    break;
                }
            }
            max_freq--;
        }
        return ans;
    }
};
