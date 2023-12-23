#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> deadline;
    vector<pair<int,int>> profit_with_idx;

    for(int i=0;i<n;i++)
    {
        int x, y;
        cin >> x >> y;
        deadline.emplace_back(x);
        profit_with_idx.emplace_back(make_pair(y,i));
    }

    sort(profit_with_idx.begin(), profit_with_idx.end(), greater<pair<int, int>>());

    int max_deadline = *max_element(deadline.begin(), deadline.end());
    vector<int> filled(max_deadline, -1);
    int maxProfit = 0;

    for(int i=0; i<n; i++)
    {
        int job_no = profit_with_idx[i].second;
        int currentDeadline = deadline[job_no];

        for(int j=currentDeadline-1; j>=0; j--)
        {
            if(filled[j] == -1)
            {
                filled[j] = job_no;
                maxProfit += profit_with_idx[i].first;
                break;
            }
        }
    }

    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
