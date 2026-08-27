class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        // vector<vector<int>> freq(nums.size() + 1);
        for(int num: nums){
            count[num]++;
        }
        
        // int max_freq = 0;
        // for (const auto& entry: count){
        //     freq[entry.second].push_back(entry.first);
        //     max_freq = max(entry.second, max_freq);
        // }

        // vector<int> ans;
        // for (int i = max_freq; max_freq >= 0; max_freq--){
        //     for (int num: freq[max_freq]){
        //         ans.push_back(num);
        //         if (ans.size() == k){
        //             return ans;
        //         }
        //     }
        // }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (const auto& entry: count){
            pq.push({entry.second, entry.first});
            if (pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
