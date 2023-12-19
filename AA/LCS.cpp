//Longest Common Subsequence with LCS Sequence

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printAllLCS(string s1, string s2, int m, int n, vector<vector<int>>& dp, string current)
{
    if (m == 0 || n == 0)
    {
        cout << current << endl;
        return;
    }

    if (s1[m - 1] == s2[n - 1])
    {
        printAllLCS(s1, s2, m - 1, n - 1, dp, s1[m - 1] + current);
    }
    else
    {
        if (dp[m - 1][n] >= dp[m][n - 1])
            printAllLCS(s1, s2, m - 1, n, dp, current);
        if (dp[m][n - 1] >= dp[m - 1][n])
            printAllLCS(s1, s2, m, n - 1, dp, current);
    }
}

int lcs(string s1, string s2)
{
    int m = s1.length(), n = s2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string current = "";
    printAllLCS(s1, s2, m, n, dp, current);

    return dp[m][n];
}

int main()
{

    string s1 = "abdc", s2 = "addc";

    cout << "Length of LCS: " << lcs(s1, s2);

    return 0;
}
