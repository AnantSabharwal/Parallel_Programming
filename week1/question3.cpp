#include<iostream>
#include<string.h>
using namespace std;

void toggle(char str[]){
	for (int i=0;str[i]!='\0';i++){
		if(str[i]>='A' && str[i]<='Z'){
			str[i] = str[i]+32; 
		}else if(str[i]>='a' && str[i]<='z'){
			str[i] = str[i]-32;
		}else{
			cout<<"Non alphabet type character encountered and unedited/partially toggled string returned";
			break;
			
		}
	}
	cout<<"\nToggled string: "<<str<<endl;
}

int main(){
	char str[100];
	cout<<"Enter the string"<<endl;
	gets(str);
	toggle(str);
	return 0;
}
