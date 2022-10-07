class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // (L.I.S = Longest Increasing Subsequence)
        int maxLen = 1;  // length of L.I.S from 0 to n
        vector<int> tempLIS(n);  // vector with length of L.I.S from 0 to each element
        tempLIS[0] = 1;
      
        for (int i = 1; i < n; i++) {
            int curMaxLen = 0;
            for (int j = i-1; j >= 0; j--) {
                if (nums[j] < nums[i])
                    curMaxLen = max(curMaxLen, tempLIS[j]);
            }
            tempLIS[i] = curMaxLen + 1;
            maxLen = max(maxLen, curMaxLen + 1);
        }
        return maxLen;
    }
};
