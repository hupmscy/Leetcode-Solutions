class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ans;
        for (int i = 0; i < int(pow(2.0, n)); i++)
            ans.push_back(i^(i>>1));
        return ans;
    }
};
