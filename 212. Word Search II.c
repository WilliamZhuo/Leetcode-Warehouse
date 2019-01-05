//use modified bfs,
//for each word
//step1. find all nodes containing the same character as ch1 in word, and push them into queue 1
//step2.  all neighbors of queue containing the same character as ch2 in word, and push them into queue 2
//repeat until the last character in the word, if there is something in the queue len(word), there is such word, otherwise there is no such word
//problem: the repeat ch problem
//solution: let's call the nodes in step1 "source node", and for each node in step1, it has an unique id
//for each node, it has a queue to record the id if a node is visited by a source
 

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
    }
};