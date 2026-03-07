// google amazon microsoft bloomber oracle meta doordash uber flipkart turing tiktok atlassian accenture deshaw linkeidn
class Solution {
public:
    int n;
    long long counthours(vector<int>& piles, int k){
        long long hours = 0;
        for(int i = 0;i<n;i++){
            hours += (piles[i] + k - 1) / k;
        }
        return hours;
    } 
    int minEatingSpeed(vector<int>& piles, int h) {
        n = piles.size();
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int mid;
        while(s<=e){
            mid = s +(e-s)/2;
            long long totalhours = counthours(piles,mid);
            if(totalhours <= h){
                e = mid-1;
            }else if(totalhours > h){
                s = mid+1;
            }
        }
        return s;
    }
};
