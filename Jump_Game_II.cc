class Solution {
public:

    int jump(int A[], int n) {
        int l, r, ans, r_next;
        l = r = ans = 0;
        if (n == 1)
            return 0;
        while (true)
        {
            ans++;
            r_next = r+1;
            for (int i = l; i <= r; i++)
                if (i+A[i] >= r_next)
                    r_next = i+A[i];
            if (r_next >= n-1)
                return ans;
            l = r+1;
            r = r_next;
        }
    }
};
