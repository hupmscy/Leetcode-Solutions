class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int cur = gas[0], start = 0, ans = 1, size, ans_start;
        size = gas.size();
        for (int i = 1; i <= gas.size()*2; i++)
        {
            cur -= cost[(i-1)%size];
            if (cur >= 0)
            {
                if (i-start+1 > ans)
                {
                    ans_start = start%size;
                    ans = i-start+1;
                }
            }
            else
            {
                cur = 0;
                start = i;
            }
            cur += gas[i%size];
        }
        return ans > size ? ans_start : -1;
    }
};
