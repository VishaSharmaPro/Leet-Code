// Company == Microsoft
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n =  strs.size();
        int e = strs[0].length();
        int del = 0;
        for(int x= 0; x<e;x++){
            for(int i = 0;i<n-1;i++){
                if(strs[i][x] > strs[i+1][x]) {
                    del++;
                    break;
                }
            }
        }
        return del;
    }
};
