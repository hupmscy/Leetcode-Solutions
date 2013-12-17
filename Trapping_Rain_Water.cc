class Solution {
public:
    int trap(int A[], int n) {
       int llimit[n+10], rlimit[n+10];
       memset(llimit, 0, sizeof(llimit));
       memset(rlimit, 0, sizeof(rlimit));
       int maxv = 0;
       int i, ans;
       for (i = 0; i < n; i++)
       {
           llimit[i] = maxv;
           maxv = max(maxv, A[i]);
       }
       maxv = 0;
       for (i = n-1; i >= 0; i--)
       {
           rlimit[i] = maxv;
           maxv = max(maxv, A[i]);
       }
       for (i = ans = 0; i < n; i++)
       {
           if (A[i] < llimit[i] && A[i] < rlimit[i])
           {
               int v = min(llimit[i], rlimit[i]);
               ans += v-A[i];
           }
       }
       return ans;
    }
};
