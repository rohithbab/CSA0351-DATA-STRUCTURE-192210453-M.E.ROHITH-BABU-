#include <stdio.h>
#include <stdbool.h>

#define V 5 
int graph[V][V] = {
    {0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0}
};

void printPath(int path[], int pathLength) {
    for (int i = 0; i < pathLength; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

void dfs(int currentVertex, int destination, bool visited[], int path[], int pathLength) {
    visited[currentVertex] = true;
    path[pathLength] = currentVertex;
    pathLength++;

    if (currentVertex == destination) {
        printPath(path, pathLength);
    } else {
        for (int v = 0; v < V; v++) {
            if (graph[currentVertex][v] == 1 && !visited[v]) {
                dfs(v, destination, visited, path, pathLength);
            }
        }
    }

    visited[currentVertex] = false;
}

void printValidPaths(int source, int destination) {
    bool visited[V] = {false};
    int path[V];
    int pathLength = 0;

    dfs(source, destination, visited, path, pathLength);
}

int main() {
    int source = 0;       
    int destination = 4;  
    printf("Valid paths from %d to %d:\n", source, destination);
    printValidPaths(source, destination);

    return 0;
}

