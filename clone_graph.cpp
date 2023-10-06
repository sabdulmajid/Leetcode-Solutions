#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

The Solution class has two primary functions: dfs and cloneGraph. The dfs function is a private helper function used to deep copy (or clone) a graph node and its neighbors recursively. It uses a depth-first search approach to traverse and clone the graph. The unordered_map named mp is used to keep track of nodes that have already been cloned, ensuring that we don't end up in infinite loops and also to reuse the already cloned nodes when encountering them again.

The cloneGraph function is the main public function that initiates the cloning process. It starts by checking for edge cases: if the input node is NULL, it returns NULL. If the node has no neighbors (i.e., it's a standalone node), it creates a new node with the same value and returns it. Otherwise, it calls the dfs function to clone the entire graph starting from the given node.

*/

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end())   //already clone and stored in map
                {
                    neighbour.push_back(mp[it]);    //directly push back the clone node from map to neigh
                }
                else
                    neighbour.push_back(dfs(it,mp));
            }
            clone->neighbors=neighbour;
            return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)   //if only one node present no neighbors
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
    }
};