class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long threshold = 1000; // 10^3

        while (n >= threshold) {
            totalCommas += (n - threshold + 1);
            if (threshold > LLONG_MAX / 1000) break; // Prevent overflow
            threshold *= 1000;
        }

        return totalCommas;
    }
};