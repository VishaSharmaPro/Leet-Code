class Solution {
public:
    
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        int bs =0;
        for(int i = 0;i<n;i++){
            int vc = 0;
            int cc = 0;
            if(isVowel(s[i])) vc++;
            else cc++;
            for(int j =i+1;j<n;j++){
                if(isVowel(s[j])) vc++;
                else cc++;
                if(vc == cc && (vc*cc)%k == 0){
                    bs++;
                }
            } 
        }
        return bs;
    }
};
