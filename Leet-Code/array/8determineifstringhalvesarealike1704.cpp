//Company Tags                : Google, Amazon, Microsoft, Meta
class Solution {
public:
    bool isVowel(char & ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || 
                ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
    }
    bool halvesAreAlike(string s) {
        int n = s.length();
        int cl = 0;
        int cr =0;
        int i = 0;
        for(char &ch : s){
            if(i<n/2 && isVowel(s[i])) cl++;
            if(i>=n/2 && isVowel(s[i])) cr++;
            i++; 
        }
        return cr == cl;
    }
};
