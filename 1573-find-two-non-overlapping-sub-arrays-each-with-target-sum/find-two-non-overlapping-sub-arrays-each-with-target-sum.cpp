class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        vector<int> best(n, INT_MAX);

        int l = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int r = 0; r < n; r++) {

            sum += arr[r];

            while (sum > target && l <= r) {
                sum -= arr[l];
                l++;
            }

            if (sum == target) {

                int len = r - l + 1;

                // Previous non-overlapping subarray
                if (l > 0 && best[l - 1] != INT_MAX) {
                    ans = min(ans, best[l - 1] + len);
                }

                // Store minimum length till r
                if (r == 0)
                    best[r] = len;
                else
                    best[r] = min(best[r - 1], len);

            } else {

                if (r > 0)
                    best[r] = best[r - 1];
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};