//Merge Sort

#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    
    int n1=mid-low+1, n2=high-mid;
    int left[n1],right[n2];
    
    for(int i=0;i<n1;i++){
    	left[i]=arr[i+low];
	}
        
    for(int j=0;j<n2;j++){
    	right[j]=arr[mid+1+j];  
	}
		  
    int i=0,j=0,k=low;
    
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k++]=left[i++];
			}
        else{
			arr[k++]=right[j++];
		}
    }
    while(i<n1){
        arr[k++]=left[i++];
	}
    while(j<n2){
    	arr[k++]=right[j++];    
	}
}

void mergeSort(int arr[],int low,int high){
    if(high>low){
        int mid=low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main() {
	int N;
	cout<<"Enter Size of Array:";
	cin>>N;
    int arr[N];
	 cout<<"Enter array Element:";
	 for(int i=0;i<N;i++){
	 	cin>>arr[i];
	 }
	int l=0,h=N-1;
	
	mergeSort(arr,l,h);
	cout<<"Sorted Array:";
	for(int x: arr)
	    cout<<x<<" ";
}