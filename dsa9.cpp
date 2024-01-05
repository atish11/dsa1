Assignment 9

Code:
#include <stdio.h>
#include <limits.h>
#define MAX_CITIES 10

int graph[MAX_CITIES][MAX_CITIES];
int numCities;
void initializeGraph() {
    int i, j;
    for (i = 0; i < MAX_CITIES; i++) {
        for (j = 0; j < MAX_CITIES; j++) {
            graph[i][j] = (i == j) ? 0 : INT_MAX; 
        }
    }
}
void addEdge(int source, int destination, int distance) {
    graph[source][destination] = distance;
    graph[destination][source] = distance; 
}
void dijkstra(int source) {
    int distance[MAX_CITIES];
    int visited[MAX_CITIES] = {0};

    for (int i = 0; i < MAX_CITIES; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;
    for (int count = 0; count < MAX_CITIES - 1; count++) {
        int minDistance = INT_MAX, minIndex;

        for (int v = 0; v < MAX_CITIES; v++) {
            if (!visited[v] && distance[v] <= minDistance) {
                minDistance = distance[v];
                minIndex = v;
            }
        }
        visited[minIndex] = 1;

        for (int v = 0; v < MAX_CITIES; v++) {
            if (!visited[v] && graph[minIndex][v] != INT_MAX &&
                distance[minIndex] != INT_MAX && (distance[minIndex] + graph[minIndex][v] < distance[v])) {
                distance[v] = distance[minIndex] + graph[minIndex][v];
            }
        }
    }
    printf("Shortest distances from city %d:\n", source);
    for (int i = 0; i < MAX_CITIES; i++) {
        if (distance[i] == INT_MAX) {
            printf("To city %d: INF\n", i);
        } else {
            printf("To city %d: %d\n", i, distance[i]);
        }
    }
}
void displayGraph() {
    printf("Adjacency Matrix representing the graph:\n");
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            if (graph[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", graph[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, source, destination, distance;
    printf("Enter the number of cities (maximum %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    initializeGraph();

    do {
        printf("\nMenu:\n");
        printf("1. Add an edge\n");
        printf("2. Find shortest path from a source city\n");
        printf("3. Display graph\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source city, destination city, and distance: ");
                scanf("%d %d %d", &source, &destination, &distance);
                addEdge(source, destination, distance);
                break;
            case 2:
                printf("Enter the source city: ");
                scanf("%d", &source);
                if (source >= 0 && source < numCities) {
                    dijkstra(source);
                } else {
                    printf("Invalid source city. Please enter a valid city.\n");
                }
                break;
            case 3:
                displayGraph();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
Output:
 
 
