class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        if (num.size() == 0)
            return ans;
        multimap<int, pair<int, int> > exist;
        int i, j, k;
        sort(num.begin(), num.end());
        for (i = 0; i < num.size(); i++)
        for (j = i+1; j < num.size(); j++)
            exist.insert(make_pair(num[i]+num[j], make_pair(i, j)));

        multimap<int, pair<int, int> >::iterator iter;
        for (i = 0; i < num.size(); i++)
        for (j = i+1; j < num.size(); j++)
        {
            int v = num[i]+num[j];
            if ((iter = exist.find(target-v)) != exist.end())
            {
                while (iter != exist.end() && iter->first == target-v)
                {
                    if ((iter->second).first > j)
                    {
                        vector<int> tmp(4);
                        tmp[0] = num[i];
                        tmp[1] = num[j];
                        tmp[2] = num[(iter->second).first];
                        tmp[3] = num[(iter->second).second];
                        for (k = 0; k < ans.size(); k++)
                            if (ans[k][0]==tmp[0] && ans[k][1]==tmp[1] && ans[k][2]==tmp[2] && ans[k][3]==tmp[3])
                                break;
                        if (k == ans.size())
                            ans.push_back(tmp);
                    }
                    iter++;
                }
            }
        }
        return ans;
    }
};
