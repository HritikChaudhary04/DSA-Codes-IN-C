#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct node {
    int vertex;
    struct node* next;
};

struct graph {
    int num_vertices;
    struct node* adj_list[MAX_VERTICES];
};

struct node* create_node(int v) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

struct graph* create_graph(int n) {
    struct graph* new_graph = (struct graph*) malloc(sizeof(struct graph));
    new_graph->num_vertices = n;
    int i;
    for (i = 0; i < n; i++) {
        new_graph->adj_list[i] = NULL;
    }
    return new_graph;
}

void add_edge(struct graph* g, int u, int v) {
    struct node* new_node = create_node(v);
    new_node->next = g->adj_list[u];
    g->adj_list[u] = new_node;

    new_node = create_node(u);
    new_node->next = g->adj_list[v];
    g->adj_list[v] = new_node;
}

void dfs(struct graph* g, int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v);

    struct node* adj_list = g->adj_list[v];
    while (adj_list != NULL) {
        int connected_vertex = adj_list->vertex;
        if (!visited[connected_vertex]) {
            dfs(g, connected_vertex, visited);
        }
        adj_list = adj_list->next;
    }
}

void bfs(struct graph* g, int start, int* visited) {
    int queue[MAX_VERTICES];
    int front = -1;
    int rear = -1;

    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear) {
        int v = queue[++front];
        printf("%d ", v);

        struct node* adj_list = g->adj_list[v];
        while (adj_list != NULL) {
            int connected_vertex = adj_list->vertex;
            if (!visited[connected_vertex]) {
                visited[connected_vertex] = 1;
                queue[++rear] = connected_vertex;
            }
            adj_list = adj_list->next;
        }
    }
}

int main() {
   
    struct graph* g = create_graph(5);

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    int visited[MAX_VERTICES] = {0};
    printf("Depth-first traversal starting from vertex 0: ");
    dfs(g, 0, visited);
    printf("\n");

    // Perform breadth-first traversal
    int visited2[MAX_VERTICES] = {0};
    printf("Breadth-first traversal starting from vertex 0: ");
    bfs(g, 0, visited2);
    printf("\n");

    return 0;
}
