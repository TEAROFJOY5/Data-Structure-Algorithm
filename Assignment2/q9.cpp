
#include<iostream>
using namespace std;

int totalArrangements = 0;

char courses[4][30] =
{
    "Programming",
    "Database Systems",
    "Operating Systems",
    "Computer Networks"
};

int usedRow[6] = {0};
int usedCol[8] = {0};

int seats[4][2];

bool isSafe(int row, int col, int course)
{
    if(usedRow[row] == 1 || usedCol[col] == 1)
        return false;

    if(row == 2 && col == 2)
        return false;

    for(int i=0; i<course; i++)
    {
        int rowDiff = row - seats[i][0];
        int colDiff = col - seats[i][1];

        if(rowDiff < 0)
            rowDiff = -rowDiff;

        if(colDiff < 0)
            colDiff = -colDiff;

        if(rowDiff == colDiff)
            return false;
    }

    return true;
}

void display()
{
    totalArrangements++;

    cout<<"\nArrangement "<<totalArrangements<<endl;

    for(int i=0; i<4; i++)
    {
        cout<<courses[i]<<" : ";

        cout<<"Row "<<seats[i][0]+1
            <<", Column "<<seats[i][1]+1<<endl;
    }
}

void assignSeats(int course)
{
    if(course == 4)
    {
        display();
        return;
    }

    int startRow = 0;
    int endRow = 5;

    if(course == 0)
    {
        startRow = 0;
        endRow = 0;
    }

    for(int row=startRow; row<=endRow; row++)
    {
        for(int col=0; col<8; col++)
        {
            if(isSafe(row, col, course))
            {
                seats[course][0] = row;
                seats[course][1] = col;

                usedRow[row] = 1;
                usedCol[col] = 1;

                assignSeats(course+1);

                usedRow[row] = 0;
                usedCol[col] = 0;
            }
        }
    }
}

int main()
{
    assignSeats(0);

    if(totalArrangements == 0)
        cout<<"\nNo valid seating arrangement exists.";

    else
        cout<<"\nTotal valid arrangements: "<<totalArrangements;

    return 0;
}
