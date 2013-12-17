class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0)
            return 0;
        int wpos, rpos;
        for (rpos = wpos = 1; rpos < n; rpos++)
            if (A[rpos] != A[rpos-1])
                A[wpos++] = A[rpos];
        return wpos;
    }
};
