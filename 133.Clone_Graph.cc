#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* dfs(Node* node) {
        if (OGToNew.find(node) != OGToNew.end()) return OGToNew[node];

        Node* copy = new Node(node->val);
        OGToNew[node] = copy;
        for (auto& neighbor : node->neighbors) {
            copy->neighbors.push_back(dfs(neighbor));
        }
        
        return copy;
    }

    Node* cloneGraph(Node* node) {
        return (node) ? dfs(node) : nullptr;
    }
private:
    std::unordered_map<Node*, Node*> OGToNew;
};

/*
    DFS 

    Using DFS, iterate through each neighbor of the initial node.
    Use an unordered_map as an adjacency list

    Starting with the initial node and using a dfs function, we copy the node and set it as the value to the current Node in the hashmap. 

    Then, we push all of the neighbors into the node's neighbors vector and also call dfs on those nodes.
    
*/

// Utility function to compare two graphs and ensure they are identical but distinct instances
bool compareGraphs(Node* original, Node* cloned, std::unordered_set<Node*>& visited) {
    if (original == nullptr || cloned == nullptr) return original == cloned;
    if (original->val != cloned->val) return false; // Value mismatch
    if (original == cloned) return false; // Same instance, not a deep copy
    if (visited.find(original) != visited.end()) return true; // Already visited this node
    visited.insert(original);
    if (original->neighbors.size() != cloned->neighbors.size()) return false; // Different number of neighbors
    for (size_t i = 0; i < original->neighbors.size(); ++i) {
        if (!compareGraphs(original->neighbors[i], cloned->neighbors[i], visited)) return false;
    }
    return true;
}

// Cleanup utility to prevent memory leaks
void cleanUp(Node* node, std::unordered_set<Node*>& visited) {
    if (!node || visited.find(node) != visited.end()) return;
    visited.insert(node);
    for (Node* neighbor : node->neighbors) {
        cleanUp(neighbor, visited);
    }
    delete node;
}

// Test Case 1: Null Graph
void testNullGraph() {
    Solution solution;
    Node* nullGraph = nullptr;
    Node* clonedGraph = solution.cloneGraph(nullGraph);
    assert(clonedGraph == nullptr);
    std::cout << "Test Case 1 Passed: Null Graph\n";
}

// Test Case 2: Single Node Graph
void testSingleGraphNode() {
    Solution solution;
    Node* singleNode = new Node(1);
    Node* clonedGraph = solution.cloneGraph(singleNode);
    std::unordered_set<Node*> visited;
    assert(compareGraphs(singleNode, clonedGraph, visited));
    std::cout << "Test Case 2 Passed: Single Node Graph\n";
    cleanUp(singleNode, visited); // Cleanup original graph
    visited.clear();
    cleanUp(clonedGraph, visited); // Cleanup cloned graph
}

void testLinearGraph() {
    Solution solution;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node3);

    Node* clonedGraph = solution.cloneGraph(node1);
    std::unordered_set<Node*> visited;
    assert(compareGraphs(node1, clonedGraph, visited));
    std::cout << "Test Case 3 Passed: Linear Graph\n";

    visited.clear();
    cleanUp(node1, visited); // Cleanup original graph
    visited.clear();
    cleanUp(clonedGraph, visited); // Cleanup cloned graph
}

void testGraphWithCycles() {
    Solution solution;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node1); // Create a cycle

    Node* clonedGraph = solution.cloneGraph(node1);
    std::unordered_set<Node*> visited;
    assert(compareGraphs(node1, clonedGraph, visited));
    std::cout << "Test Case 4 Passed: Graph with Cycles\n";

    visited.clear();
    cleanUp(node1, visited); // Cleanup original graph
    visited.clear();
    cleanUp(clonedGraph, visited); // Cleanup cloned graph
}

void testComplexGraph() {
    Solution solution;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3}; // Create a complex, interconnected graph

    Node* clonedGraph = solution.cloneGraph(node1);
    std::unordered_set<Node*> visited;
    assert(compareGraphs(node1, clonedGraph, visited));
    std::cout << "Test Case 5 Passed: Complex Graph\n";

    visited.clear();
    cleanUp(node1, visited); // Cleanup original graph
    visited.clear();
    cleanUp(clonedGraph, visited); // Cleanup cloned graph
}

int main() {
    testNullGraph();
    testSingleGraphNode();
    testLinearGraph();
    testGraphWithCycles();
    testComplexGraph();
    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}
