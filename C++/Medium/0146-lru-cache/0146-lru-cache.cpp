class LRUCache {
private:
    priority_queue<pair<int, int>> pq; // {ctr, key}
    int cap;
    int ctr;
    unordered_map<int, pair<int, int>> mp; // key = {ctr, value}
public:
    LRUCache(int capacity) {
        cap = capacity;
        ctr = 1e6;
    }
    
    int get(int key) {
        if(mp.count(key) == 0){
            return -1;
        }
        put(key, mp[key].second);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        mp[key] = {ctr, value};
        pq.push({ctr, key});
        ctr--;
        while(mp.size() > cap){
            if(mp.count(pq.top().second) != 0 && pq.top().first == mp[pq.top().second].first){
                mp.erase(pq.top().second);
            }
            pq.pop();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */