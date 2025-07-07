// Company == Google
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int i = 0;
        int j = 1;
        int fchar = word[i];
        if(fchar > 96){
            for(int i =0 ;i<n;i++){
                int num  = word[i];
                if(num < 97) return false;
            }
            return true;
        }
        int schar = word[j];
        if(fchar <97 && schar > 96){
            for(int i =2 ;i<n;i++){
                int num  = word[i];
                if(num < 97) return false;
            }
            return true;
        }
        if(fchar <97 && schar <97){
            for(int i =2 ;i<n;i++){
                int num  = word[i];
                if(num > 96) return false;
            }
            return true;
        }
        return true;
    }
};
