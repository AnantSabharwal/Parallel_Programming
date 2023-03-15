#include<iostream>
using namespace std;

void format(char str1[], char str2[], int n){
	char str3[2*n];
	int j = 0;
	int k = 0;
	for(int i=0;i<2*n;i++){
		if (i%2==0){
			str3[i] = str1[j];
			j++; 
		}else if(i%2!=0){
			str3[i] = str2[k];
			k++;
		}
	}
	cout<<"formatted string is : "<<str3<<endl;
}
int main(){
	cout<<"Enter the size of the two strings:"<<endl;
	int n;
	cin>>n;
	char str1[n],str2[n];
	cout<<"Enter first string: "<<endl;
	cin>>str1;
	cout<<"Enter second string: "<<endl;
	cin>>str2;
	format(str1,str2,n);
	return 0;
}
