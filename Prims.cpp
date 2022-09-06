#include <iostream>
#include <bits/stdc++.h>
#include<string.h>
using namespace std;
int nonZeroSmall(int cost[7][7], int near[])
{
    int j = 0;
    int min = 100000;
    for (int i = 0; i < 7; i++)
    {
        if (near[i] != i && cost[i][near[i]] < min)
        {
            min = cost[i][near[i]];
            j = i;
        }
    }
    
    return j;
}
void updateNear(int near[], int cost[7][7], int k)
{
    for (int i = 0; i < 7; i++)
    {
        if (near[i] != i && cost[i][near[i]] > cost[i][k])
            near[i] = k;
    }
    return;
}
int main()
{
    int cost[][7] = {{   0, 1165,  985, 1939, 1341, 1483, 1378},
                     {1165,    0, 1932, 1578, 2070,  881,  573},
                     { 985, 1932,    0, 1868,  348, 1825, 1868},
                     {1939, 1578, 1868,    0, 1663,  648, 1006},
                     {1341, 2070,  348, 1663,    0, 1858, 1901},
                     {1483,  881, 1825,  648, 1858,    0,  312},
                     {1378,  573, 1868, 1006, 1901,  312,    0}
                     };
// finding the minimum
    int min = cost[0][1];
    int l, k;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
        {
            if (i != j && min > cost[i][j])
            {
                min = cost[i][j];
                l = i;
                k = j;
            }
        }
    // making a t matrix
    int t[6][3];
    t[0][0] = l;
    t[0][1] = k;
    t[0][2] = cost[l][k];
    string city[]={"Mumbai","Jaipur","Bengaluru","Kolkata","Chennai","Varanasi","Lucknow"};
    cout << city[l]<<"-->"<<city[k]<<"-->";
    // now calculation of the near
    int near[7];
    for (int i = 0; i < 7; i++)
        near[i] = cost[l][i] > cost[k][i] ? k : l;
    
    // maintaining a t matrix for display purpose
    for (int i = 1; i < 6; i++)
    {
        int j = nonZeroSmall(cost, near);
        cout << city[j]<<"-->";
        // update spanning tree matrix
        t[i][0] = near[j];
        t[i][1] = j;
        t[i][2] = cost[j][near[j]];
        near[j] = j;
        // updating the near
        updateNear(near, cost, j);
    
    }
    // display the matrix of spanning tree
    cout<<endl;
    cout<<"============"<<endl;
    cout<<"Minimum cost spanning tree"<<endl;
    for (int i = 0; i < 6; i++)
    {
        {
            for (int j = 0; j < 3; j++)
                cout << t[i][j]<<" ";
        }
        cout << endl;
    }
    cout<<"============"<<endl;

}
