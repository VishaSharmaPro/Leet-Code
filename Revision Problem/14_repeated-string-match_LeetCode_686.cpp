// google amazon microsoft meta amazon bloomberg uber
// method1
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m = a.length();
        int n = b.length();
        for(int start = 0; start < m; start++){   // fix: har starting position try karo
            int i = start;
            int j = 0;
            int count = 1;
            while(j < n){
                if(i == m){
                    count++;
                    i = 0;
                }
                if(a[i] != b[j]) break;
                i++;
                j++;
            }
            if(j == n) return count;   // fix: pura b match hua
        }
        return -1;
    }
};

// method2
class Solution {
public:
    bool isSubstring(string rep,string b){
        int m = rep.length();
        int n = b.length();
        for(int i = 0;i<=m-n;i++){
            int j = 0;
            while(j<n && rep[i+j] == b[j]){
                j++;
            }
            if(j == n) return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int m = a.length();
        string rep = a;
        int n = b.length();
        int count = 1;
        while(rep.length()<n){
            rep += a;
            count++;
        }
        if(isSubstring(rep,b)) return count;
        rep += a;
        count++;
        if(isSubstring(rep,b)) return count;
        return -1;
    }
};
