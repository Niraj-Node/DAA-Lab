//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h> 
using namespace std; 
// } Driver Code Ends
//User function template for C++

class nQueen
{
    private:
        int n;
        vector<int> ans;

        void printSolution()
        {
            cout << "Solution: < ";
            for(int i=0; i<n-1; i++)
            {
                cout << ans[i]+1 << ", ";
            }
            cout << ans[n-1] << " >" << endl;
        }

        bool place(int row, int col)
        {
            for(int i=0; i<=row-1; i++)
            {
                if((ans[i]==col) || (abs(row-i)==abs(ans[i]-col)))
                    return false;
            }
            return true;
        }

    public:
        nQueen(int n)
        {
            this->n = n;
            ans.resize(n);
        }

        void nQueenSol(int row)
        {
            for(int i=0; i<n; i++)
            {
                if(place(row, i))
                {
                    ans[row] = i;
                    
                    if(row == n-1)
                        printSolution();
                    else
                        nQueenSol(row+1);
                }
            }
        }
};

//{ Driver Code Starts.
int main() 
{ 
    cout << "Enter the Number of Queens: ";
    int N;
    cin >> N;
    
    nQueen q(N);
    q.nQueenSol(0);
    
    return 0; 
} 