#User function Template for python3

class Solution:
    
    #Function to return list of integers that form the boundary 
    #traversal of the matrix in a clockwise manner.
    def BoundaryTraversal(self,matrix, n, m):
        ans = []
        rows = len(matrix)
        cols = len(matrix[0])
        for i in range(cols):
            ans.append(matrix[0][i])
        for i in range(1, rows):
            ans.append(matrix[i][cols - 1])
        if rows - 1 > 0:
            for i in reversed(range(0, cols - 1)):
                ans.append(matrix[rows - 1][i])
        if cols - 1 > 0:
            for i in reversed(range(1, rows - 1)):
                ans.append(matrix[i][0])
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n,m = map(int, input().strip().split())
        values = list(map(int, input().strip().split()))
        k = 0
        matrix =[]
        for i in range(n):
            row=[]
            for j in range(m):
                row.append(values[k])
                k+=1
            matrix.append(row)
        obj = Solution()
        ans = obj.BoundaryTraversal(matrix,n,m)
        for i in ans:
            print(i,end=" ")
        print()

# } Driver Code Ends