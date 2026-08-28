class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set<int> nums_set(nums.begin(), nums.end());
        int max_seq = 0;
        unordered_map <int, int> mp;
        for (int num: nums){
            if(!mp[num]){
                mp[num] = mp[num+1] + mp[num-1] + 1;
                mp[num + mp[num + 1]] = mp[num];
                mp[num - mp[num - 1]] = mp[num];
                max_seq = max(mp[num], max_seq); 
            }
        }
        // for (int num: nums){
        //     if (nums_set.contains(num - 1)){
        //         continue;
        //     }
        //     int n = 0;
        //     while (nums_set.contains(num + n)){
        //         n++;
        //     }
        //     max_seq = max(n, max_seq);
        // }
        return max_seq;
    }
};
