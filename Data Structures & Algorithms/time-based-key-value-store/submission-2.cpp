class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> logs;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        logs[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& log = logs[key];
        int l = 0, r = log.size() - 1;
        string result = "";
        while (l <= r){
            int mid = l + (r - l)/2;
            if (log[mid].first <= timestamp){
                result = log[mid].second;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return result;
    }
};
