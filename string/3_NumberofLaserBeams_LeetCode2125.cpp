class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int pc = 0;
        int cc = 0;
        int result = 0;
        int n = bank.size(); 
        for(int i = 0; i < n; i++){
            for(char & ch : bank[i]){
                if(ch == '1'){
                    cc++;
                }
            }
            if(cc > 0) { 
                result += cc * pc;
                pc = cc;
                cc = 0;
            }
        }
        return result;
    }
};
