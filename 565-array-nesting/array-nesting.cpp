class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            int j = i;

            while (nums[j] != -1) {
                int next = nums[j];
                nums[j] = -1;   // visited
                j = next;
                count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};