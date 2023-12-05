#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v;
    int size;
    cout << "Enter the Size:" << endl;
    cin >> size;

    cout << "Enter the data One-by-One seprated by space: " << endl;
    for(int i=0;i<size;i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int cmp=0,ex=0;
    for(int i=1;i<size;i++)
    {
        int key = v[i];
        int j = i-1;
        while(++cmp && j>=0 && v[j]>key)
        {
            v[j+1] = v[j];
            ex++;
            j--;
        }
        if(j!=i)
        {
            ex++;
            v[j+1] = key;
        }
    }

    cout << "comparison: " << cmp << ", exchanges: " << ex << endl;
}