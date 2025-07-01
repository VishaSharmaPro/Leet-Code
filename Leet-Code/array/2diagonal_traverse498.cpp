// Company Tags  : Google, Amazon
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rs = mat.size();
        int cs = mat[0].size();
        vector<int> result;
        map<int,vector<pair<int,int>>> mp;
        for(int i =0; i<rs;i++){
            for(int j =0; j<cs;j++){
                mp[i+j].push_back({i,j});
            }
        }
        for(auto &it : mp){
            auto ist = it.second[0].first;
            auto jst = it.second[0].second;
            if((ist+jst)%2 == 0){
                reverse(begin(it.second),end(it.second));
            }
        }
        for(auto &it : mp) {
            for(auto &p : it.second) {
                result.push_back(mat[p.first][p.second]);
            }
        }
        return result;
    }
};
// Diagonal Traverse kei two ways => [i+j] and [i-j]
