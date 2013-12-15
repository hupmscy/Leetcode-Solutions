class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m+n-1;
        int a, b;
        a = m-1;
        b = n-1;
        while (a >= 0 && b >= 0)
        {
            if (A[a] > B[b])
                A[i--] = A[a--];
            else
                A[i--] = B[b--];
        }
        while (b >= 0)
            A[i--] = B[b--];
    }
};
