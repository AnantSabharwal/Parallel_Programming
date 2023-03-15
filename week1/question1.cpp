#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void print(int arr[]){
	for(int i=0;i<=sizeof(arr);i++){
		cout<<arr[i];
		cout<<" ";
	}
}

int reverse_digits(int n){
	int rev_num = 0;
	while(n>0){
		rev_num = rev_num * 10 + n % 10;
		n = n/10;
	}
	return rev_num;
}

int main(){
	int arr[] = {18, 523, 301, 1234, 2, 14, 108, 150, 1928};
	int rev_arr[sizeof(arr)];
	for (int i =0;i<=sizeof(arr);i++){
		rev_arr[i] = reverse_digits(arr[i]);
	}
	print(rev_arr);
	//printing the arr
	return 0;
}
