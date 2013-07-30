/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 24, 2013
 Update:     Jul 30, 2013
 Problem:    Minimum Window Substring
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_76
 Notes:
 Given a string S and a string T, find the minimum window in S which will contain all the 
 characters in T in complexity O(n).
 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".
 Note:
 If there is no such window in S that covers all characters in T, return the empty string "".
 If there are multiple such windows, you are guaranteed that there will always be only one unique 
 minimum window in S.

 Solution: 1. Use two pointers: start and end. 
              First, move 'end'. After finding all the needed characters, move 'start'.
           2. Use array as hashtable.
 */

class Solution {
public:
    string minWindow(string S, string T) {
        int N = S.size(), M = T.size();
        if (N < M) return "";
        int need[256] = {0};
        int find[256] = {0};
        for (int i = 0; i < M; ++i)
            need[T[i]]++;

        int count = 0;
        int res_start = -1, res_end = N;
        for (int start = 0, end = 0; end < N; ++end)
        {
            if (need[S[end]] == 0)
                continue;
            
            if (find[S[end]] < need[S[end]])
                count++;
            find[S[end]]++;

            if (count != M)
                continue;
            // move 'start'
            start = getNextIndex(S, find, need, start);
            // update result
            if (end - start < res_end - res_start)
            {
                res_start = start;
                res_end = end;
            }
        }
        return (res_start == -1) ? "" : S.substr(res_start, res_end - res_start + 1);
    }
    
    int getNextIndex(string &S, int *find, int *need, int start)
    {
        int i = start, N = S.size();
        for (; i < N; ++i)
        {
            if (need[S[i]] == 0)
                continue;
            if (find[S[i]] <= need[S[i]])
                break;
            find[S[i]]--;
        }
        return i;
    }
};
