/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 8, 2013
 Problem:    Word Ladder
 Difficulty: High
 Source:     http://leetcode.com/onlinejudge#question_127
 Notes:
 Given two words (start and end), and a dictionary, find the length of shortest transformation 
 sequence from start to end, such that:
 Only one letter can be changed at a time
 Each intermediate word must exist in the dictionary
 For example,
 Given:
 start = "hit"
 end = "cog"
 dict = ["hot","dot","dog","lot","log"]
 As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 return its length 5.
 Note:
 Return 0 if there is no such transformation sequence.
 All words have the same length.
 All words contain only lowercase alphabetic characters.

 Solution: BFS.
*/

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<pair<string, int>> q;
        q.push(make_pair(start, 1));
        while (!q.empty())
        {
            pair<string, int> front = q.front();
            q.pop();
            string word = front.first;
            for (size_t i = 0; i < word.size(); i++)
            {
                char before = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (word == end)
                        return front.second + 1;
                    if (dict.find(word) != dict.end())
                    {
                        q.push(make_pair(word, front.second + 1));
                        dict.erase(word);
                    }
                }
                word[i] = before;
            }
        }
        return 0;
    }
};