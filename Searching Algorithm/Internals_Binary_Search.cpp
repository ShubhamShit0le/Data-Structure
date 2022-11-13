#include<iostream>
#include<algorithm>

using namespace std;

bool BinarySearch(int Arr[],int n, int iNo)
{
    sort(Arr,Arr+n);

    int iStart,iMid,iEnd;
    
    iStart = 0;
    iEnd = n-1;
    iMid =  (iStart + iEnd)/2;

    while(iStart <= iEnd)
    {
        if(Arr[iMid] == iNo)
        {
            break;
        }
        else if(iNo > Arr[iMid])
        {
            iStart = iMid + 1;
        }
        else if(iNo < Arr[iMid])
        {
            iEnd = iMid-1;
        }

    
        iMid = (iStart + iEnd) / 2;
        
    }  

    if(Arr[iMid] == iNo)
    {
        return true;
    }   
    else
    {
        return false;

    }
     
   
}



int main()
{
     int Arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
     int iSize = sizeof(Arr)/sizeof(Arr[0]);

     int iVal = 1;

     bool bret = BinarySearch(Arr,iSize,iVal);

     if(bret == true)
     {
        cout<<"Number Is Found In The Array"<<endl;

     }
     else
     {
        cout<<"Number Is Not Found In The Array"<<endl;
     }

     return 0;

}