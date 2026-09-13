class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        // Collect coordinates of all 1s from both matrices
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) ones1.push_back({r, c});
                if (img2[r][c] == 1) ones2.push_back({r, c});
            }
        }

        // Count shift vector frequencies
        // Use an encoded integer key (dr * 100 + dc) to avoid custom hash on pair
        unordered_map<int, int> shiftCount;
        int maxOverlap = 0;

        for (const auto& [r1, c1] : ones1) {
            for (const auto& [r2, c2] : ones2) {
                int dr = r2 - r1;
                int dc = c2 - c1;
                int key = dr * 100 + dc;
                
                shiftCount[key]++;
                maxOverlap = max(maxOverlap, shiftCount[key]);
            }
        }

        return maxOverlap;
    }
};