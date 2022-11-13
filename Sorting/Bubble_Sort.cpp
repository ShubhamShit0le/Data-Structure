#include<iostream>
using namespace std;



class SortingAlgorithm
{
    public : 
         
           void Display(int Arr[],int iSize);
           void BubbleSort(int Arr[],int iSize);
           
      
};

void SortingAlgorithm :: Display(int Arr[],int iSize)
{
    int i = 0;
    cout<<"\nBubble Sorted Array Is :\n";
    for(i = 0; i<iSize; i++)
    {
        cout<<Arr[i]<<endl;
    }
}

void SortingAlgorithm :: BubbleSort(int Arr[],int iSize)
{
   int i = 0;
   int j = 0;
   
   for(i = 0; i<iSize-1; i++)
   {
    for(j = 0; j<iSize-i-1; j++)
    {
        if(Arr[j] > Arr[j+1])
        {
             int temp = Arr[j];
             Arr[j] = Arr[j+1];
             Arr[j+1] = temp;
        }
    }
   
   }

     Display(Arr,iSize);
  
}

int main()
{
   int Arr[] = {7,8,3,1,2};

    int iSize = sizeof(Arr)/sizeof(Arr[0]);

   SortingAlgorithm *obj = new SortingAlgorithm();

   obj->BubbleSort(Arr,iSize);


   return 0;


}
