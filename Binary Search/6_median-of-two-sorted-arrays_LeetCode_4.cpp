/* google amazon microsoft meta bloomberg rippling goldman udemy oracle adobe apple tcs wix yandex walmart accenture
   zoho autodesk cognizant palto_alto
  */
// khud sach par optimse nhi hai yeh approach
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m == 0 && n == 0) return 0;

        int total = m + n;
        int med = total/2 + 1;              

        int count = 0;
        int i = 0, j = 0;
        vector<int> st;

        while(i < m && j < n && count < med){
            if(nums1[i] < nums2[j]){
                st.push_back(nums1[i++]);
            }else{
                st.push_back(nums2[j++]);
            }
            count++;
        }
        while(i < m && count < med){ st.push_back(nums1[i++]); count++; }
        while(j < n && count < med){ st.push_back(nums2[j++]); count++; }

        int size = st.size();
        if(total % 2 != 0){                 // odd
            return st[size-1];
        }else{                              // even
            return (st[size-1] + st[size-2]) / 2.0;  //  dono middle ka average
        }
    }
};
