class Solution {
public:
    bool canJump(int A[], int n) {
       int maxv = 0;
       for (int i = 0; i < n; i++)
        {
            if (i > maxv)
                return false;
            if (A[i]+i > maxv)
                maxv = A[i]+i;
        }
        return true;
    }
};
