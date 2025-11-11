#include <stdio.h>

int check_rows(int a[9][9])
{
    int r,c,i;
    for(r=0;r<9;r++)
    {
        for(c=0;c<9;c++)
        {
            for(i=c+1;i<9;i++)
            {
                if(a[r][c]==a[r][i])
                {
                    return 0; // row repeat
                }
            }
        }
    }
    return 1;
}

int check_columns(int a[9][9])
{
    int r,c,i;
    for(c=0;c<9;c++)
    {
        for(r=0;r<9;r++)
        {
            for(i=r+1;i<9;i++)
            {
                if(a[r][c]==a[i][c])
                {
                    return 0; // col repeat
                }
            }
        }
    }
    return 1;
}

int check_subgrids(int a[9][9])
{
    int sr,sc,r,c,r2,c2;
    for(sr=0;sr<9;sr+=3)
    {
        for(sc=0;sc<9;sc+=3)
        {
            for(r=sr;r<sr+3;r++)
            {
                for(c=sc;c<sc+3;c++)
                {
                    for(r2=r;r2<sr+3;r2++)
                    {
                        for(c2=(r2==r?c+1:sc);c2<sc+3;c2++)
                        {
                            if(a[r][c]==a[r2][c2])
                            {
                                return 0; // box repeat
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}

int main()
{
    int grid[9][9]={
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    };

    if(check_rows(grid)==1 && check_columns(grid)==1 && check_subgrids(grid)==1)
    {
        printf("VALID SOLUTION");
    }
    else
    {
        printf("INVALID SOLUTION");
    }

    return 0;
}
