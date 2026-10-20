#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        // 1. Precompute prefixMax and suffixMin to validate block boundaries in O(1)
        vector<int> prefix_max(n);
        vector<int> suffix_min(n);

        prefix_max[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix_max[i] = max(prefix_max[i - 1], nums[i]);
        }

        suffix_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = min(suffix_min[i + 1], nums[i]);
        }

        // 2. Precompute internal drop prefix sums to check internal descents in O(1)
        // drop[i] = 1 if nums[i] > nums[i + 1] else 0
        vector<int> drop_pref(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            drop_pref[i + 1] = drop_pref[i] + (nums[i] > nums[i + 1] ? 1 : 0);
        }

        // 3. Find all divisors of n
        vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }

        int total_sum = 0;

        for (int k : divisors) {
            bool valid = true;

            // Check boundary condition: prefix_max[start - 1] <= suffix_min[start]
            for (int start = k; start < n; start += k) {
                if (prefix_max[start - 1] > suffix_min[start]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;

            // Check each block has at most 1 cyclic drop
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;

                if (k == 1) continue;

                // Internal drops inside nums[start .. end]
                int internal_drops = drop_pref[end] - drop_pref[start];
                // Wrap-around drop from the last element to the first
                int wrap_drop = (nums[end] > nums[start]) ? 1 : 0;

                if (internal_drops + wrap_drop > 1) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                total_sum += k;
            }
        }

        return total_sum;
    }
};