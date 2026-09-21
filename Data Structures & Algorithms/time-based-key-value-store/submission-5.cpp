class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> KeyStore;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        KeyStore[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        const auto& logs = KeyStore[key];
        int l = 0, r = logs.size() - 1;
        int result = -1;
        while (l <= r){
            int mid = l + (r - l)/2;
            if (logs[mid].first <= timestamp){
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result != -1 ? logs[result].second : "";
    }
};
