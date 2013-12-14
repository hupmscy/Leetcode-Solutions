class Solution {
public:
    int numTrees(int n) {
        long long ans = 1;
        for (long long i = 2*n; i > n; i--)
            ans *= i;
        for (long long i = 2; i <= n; i++)
            ans /= i;
        return ans / (n+1);
    }
};
