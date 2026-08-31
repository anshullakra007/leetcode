class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int first_cp = -1;
        int prev_cp = -1;
        int min_dist = INT_MAX;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr && curr->next) {
            bool is_maxima = (curr->val > prev->val && curr->val > curr->next->val);
            bool is_minima = (curr->val < prev->val && curr->val < curr->next->val);

            if (is_maxima || is_minima) {
                if (first_cp == -1) {
                    first_cp = index;
                } else {
                    min_dist = min(min_dist, index - prev_cp);
                }
                prev_cp = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (first_cp == -1 || first_cp == prev_cp) {
            return {-1, -1};
        }

        return {min_dist, prev_cp - first_cp};
    }
};