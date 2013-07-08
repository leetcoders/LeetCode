/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 8, 2013
 Problem:    Word Ladder II
 Difficulty: High
 Source:     http://leetcode.com/onlinejudge#question_126
 Notes:
 Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
 Only one letter can be changed at a time
 Each intermediate word must exist in the dictionary
 For example,
 Given:
 start = "hit"
 end = "cog"
 dict = ["hot","dot","dog","lot","log"]
 Return
 [
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
 ]
 Note:
 All words have the same length.
 All words contain only lowercase alphabetic characters.

 Solution: Idea is from blog: http://blog.csdn.net/niaokedaoren/article/details/8884938
*/

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        map<string, vector<string>> traces; // If A->C and B->C, then traces[C] contains A and B.
                                            // This is used for recovering the paths.
        vector<unordered_set<string>> level(2);
        int cur = 0;
        int prev = 1;
        level[cur].insert(start);
        dict.insert(end);

        while (true)
        {
            prev = !prev;
            cur = !cur;
            level[cur].clear();

            // remove visited words. IMPORTANT!
            for (unordered_set<string>::iterator it = level[prev].begin(); it != level[prev].end(); ++it)
                dict.erase(*it);

            for (unordered_set<string>::iterator it = level[prev].begin(); it != level[prev].end(); ++it)
            {
                string word = *it;
                for (size_t i = 0; i < word.size(); i++) {
                    char before = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == before)
                            continue;
                        word[i] = c;
                        if (dict.find(word) != dict.end()) {
                            traces[word].push_back(*it);
                            level[cur].insert(word);
                        }
                    }
                    word[i] = before;
                }
            }

            if (level[cur].empty() || level[cur].count(end) > 0)
                break;
        }

        vector<vector<string>> res;
        vector<string> onePath;
        if (!traces.empty())
            buildResult(traces, res, onePath, end);

        return res;
    }

    void buildResult(map<string, vector<string>> &traces, vector<vector<string>> &res, vector<string> &onePath, string word)
    {
        if (traces.count(word) == 0)
        {
            vector<string> copy(onePath);
            copy.push_back(word);
            reverse(copy.begin(), copy.end());
            res.push_back(copy);
            return;
        }

        const vector<string> &s = traces[word];
        onePath.push_back(word);
        for (vector<string>::const_iterator it = s.begin(); it != s.end(); ++it)
            buildResult(traces, res, onePath, *it);
        onePath.pop_back();
    }
};