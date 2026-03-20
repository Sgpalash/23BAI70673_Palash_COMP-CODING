class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalhours = 0;

            for (int n : piles) {
                totalhours += (n + mid - 1) / mid;
            }

            if (totalhours <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};