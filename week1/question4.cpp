#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void get_formatted_output(char str[],int n){
	for (int i = 0;i<n;i++){
		for(int j=0;j<=i;j++){
			cout<<str[i];
		}
	}
}
int main(){
	int n;
	cout<<"Enter the length of the string"<<endl;
	cin>>n;
	char str[n];
	cin>>str;
	get_formatted_output(str,n);
	return 0;
}
