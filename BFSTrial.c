#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 100

struct Queue {
    int front, rear;
    int items[MAX];
};


void initGraph(bool m[MAX][MAX], int V) {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
        	m[i][j] = false;
        }
    }
}

void bfs(bool m[MAX][MAX], int V,  int startVertex) {
    struct Queue q;
    int i;
    bool visited[MAX];

    q.front = q.rear = -1;
    for (i = 0; i < V; i++) {
        visited[i] = false;
    }

    q.items[++q.rear] = startVertex;
    visited[startVertex] = true;

    while (q.front <= q.rear) {
        int currentVertex = q.items[q.front++];

        printf("%d ", currentVertex);

        for (i = 0; i < V; i++) {
            if (m[currentVertex][i] && !visited[i]) {
                q.items[++q.rear] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    int V, E, i, src, dest;
	int startVertex;
    
	bool m[MAX][MAX];
	
    printf("Enter the number of Vertices : ");
    scanf("%d", &V);
    
	initGraph(m, V);

    printf("Enter the number of Edges : ");
    scanf("%d", &E);

    printf("Enter the Edges (source destination):\n");
    for (i = 0; i < E; i++) 
	{
    	printf("Edge %d : ", i);
        scanf("%d %d", &src, &dest);
	    m[src][dest] = true;
	    m[dest][src] = true;
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("BFS Traversal starting from vertex %d: ", startVertex);
    bfs(m, V, startVertex);

    return 0;
}
