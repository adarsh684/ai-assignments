#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 5000
#define LIMIT 20

typedef struct {
    int m, c, boat;
    int depth, cost;
    int parent;
} Node;

int visited[4][4][2];
int startM = 3;
int startC = 3;
int startBoat = 1;
void BFS();
void DFS();
void DLS();
void IDDFS();
int DLS_util(int limit, int print, int *expanded);

void resetVisited() {
    memset(visited, 0, sizeof(visited));
}

int isValid(int m, int c) { //checks if condition is still valid

    if (m < 0 || c < 0 || m > 3 || c > 3) return 0;
    if (m > 0 && m < c) return 0;
    int mr = 3 - m, cr = 3 - c;
    if (mr > 0 && mr < cr) return 0;
    return 1;
}

int goal(Node n) {
    return (n.m == 0 && n.c == 0 && n.boat == 0);
}

void printState(Node n) {
    printf("(M=%d, C=%d, Boat=%s)\n",n.m, n.c, n.boat ? "Left" : "Right");
}

void printPath(Node tree[], int index) {
    if (index == -1) return;
    printPath(tree, tree[index].parent);
    printState(tree[index]);
}

//BFS
void BFS() {
    resetVisited();
    Node q[MAX];
    int front = 0, rear = 0, expanded = 0;

    q[rear] = (Node){startM,startC,startBoat,0,0,-1};
    visited[startM][startC][startBoat] = 1;
    rear++;

    while (front < rear) {

        Node cur = q[front];
        int cur_index = front;
        front++; expanded++;

        if (goal(cur)) {
            printf("Goal found(BFS)\n");
            printPath(q, cur_index);
            printf("Expanded: %d\n", expanded);
            return;
        }

        int moves[5][2] = {{1,0},{2,0},{0,1},{0,2},{1,1}};

        for (int i = 0; i < 5; i++) {
            int nm = cur.m, nc = cur.c, nb = !cur.boat;
            if (cur.boat){ 
                nm -= moves[i][0]; nc -= moves[i][1]; 
            }
            else { 
                nm += moves[i][0]; nc += moves[i][1]; 
            }
            if (isValid(nm,nc) && !visited[nm][nc][nb]) {
                if (rear < MAX) {
                    visited[nm][nc][nb] = 1;
                    q[rear] = (Node){nm,nc,nb,cur.depth+1,cur.cost+1,cur_index};
                    rear++;
                }
            }
        }
    }
}

//DFS
void DFS() {
    resetVisited();
    Node st[MAX];
    int top = -1, expanded = 0;
    st[++top] = (Node){startM,startC,startBoat,0,0,-1};
    visited[startM][startC][startBoat] = 1;
    while (top >= 0) {
        Node cur = st[top--];
        expanded++;
        if (goal(cur)) {
            printf("Goal found(DFS)\n");
            printState(cur);
            printf("Expanded: %d\n", expanded);
            return;
        }
        int moves[5][2] = {{1,0},{2,0},{0,1},{0,2},{1,1}};
        for (int i = 0; i < 5; i++) {
            int nm = cur.m, nc = cur.c, nb = !cur.boat;
            if (cur.boat) { nm -= moves[i][0]; nc -= moves[i][1]; }
            else { nm += moves[i][0]; nc += moves[i][1]; }
            if (isValid(nm,nc) && !visited[nm][nc][nb]) {
                if (top + 1 < MAX) {
                    visited[nm][nc][nb] = 1;
                    st[++top] = (Node){nm,nc,nb,cur.depth+1,cur.cost+1,-1};
                }
            }
        }
    }
}

//DLS
int DLS_util(int limit, int print, int *expanded) {
    resetVisited();
    Node st[MAX];
    int top = -1;
    st[++top] = (Node){startM,startC,startBoat,0,0,-1};
    visited[startM][startC][startBoat] = 1;
    while (top >= 0) {
        Node cur = st[top--];
        (*expanded)++;
        if (goal(cur)) {
            if (print) {
                printf("Goal found(DLS)\n");
                printState(cur);
            }
            return 1;
        }
        if (cur.depth < limit) {
            int moves[5][2] = {{1,0},{2,0},{0,1},{0,2},{1,1}};
            for (int i = 0; i < 5; i++) {
                int nm = cur.m, nc = cur.c, nb = !cur.boat;
                if (cur.boat) { nm -= moves[i][0]; nc -= moves[i][1]; }
                else { nm += moves[i][0]; nc += moves[i][1]; }
                if (isValid(nm,nc) && !visited[nm][nc][nb]) {
                    if (top + 1 < MAX) {
                        visited[nm][nc][nb] = 1;
                        st[++top] = (Node){nm,nc,nb,cur.depth+1,cur.cost+1,-1};
                    }
                }
            }
        }
    }

    return 0;
}

void DLS() {
    int expanded = 0;
    DLS_util(LIMIT, 1, &expanded);
    printf("Expanded: %d\n", expanded);
}

//IDDFS
void IDDFS() {
    int totalExpanded = 0;
    for (int depth = 0; depth <= LIMIT; depth++) {
        int expanded_this_round = 0;
        int found = DLS_util(depth, 0, &expanded_this_round);
        totalExpanded += expanded_this_round;
        if (found) {
            printf("Goal found at depth %d(IDDFS)\n",depth);
            break;
        }
    }
    printf("Total expanded(IDDFS): %d\n", totalExpanded);
}

int main() {
    clock_t s, e;
    printf("\nBFS:");
    s = clock(); BFS(); e = clock();
    printf("Time: %.6f sec\n",(double)(e-s)/CLOCKS_PER_SEC);
    printf("\nDFS:");
    s = clock(); DFS(); e = clock();
    printf("Time: %.6f sec\n",(double)(e-s)/CLOCKS_PER_SEC);
    printf("\nDLS:");
    s = clock(); DLS(); e = clock();
    printf("Time: %.6f sec\n",(double)(e-s)/CLOCKS_PER_SEC);
    printf("\nIDDFS:");
    s = clock(); IDDFS(); e = clock();
    printf("Time: %.6f sec\n",(double)(e-s)/CLOCKS_PER_SEC);

}
