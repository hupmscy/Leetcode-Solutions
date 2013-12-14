class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> a(rowIndex+1);
        vector<int> b(rowIndex+1);
        int i, j;
        for (i = 0; i <= rowIndex; i++)
        {
            a[0] = 1;
            for (j = 1; j < i; j++)
                a[j] = b[j] + b[j-1];
            if (i > 0)
                a[i] = 1;
            swap(a, b);
        }
        return b;
    }
};
