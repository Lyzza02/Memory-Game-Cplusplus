#include<iostream>
#include<cstdlib>
#include<time.h>
#include<windows.h>
using namespace std;
struct box{
	int ans, choice;
	int row, col,row1,col1;
	int matrix[5][5];
	int times;
};

int table();// this will print the asterisk matrix 
void design(); //for display
void design2();//for display
int gamestart(struct box); // for the 1st case
int trial(struct box); // for the 2nd case

int main()
{
	start:
	box tabs;
	system("cls");
	design2();
	cout<<"\n    M E M O R Y  G A M E\n";
	design2();
	cout<<"\n\n[1] - Game Start\n[2] - Trials\n[3] - Exit";
	cout<<"\n\nYour Option: ";
	cin>>tabs.choice;
	switch(tabs.choice)
	{
		case 1:
			gamestart(tabs); // games
			break;
		case 2:
			trial(tabs); // trials or practice
			break;
		case 3: //exit
			cout<<"THANK YOU FOR PLAYING THE GAME! GOODBYE!";
			return 0;
			break;
		default: // when the user input wrong number
			cout<<"\nINVALID INPUT ;(";
			cout<<"\nDo you want try again?(1 for yes and 2 for no)"<<endl;
			cin>>tabs.ans;
			if(tabs.ans==1)
				goto start;
			else
			{
				cout<<"THANK YOU FOR PLAYING THE GAME! GOODBYE!";
				return 0;
			}
	}
	return 0;
}

int gamestart(struct box tabs)
{
	again:
	system("cls");
	tabs.times=1;
	cout<<"READY.....";Sleep(2000);
	cout<<"SET......";Sleep(2000);
	cout<<"\nGAME START!!";
	srand((unsigned)time(NULL)); // for the random numbers
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<5;j++)
			tabs.matrix[i][j]=rand()%9+1;
	}
	restart:
	cout<<"\n1\t2\t3\t4 ";
	design();
	table();// this will print the matrix
	cout<<"\nEnter from 1 to 4";// the user will input the rows and columns
	cout<<"\nPlease insert the 1st row : ";
	cin>>tabs.row;
	cout<<"Please insert the 1st column: ";
	cin>>tabs.col;
	cout<<"\nPlease insert the 2nd row: ";
	cin>>tabs.row1;
	cout<<"Please insert the 2nd column: ";
	cin>>tabs.col1;
	cout<<endl;
	
	//these will place at the matrix (row,row1,col,col1)
	tabs.matrix[tabs.row][tabs.col];
	tabs.matrix[tabs.row1][tabs.col1];
	
	if(tabs.row==tabs.row1&&tabs.col==tabs.col1)// when the position si taken [row][col]
	{
		cout<<"\nOops, the slot ["<<tabs.row1<<"]["<<tabs.col1<<"] was already taken.";
		goto ask;
	}
	cout<<"\t1\t2\t3\t4\n";
	cout<<"  ---------------------------------\n";
	for(int i=1;i<5;i++)
	{
		cout<<" "<<i<<"|\t";
		for(int j=1;j<5;j++)
		{
			if(i == tabs.row && j == tabs.col)// this will show the nu
				cout<<tabs.matrix[i][j]<<"\t";
			else if(i == tabs.row1 && j == tabs.col1)
                cout << tabs.matrix[i][j]<<"\t";
            else
                cout << "*\t";
		}
		cout<<endl;
	}
	cout<<"\nRound: "<<tabs.times++;// this will measure how many times you have tried before achieving the match pairs
	if (tabs.matrix[tabs.row][tabs.col]==tabs.matrix[tabs.row1][tabs.col1])
	{
		cout<<"\nCongrats, you got the same number";
		cout<<"\nEnter\n[1] - To play the trial game\n[2] - To play the actual game\n[3] - Exit";// this will ask again the user if he or she wants to restart the game.
		cout<<"\n\nYour choice: ";
		cin>>tabs.ans;
		if(tabs.ans==1)
			trial(tabs);
		else if(tabs.ans==2)
			goto again;
		else
		{
			cout<<"THANK YOU FOR PLAYING THE GAME !!!";// this will end the game
			return 0;
		}	
	}
	else
	{
		ask:
		cout<<"\nEnter 1 to play again. Enter 0 to quit: ";
		cin>>tabs.ans;
		if(tabs.ans==1)
		{
			system("cls");
			goto restart;
		}
		else
		{
			cout<<"\nTHANK YOU FOR PLAYING THE GAME !!!";
			return 0;
		}	
	}
}

