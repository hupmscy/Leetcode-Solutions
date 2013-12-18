class Solution {
public:

    double single_median(int A[], int n)
    {
        if (n & 1)
            return A[n/2];
        else
            return (double(A[n/2])+A[n/2-1])/2;
    }

    int search(int k, int A[], int m, int B[], int n)
    {
        int l = 0;
        int r = m-1;
        int mid, j;
        while (l <= r)
        {
            mid = (l+r)/2;
            j = k-mid-1;
            if (j < 0)
            {
                if (j+1 < n && j+1 >= 0 && A[mid] <= B[j+1])
                    return mid;
                else
                    r = mid-1;
            }
            else if (j+1 >= n)
            {
                if (j < n && B[j] <= A[mid])
                    return mid;
                else
                    l = mid+1;
            }
            else
            {
                if (B[j] <= A[mid] && A[mid] <= B[j+1])
                    return mid;
                else if (A[mid] < B[j])
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        return -1;
    }

    int find_k(int k, int A[], int m, int B[], int n)
    {
        int res = search(k, A, m, B, n);
        if (res != -1)
            return A[res];
        else
        {
            res = search(k, B, n, A, m);
            return B[res];
        }
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (n == 0)
            return single_median(A, m);
        else if (m == 0)
            return single_median(B, n);
        if ((m+n)&1)
            return find_k((m+n)/2, A, m, B, n);
        else
        {
            int v1 = find_k((m+n)/2, A, m, B, n);
            int v2 = find_k((m+n)/2-1, A, m, B, n);
            return double(v1+v2)/2;
        }
    }
};
