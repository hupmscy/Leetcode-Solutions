class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        if (numbers.size() == 0)
            return ans;
        int n = numbers.size();
        unordered_map<int, int> lookup;
        for (int i = 0; i < n; i++)
            lookup.insert(make_pair(numbers[i], i));
        for (int i = 0; i < n; i++)
        {
            int v = target - numbers[i];
            if (lookup.find(v) != lookup.end() && lookup[v] < i)
            {
                ans.push_back(lookup[v]+1);
                ans.push_back(i+1);
                return ans;
            }
        }
    }
};
