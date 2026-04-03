// google amazon microsoft meta doordash bllomberg apple coupang adobe flipkart walmart yandex linkedin
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int minsum = 0;
        vector<int> ans;
        pair<int,int> p;
        int currsum = 0;
        for(int i = 0;i<k;i++){
            minsum += abs(x-arr[i]);
        }
        currsum = minsum;
        p = {0,k-1};
        int i = 1;
        int j = k;
        while(i<n && j<n){
            currsum -= abs(x-arr[i-1]);
            currsum += abs(x-arr[j]);
            if(currsum <minsum){
                p = {i,j};
                minsum = currsum;
            }
            i++;
            j++;
        }
        for(int i = p.first;i<=p.second;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
