/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 26, 2014
 Problem:    Two Sum III - Data structure design 
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/
 Notes:
 Design and implement a TwoSum class. 
 It should support the following operations: add and find.
 add - Add the number to an internal data structure.
 find - Find if there exists any pair of numbers which sum is equal to the value.
 For example
 add(1); add(3); add(5);find(4) -> true; find(7) -> false,
 Solution: Thanks to Javaman Cao.
 */

class TwoSum {
public:
    unordered_map<int,int> hash;
    void add(int number) {
        ++hash[number];
    }
    bool find(int value) {
        for (unordered_map<int,int>::iterator t = hash.begin(); t != hash.end(); ++t) {
            int x = value - t->first;
            if (x <= t->first) {
                unordered_map<int,int>::iterator it = hash.find(x); 
                if ((it != hash.end()) && ((t != it)  || (it->second > 1))) {
                    return true;
                }
            }
        }
        return false;
    }
};