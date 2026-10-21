/*
  Q3. Maze Navigation Robot
Scenario: A robot is placed inside a warehouse represented as a grid. Some cells contain obstacles, while others are free paths. The robot must find a path from the starting position to the destination.

Task:
Implement a recursive C++ function solveMaze() that finds a path from the starting cell to the destination.
Requirements:
The robot can move up, down, left, or right.
It cannot move through obstacles or outside the grid.
Use recursion and backtracking.
Display the path if a solution exists.
Example:
S  0  1  0  0
1  0  1  0  1
0  0  0  0  0
0  1  1  1  0
0  0  0  0  E
Here, S is the start, E is the destination, 0 is an open cell, and 1 is an obstacle.
*/
#include <iostream>
using namespace std;

const int N = 5;

bool solveMaze(int maze[N][N], int path[N][N], int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N)
        return false;

    if (maze[row][col] == 1 || path[row][col] == 1)
        return false;

    path[row][col] = 1;

    if (row == N - 1 && col == N - 1)
        return true;

    if (solveMaze(maze, path, row + 1, col))
        return true;

    if (solveMaze(maze, path, row, col + 1))
        return true;

    if (solveMaze(maze, path, row - 1, col))
        return true;

    if (solveMaze(maze, path, row, col - 1))
        return true;

    path[row][col] = 0;
    return false;
}

int main() {
    int maze[N][N] = {
        {0, 0, 1, 0, 0},
        {1, 0, 1, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    int path[N][N] = {0};

    if (solveMaze(maze, path, 0, 0)) {
        cout << "Path Found:\n";

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0 && j == 0)
                    cout << "S ";
                else if (i == N - 1 && j == N - 1)
                    cout << "E ";
                else if (path[i][j] == 1)
                    cout << "* ";
                else if (maze[i][j] == 1)
                    cout << "1 ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    } else {
        cout << "No Path Found";
    }

    return 0;
}
