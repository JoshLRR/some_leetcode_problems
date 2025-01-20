import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.HashMap;
import java.util.HashSet;

class All_Ancestors_of_a_Node_in_a_Directed_Acylic_Graph {
    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        HashMap<Integer, List<Integer>> graph = new HashMap<>();
        List<List<Integer>> ancestorList = new ArrayList<>();

        for (int[] edgePair : edges) {
            List<Integer> list = graph.getOrDefault(edgePair[1], new ArrayList<>());
            list.add(edgePair[0]);
            graph.put(edgePair[1], list);  // Put the updated list back into the map
        }

        // Print the graph to verify the result
        for (Map.Entry<Integer, List<Integer>> entry : graph.entrySet()) {
            System.out.println("Key: " + entry.getKey() + " -> " + entry.getValue());
        }

        // Initialize the ancestorList with empty lists
        for (int i = 0; i < n; i++) {
            ancestorList.add(new ArrayList<>());
        }

        // Helper function for DFS to find all ancestors
        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                findAncestors(i, graph, ancestorList, visited);
            }
        }

        // Sort each ancestor list in ascending order
        for (List<Integer> ancestors : ancestorList) {
            Collections.sort(ancestors);
        }

        return ancestorList;
    }

    private void findAncestors(int node, HashMap<Integer, List<Integer>> graph, List<List<Integer>> ancestorList, boolean[] visited) {
        visited[node] = true;

        if (!graph.containsKey(node)) {
            return;
        }

        for (int ancestor : graph.get(node)) {
            if (!visited[ancestor]) {
                findAncestors(ancestor, graph, ancestorList, visited);
            }
            ancestorList.get(node).add(ancestor);
            ancestorList.get(node).addAll(ancestorList.get(ancestor));
        }

        // Remove duplicates if any (this can be optimized)
        HashSet<Integer> uniqueAncestors = new HashSet<>(ancestorList.get(node));
        ancestorList.get(node).clear();
        ancestorList.get(node).addAll(uniqueAncestors);
    }

    public static void main(String[] args) {
        All_Ancestors_of_a_Node_in_a_Directed_Acylic_Graph solution = new All_Ancestors_of_a_Node_in_a_Directed_Acylic_Graph();

        int n1 = 8;
        int[][] edgeList1 = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
        List<List<Integer>> ans1 = new ArrayList<>();
        ans1.add(new ArrayList<>()); // Add an empty list
        ans1.add(new ArrayList<>()); // Add another empty list
        ans1.add(new ArrayList<>()); // Add another empty list
        ans1.add(List.of(0, 1)); // Add a list with elements 0 and 1
        ans1.add(List.of(0, 2)); // Add a list with elements 0 and 2
        ans1.add(List.of(0, 1, 3)); // Add a list with elements 0, 1, and 3
        ans1.add(List.of(0, 1, 2, 3, 4)); // Add a list with elements 0, 1, 2, 3, and 4
        ans1.add(List.of(0, 1, 2, 3)); // Add a list with elements 0, 1, 2, and 3

        int n2 = 5;
        int[][] edgeList2 = {{0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};
        List<List<Integer>> ans2 = List.of(
            List.of(),
            List.of(0),
            List.of(0, 1),
            List.of(0, 1, 2),
            List.of(0, 1, 2, 3)
        );

        long startTime = System.nanoTime();
        List<List<Integer>> test1 = solution.getAncestors(n1, edgeList1);
        // List<List<Integer>> test2 = solution.getAncestors(n2, edgeList2);
        long endTime = System.nanoTime();
        assert test1 == ans1 : "Test 1 failed, got " + test1 + " instead of " + ans1;
        // assert test2 == ans2 : "Test 2 failed, got " + test2 + " instead of " + ans2;
        

        double time = (endTime - startTime) / 1e6;
        
        System.out.println("\033[32mAll tests passed in " + time + "ms!\033[0m");
    }
}