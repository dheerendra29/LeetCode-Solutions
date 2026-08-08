class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> first;
        unordered_map<int, int> last;

        int degree = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (!first.count(nums[i]))
                first[nums[i]] = i;

            last[nums[i]] = i;
            freq[nums[i]]++;

            degree = max(degree, freq[nums[i]]);
        }

        int ans = nums.size();

        for (auto& p : freq) {
            int x = p.first;

            if (p.second == degree) {
                ans = min(ans, last[x] - first[x] + 1);
            }
        }

        return ans;
    }
};