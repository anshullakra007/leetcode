#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
    bool isValid(const string& str) {
        int count = 0;
        for (char ch : str) {
            if (ch == '(') count++;
            else if (ch == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; ++k) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    result.push_back(curr);
                    found = true;
                }

                if (found) continue;

                for (int i = 0; i < curr.size(); ++i) {
                    if (curr[i] != '(' && curr[i] != ')') continue;

                    string next_str = curr.substr(0, i) + curr.substr(i + 1);
                    if (visited.find(next_str) == visited.end()) {
                        visited.insert(next_str);
                        q.push(next_str);
                    }
                }
            }

            if (found) break;
        }

        return result;
    }
};