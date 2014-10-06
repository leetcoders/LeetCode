/*
 Author:     King, higuige@gmail.com
 Date:       Sep 24, 2014
 Update:     Oct 06, 2014
 Problem:    Maximum Product Subarray
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/maximum-product-subarray/
 Notes:
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.

 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
*/
class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n <= 0) {
            return 0;
        }
        int maxVal = A[0], minVal = A[0], res = A[0];
        for (int i = 1; i < n; ++i) {
            int tmpVal = maxVal;
            maxVal = max(max(maxVal * A[i], minVal * A[i]), A[i]);
            minVal = min(min(tmpVal * A[i], minVal * A[i]), A[i]);
            res = max(res, maxVal);
        }
        return res;
    }

    int maxProduct_2(int A[], int n) {
        if(n==0) return 0;
        if(n==1) return A[0];
        int minVal = 0;
        int product = 1;
        int res = A[0];
        for(int i=0;i<n;i++){
            product = product*A[i];
            if(product<0){
                if(minVal==0) minVal=product;
                else {
                    res = max(res,product/minVal);
                    minVal=max(minVal,product);
                }
            }else if(product==0){
                res = max(res,product);
                product = 1;
                minVal=0;
            }else{
                res = max(res,product);
            }
        }
        return res;
    }
};
