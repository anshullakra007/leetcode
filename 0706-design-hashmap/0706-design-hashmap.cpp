class MyHashMap {
public:
    vector<list<pair<int, int>>> mp;
    int M ;

    MyHashMap() {
        M = 1500;
        mp.resize(M);
    }

    int getIdx(int key){
        return key%M;
    }

    auto find(int idx, int key){
        for(auto it = mp[idx].begin(); it != mp[idx].end(); ++it) {
            if(it->first == key){
                return it;
            }
        }

        return mp[idx].end();
    }
    
    void put(int key, int value) {
        int idx = getIdx(key);
        auto it = find(idx, key);

        if(it == mp[idx].end())
            mp[idx].push_back({key, value});
        else 
            it->second = value;
    }
    
    int get(int key) {
        int idx = getIdx(key);
        
        auto it = find(idx, key);
        
        if(it == mp[idx].end())
            return -1;
        
        return it->second;
    }
    
    void remove(int key) {
        int idx = getIdx(key);
        
        auto it = find(idx, key);

        if(it != mp[idx].end())   
            mp[idx].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */