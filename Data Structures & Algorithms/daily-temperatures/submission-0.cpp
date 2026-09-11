class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> max_temp;
        vector<int> ans(temperatures.size(), 0); 
        for (int i = temperatures.size() - 1; i >= 0; i--){
            while (!max_temp.empty() and temperatures[max_temp.top()] <= temperatures[i]){
                max_temp.pop();
            }
            if (max_temp.empty()){
                ans[i] = 0;
            }else{
                ans[i] = max_temp.top() - i;
            }
            max_temp.push(i);
        }
        return ans;
    }
};
