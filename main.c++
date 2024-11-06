#include <iostream>
using namespace std;

// Constants for the maze dimensions
const int WIDTH = 5;
const int HEIGHT = 5;

// Maze representation
// 0 - Open path
// 1 - Wall
// 2 - Part of the solution path
int maze[HEIGHT][WIDTH] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

// Function to print the maze with the solution path
void printMaze() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 1) {
                cout << "#"; // Wall
            } else if (maze[i][j] == 2) {
                cout << "."; // Part of the solution path
            } else {
                cout << ","; // Open space
            }
        }
        cout << endl;  // Move to the next line after each row
    }
}

// Recursive function to solve the maze
bool solveMaze(int x, int y) {
    // Check if out of bounds, wall, or already visited
    if (x < 0 || x >= HEIGHT || y < 0 || y >= WIDTH || maze[x][y] == 1 || maze[x][y] == 2) {
        return false;  // Invalid position or already part of the path
    }

    // If we reach the goal (bottom-right corner), mark it and return true
    if (x == HEIGHT - 1 && y == WIDTH - 1) {
        maze[x][y] = 2;  // Mark goal as part of the path
        return true;
    }

    // Mark the current cell as part of the solution path
    maze[x][y] = 2;

    // Try moving down, up, right, and left (recursive calls)
    if (solveMaze(x + 1, y)) return true;  // Move down
    if (solveMaze(x - 1, y)) return true;  // Move up
    if (solveMaze(x, y + 1)) return true;  // Move right
    if (solveMaze(x, y - 1)) return true;  // Move left

    // Backtrack if no solution was found from this point
    maze[x][y] = 0;  // Reset the cell and backtrack
    return false;
}

int main() {
    // Start the maze solver from the top-left corner (0, 0)
    if (solveMaze(0, 0)) {
        cout << "Path found:\n";
    } else {
        cout << "No path found.\n";
    }

    // Display the maze with the solution path
    printMaze();

    return 0;
}
