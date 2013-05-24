/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 24, 2013
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
              First, move 'end'. When find all the needed characters, move 'start'.
           2. Use array as map.
 */

class Solution {
public:
    string minWindow(string S, string T) {
        int N = S.size(), M = T.size();
        int need[256] = {0};
        int find[256] = {0};
        for (int i = 0; i < M; ++i)
            need[T[i]]++;

        int count = 0;
        string res;
        int res_size = N + 1;
        for (int start = 0, end = 0; end < N; ++end)
        {
            if (need[S[end]] == 0)
                continue;

            find[S[end]]++;
            if (find[S[end]] <= need[S[end]])
                count++;

            if (count != M)
                continue;

            while (start < end) {
                if (need[S[start]] == 0 || find[S[start]] > need[S[start]]) {
                    find[S[start]]--;
                    start++;
                } else {
                    break;
                }
            }
            if (end - start + 1 < res_size)
            {
                res = string(S.begin() + start, S.begin() + end + 1);
                res_size = res.size();
            }
        }
        return res;
    }
};