int trial(struct box tabs)//this is the trial or practice of the game
{
	again:
	tabs.times=1;
	srand((unsigned)time(NULL)); // for the random numbers
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<5;j++)
			tabs.matrix[i][j]=rand()%9+1;
	}
	restart:
	system("cls");
	cout<<"::::::::GAME TRIAL:::::::::";
	cout<<"\n\n1\t2\t3\t4 ";
	design();
	table();// this will print the matrix
	cout<<"\nEnter from 1 to 4";// the user will input the rows and columns
	cout<<"\nPlease insert the 1st row : ";
	cin>>tabs.row;
	cout<<"Please insert the 1st column: ";
	cin>>tabs.col;
	cout<<"\nPlease insert the 2nd row: ";
	cin>>tabs.row1;
	cout<<"Please insert the 2nd column: ";
	cin>>tabs.col1;
	cout<<endl;
	//these will place at the matrix (row,row1,col,col1)
	tabs.matrix[tabs.row][tabs.col];
	tabs.matrix[tabs.row1][tabs.col1];
	
	if(tabs.row==tabs.row1&&tabs.col==tabs.col1)
	{
		cout<<"\nOops, the slot ["<<tabs.row1<<"]["<<tabs.col1<<"] was already taken.";
		goto ask;
	}
	cout<<"\t1\t2\t3\t4\n";
	cout<<"  ---------------------------------\n";
	for(int i=1;i<5;i++)
	{
		cout<<" "<<i<<"|\t";
		for(int j=1;j<5;j++)
		{
			if(i == tabs.row && j == tabs.col)// this will show the nu
				cout<<tabs.matrix[i][j]<<"\t";
			else if(i == tabs.row1 && j == tabs.col1)
                cout << tabs.matrix[i][j]<<"\t";
            else
                cout << "*\t";
		}
		cout<<endl;
	}
	cout<<"\nRound: "<<tabs.times++;// this will measure how many times you have tried before achieving the match pairs
	if (tabs.matrix[tabs.row][tabs.col]==tabs.matrix[tabs.row1][tabs.col1])
	{
		cout<<"\nCongrats, you got the same number";
		cout<<"\nEnter\n[1] - To play again (Trial)\n[2] - To play the actual game\n[3] - Exit";// this will ask again the user if he or she wants to restart the game.
		cout<<"\n\nYour choice: ";
		cin>>tabs.ans;
		if(tabs.ans==1)
			goto again;
		else if(tabs.ans==2)
			gamestart(tabs);
		else
		{
			cout<<"THANK YOU FOR PLAYING THE GAME !!!";// this will end the game
			return 0;
		}	
	}
	else
	{
		ask:
		cout<<"\nEnter 1 to play again. Enter 0 to quit: ";
		cin>>tabs.ans;
		if(tabs.ans==1)
			goto restart;
		else
		{
			cout<<"\nTHANK YOU FOR PLAYING THE GAME !!!";
			return 0;
		}	
	}
}

void design()
{
	cout<<endl;
	for(int i=1;i<10;i++)
		cout<<"---";
	cout<<endl;
}

void design2()
{
	for(int i=1;i<29;i++)
		cout<<"+";	
}

int table()
{
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<5;j++)
			cout<<"*\t";
		cout<<"\n";
	}
}
