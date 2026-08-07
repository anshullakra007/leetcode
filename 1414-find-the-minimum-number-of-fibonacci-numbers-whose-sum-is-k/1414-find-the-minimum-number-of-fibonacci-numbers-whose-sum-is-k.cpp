class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        // Step 1: Saare Fibonacci numbers k tak generate karke array me daal lo
        vector<int> fib = {1, 1};
        while (fib.back() < k) {
            fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
        }
        
        int count = 0;
        
        // Step 2: Peeche (sabse bade) se check karo aur k me se minus karte jao
        for (int i = fib.size() - 1; i >= 0; i--) {
            if (fib[i] <= k) {
                k -= fib[i];
                count++;
            }
        }
        
        return count;
    }
};