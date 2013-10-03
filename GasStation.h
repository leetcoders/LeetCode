/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 3, 2013
 Problem:    Gas Station
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/gas-station/
 Notes:
 There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 The solution is guaranteed to be unique.

 Solution: ...
*/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();
        int res = 0, min = gas[0] - cost[0], sum = min;
        for (int i = 1; i < N; ++i)
        {
            sum += gas[i] - cost[i];
            if (sum < min) {
                min = sum;
                res = i;
            }
        }
        return sum >= 0 ? (res + 1) % N : -1;
    }
};