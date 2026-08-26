/*class Solution {

    private:

    void merge(int start,int mid,int end,vector<int>& nums,int &count){

        int left=start;
        int right=mid+1;


        vector<int> temp;


        while(left<=mid && right<=end){
            if(nums[left]>(2*nums[right])){
                temp.push_back(nums[right]);
                right++;
                count+=mid-left+1;


            }

            else{
                temp.push_back(nums[left]);
                left++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right<=end){
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = 0; i < temp.size(); i++) {
    nums[start + i] = temp[i];
}
    }
    void mergesort(int start,int end,vector<int>& nums,int &count){
        //break

        if(start>=end) return;

        int mid= start + (end-start)/2;

        mergesort(start,mid,nums,count);
        mergesort(mid+1,end,nums,count);

        merge(start,mid,end,nums,count);


    }
public:
    int reversePairs(vector<int>& nums) {

        int count=0;

        mergesort(0,nums.size()-1,nums,count);

        return count;
        
    }
};*/

#include <vector>
using namespace std;

class Solution {
private:
    void merge(int start, int mid, int end, vector<int>& nums, int &count) {

        // STEP 1: Count Reverse Pairs (nums[i] > 2 * nums[j])
        int j = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (j <= end && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // STEP 2: Standard Merge Sort (Sort by value so array stays ordered)
        int left = start;
        int right = mid + 1;

        vector<int> temp;

        while (left <= mid && right <= end) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= end) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = 0; i < temp.size(); i++) {
            nums[start + i] = temp[i];
        }
    }

    void mergesort(int start, int end, vector<int>& nums, int &count) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;

        mergesort(start, mid, nums, count);
        mergesort(mid + 1, end, nums, count);

        merge(start, mid, end, nums, count);
    }

public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergesort(0, nums.size() - 1, nums, count);
        return count;
    }
};