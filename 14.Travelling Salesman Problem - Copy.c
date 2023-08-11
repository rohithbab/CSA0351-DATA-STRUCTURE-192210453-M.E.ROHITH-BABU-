#include <stdio.h>
#include <limits.h>

#define V 4 

int tsp(int graph[][V], int mask, int pos, int n) {
    if (mask == (1 << n) - 1) {
        return graph[pos][0]; 
    }

    int minCost = INT_MAX;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { 
            int newMask = mask | (1 << city);
            int newCost = graph[pos][city] + tsp(graph, newMask, city, n);

            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }

    return minCost;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int startingCity = 0;

    int minCost = tsp(graph, 1, startingCity, V);
    
    printf("Minimum cost for TSP: %d\n", minCost);

    return 0;
}

