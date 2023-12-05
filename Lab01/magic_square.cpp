#include<bits/stdc++.h>
using namespace std;

void cir(int& x, int& y, int size)
{
    if(x < 0) x+=size;
    else if(x > size-1) x-=size;
    if(y < 0) y+=size;
    else if(y > size-1) y-=size;
}

int main()
{
    int size;
    cout << "Enter the Odd Size:" << endl;
    cin >> size;
    if(!(size & 1))
    {
        cout << "Entered Number is Even, Try Again!" << endl;
        exit(0);
    }

    int arr[size][size]={0};
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            arr[i][j] = 0;
    }

    int x = size/2,y = size-1;
    arr[x][y] = 1;
    for(int i=2;i<=(size*size);i++)
    {
        x -= 1;
        y += 1;

        cir(x,y,size);

        if(arr[x][y])
        {
            x += 1;
            y -= 2;
            cir(x,y,size);
        }

        arr[x][y] = i;
    }

    cout << "Magic Square: " << endl;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}