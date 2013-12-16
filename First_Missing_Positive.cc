class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; i++)
        {
            int v = A[i];
            while (v > 0 && v <= n && A[v-1] != v)
            {
                int tmp = A[v-1];
                A[v-1] = v;
                v = tmp;
            }
        }
        for (int i = 0; i < n; i++)
            if (A[i] != i+1)
                return i+1;
        return n+1;
    }
};
