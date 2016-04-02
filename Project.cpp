#include<iostream>
#include<conio.h>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
int i,j,sw,die;
int check(int x)
{
    int z;
    if(x==17)
    {
        z=7;
    }
    else
    if(x==54)
    {
        z=34;
    }
    else
    if(x==62)
    {
        z=19;
    }
    else
    if(x==64)
    {
        z=60;
    }
    else
    if(x==87)
    {
        z=24;
    }
    else
    if(x==93)
    {
        z=73;
    }
    else
    if(x==95)
    {
        z=79;
    }
    else
    if(x==98)
    {
        z=79;
    }
    else
    if(x==1)
    {
        z=38;
    }
    else
    if(x==4)
    {
        z=14;
    }
    else
    if(x==9)
    {
        z=31;
    }
    else
    if(x==21)
    {
        z=42;
    }
    else
    if(x==28)
    {
        z=84;
    }
    else
    if(x==51)
    {
        z=67;
    }
    else
    if(x==71)
    {
        z=91;
    }
    else
    if(x==80)
    {
        z=100;
    }
    else
    {
        z=x;
    }
    return z;
}
int table()
{
    int board[100];
    for(i=0;i<=99;i++)
    {
        board[i]=i+1;
    }
    for(i=99;i>=10;i--)
    {
        cout<<board[i]<<" ";
        if(board[i]%10==1)
        {
            cout<<endl;
        }
    }
    for(i=0;i<=9;i++)
    {
        cout<<board[i]<<"  ";
    }
}
int pos()
{
    cout<<"\n\nSNAKES ARE FROM:\n98->79\n95->79\n93->73\n87->24\n64->60\n62->19\n54->34\n17->7\n";
        cout<<"LADDERS ARE FROM:\n1->38\n4->14\n9->31\n21->42\n28->84\n51->67\n71->91\n80->100";
}
int game()
{
    int pos[4]={0},score[4]={0};
    char name[4][15];
    int no;
    srand((int)time(0));
    here:
    cout<<"\n\nEnter the Number of Players(1-4):\n";
    cin>>no;
    if(no<=4)
    {
        for(i=0;i<=no-1;i++)
    {
            cout<<"Enter the Name of PLAYER "<<i+1<<":\n";
            cin>>name[i];
    }
    }
    else
    {
        cout<<"More than 4 Players are not allowed!\n";
        cout<<"Enter a value less than 4.\n";
        goto here;
    }
    i=0;
    do
    {
        if(i==no)
        {
            i=0;
        }
        cout<<endl<<name[i]<<"'s Turn:\n";
        cout<<"Rolling the Die\n";
        die=(rand()%6)+1;
        cout<<"You've got\n"<<die<<"\n";
        cout<<"Your Position on Board Now is "<<pos[i]<<".";
        cout<<endl<<"Press any key to let the other play!\n";
        getch();
        if(die==6&&pos[i]==0)
        {
            cout<<"\n"<<name[i]<<" can start the game.\n";
            cout<<"Rolling the die again\n";
            die=(rand()%6)+1;
            cout<<"You've got\n"<<die<<"\n";
            if(pos[i]<check(die))
            {
                cout<<"Congrats! You got a ladder!\n";
                pos[i]=check(die);
            }
            else
            if(pos[i]>check(die))
            {
                cout<<"OOPS! A Snake just bit you!\n";
                pos[i]=check(die);
            }
            cout<<"Your Position on Board Now is "<<pos[i]<<".";
            cout<<endl<<"Press any key to let the other play!\n";
            getch();
        }
        else
        if(pos[i]!=0&&pos[i]!=100)
        {
            pos[i]+=die;
            if(pos[i]<check(die))
            {
                cout<<"Congrats! You got a ladder!\n";
                pos[i]=check(die);
            }
            else
            if(pos[i]>check(die))
            {
                cout<<"OOPS! A Snake just bit you!\n";
                pos[i]=check(die);
            }
        }
        i++;
    }
while(pos[0]<=100||pos[1]<=100||pos[2]<=100||pos[3]<=100);
}
int main()
{
    int ch;
    cout<<setw(70)<<"\"MADE BY ANKUR PANDEY\""<<endl;
    cout<<setw(70)<<"\"SNAKE AND LADDER GAME\""<<endl;
    here:
    cout<<"\n\n";
    cout<<setw(85)<<"PRESS THE NUMERIC KEY CORRESPONDING TO YOUR CHOICE\n";
    cout<<setw(63)<<"1.RULES\n";
    cout<<setw(73)<<"2.POSITION OF SNAKES&LADDERS\n";
    cout<<setw(95)<<"3.IF YOU WANT TO SEE THE POSITIONS OF SNAKE&LADDERS DURING YOUR MOVES\n";
    cout<<setw(100)<<"4.IF YOU DON'T WANT TO SEE THE POSITIONS OF SNAKE&LADDERS DURING YOUR MOVES\n";
    cout<<setw(70)<<"5.TO SEE THE BOARD\n";
    cout<<setw(65)<<"6.PLAY\n\n\n";
    ch=getche();

    switch (ch)
    {
        case '1':
        cout<<".Maximum 4 Players can play the game.\n2.Moving 1 step will award you 1 point.\n3.Climbing with ladder will award 2 Points.\n4.Snake bite will reduce 1 point.\n5.So,the slowest of all the players will win.\n6.It's slightly different from the traditional Snake and ladder game(It's for fun :P).\n7.Player can start only when it'll be 6 on dice.";
        goto here;
        break;
        case '2':
        pos();
        goto here;
        break;
        case '3':
        cout<<"\n\nDONE! NOW YOU'LL SEE THE POSITIONS OF SNAKE&LADDER DURING YOUR MOVES";
        goto here;
        break;
        case '4':
        cout<<"\n\nDONE! NOW YOU'LL NOT SEE THE POSITIONS OF SNAKE&LADDER DURING YOUR MOVES";
        sw=1;
        goto here;
        break;
        case '5':
        cout<<"\n\n";
        table();
        goto here;
        break;
        case '6':
        game();
    }
    return 0;
}
