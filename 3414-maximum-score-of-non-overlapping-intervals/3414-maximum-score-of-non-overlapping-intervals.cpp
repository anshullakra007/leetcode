#include <vector>
#include <algorithm>
#include <array>

using namespace std;

class Solution {
    struct Interval {
        int l, r, weight, id;
    };

    struct State {
        long long weight = 0;
        vector<int> indices;

        // Custom comparator: higher weight first, tie-break by lexicographically smaller indices
        bool operator<(const State& other) const {
            if (weight != other.weight) {
                return weight < other.weight;
            }
            return indices > other.indices; // smaller vector is "greater/better"
        }
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort by right endpoint, then left endpoint, then id
        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            if (a.r != b.r) return a.r < b.r;
            return a.l < b.l;
        });

        // Precompute binary search predecessor for each interval
        vector<int> prev(n, -1);
        for (int i = 0; i < n; ++i) {
            int low = 0, high = i - 1, best = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid].r < arr[i].l) {
                    best = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            prev[i] = best;
        }

        // dp[k][i+1] stores the best State using at most k intervals from arr[0...i]
        vector<vector<State>> dp(5, vector<State>(n + 1));

        for (int i = 0; i < n; ++i) {
            int p = prev[i]; // 0-indexed predecessor, corresponds to p + 1 in dp
            for (int k = 1; k <= 4; ++k) {
                // Option 1: Skip current interval
                State best = dp[k][i];

                // Option 2: Pick current interval
                State take = dp[k - 1][p + 1];
                take.weight += arr[i].weight;
                take.indices.push_back(arr[i].id);
                sort(take.indices.begin(), take.indices.end());

                if (best < take) {
                    best = take;
                }

                dp[k][i + 1] = best;
            }
        }

        return dp[4][n].indices;
    }
};