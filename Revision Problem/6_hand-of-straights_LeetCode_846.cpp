// google amazon microsoft meta bloomberg visa
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        map<int,int> mp;
        for(int i = 0;i<n;i++){
            mp[hand[i]]++;
        }
        int tg = n/groupSize;
        for(int i = 0;i<tg;i++){
            int count = 0;
            auto it = mp.begin();
            int prev = it->first-1;
            while(!mp.empty() && count < groupSize){
                if(it == mp.end()) return false;
                int el = it->first;   // el declare pehle, it->first
                if(el != prev + 1) return false;
                mp[el]--;
                if(mp[el] == 0) it = mp.erase(mp.find(el)); // it update karo
                else it++;
                count++;
                prev = el;
                
            }
        }
        return true;
    }
};
