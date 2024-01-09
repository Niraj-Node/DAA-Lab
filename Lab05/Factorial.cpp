//{ Driver Code Starts
//Initial Template for C
#include<stdio.h> 
// } Driver Code Ends

//User function Template for C
unsigned long long int factorialRec(int n, unsigned long long ans = 1)
{
    if(!n) return ans;

    return factorialRec(n-1,ans*n);
}

unsigned long long int factorialMemo(int n)
{
    unsigned long long fact[n+1];
    fact[0] = 1;

    for(int i=1; i<=n; i++)
    {
        fact[i] = fact[i-1]*i;
    }

    return (fact[n]);
}

unsigned long long int factorialTab(int n)
{

    unsigned long long fact = 1;

    for(int i=2; i<=n; i++)
    {
        fact = fact*i;
    }

    return fact;
}

//{ Driver Code Starts.
int main() 
{ 
    int N;
    scanf("%d", &N);
    printf("%llu\n", factorialRec(N));
    printf("%llu\n", factorialMemo(N));
    printf("%llu\n", factorialTab(N));
    return 0; 
}