#include <bits/stdc++.h>
using namespace std;
#define N 3

// State space tree nodes
struct Node {
    Node* parent; // Stores the parent node of the current node
    int mat[N][N]; // Stores matrix
    int x, y; // Stores blank tile coordinates
    int cost; // Stores the number of misplaced tiles
    int level; // Stores the number of moves so far
};

// Function to print N x N matrix
void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// Function to allocate a new node
Node* newNode(int mat[N][N], int x, int y, int newX, int newY, int level, Node* parent) {
    Node* node = new Node;
    node->parent = parent; // Set pointer for path to root
    memcpy(node->mat, mat, sizeof node->mat); // Copy data from parent node to current node
    swap(node->mat[x][y], node->mat[newX][newY]); // Move tile by 1 position
    node->cost = INT_MAX; // Set number of misplaced tiles
    node->level = level; // Set number of moves so far
    node->x = newX; // Update new blank tile coordinates
    node->y = newY;
    return node;
}

// Bottom, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

// Function to calculate the number of misplaced tiles
int calculateCost(int initial[N][N], int final[N][N]) {
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (initial[i][j] && initial[i][j] != final[i][j])
                count++;
    return count;
}

// Function to check if (x, y) is a valid matrix coordinate
bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Print path from root node to destination node
void printPath(Node* root) {
    if (root == NULL)
        return;
    printPath(root->parent);
    printMatrix(root->mat);
    printf("\n");
}

// Comparison object to be used to order the heap
struct comp {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};

// Function to solve N*N - 1 puzzle algorithm using Branch and Bound
void solve(int initial[N][N], int x, int y, int final[N][N]) {
    priority_queue<Node*, std::vector<Node*>, comp> pq; // Create a priority queue to store live nodes of search tree
    Node* root = newNode(initial, x, y, x, y, 0, NULL); // Create a root node and calculate its cost
    root->cost = calculateCost(initial, final);
    pq.push(root); // Add root to list of live nodes

    while (!pq.empty()) {
        Node* min = pq.top(); // Find a live node with least estimated cost
        pq.pop(); // The found node is deleted from the list of live nodes

        if (min->cost == 0) { // If min is an answer node
            printPath(min); // Print the path from root to destination
            return;
        }

        // Do for each child of min (max 4 children for a node)
        for (int i = 0; i < 4; i++) {
            if (isSafe(min->x + row[i], min->y + col[i])) {
                Node* child = newNode(min->mat, min->x, min->y, min->x + row[i], min->y + col[i], min->level + 1, min);
                child->cost = calculateCost(child->mat, final);
                pq.push(child); // Add child to list of live nodes
            }
        }
    }
}

// Driver code
int main() {
    int initial[N][N] = { // Initial configuration (Value 0 is used for empty space)
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };

    int final[N][N] = { // Solvable Final configuration (Value 0 is used for empty space)
        {1, 2, 3},
        {5, 8, 6},
        {0, 7, 4}
    };

    int x = 1, y = 2; // Blank tile coordinates in initial configuration
    solve(initial, x, y, final);
    return 0;
}
