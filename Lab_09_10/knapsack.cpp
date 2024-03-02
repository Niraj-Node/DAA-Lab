/*
50
60 10
100 20
120 30
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* parent;
    int level;
    int profit;
    int weight;
    int bound;

    static Node* newNode(int level, int profit, int weight, Node* parent) {
        Node* node = new Node;
        node->level = level;
        node->profit = profit;
        node->weight = weight;
        node->parent = parent;
        return node;
    }
};
struct comp {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->bound < rhs->bound;
    }
};

class Knapsack 
{
    private:
        int capacity;
        vector<pair<int, int>> items;
        priority_queue<Node*, vector<Node*>, comp> pq;

        int bound(Node* u) 
        {
            int n = items.size();
            if(u->weight >= capacity) return 0;
            
            int profit_bound = u->profit;
            int j = u->level + 1;
            int total_weight = u->weight;

            while(j < n && total_weight + items[j].second <= capacity) 
            {
                total_weight += items[j].second;
                profit_bound += items[j].first;
                j++;
            }

            if(j < n) profit_bound += (capacity - total_weight) * (items[j].first/items[j].second);

            return profit_bound;
        }

    public:
        Knapsack(int cap, vector<pair<int, int>> vals) 
        {
            capacity = cap;
            items = vals;
        }

        int knapsack() 
        {
            sort(items.begin(), items.end(), [](pair<int, int>& a, pair<int, int>& b) {
                return (double)a.first / a.second > (double)b.first / b.second;
            });

            Node* u, * v;
            u = Node::newNode(-1, 0, 0, nullptr);
            u->bound = bound(u);
            int max_profit = 0;

            pq.push(u);

            while(!pq.empty()) 
            {
                u = pq.top();
                pq.pop();

                if(u->bound > max_profit) 
                {
                    v = Node::newNode(u->level + 1, u->profit + items[u->level + 1].first,
                        u->weight + items[u->level + 1].second, u);

                    if(v->weight <= capacity && v->profit > max_profit)
                        max_profit = v->profit;

                    v->bound = bound(v);
                    if(v->bound > max_profit)
                        pq.push(v);

                    v = Node::newNode(u->level + 1, u->profit, u->weight, u);
                    v->bound = bound(v);
                    if(v->bound > max_profit)
                        pq.push(v);
                }
            }

            return max_profit;
        }
};

int main() 
{
    int capacity, n;
    cin >> capacity >> n;

    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second; // value, weight
    }

    Knapsack ks(capacity, items);
    cout << "Maximum profit: " << ks.knapsack() << endl;

    return 0;
}
