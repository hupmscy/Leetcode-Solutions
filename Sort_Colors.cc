class Solution {
public:
    void sortColors(int A[], int n) {
        int freq[3];
        memset(freq, 0, sizeof(freq));
        int i, j, start, end;
        for (i = 0; i < n; i++)
            freq[A[i]]++;
        for (i = start = end = 0; i < 3; i++)
        {
            start = end;
            end += freq[i];
            for (j = start; j < end; j++)
                A[j] = i;
        }
    }
};
