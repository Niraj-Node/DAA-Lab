#ifndef GRAPH_COLOR //Header Guards - Which Prevents file inclusion multiple times
#define GRAPH_COLOR
#include<iostream>
#include<vector>

class Coloring
{
private:
    int V, E, m;
    int noOfSolutions = 0;
    bool shouldPrint = true;
    bool shouldTakeColor = true;
    std::vector<std::vector<int>> adj;
    std::vector<int> color;

    void assignColor(int x)
    {
        while(true)
        {
            color[x] = (color[x] + 1) % (m+1); // try next color

            if(color[x] == 0) // tried all the Color but, non of them are Available
                return;

            bool flag = false;
            for(int i : adj[x])
            {
                if(color[i] == color[x])
                {
                    flag = true;
                    break;
                }
            }

            if(!flag) // Color has been Assigned
                return;
        }
    }

    void printColor()
    {
        std::cout << "------------Possible Color-----------" << std::endl;
        for(int i = 0; i < V; i++)
        {
            std::cout << (i + 1) << " : " << color[i] << std::endl;
        }
        std::cout << "-------------------------------------" << std::endl;
    }

public:
    void setPrint(bool b)
    {
        this->shouldPrint = b;
    }
    void setShouldTakeColor(bool b)
    {
        shouldTakeColor = b;
    }
    void setColor(int m)
    {
        this->m = m;
    }
    void setSolution() // Initializing Color Vector
    {
        color.resize(V, 0);
        noOfSolutions = 0;
    }
    int getCount()
    {
        return this->noOfSolutions;
    }
    int getNoOfVertices()
    {
        return this->V;
    }

    void takeGraph()
    {
        std::cout << "Enter the Number of Vertices:" << std::endl;
        std::cin >> V;
        std::cout << "Enter the Number of Edges:" << std::endl;
        std::cin >> E;
        if(shouldTakeColor)
        {
            std::cout << "Enter the Number of Colors: " << std::endl;
            std::cin >> m;
        }
        adj.resize(V, std::vector<int>());

        std::cout << "Enter the Edges: u v" << std::endl;
        for(int i = 0; i < E; i++)
        {
            int u, v;
            std::cin >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        setSolution();
    }

    void mColor(int k)
    {
        while(true)
        {
            // Will either assign a legal color or backtrack
            assignColor(k);

            if(color[k] == 0) // Cannot assign a legal color
                return;        // Backtrack

            if(k == V - 1) // All vertices have been colored
            {
                noOfSolutions++;
                if(shouldPrint)
                    printColor();
            }
            else
                mColor(k + 1);
        }
    }
};
#endif
