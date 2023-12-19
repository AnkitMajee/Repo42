#include <bits/stdc++.h>

using namespace std;

bool mycap(pair<int,int>a,pair<int,int>b){
	double r1= (double)a.first/a.second;
	double r2=(double)b.first/a.second;
	
	return r1>r2;
}

double fkap(int W,vector<pair<int,int>>arr,int n){
	sort(arr.begin(),arr.end(),mycap);
	double res=0.0;
	for(int i=0;i<n;i++){
		if(arr[i].second<=W){
			res+=arr[i].first;
			W-=arr[i].second;
		}
		else{
			res+=arr[i].first*(static_cast<double>(W)/arr[i].second);
			break;
		}
	}
	return res;
}


int main(){
	int n,W;
	vector<pair<int,int>>arr;
	cout<<"Enter Knapsach item:-";
	cin>>n;
	cout<<"Enter weight value of the knapsach:-";
	for(int i=0;i<n;i++){
		int weight,value;
		cin>>weight>>value;
		arr.push_back(make_pair(weight,value));
	}
	cout<<"Enter Knapsach Capacity:";
	cin>>W;
	cout<<fkap(W,arr,n);
}






//Goto tools > Editor Option > Snippets >Default Source Code
