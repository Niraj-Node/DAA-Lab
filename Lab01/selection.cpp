#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v;
    int size;
    cout << "Enter the Size:" << endl;
    cin >> size;
    v.resize(size);

    cout << "Enter the data One-by-One seprated by space: " << endl;
    for(int i=0;i<size;i++)
        cin >> v[i];

    int cmp=0,ex=0;

    for(int i=0;i<size-1;i++)
    {
        int min_idx = i;
        for(int j=i+1;j<size;j++)
        {
            if(++cmp && v[min_idx] > v[j])
            {
                min_idx = j;
            }
        }

        if(min_idx != i)
        {
            swap(v[i],v[min_idx]);
            ex++;
        }
    }

    cout << "comparison: " << cmp << ", exchanges: " << ex << endl;
}