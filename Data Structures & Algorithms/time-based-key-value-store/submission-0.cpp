class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int l=0, r=mp[key].size()-1;

        string khooshi = "";
        if(mp.find(key)==mp.end())return khooshi;

        while(l<=r){
            int m = l + (r-l)/2;

            if(mp[key][m].first <= timestamp){
                khooshi = mp[key][m].second;
                l=m+1;
            }
            else r = m-1;
        }
        return khooshi;
    }
};
