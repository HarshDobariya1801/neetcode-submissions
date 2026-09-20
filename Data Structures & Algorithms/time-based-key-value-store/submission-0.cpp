class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> m;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       m[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {

        if (m.find(key) == m.end()) {
            return "";
        }

        auto &v = m[key];

        int left = 0;
        int right = v.size() - 1;

        string ans = "";

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (v[mid].first <= timestamp) {
                ans = v[mid].second;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */