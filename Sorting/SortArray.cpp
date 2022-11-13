#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
    int *ptr = NULL;
    int iSize = 0;

    cout<<"Size : ";
    cin>>iSize;

    ptr = new int[iSize];

    cout<<"Enter Data :\n";
    for(int i = 0; i<iSize; i++)
    {
       cin>>ptr[i];
    }
    cout<<"Before Sort :\n";
    for(int i = 0; i<iSize; i++)
    {
    cout<<ptr[i]<<endl;
    }

    sort(ptr,ptr + iSize);

    cout<<"After Swap :\n";
    for(int i = 0; i< iSize; i++)
    {
     cout<<ptr[i]<<endl;
    }


   return 0;

}