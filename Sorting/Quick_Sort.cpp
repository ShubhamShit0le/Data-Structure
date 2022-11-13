#include<iostream>
using namespace std;

class SortingAlogorithm
{
public:
    static int Partition(int Arr[], int iLow, int iHigh);

    void QuickSort(int Arr[], int iLow, int iHigh);
};

int SortingAlogorithm :: Partition(int Arr[], int iLow, int iHigh)
{

    int i = iLow - 1;
    int Pivot = Arr[iHigh];

    for (int j = iLow; j < iHigh; j++)
    {

        if (Arr[j] < Pivot)
        {
            i++;

            // swap for placed low elements in left side of pivot
            int temp = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = temp;
        }
    }
    // swap for placed pivot in right position;
    i++;
    int temp = Arr[i];
    Arr[i] = Arr[iHigh];
    Arr[iHigh] = temp;

    return i;
}

void SortingAlogorithm ::QuickSort(int Arr[], int iLow, int iHigh)
{
    if (iLow < iHigh)
    {

        int Pivot = Partition(Arr, iLow, iHigh);

        QuickSort(Arr, iLow, Pivot - 1);  // low Elements:  low to high-1
        QuickSort(Arr, Pivot + 1, iHigh); // high Elements :  pivot index+1 to High
    }
}

int main()
{
    int Arr[] = {6,3,9,5,2,8};
    int iSize = sizeof(Arr)/sizeof(Arr[0]);
    int iLow = 0;
    int iHigh = iSize-1;

   SortingAlogorithm *obj = new SortingAlogorithm();

    obj->QuickSort(Arr,iLow,iHigh);

    cout<<"\nQuick sorted Array is :\n";

    for(int i = 0; i< iSize; i++)
    {
        cout<<Arr[i]<<endl;
    }



    return 0;



}