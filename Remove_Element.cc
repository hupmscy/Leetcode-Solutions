class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int wpos, rpos;
        for (rpos = wpos = 0; rpos < n; rpos++)
            if (A[rpos] != elem)
                A[wpos++] = A[rpos];
        return wpos;
    }
};
