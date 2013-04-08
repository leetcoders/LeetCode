/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Problem:    Sort Colors
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_75
 Notes:
 Given an array with n objects colored red, white or blue, sort them so that objects of the same color
 are adjacent, with the colors in the order red, white and blue.
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 Note:
 You are not suppose to use the library's sort function for this problem.
 Follow up:
 A rather straight forward solution is a two-pass algorithm using counting sort.
 First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with 
 total number of 0's, then 1's and followed by 2's.
 Could you come up with an one-pass algorithm using only constant space?

 Solution: The idea is similar to quick-sort. Traverse the array from both side and try to push all the '0'
           to the beginning and all the '2' to the back (f_1 is used to indicate the index of first '1' in the array).
 */

class Solution {
public:
    void sortColors(int A[], int n) {
        int f_1 = -1;   // index of first 1
        int f = 0;
        int b = n - 1;
        
        while (f <= b)
        {
            while (A[b] == 2)
                b--;
            while (A[f] == 1 && f_1 != -1 ||
                   A[f] == 0 && f_1 == -1) 
                f++;
            
            if (f > b)
                break;
            
			if (A[f] == 0 && f_1 != -1)
            {
                swap(A[f], A[f_1++]);
            }
            if (A[f] == 1 && f_1 == -1)
            {
                f_1 = f;
            }
            if (A[f] == 2 && A[b] != 2)
            {
                swap(A[f], A[b]);
            }
        }
    }
};