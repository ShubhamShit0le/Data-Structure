#include<stdio.h>
#include<stdlib.h>



typedef struct node
{
    int data;
    struct node *next;

}NODE,*PNODE,**PPNODE;




void InsertFirst(PPNODE Head,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;

    if((*Head) == NULL)
    {
    
    *Head=newn;

    }
    else
    {
      newn -> next = *Head;
      *Head = newn;
     
    }   

}

void Display(PNODE Head)
{
  
   while(Head != NULL)
   {
    printf("|%d| -> ",Head -> data);
    Head = Head -> next;
    
   }
   printf("NULL\n");

}

int count(PNODE Head)
{
    int icnt = 0;
    while (Head != NULL)        
    {
        icnt++;
        Head = Head -> next;
    }
    return icnt;
    
}

void InsertLast(PPNODE Head,int no)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
   
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;

    if((*Head) == NULL)
    *Head = newn;
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }


    
}


void InsertAtPos(PPNODE Head,int no,int iPos)
{

    PNODE newn = NULL;
    PNODE temp = *Head;

    int Size = count(*Head);
    
    if(iPos < 1 || iPos > Size+1)
    {
        printf("Invalid Position\n");
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(Head,no);

    }
    else if(iPos == Size+1)
    {
        InsertLast(Head,no);
    }
    else
    {
         int i = 0;
         newn = (PNODE)malloc(sizeof(NODE));
         newn -> data =no;
         newn->next =NULL;

         for(i = 1; i<iPos-1; i++)
         {
            temp = temp -> next;
         }

         newn->next= temp->next;
         temp->next=newn;
         

    }

}

void DeleteFirst(PPNODE Head)
{
   PNODE temp = *Head;


    if(*Head == NULL)
    {
        return;
    }
    else if(*Head != NULL)
    {
        *Head = temp->next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        return;
    }
    else
    {
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        free(temp -> next);
        temp-> next = NULL;
    }
}

void DeleteAtPos(PPNODE Head,int iPos)
{
    PNODE temp = *Head;
    PNODE targetted = NULL;

    int iSize = count(*Head);

    if(iPos < 1 || iPos > iSize)
    {
        printf("Invalide Position\n");
        return;
    }

    if(iPos == 1)
    {
       DeleteFirst(Head);    
    }
    else if(iPos == iSize)
    {
        DeleteLast(Head);
        
    }
    else
    {
           for(int i = 1; i< iPos-1; i++)
           {
              temp = temp -> next;
           }

           targetted = temp -> next;
           temp -> next = targetted ->next;
           free(targetted);

            
    }
}


int main()
{
    PNODE first = NULL;
    
    int Choice = 1;
    int iVal = 0;
    int iRet = 0;
    int iPos = 0;


    while(Choice != 0)
    {
        printf("\n------------------------------------------\n");

        printf("\n1 : Insert Node On First Position\n");
        printf("\n2 : Insert Node On Last Position\n");
        printf("\n3 : Insert Node On Desire Position\n");
        printf("\n4 : Delete Node On First Position\n");
        printf("\n5 : Delete Node On Last Position\n");
        printf("\n6 : Delete Node On Desire Position\n");
        printf("\n7 : Display Contents\n");
        printf("\n8 : Count The Nodes\n");
        printf("\n0 : Terminate Application\n");
        
        printf("\n------------------------------------------\n");

       printf("\nEnter Your Choice : ");
       scanf("%d",&Choice);
       printf("\n");

       switch (Choice)
       {
       case 1:
               printf("\nEnter Data : ");
               scanf("%d",&iVal);
               InsertFirst(&first,iVal);
               printf("\nData Added Successfully");
        break;

        case 2 : 
               printf("\nEnter Data : ");
               scanf("%d",&iVal);
               InsertLast(&first,iVal);
               printf("\nData Added Successfully");

               break;

        case 3:
               printf("\nEnter Data : ");
               scanf("%d",&iVal);
               printf("\nEnter Position : ");
               scanf("%d",&iPos);
               InsertAtPos(&first,iVal,iPos); 
               printf("\nData Added Successfully");  

               break;
       case 4:

               DeleteFirst(&first);
               printf("\nDelete Successfully");
               break;
        case 5: 
                
                DeleteLast(&first);
               printf("\nDelete Successfully");
                  break;
         case 6:
                printf("\nEnter Position : ");
                scanf("%d",&iPos); 
                DeleteAtPos(&first,iPos);  
                printf("\nDelete Successfully"); 
                     break;
         case 7:
                 Display(first);
                    break;
         case 8: 
                iRet = count(first);
                printf("\nCount Is : %d ",iRet);
                break;

         case 0: 
               printf("Thank You!!!!\n");
               break;
               
       default:
            printf("\nPlease Enter Propper Choice\n");
        break;
       }
            

    }





    return 0;
}