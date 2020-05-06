// Header files
#include<stdio.h>
#include<conio.h>
// Global variables
char p1[15],p2[15];
int pos[9],index,moves,win,sign,player;

void instructions()
{
// This function executes only once
printf("\n\t\t\t       TIC TAC TOE");
printf("\n\n\n\t\t\t          RULES");
printf("\n\n\n        CHOOSE A CELL NUMBERED FROM 1 TO 9 AS SHOWN BELOW AND PLAY\n\n");
printf("\n\t\t\t        |       |       ");
printf("\n\t\t\t    %d   |   %d   |   %d   ",1,2,3);
printf("\n\t\t\t -------|-------|-------");
printf("\n\t\t\t    %d   |   %d   |   %d   ",4,5,6);
printf("\n\t\t\t -------|-------|-------");
printf("\n\t\t\t    %d   |   %d   |   %d   ",7,8,9);
printf("\n\t\t\t        |       |       ");
}

void display()
{
// Function to display the game-board
printf("\n\t\t\t\tTIC TAC TOE");
printf("\nPLAYER 1: %s",p1);
printf("\nPLAYER 2: %s",p2);
printf("\n\n%s's SYMBOL: X",p1);
printf("\n%s's SYMBOL: O",p2);
printf("\n\t\t\t         |       |       ");
printf("\n\t\t\t     %c   |   %c   |   %c   ",pos[0],pos[1],pos[2]);
printf("\n\t\t\t  -------|-------|-------");
printf("\n\t\t\t     %c   |   %c   |   %c   ",pos[3],pos[4],pos[5]);
printf("\n\t\t\t  -------|-------|-------");
printf("\n\t\t\t     %c   |   %c   |   %c   ",pos[6],pos[7],pos[8]);
printf("\n\t\t\t         |       |       ");
}

void start()
{
// This function executes only once
int i;
for(i=0;i<9;i++)
	pos[i]=' ';
}

int checkD()
{
// Function to check diagonal
if((pos[0]==sign && pos[4]==sign && pos[8]==sign)
			||
(pos[2]==sign && pos[4]==sign && pos[6]==sign))
	win=1;
return win;
}
int checkRow()
{
// Function to check row
int i;
for(i=0;i<9;i+=3)
{
	if(pos[i]==sign && pos[i+1]==sign && pos[i+2]==sign)
	{
		win=1;
		break;
	}    
}
return win;
}

int checkCol()
{
// Function to check column
int i;
win=0;
for(i=0;i<3;i++)
{
	if((pos[i]==sign) && (pos[i+3]==sign) && (pos[i+6]==sign))
		{
			win=1;
			break;
		}
}
return win;
}

void run()
{
start();
clrscr();
while(moves<9)
{
	clrscr();
	display	();
	if(moves%2==0)
	{
		sign='X';
		player=1;
	}
	else
	{
		sign='O';
		player=2;
	}
	printf("\nENTER POSITION PLAYER %d ",player);
	scanf("	%d",&index);
	if(index<0 || index>9)
	{
		printf("\nENTER POSITION BETWEEN 1 AND 9");
		scanf("%d",&index);
	}
	if(pos[index-1]=='X' || pos[index-1]=='O')
	{
		printf("\nPOSITION OCCUPIED! ENTER NEW POSITION:");
		scanf("%d",&index);
	}
	pos[index-1]=sign;
	if(checkRow() || checkD() || checkCol())
			break;
	moves++;
	}
}
void main()
{
int i,len;
clrscr();
instructions();
printf("\n\n\n\t\t        PRESS ANY KEY TO CONTINUE!");
getch();
clrscr();
printf("\nENTER PLAYER 1:");
gets(p1);
for(i=0;p1[i]!='\0';i++)
	if(p1[i]>='a' && p1[i]<='z')
		p1[i]-=32;
printf("\nENTER PLAYER 2:");
gets(p2);
for(i=0;p2[i]!='\0';i++)
	if(p2[i]>='a' && p2[i]<='z')
		p2[i]-=32;
clrscr();
run();
clrscr();
display();
if(player==1 && win==1)
	printf("\n\n\n\t\t\t        %s IS WINNER! ",p1);
else if(win==1)
	printf("\n\n\n\t\t\t        %s IS WINNER! ",p2);
else
	printf("\n\n\n\t\t\t        MATCH DRAWN !");
printf("\n\n\t\t\t    PRESS ANY KEY TO EXIT !");
getch();
}