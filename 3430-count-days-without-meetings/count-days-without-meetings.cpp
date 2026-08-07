class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int ans = 0;
        int lastEnd = 0;

        for (auto &m : meetings) {
            if (m[0] > lastEnd + 1) {
                ans += m[0] - lastEnd - 1;
            }
            lastEnd = max(lastEnd, m[1]);
        }

        ans += days - lastEnd;
        return ans;
    }
};