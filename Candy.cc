class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.size() == 0)
            return 0;
        vector<int> num(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
            if (ratings[i] > ratings[i-1])
                num[i] = num[i-1]+1;
        for (int i = ratings.size()-2; i >= 0; i--)
            if (ratings[i] > ratings[i+1] && num[i] <= num[i+1])
                num[i] = num[i+1]+1;
        int res = 0;
        for (int i = 0; i < num.size(); i++)
            res += num[i];
        return res;
    }
};
