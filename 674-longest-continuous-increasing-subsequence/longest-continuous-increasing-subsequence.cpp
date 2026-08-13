class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        int len = INT_MIN;
        int cnt = 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                cnt++;
                len = max(len, cnt);
            } else {
                cnt = 1;
                len = max(len, cnt);
            }
        }
        return len;
    }
};