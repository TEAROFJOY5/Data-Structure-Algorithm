
#include<iostream>
using namespace std;

int N = 4;
int pathCount = 0;

void displayPath(int path[4][4])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(path[i][j] == 1)
                cout<<"* ";
            else
                cout<<"- ";
        }

        cout<<endl;
    }

    cout<<endl;
}

void findPaths(int maze[4][4], int path[4][4], int row, int col)
{
    if(row < 0 || col < 0 || row >= N || col >= N)
        return;

    if(maze[row][col] == 0 || path[row][col] == 1)
        return;

    path[row][col] = 1;

    if(row == N-1 && col == N-1)
    {
        pathCount++;

        cout<<"Path "<<pathCount<<":"<<endl;
        displayPath(path);

        path[row][col] = 0;
        return;
    }

    findPaths(maze, path, row-1, col);
    findPaths(maze, path, row+1, col);
    findPaths(maze, path, row, col-1);
    findPaths(maze, path, row, col+1);

    path[row][col] = 0;
}

int main()
{
    int maze[4][4] =
    {
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 1}
    };

    int path[4][4] = {0};

    if(maze[0][0] == 0 || maze[N-1][N-1] == 0)
    {
        cout<<"No path exists."<<endl;
        return 0;
    }

    findPaths(maze, path, 0, 0);

    if(pathCount == 0)
        cout<<"No valid path exists."<<endl;

    return 0;
}
