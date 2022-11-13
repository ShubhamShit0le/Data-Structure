#include<iostream>
#include<algorithm>
using namespace std;





int main()
{
    int Arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int iSize = sizeof(Arr)/sizeof(Arr[0]);

    int iVal = 18;

     sort(Arr,Arr+iSize);
   
     if(binary_search(Arr,Arr+iSize,iVal))
     {
        cout<<iVal<<" Element Present In The Array"<<endl;
     }
     else
     {
        cout<<iVal<<" Elemnt Not Present In The Array"<<endl;
     }


    return 0;

}