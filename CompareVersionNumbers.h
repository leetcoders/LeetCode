/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 15, 2014
 Problem:    Compare Version Numbers
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/compare-version-numbers/
 Notes:
 Compare two version numbers version1 and version1.
 If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

 You may assume that the version strings are non-empty and contain only digits and the . character.
 The . character does not represent a decimal point and is used to separate number sequences.
 For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

 Here is an example of version numbers ordering:

 0.1 < 1.1 < 1.2 < 13.37

 Solution: ...
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1len = version1.size(), v2len = version2.size();
        for (int i = 0, j = 0; (i < v1len || j < v2len); ) {
        	long long a = 0, b =0;
        	while (i < v1len && version1[i] != '.') {
        		a = a * 10 + version1[i++] - '0';
        	}
        	++i;
        	while (j < v2len && version2[j] != '.') {
        		b = b * 10 + version2[j++] - '0';
        	}
        	++j;
        	if (a > b) return 1;
        	if (a < b) return -1;
        }
    	return 0;
    }
};