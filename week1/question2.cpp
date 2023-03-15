#include<bits/stdc++.h>
#include<iostream>
using namespace std;

float add(float a, float b){
	return a+b;
}
float subtract(float a, float b){
	return a-b;
}
float multiply(float a, float b){
	return a*b;
}
float divide(float a, float b){
	return a/b;
}
int main(){
	cout<<"---------Calculator-----------"<<endl;
	int a, b;
	cout<<"Enter 1st number"<<endl;
	cin>>a;
	cout<<"Enter 2nd number"<<endl;
	cin>>b;
	cout<<(add(a,b))<<endl;
	cout<<(subtract(a,b))<<endl;
	cout<<(multiply(a,b))<<endl;
	cout<<(divide(a,b))<<endl;
	return 0;
	
}

