
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

#include<ncurses.h>
#include<curses.h>       

#include"getchInLinux.h"

 create matrix 4*4
void  createMatrix(int arr[][4])
{
    int n=15;
    int num[n],i,j;
    for(i=0;i<15;i++)        
    num[i]=i+1;

    srand(time(NULL));           

    int lastIndex=n-1,index;

    for(i=0;i<4;i++)
    for(j=0;j<4;j++)
  {
    if(lastIndex>=0)
    {  index=rand()%(lastIndex+1);
       arr[i][j]=num[index];       
       num[index]=num[lastIndex--]; 
    }                               
  }
       arr[i-1][j-1]=0;      

}

void showMatrix(int arr[][4])
{
    int i,j;
    printf("----------------------\n");
    for(i=0;i<4;i++)
   { printf("༏  ");
       for(j=0;j<4;j++)
    {   if(arr[i][j]!=0)
        printf("%-2d ༏ ",arr[i][j]);
        else
        printf("   ༏ ");
    }
    printf("\n");
   }

    printf("----------------------\n");
}


int winner(int arr[][4])
{
    int i,j,k=1;
    for(i=0;i<4;i++)
   { for(j=0;j<4;j++,k++)
        if(arr[i][j]!=k && k!=16)
        break;
    if(j<4)
    break;
   }
        if(j<4)
        return 0;
        return 1;
}

void swap(int *x,int *y)
{
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
    printf("\a\a\a");
}


int readEnteredKey()
{
        char c;
            c = getchInLinux();
            if(c==27 || c==91)      
         {  c = getchInLinux();
             if(c==27 || c==91)     
              c=getchInLinux();
         }
    return c;
}

int shiftUp(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(i==3)                
        return 0;
        swap(&arr[i][j],&arr[i+1][j]);
        return 1;               
}

int shiftDown(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(i==0)                 
        return 0;
         swap(&arr[i][j],&arr[i-1][j]);    

        return 1;         
}

int shiftRight(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(j==0)                 
        return 0;
             swap(&arr[i][j],&arr[i][j-1]);

        return 1;           
}

int shiftLeft(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(j==3)               
        return 0;
                swap(&arr[i][j],&arr[i][j+1]);
        return 1;              
}

// Game rules
void gameRule(int arr[][4])
{
    system("clear");
    int x=readEnteredKey();
    int i,j,k=1;
    printf("                 RULE OF THIS GAME                 \n");
    printf("\n1.You can move only 1 step at a time by arrow key ");
    printf("\nMove Up   : by Up arrow key ");
    printf("\nMove Down : by Down arrow key");
    printf("\nMove Left : by Left arrow key");
    printf("\nMove Right: by Right arrow key");

    printf("\n2.You can move number at empty position only ");
    printf("\n");
    printf("\n3.For each valid move : your total number of move will decreased by 1 \n");
    printf("4.Wining situation : ");
    printf("number in a 4*4 matrix should be in order from 1 to 15 ");
    printf("\n\n            winning situation:         \n");

    printf("----------------------\n");
    for(i=0;i<4;i++)
   { printf("༏  ");
       for(j=0;j<4;j++)
    {   if(arr[i][j]!=0)
        printf("%-2d ༏ ",4*i+j+1);
        else
        printf("   ༏ ");
    }
    printf("\n");
   }

    printf("----------------------\n");
    printf("\n5.You can exit the game at any time by pressing 'E' or 'e' ");


    printf("\nSo Try to win in minimum no of move \n");
    printf("\n         Happy gaming , Good Luck\n");

    printf("\nEnter any key to start.....  🆗 : ");
    x=readEnteredKey();
}

// main function
int main()
{
    int arr[4][4];      
    int maxTry=400;       
    char name[20];
   system("clear");        

    printf("Enter Your Good Name: ");
    scanf("%s",name);

       while(1)
    {             createMatrix(arr);   
                  gameRule(arr);      

          while(!winner(arr))     
        {
               system("clear");
               if(!maxTry)        
                break;

               printf("\n\n  welcome  %s  ,  Move remaining : %d\n\n",name,maxTry);

              showMatrix(arr);    


            int key=readEnteredKey();   

        switch(key)         
        {
            case 69:                  

            case 101:                
                        printf("\a\a\a\a\a\a\n     Thanks for Playing ! \n\a");
                        printf("\nHit 'Enter' to exit the game \n");
                        key=readEnteredKey();
                        exit(0);


            case 65:          
                        if(shiftUp(arr))
                        maxTry--;
                        break;
            case 66:          
                        if(shiftDown(arr))
                        maxTry--;
                        break;
            case 67:          
                        if(shiftRight(arr))
                        maxTry--;
                        break;
            case 68:            
                        if(shiftLeft(arr))
                        maxTry--;
                        break;
            default:

                       printf("\n\n      \a\a❌ Not Allowed \a\a\a\a");
        }

        }
        if(!maxTry)
         printf("\n\a          YOU LOSE !          \a\a\n");
         else
         { printf("\n\a!!!!!!!!!!!!!Congratualization !!!!!!!!!!!!!\n\a");
           printf("\a               You have Won      \a\a\a ");
         }
         char check;
        printf("\nwant to play again ? \n");
        printf("enter 'y' to play again:  ");
        scanf("%c",&check);
        if(check!='y' && check!='Y')
            break;
        maxTry=400;
    }
    return 0;
}
