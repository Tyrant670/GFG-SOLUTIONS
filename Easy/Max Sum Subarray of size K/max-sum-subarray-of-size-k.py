#User function Template for python3
class Solution:
    def maximumSumSubarray (self,K,Arr,N):
        # code here 
        i,j,sum,ans=0,0,0,0
        while j<K:
            sum+=Arr[j]
            j+=1
            ans=max(ans,sum)
            
        while j<N:
            sum-=Arr[i]
            sum+=Arr[j]
            i+=1
            j+=1
            ans=max(ans,sum)
            
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        N,K = input().split()
        N = int(N)
        K = int(K)
        Arr = list( map(int,input().strip().split(" ")))

        ob = Solution()
        print(ob.maximumSumSubarray(K,Arr,N))
# } Driver Code Ends