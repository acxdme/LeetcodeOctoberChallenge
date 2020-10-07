class RecentCounter {
    vector<int> v;
public:
    RecentCounter() {
        
    }
    
    int ping(int t)
    {
        v.push_back(t);
        return v.end() - lower_bound(v.begin(), v.end(), t-3000);
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
