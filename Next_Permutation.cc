class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() <= 1)
            return;
        int i, j, min_v, min_ind;
        for (j = num.size()-2; j >= 0; j--)
            if (num[j] < num[j+1])
                break;
        if (j == -1)
        {
            sort(num.begin(), num.end());
            return;
        }
        for (i = j+1, min_v = INT_MAX; i < num.size(); i++)
            if (num[i] > num[j] && num[i] < min_v)
            {
                min_v = num[i];
                min_ind = i;
            }
        swap(num[j], num[min_ind]);
        vector<int>::iterator iter = num.begin();
        for (i = 0; i <= j ;iter++, i++);
        sort(iter, num.end());
    }
};
