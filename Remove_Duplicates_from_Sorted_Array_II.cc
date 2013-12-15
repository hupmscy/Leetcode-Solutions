class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int wpos, i, j, k;
        i = wpos = 0;
        while (i < n)
        {
            j = i+1;
            while (j < n && A[j] == A[i])j++;
            for (k = i; k < min(i+2, j); k++)
                A[wpos++] = A[k];
            i = j;
        }
        return wpos;
    }
};
