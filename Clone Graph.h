/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Sep 26, 2013
 Problem:    Clone Graph
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/clone-graph/
 Notes:
 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 
 OJ's undirected graph serialization:
 Nodes are labeled from 0 to N - 1, where N is the total nodes in the graph.
 We use # as a separator for each node, and , as a separator for each neighbor of the node.
 As an example, consider the serialized graph {1,2#2#2}.
 The graph has a total of three nodes, and therefore contains three parts as separated by #.
 Connect node 0 to both nodes 1 and 2.
 Connect node 1 to node 2.
 Connect node 2 to node 2 (itself), thus forming a self-cycle.
 Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

 Solution: 1. DFS. 2. BFS.
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    typedef UndirectedGraphNode GraphNode;
    typedef unordered_map<GraphNode *, GraphNode *> MAP;
    
    GraphNode *cloneGraph(GraphNode *node) {
        return cloneGraph_1(node);
    }
    
    // DFS
    GraphNode *cloneGraph_1(GraphNode *node) {
        MAP map;
        return cloneGraphRe(node, map);
    }
    
    GraphNode *cloneGraphRe(GraphNode *node, MAP &map) {
        if (!node) return NULL;
        if (map.find(node) != map.end())
            return map[node];
        GraphNode *newNode = new GraphNode(node->label);
        map[node] = newNode;
        for (int i = 0; i < node->neighbors.size(); ++i)
            newNode->neighbors.push_back(cloneGraphRe(node->neighbors[i], map));
        return newNode;
    }
    
    // BFS
    GraphNode *cloneGraph_2(GraphNode *node) {
        if (!node) return NULL;
        queue<GraphNode*> q;
        q.push(node);
        MAP map;
        map[node] = new GraphNode(node->label);
        while (!q.empty())
        {
            GraphNode *oriNode = q.front(); q.pop();
            GraphNode *newNode = map[oriNode];
            for (int i = 0; i < oriNode->neighbors.size(); ++i)
            {
                GraphNode *oriNeighbor = oriNode->neighbors[i];
                if (map.find(oriNeighbor) != map.end()) {
                    newNode->neighbors.push_back(map[oriNeighbor]);
                    continue;
                }
                GraphNode *newNeighbor = new GraphNode(oriNeighbor->label);
                newNode->neighbors.push_back(newNeighbor);
                map[oriNeighbor] = newNeighbor;
                q.push(oriNeighbor);
            }
        }
        return map[node];
    }
};