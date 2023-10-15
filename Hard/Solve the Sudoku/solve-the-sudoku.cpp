//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    #define N 9

    bool isSafe(int grid[N][N], int row, 
					int col, int num)
    {
        for (int x = 0; x <= 8; x++)
            if (grid[row][x] == num)
                return false;

        for (int x = 0; x <= 8; x++)
            if (grid[x][col] == num)
                return false;

        int startRow = row - row % 3, 
                startCol = col - col % 3;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (grid[i + startRow][j + 
                                startCol] == num)
                    return false;

        return true;
    }

    bool solveSudoku1(int grid[N][N], int row, int col)
    {

        if (row == N - 1 && col == N)
            return true;

        if (col == N) {
            row++;
            col = 0;
        }

        if (grid[row][col] > 0)
            return solveSudoku1(grid, row, col + 1);

        for (int num = 1; num <= N; num++) 
        {
            
            if (isSafe(grid, row, col, num)) 
            {
                grid[row][col] = num;
            
                if (solveSudoku1(grid, row, col + 1))
                    return true;
            }
        
            grid[row][col] = 0;
        }
        return false;
    }
    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        return solveSudoku1(grid,0,0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        if(SolveSudoku(grid))
        for (int i = 0; i < N; i++) 
    	{
    		for (int j = 0; j < N; j++)
    			cout << grid[i][j] << " ";
    	}
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends