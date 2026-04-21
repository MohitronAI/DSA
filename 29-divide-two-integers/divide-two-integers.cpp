class Solution {
public:
    int divide(int dividend, int divisor) {

        // overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = dividend;
        long long b = divisor;

        // make positive safely
        if (a < 0) a = -a;
        if (b < 0) b = -b;

        long long ans = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            ans += multiple;
        }

        // sign apply
        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;

        return (int)ans;
    }
};