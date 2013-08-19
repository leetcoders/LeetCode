/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 10, 2013
 Problem:    Median of Two Sorted Arrays
 Difficulty: Hard
 Source:     http://leetcode.com/onlinejudge#question_4
 Notes:
 There are two sorted arrays A and B of size m and n respectively. 
 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

 Solution: 1. O(m+n)
           2. O(log(m+n))
           3. O(logm + logn)
*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        return findMedianSortedArrays_1(A, m, B, n);
    }

    double findMedianSortedArrays_1(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        int m1 = 0, m2 = 0;
        int total = m + n;

        for (int k = 0; k <= total / 2; ++k)
        {
            int a = (i == m) ? INT_MAX : A[i];
            int b = (j == n) ? INT_MAX : B[j];

            m1 = m2;
            m2 = min(a, b);

            if (a < b) i++;
            else j++;
        }

        if (total & 0x1) return m2;
        else return (m1 + m2) / 2.0;
    }

    double findMedianSortedArrays_2(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total & 0x1)
            return findKthSortedArrays(A, m, B, n, total / 2 + 1);
        else
            return (findKthSortedArrays(A, m, B, n, total / 2) + findKthSortedArrays(A, m, B, n, total / 2 + 1)) / 2;
    }

    double findKthSortedArrays(int A[], int m, int B[], int n, int k) {
        if (m > n)
            return findKthSortedArrays(B, n, A, m, k);
        if (m == 0) return B[k-1];
        if (k == 1) return min(A[0], B[0]);

        int i = min(k / 2, m);
        int j = k - i;
        int a = A[i-1];
        int b = B[j-1];

        if (a < b) return findKthSortedArrays(A + i, m - i, B, n, k - i);
        else if (a > b) return findKthSortedArrays(A, m, B + j, n - j, k - j);
        else return a;
    }

    double findMedianSortedArrays_3(int A[], int m, int B[], int n) {
        return findMedian(A, m, B, n, max(0, (m + n) / 2 - n), min(m - 1, (m + n) / 2));
    }

    double findMedian(int A[], int m, int B[], int n, int l, int r) {
        if (l > r)
            return findMedian(B, n, A, m, max(0, (m + n) / 2 - m), min(n, (m + n) / 2));

        int i = (l + r) / 2;
        int j = (m + n) / 2 - i;

        int Ai_1 = (i == 0) ? INT_MIN : A[i-1];
        int Bj_1 = (j == 0) ? INT_MIN : B[j-1];
        int Ai = (i == m) ? INT_MAX : A[i];
        int Bj = (j == n) ? INT_MAX : B[j];

        if (Ai < Bj_1) return findMedian(A, m, B, n, i+1, r);
        if (Ai > Bj) return findMedian(A, m, B, n, l, i-1);

        if ((m + n) % 2 == 1) return Ai;
        else return (Ai + max(Ai_1, Bj_1)) / 2.0;
    }
};
