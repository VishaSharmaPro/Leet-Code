// google amazon microsoft apple zoho tiktok vk nextdoor
class Solution {
public:
    int compareVersion(string version1, string version2) {
        unordered_map<int,vector<int>> mp1;
        unordered_map<int,vector<int>> mp2;
        int n = version1.size();
        int i= 0;
        int dot = 0;
        while(i < n){
            if(version1[i] == '.'){
                dot++;
            } else {
                mp1[dot].push_back(version1[i] - '0');  // fix: char - '0' se int
            }
            i++;
        }
        int m = version2.size();                        // fix: m alag rakho
        int j = 0;
        dot = 0;
        while(j < m){                                   // fix: m use karo n nahi
            if(version2[j] == '.'){
                dot++;
            } else {
                mp2[dot].push_back(version2[j] - '0'); // fix: char - '0' se int
            }
            j++;
        }
        int maxdots = max(mp1.size(),mp2.size());
            for(int d = 0;d< maxdots;d++){
                int num1 = 0;
                if(mp1.find(d) != mp1.end()){
                    for(int x : mp1[d]) num1 = num1*10 + x;
                }
                int num2 = 0;
                if(mp2.count(d)){
                    for(int x : mp2[d]) num2 = num2*10 + x;
                }
                if(num1 > num2) return 1;
                else if(num1 < num2) return -1; 
        }
        return 0;
    }
};
