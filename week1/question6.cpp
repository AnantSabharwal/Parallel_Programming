#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	//hardcoding matrix and vector values such that they are always multiplicable
	cout<<"Enter the dimensions of the matrix"<<endl;
	int n,m;
	cin>>n>>m;
	//int a[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
	//int b[3] = {2,2,2};
	//int c[3];
	int a[n][m];
	cout<<"Enter the matrix values: "<<endl;
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	cout<<"Enter the size of the array: "<<endl;
	int s;
	cin>>s;
	int b[s];
	cout<<"Enter values of the array: "<<endl;
	for(int i=0;i<s;i++){
		cin>>b[i];
	}
	int c[s];
	//intializing all the balues of the vector c to 0
	for(int i =0 ;i<s;i++){
		c[i] = 0;
	}
	if (m!=s){
		cout<<"Multiplication not possible";
		exit(0);
	}else{
		//multiplication
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				c[i]+=(a[i][j]*b[j]);
			}
		}
	}
	//printing the arr
	for (int i=0;i<s;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
