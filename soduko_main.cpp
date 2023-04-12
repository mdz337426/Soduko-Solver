#include <iostream>
using namespace std;
int grid[9][9];

bool isempty(int grid[][9], int &row, int &col)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(grid[i][j]==0)
            {
                row =i;
                col =j;
                return true;
            }
        }
    }
    return false;
}

bool isvalid(int number, int row, int col)
{

    for(int i=0; i<9; i++)
    {
        if(grid[row][i]==number)
            return false;
    }

    for(int i=0; i<9; i++)
    {
        if(grid[i][col]==number)
            return false;
    }

    row = row-row%3;
    col = col - col%3;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(grid[row+i][col+j]==number)
                return false;
        }

    }

    return true;

}


bool soduko_Helper(int grid[][9], int row, int col)
{
    if(!isempty(grid, row, col))
    {

        for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout<<grid[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
        return true;

    }


    for(int i=1; i<=9; i++)
    {
        if(isvalid(i, row, col))
        {
            grid[row][col]=i;
            if(soduko_Helper(grid, row, col))
            {
                return true;
            }
            grid[row][col]=0;
        }
    }

    return false;
}





void solve_soduko(int grid[][9])
{
    int i=0, j=0;
    if(soduko_Helper(grid, i, j))
        cout<<"true"<<endl;

    return;
}

int main(){

    cout<<"Enter the 9*9 grid, enter 0 for empty places or unfilled places "<<endl;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<endl<<endl;

    solve_soduko(grid);

    return 0;
}
