//Write a program to reverse an array or string


//1. Reverse an array
#include <iostream>

using namespace std;
void reverse(int arr[],int st,int end){
    if(st>=end){
        return;
    }
    int temp = arr[st];
    arr[st] = arr[end];
    arr[end] = temp;
    
    reverse(arr,st+1,end-1);
    
}

int main()
{
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    reverse(arr,0,n-1);
    cout<<"Reverse array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}


//2. Reverse a String
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


string reverseWord(string str){
    
  //Your code here
  int len = str.length();
  string temp="";
  for(int i= len-1;i >=0;i--){
      temp = temp + str[i];
  }
  cout<<temp;
}
