class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for (auto b : batteries) sum += b;

        long long left = 1, right = sum / n;

        while (left < right) {
            long long mid = (left + right + 1) / 2;

            long long power = 0;
            for (auto b : batteries)
                power += min((long long)b, mid);

            if (power >= mid * n)
                left = mid;
            else
                right = mid - 1;
        }

        return left;
    }
};