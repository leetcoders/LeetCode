/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Problem:    Simplify Path
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_71
 Notes:
 Given an absolute path for a file (Unix-style), simplify it.

 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"

 Corner Cases:
 Did you consider the case where path = "/../"?
 In this case, you should return "/".
 Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 In this case, you should ignore redundant slashes and return "/home/foo".

 Solution: Add an additional '/' at the end of 'path' for simply detecting the end.
 */

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> res_paths;
        int start = 0;
        path += "/";
        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] != '/')
                continue;
            
            if (start == i) {
                start = i + 1;
                continue;
            }

            string s = string(path.begin()+start, path.begin()+i);
            if (s == "..") {
                if (!res_paths.empty())
                    res_paths.pop_back();
            } else if (s != ".") {
                res_paths.push_back(s);
            }
            start = i + 1;
        }

        string res;
        for (int i = 0; i < res_paths.size(); ++i)
            res = res + "/" + res_paths[i];
        if (res.empty()) res += "/";
        return res;
    }
};