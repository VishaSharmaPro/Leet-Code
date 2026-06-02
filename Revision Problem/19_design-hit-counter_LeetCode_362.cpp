// google amazon microosft meta yandex atlassian bloomberg databricks apple uber openai roblox coupang cloudflare reddit affirm careem walmart
class HitCounter {
public:
    vector<int> times;
    vector<int> count;
    HitCounter() {
        times.resize(300,0);
        count.resize(300,0);
    }
    
    void hit(int timestamp) {
        int id = timestamp%300;
        if(times[id] != timestamp){
             times[id] = timestamp;
             count[id]= 1;
        }else{
            count[id]++;
        }
    }
    
    int getHits(int timestamp) {
        int total = 0;
        for(int i = 0;i<300;i++){
            if(times[i] != 0 && timestamp-times[i] < 300){
                total += count[i];
            }
        }
        return total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */


// method = 2
class HitCounter {
public:
    vector<int> hits;
    
    HitCounter() {}
    
    void hit(int timestamp) {
        hits.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        int start = timestamp - 300;  // hits <= start should be removed
        
        int s = 0, e = hits.size() - 1;
        int pos = hits.size();
        
        while(s <= e) {
            int mid = s + (e - s) / 2;
            if(hits[mid] > start) {  // >, not >=
                pos = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        
        return hits.size() - pos;
    }
};
