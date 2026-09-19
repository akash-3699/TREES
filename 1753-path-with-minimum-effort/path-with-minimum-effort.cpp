class Solution {
public:
    int rw[4] = {-1,0,0,1};
    int cl[4] = {0,-1,1,0};

    bool valid(int a,int b,int c,int d){
        return a>=0 && b>=0 && a<c && b<d;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>> efforts(row, vector<int>(col, INT_MAX));
        efforts[0][0] = 0;

        priority_queue<pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>> p;

        p.push({0, {0,0}});

        while (!p.empty()) {
            auto [e, pos] = p.top();
            auto [r, c] = pos;
            p.pop();

            // Skip stale entries
            if (e > efforts[r][c]) continue;

            if (r == row-1 && c == col-1) return e; // early exit (optional)

            for (int k = 0; k < 4; k++) {
                int new_r = r + rw[k];
                int new_c = c + cl[k];

                if (!valid(new_r, new_c, row, col)) continue;

                int new_effort = max(e, abs(heights[new_r][new_c] - heights[r][c]));

                if (new_effort < efforts[new_r][new_c]) {
                    efforts[new_r][new_c] = new_effort;
                    p.push({new_effort, {new_r, new_c}});
                }
            }
        }

        return efforts[row-1][col-1];
    }
};