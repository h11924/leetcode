class Solution {
    
    
    
  public:
    int floorSqrt(int n) {
        // code here
        
        int start=0;
        int end=n;
        
        int ans=0;
        
        while(start<=end){
            long long mid = start + (end - start) / 2;
            long long val = mid * mid;

            if (val == n) {
                return mid;
            }
            else if (val > n) {
                end = mid - 1;
            }
            else {
                ans = mid; // Store potential floor answer
                start = mid + 1;
            }
        }
        
        
        return ans;
        
        
        
    }
};