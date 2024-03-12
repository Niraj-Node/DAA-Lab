//{ Driver Code Starts
#include <bits/stdc++.h>
#include "graph_coloring.hpp"
using namespace std;
// } Driver Code Ends

int main() 
{
    Coloring c;
    c.takeGraph();
    c.mColor(0);

    if(!c.getCount())
        cout << "The graph cannot be colored with the given number of colors." << endl;

    return 0;
}