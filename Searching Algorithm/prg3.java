
import java.util.Scanner;

abstract class ArrayX
{
    public int Arr[];

    public ArrayX(int Size)
    {
        Arr = new int[Size];
    }

    public void Accept()
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter the elements : ");
        for(int i = 0; i < Arr.length; i++)
        {
            Arr[i] = sobj.nextInt();
        }
    }

    public void Display()
    {
        System.out.println("Elements are : ");
        for(int i = 0; i < Arr.length; i++)
        {
            System.out.println(Arr[i]);
        }
    }
    public abstract boolean BinarySearch(int iValue);
}

class Searching extends ArrayX
{
    public Searching(int Size)
    {
        super(Size);
    }

    public boolean BinarySearch(int iValue)
    {
        int istart,iend,imid;
        
        istart = 0;
        
        iend = Arr.length-1;

        imid = (istart + iend) / 2;


        while(istart <= iend)
        {
            if(Arr[imid] == iValue)
            {
                break;
            }
            else if(iValue > Arr[imid])
            {
               istart = imid + 1;     
            }
            else if(iValue < Arr[imid])
            {
                iend = imid - 1;
            }
           
            imid = (istart + iend) / 2;

        }

        if(Arr[imid] == iValue)
            return true;
        else
            return false;
    }
}

class prg3
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.print("Enter the size of array : ");
        int Size =  sobj.nextInt();

        Searching obj = new Searching(Size);
        
        obj.Accept();
        // obj.Display();

        System.out.println("Enter the number to search : ");
        int iNo = sobj.nextInt();

        boolean bRet = obj.BinarySearch(iNo);
        if(bRet == true)
        {
            System.out.println("Number is there in array");
        }
        else
        {
            System.out.println("Number is not there in array");
        }

        System.out.print("\n");
    }
}
