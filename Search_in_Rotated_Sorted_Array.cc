class Solution {
public:

    int b_search(int A[], int l, int r, int target)
    {
        int mid;
        int l_copy = l;
        int r_copy = r;
        while (l <= r)
        {
            mid = (l+r)/2;
            if (A[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        if (l > r_copy || A[l] != target)
            return -1;
        return l;
    }

    int search(int A[], int n, int target) {
        int l = 0;
        int r = n-1;

        if (A[0] < A[n-1])
            return b_search(A, 0, n-1, target);

        while (l <= r)
        {
            int mid = (l+r)/2;
            if (A[mid] >= A[0])
                l = mid+1;
            else
                r = mid-1;
        }
        if(target >= A[0])
            return b_search(A, 0, l-1, target);
        else
            return b_search(A, l, n-1, target);
    }
};
