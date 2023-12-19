//Fractional Knapsack using Greedy

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool myCmp(pair<int, int> a, pair<int, int> b)
{
    double r1 = static_cast<double>(a.first) / a.second;
    double r2 = static_cast<double>(b.first) / b.second;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<pair<int, int>> &arr)
{
    sort(arr.begin(), arr.end(), myCmp);

    double res = 0.0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].second <= W)
        {
            res += arr[i].first;
            W = W - arr[i].second;
        }
        else
        {
            res += arr[i].first * (static_cast<double>(W) / arr[i].second);
            break;
        }
    }

    return res;
}

int main()
{
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<pair<int, int>> arr;

    cout << "Enter the weight and value for each item:\n";
    for (int i = 0; i < n; i++)
    {
        int weight, value;
        cout << "Item " << i + 1 << ": ";
        cin >> weight >> value;
        arr.push_back(make_pair(value, weight));
    }

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, arr) << endl;

    return 0;
}
