// microsoft meta linkedin bloomberg
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> mp;
        for(auto & it : reservedSeats){
            mp[it[0]].push_back(it[1]);
        }
        int res = (n - (int)mp.size())*2;
        for(auto &it : mp){
            bool left = true, right = true, middle = true;
            for(int &num : it.second){
                if(num>=2 && num<=5) left = false;
                if(num>=4 && num<=7) middle = false;
                if (num >= 6 && num <= 9) right = false;
            }
            if(left && right) res +=2;
            else if (left || middle || right) {
                res += 1;
            }
        }
        return res;
    }
};
