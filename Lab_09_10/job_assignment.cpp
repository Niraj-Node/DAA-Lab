/*
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4

4
82 83 69 92
77 37 49 92
11 69 5 86
8 9 98 23
*/

#include <bits/stdc++.h>
using namespace std;

class Node 
{
    public:
    Node* parent;
    int pathCost;
    int estimatedTotalCost;
    int workerID;
    int jobID;
    vector<bool> assigned;

    
    static Node* newNode(int x, int y, Node* parent, vector<bool> assigned) 
    {
        Node* node = new Node;
        
        node->assigned = assigned;
        node->parent = parent;
        node->workerID = x;
        node->jobID = y;
        return node;
    }
};
struct comp {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->estimatedTotalCost > rhs->estimatedTotalCost;
    }
};
        
class JobAssignment 
{
    private:

        vector<vector<int>> costMatrix;
        priority_queue<Node*, vector<Node*>, comp> pq;

        int calculateEstimatedTotalCost(int x, int y, vector<bool> assigned) 
        {
            int cost = 0;
            int n = costMatrix.size();
            vector<bool> available(n, true);
            for (int i = x + 1; i < n; i++) 
            {
                int min = INT_MAX, minIndex = -1;
                for(int j = 0; j < n; j++) 
                {
                    if(!assigned[j] && available[j] && costMatrix[i][j] < min) 
                    {
                        minIndex = j;
                        min = costMatrix[i][j];
                    }
                }
                cost += min;
                available[minIndex] = false;
            }
            return cost;
        }

        void printAssignments(Node* min) 
        {
            if(min->parent == NULL)
                return;
            printAssignments(min->parent);
            cout << "Assign Worker " << char(min->workerID + 'A') << " to Job " << min->jobID << endl;
        }

    public:

        JobAssignment(vector<vector<int>> cost) 
        {
            costMatrix = cost;
        }

        int findMinCost() 
        {
            int n = costMatrix.size();
            vector<bool> assigned(n, false);
            Node* root = Node::newNode(-1, -1, NULL, assigned);
            root->pathCost = root->estimatedTotalCost = 0;
            pq.push(root);

            while(!pq.empty()) 
            {
                Node* min = pq.top();
                pq.pop();
                int i = min->workerID + 1;
                if(i == n) 
                {
                    printAssignments(min);
                    return min->estimatedTotalCost;
                }
                for(int j = 0; j < n; j++) 
                {
                    if(!min->assigned[j]) 
                    {
                        min->assigned[j] = true;
                        Node* child = Node::newNode(i, j, min, min->assigned);
                        child->pathCost = min->pathCost + costMatrix[i][j];
                        child->estimatedTotalCost = child->pathCost + calculateEstimatedTotalCost(i, j, child->assigned);
                        pq.push(child);
                        min->assigned[j] = false;
                    }
                }
            }
            return -1; // Indicates failure
        }
};

int main() 
{
    int n;
    cin >> n;
    
    vector<vector<int>> cost(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> cost[i][j];
        }
    }

    JobAssignment job(cost);
    cout << "\nOptimal Cost is " << job.findMinCost() << endl;
    return 0;
}
