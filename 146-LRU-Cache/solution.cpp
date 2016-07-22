class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity_ = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()){
            return -1;
        }else{
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return cacheMap[key]->second;
        }
    }
    
    void set(int key, int value) {
        if(cacheMap.find(key) != cacheMap.end()){
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key]->second = value;
        }else if(capacity_ == cacheList.size()){
            int key = cacheList.back().first;
            cacheMap.erase(key);
            cacheList.pop_back();
        }
        cacheList.push_front(make_pair(key, value));
        cacheMap[key] = cacheList.begin();
    }
private:
    int capacity_;
    list<int, int> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
};