// google amazon mcirosoft meta bloomberg adobe autodesk udemy goldman apple tcs accenture walmart flipkart tiktok zoho yandex
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int left = (n1+n2+1)/2;
        int i = 0;
        int j = 0;
        int prev = 0;
        for(int k = 0;k<left;k++){
            if(i<n1 && (j>=n2 || nums1[i] < nums2[j]) ){
                prev = nums1[i];
                i++;
            }else if(j<n2 && (i>=n1 || nums1[i] >= nums2[j]) ){
                prev = nums2[j];
                j++;   
            }
        }
        if(n%2 != 0){
            return prev;
        }
        int a = INT_MAX;
        if(i<n1) a = min(a,nums1[i]);
        if(j<n2) a = min(a,nums2[j]);
        return (double)(prev + a)/2;
    }
};
