//{ Driver Code Starts
#include <bits/stdc++.h>
#include "graph_coloring.hpp"
using namespace std;
// } Driver Code Ends

int main() 
{
    Coloring c;
    c.setShouldTakeColor(false);
    c.takeGraph();
    c.setPrint(false);
    
    for(int i = 1; i <= c.getNoOfVertices(); i++)
    {
        c.setColor(i);
        c.setSolution();
        c.mColor(0);

        if(c.getCount())
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
