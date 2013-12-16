class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        unordered_map<string, int> lookup;
        for (int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (lookup.find(tmp) == lookup.end())
                lookup.insert(make_pair(tmp, i));
            else
            {
                if (lookup[tmp] >= 0)
                {
                    ans.push_back(strs[lookup[tmp]]);
                    lookup[tmp] = -1;
                }
                ans.push_back(strs[i]);
            }
        }
        return ans;
    }
};
