#include <stdio.h>
#include <limits.h>

#define V 5 
int min(int a, int b) {
    return (a < b) ? a : b;
}

int minEdges(int graph[][V]) {
    int minEdgeCount = INT_MAX;

    for (int start = 0; start < V; start++) {
        int visited[V] = {0}; 
        visited[start] = 1;   

        int current = start;
        int edgeCount = 0;

        for (int count = 1; count < V; count++) {
            int next = -1;
            for (int v = 0; v < V; v++) {
                if (!visited[v] && (next == -1 || graph[current][v] < graph[current][next])) {
                    next = v;
                }
            }
            visited[next] = 1;
            edgeCount += graph[current][next];

            current = next;
        }

        edgeCount += graph[current][start];

        minEdgeCount = min(minEdgeCount, edgeCount);
    }

    return minEdgeCount;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20, 30},
        {10, 0, 35, 25, 40},
        {15, 35, 0, 30, 50},
        {20, 25, 30, 0, 60},
        {30, 40, 50, 60, 0}
    };

    int minEdgesRequired = minEdges(graph);
    printf("Minimum edges required to traverse all vertices: %d\n", minEdgesRequired);

    return 0;
}

