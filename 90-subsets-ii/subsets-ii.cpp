class Solution {
public:
    void subset(int ind, vector<vector<int>>& ans,
                vector<int>& ds, vector<int>& nums) {

        // Every current subset is a valid answer
        ans.push_back(ds);

        for (int i = ind; i < nums.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > ind && nums[i] == nums[i - 1])
                continue;

            ds.push_back(nums[i]);

            subset(i + 1, ans, ds, nums);

            // Backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Bring duplicates together
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;

        subset(0, ans, ds, nums);

        return ans;
    }
};