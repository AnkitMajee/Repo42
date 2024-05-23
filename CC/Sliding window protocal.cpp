#include<iostream>


using namespace std;
int main()
{
	int w,i,f,frames[50];
	cout<<"Enter Window Size: ";
	cin>>w;
	cout<<"\n Enter no's of Frame to transmit: \n";
	cin>>f;
	cout<<"Enter"<<f<<"frames:\n";
	for(int i=1;i<=f;i++){
		cin>>frames[i];
	}
	cout<<"Sending......Frames......\n";
	cout<<"After Sending "<<w<<" frames at each stage sender waits for acknowledgement sent by the receiver \n";
	for(i=1;i<=f;i++){
		if(i%w==0){
			cout<<frames[i]<<"\n";
			cout<<"\n Acknowledgement of the above frames sent is received by Sender \n";
		}
		else{
			cout<<frames[i]<<" ";
		}
		
	}
	if(f%w!=0){
			cout<<"\n Ackmowledgement of the above frames sent is received by sender \n";
		}
	return 0;
}