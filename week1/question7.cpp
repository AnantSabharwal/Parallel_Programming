#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[5][5];
	cout<<"Enter the values of matrix a:"<<endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>a[i][j];
		}
	}
	int b[5][5];
	for (int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if (i==j){
				b[i][j] = 0;
			}else if(i<j){
				//int min;
				//for(int k=0;k<5;k++){
				int min = a[i][0];//j=0
				for(int l=0;l<5;l++){
					if (a[i][l]<min){
						min = a[i][l];
					}
				}
				//}
				b[i][j] = min;
			}else if(i>j){
				//int max;
				//for(int k=0;k<5;k++){
				int max = a[i][0];//j=0
				for(int l=0;l<5;l++){
					if (a[i][l]>max){
						max = a[i][l];
					}
				}
			b[i][j] = max;
			//}
		}
	}
}
for (int i = 0; i < 5; i++)
{
   for (int j = 0; j < 5; j++)
   {
      cout << b[i][j] << " ";
   }
   cout<<endl;

}
return 0;
}
