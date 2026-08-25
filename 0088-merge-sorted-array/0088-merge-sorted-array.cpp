class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i=m-1;//nums1
        int j=n-1;//nums2
        int k=n+m-1;//k is in nums1

        while(i>=0 && j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else if (nums1[i]<nums2[j]){
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        //copy the remaining elements from nums2 to back to nums1
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
        
    }
};