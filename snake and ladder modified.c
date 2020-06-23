#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int checkposition(int array[],int array1[],int item,int size)
  { int c,i;
    for(i=0;i<size;i++)
        {if(item==array[i])
         {int c=i;
           return (array1[c]);
           break;}

        }
    return item;

  }

  int linear_search(int array[],int size,int item)
  {   int i;
      for(i=0;i<size;i++)
      {
          if(array[i]==item)
            return 1;
      }
      return 0;
  }


  void swap(int *a,int *b)
  {  int temp;
    temp=*a;
       *a=*b;
       *b=temp;
  }



    int main()
{    int m,n,board[100],count_snake,count_ladder,start,end,i,j,k=0,k1=0,array_snake[10],array_ladder[10],flag=0;
     int newposition,position[4],count[4],array_snake1[10],p=0, array_ladder1[10],start1,end1,new_index,no_of_players,press;
	 enp:
	 printf("enter number of players(2-4)");
	 scanf("%d",&no_of_players);
	 if(no_of_players>4||no_of_players<2)
	 {
	 	goto enp;
	 }
     printf("Enter the number n of for the board to have dimention (n*n)\n");
     scanf("%d",&n);
     printf("\n",n);
	 
	 for(i=0;i<no_of_players;i++)
	 {
	 	position[i]=0;
	 	count[i]=0;
	 }


        board[0]=1;
     for(i=1;i<n*n;i++)
       {board[i]=board[i-1]+1;}

     printf("\nThis is value stored in location");

      for(i=0;i<n*n;i++)
         printf("%d\t",board[i]);

     printf("\nEnter the numbers of snakes and its location\n");
     scanf("%d",&count_snake);
     if(count_snake<=10&&count_snake>=1)

    {
        for(i=1;i<=count_snake;i++)
          {  printf("Enter the value where you want to keep snake no. %d 's tounge \n",i);
             scanf("%d",&start);
             if(start==n*n)
             {
                 printf("\nSnakes head cannot be at finish position hence enter another location ");
                 scanf("%d",start);
             }

               if(i>1) {
                  while(1)
                {
                     int result =linear_search(array_snake, k,start);
                     if(result==1)
                         {printf("\nTwo heads cannot be at one place ,so enter differnet location");
                         scanf("%d",&start);
                         continue;
                         }
                     if(result==0)
                      {

                          break;
                      }

                }
               }

              array_snake[k]=start;
              k++;


             printf("Enter the value where yow want to keep snake tail\n");
             scanf("%d",&end);
             array_snake1[p]=end;
             p++;


             if(array_snake[k-1]<array_snake1[p-1])
             {
                 printf("\n Warning:Snakes head  should be at higher position then tail");
                 printf("\nPress 1 to Renter or 2 to swap");
                 scanf("%d",&press);
                 if(press==1)
                    continue;
                 else
                    swap(&array_snake[i],&array_snake1[i]);

             }

        }

    }

        else {printf("Enter correct number of snakes\n");
             exit(1);}





  while(1)
  {
     printf("Enter the numbers of ladder and its location\n");
     scanf("%d",&count_ladder);

         if(count_ladder<=10&&count_ladder>=1)

      { flag=1;
        for(i=1;i<=count_ladder;i++)
          {  printf("Enter the value where you want to reach by ladder");
             scanf("%d",&start1);
             array_ladder[k1]=start1;

             k++;
             printf("Enter the value from where you want to climb ladder ");
             scanf("%d",&end1);
             array_ladder1[p]=end1;
             p++;
          }

      }
        if(flag==1)
           break;

        else
            { printf("\nEnter correct number of ladder next time" ) ;
            }
  }



        do
            {   next:
            	for(i=0;i<no_of_players;i++)
            	{
				again:
                printf("\npresss any key for player %d to roll the dice",i+1);
                int dice=(getche());
                srand(time(NULL));
                dice =((rand()%6)+1);
                printf("\nDice is rolled it gave %d",dice);
                position[i]+=dice;
                if(position[i]>n*n)
                {
                printf("ohhh you dice rolled too high, you cant move");
                position[i]-=dice;	
                goto next;
				}
				if(position[i]==(n*n))
				{
					goto end;
				}

                if(dice==6)
                {
				printf("\nSince 6 came ,roll it again");
                printf("\nplayer %d landed on number %d",i+1,position[i]);
                newposition =checkposition(array_snake,array_snake1, position[i],count_snake );
                if(position[i]>newposition)
                {
                    printf("\nplayer %d is  bitten by  snake so your position is=%d ",i+1,newposition);
                    position[i]=newposition;

                }


                 newposition=checkposition(array_ladder,array_ladder1,position[i], count_ladder) ;
                 if(position[i]<newposition)
                 {
                     printf("\nplayer %d is awarded ladder so your position is=%d ",i+1,newposition);
                     position[i]=newposition;
                 }
                
                goto again;
            	}
            	printf("\nplayer %d landed on number %d",i+1,position[i]);
                count[i]++ ;

                newposition =checkposition(array_snake,array_snake1, position[i],count_snake );
                if(position[i]>newposition)
                {
                    printf("\nplayer %d is  bitten by  snake so your position is=%d ",i+1,newposition);
                    position[i]=newposition;

                }


                 newposition=checkposition(array_ladder,array_ladder1,position[i], count_ladder) ;
                 if(position[i]<newposition)
                 {
                     printf("\nplayer %d is awarded ladder so your position is=%d ",i+1,newposition);
                     position[i]=newposition;
                 }
             	
				}
            }while((position[i]<(n*n)));
            
			end:
			
			printf("\nCongratulation player %d has won the game in %d dice thrown",i+1,count[i]+1);
           return 0 ;



}

































