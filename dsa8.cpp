Assignment 8
Code:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 10

struct Edge {
    int source, destination, weight;
};
struct Subset {
    int parent, rank;
};
struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    struct Edge *edgeList;
    int numEdges;
};
void initializeGraph(struct Graph *graph, int numVertices, int numEdges) {
    graph->numVertices = numVertices;
    graph->numEdges = 0;

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    graph->edgeList = (struct Edge *)malloc(numEdges * sizeof(struct Edge));
}

void displayAdjacencyMatrix(struct Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d\t", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void displayAdjacencyList(struct Graph *graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->numEdges; i++) {
        printf("(%d, %d) -> %d\n", graph->edgeList[i].source, graph->edgeList[i].destination, graph->edgeList[i].weight);
    }
}

int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootX].parent = rootY;
        subsets[rootY].rank++;
    }
}
#define MAX_EDGES 20 
void kruskal(struct Graph *graph) {
    qsort(graph->edgeList, graph->numEdges, sizeof(struct Edge), compareEdges);

    struct Subset *subsets = (struct Subset *)malloc(graph->numVertices * sizeof(struct Subset));
    for (int i = 0; i < graph->numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    printf("Minimum Spanning Tree using Kruskal's algorithm:\n");
    for (int i = 0, e = 0; e < graph->numVertices - 1 && i < graph->numEdges; i++) {
        int x = find(subsets, graph->edgeList[i].source);
        int y = find(subsets, graph->edgeList[i].destination);

        if (x != y) {
            printf("(%d, %d) -> %d\n", graph->edgeList[i].source, graph->edgeList[i].destination, graph->edgeList[i].weight);
            unionSets(subsets, x, y);
            e++;
        }
    }

    free(subsets);
}
void prim(struct Graph *graph) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];

    int inMST[MAX_VERTICES];

    for (int i = 0; i < graph->numVertices; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    printf("Minimum Spanning Tree using Prim's algorithm:\n");

    for (int count = 0; count < graph->numVertices - 1; count++) {
        int u = -1;
        int minKey = INT_MAX;

        for (int v = 0; v < graph->numVertices; v++) {
            if (inMST[v] == 0 && key[v] < minKey) {
                u = v;
                minKey = key[v];
            }
        }

        inMST[u] = 1;

        for (int v = 0; v < graph->numVertices; v++) {
            if (graph->adjacencyMatrix[u][v] && inMST[v] == 0 && graph->adjacencyMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjacencyMatrix[u][v];
            }
        }
    }

    for (int i = 1; i < graph->numVertices; i++) {
        printf("(%d, %d) -> %d\n", parent[i], i, graph->adjacencyMatrix[i][parent[i]]);
    }
}

int main() {
    struct Graph graph;
    int choice, source, destination, weight, n;

    do {
        printf("\nMenu:\n");
        printf("1. Create Graph\n");
        printf("2. Add an Edge\n");
        printf("3. Adjacency Matrix\n");
        printf("4. Adjacency List\n");
        printf("5. Find Minimum Spanning Tree (Kruskal's algorithm)\n");
        printf("6. Find Minimum Spanning Tree (Prim's algorithm)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the Number of vertices: ");
                scanf("%d", &n);
                initializeGraph(&graph, n, n - 1);
                printf("\nThe graph created successfully");
                break;
            case 2:
                printf("\nEnter source, destination, and weight of the edge: ");
                scanf("%d %d %d", &source, &destination, &weight);
                graph.adjacencyMatrix[source][destination] = weight;
                graph.adjacencyMatrix[destination][source] = weight;
                graph.edgeList[graph.numEdges].source = source;
                graph.edgeList[graph.numEdges].destination = destination;
                graph.edgeList[graph.numEdges].weight = weight;
                graph.numEdges++;
                break;
            case 3:
                displayAdjacencyMatrix(&graph);
                break;
            case 4:
                displayAdjacencyList(&graph);
                break;
            case 5:
                kruskal(&graph);
                break;
            case 6:
                prim(&graph);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    free(graph.edgeList); 

    return 0;
}

Output:
 
 
