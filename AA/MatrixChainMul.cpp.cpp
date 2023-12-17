#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int multiplycount(vector<int> &arr, vector<vector<int>> &dp, vector<vector<int>> &mincut, int start, int end){
	// base case
	if(start == end)
		return dp[start][end] = 0;

	// dp found case
	if(dp[start][end] != -1)
		return dp[start][end];

	// recursive case
	int ministep = INT_MAX, minicut = INT_MAX, curstep;
	for(int cut=start; cut<end; ++cut){
		curstep = multiplycount(arr, dp, mincut, start, cut) +
					multiplycount(arr, dp, mincut, cut+1, end) +
					(arr[start-1] * arr[cut] * arr[end]);
		if(curstep < ministep){
			ministep = curstep;
			minicut = cut;
		}
	}

	// return from current state
	mincut[start][end] = minicut;
	return dp[start][end] = ministep;
}

int main(){
	int matcount, n;

	cout << "Enter count of matrices = ";
	cin >> matcount;

	n = matcount + 1;
	vector<int> arr(n);
	cout << "Enter matrix dimensions in space separated linear fashion = ";
	for(int i=0; i<n; ++i)
		cin >> arr[i];
	
	vector<vector<int>> dp(n, vector<int>(n, -1));
	vector<vector<int>> mincut(n, vector<int>(n, -1));
	cout << "Minimum count of multiplication = " << multiplycount(arr, dp, mincut, 1, matcount) << endl;

	cout << "Filled DP Table = " << endl;
	for(auto &v : dp){
		for(auto &i : v)
			cout << i << "\t";
		cout << endl;
	}

	cout << "Filled MinCut Table = " << endl;
	for(auto &v : mincut){
		for(auto &i : v)
			cout << i << "\t";
		cout << endl;
	}
	return 0;
}