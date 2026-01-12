// Google, Microsoft, Atlassian, Morgan Stanely, Adobe, Uber, Bloomberg, Apple, PhonePe
class Solution {
    public boolean closeStrings(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        if(m != n) return false;
        int[] mpf = new int[26];  // frequency for word1
        int[] mps = new int[26];  // frequency for word2
        for(char ch : word1.toCharArray()) {
            mpf[ch - 'a']++;
        }
        for(char ch : word2.toCharArray()) {
            mps[ch - 'a']++;
        } 
        for(int i = 0;i<26;i++){
            if(mpf[i] != 0 && mps[i] == 0) return false;
        }
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                if(mpf[i] == mps[j] && mpf[i] != 0) {
                    mps[j] = 0;
                    mpf[i] = 0;
                    break;
                }
            }
        }
        for(int i = 0; i < 26; i++) {
            if(mps[i] != 0 || mpf[i] != 0) {
                return false;
            }
        }
        return true;
    }
}
