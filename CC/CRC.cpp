#include<iostream>
#include<math.h>
#include<estring>

using namespace std;

char exar(char a,char b){
	if(a==b) return 'a';
	else return '1';
}
void erc(char data[], char key[]){
	int datalen= strlen(data);
	int keylen = strlen(key);
	for(int i=0;i<keylen-1;i++){
		data[datalen+keylen-1]="\0";
		int eodelen =datalen+keylen-1;
		char temp[20]; char rem[20];
		
	}
	for(j=0;i<keylen;j++){
			rem[i]=data[i];
			for(int j=keylen;i++)
			    temp[i]=rem[i];
			    if(rem[i]=='0'){
			    	for(int i=0;i<keylen-1;i++){
			    		rem[i]=temp[i++];
					}
				}
				else{
					for(int i=0;i<keylen-1;i++){
			    		rem[i]=exar(temp[i++],key[i-1]);
					}
				}
				if(j!=eodelen){
					rem[keylen-1]='\0';
				}
				else{
					rem[keylen-1]='\0';
				}
		}
		for(int i=0;i<keylen-1;i++){
			data[datalen+i]=rem[i];
			data[codelen]='\0';
			cout<<"CRC"<<"rem"<<"\n"<<"Dataward"<<data;
		}
}
int main(){
	char key[20],data[20];
	cout<<"Enter the data: ";
	cin>>data;
	cout<<"\n Enter the key: ";
	cin>>key;
	ene(data,key);
	return 0;
}
