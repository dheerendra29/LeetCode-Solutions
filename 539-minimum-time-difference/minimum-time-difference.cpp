class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for (string time : timePoints) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));

            minutes.push_back(h * 60 + m);
        }

        sort(minutes.begin(), minutes.end());

        int ans = 1440;

        for (int i = 1; i < minutes.size(); i++) {
            ans = min(ans, minutes[i] - minutes[i - 1]);
        }

        // Difference between last and first through midnight
        ans = min(ans, 1440 - minutes.back() + minutes[0]);

        return ans;
    }
};