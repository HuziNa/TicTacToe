#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


// this is a tictactoe game 
bool num = true;
// Function to display the board
void displayboard(char board[3][3]) {
	cout << "\nCurrent Board:\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j];    // Print the cell value
			if (j < 2) cout << " | ";  // Print separators between columns
		}
		cout << endl;

		if (i < 2) {
			cout << "--|---|--" << endl;  // Print separators between rows
		}

	}
}

// function for computer move
void computer(char board[3][3])
{
	bool move = true;
	while (move == true)
	{
		srand(static_cast<unsigned>(time(0))); // for random number
		int random1 = 0 + rand() % 3; // generates the number for the computers turn
		int random2 = 0 + rand() % 3; // generates the number for the computers turn

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[random1][random2] == '-')
				{
					board[random1][random2] = 'A';
					displayboard(board);
					move = false;
				}
			}
		}
	}

}

// function for checking if a player has won or not
void winchecker(char board[3][3]) {

	// checking rows
	for (int i = 0; i < 3; i++) // 0,1 and 2 will be checked
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][0] == 'X')
			{
				cout << "You have won!!" << endl;
				num = false;
			}
			else if (board[i][0] == 'A')
			{
				cout << "The computer has won!!" << endl;
				num = false;
			}			
		}		
	}

	// checking columns
	for (int j = 0; j < 3; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
		{
			if (board[0][j] == 'X')
			{
				cout << "You have won!!" << endl;
				num = false;
			}
			else if (board[0][j] == 'A')
			{
				cout << "The computer has won!!" << endl;
				num = false;
			}			
		}	

	}

	// checking the diagnols

	//main diagnol
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		
		if (board[0][0] == 'X') {
			cout << "You have won!!" << endl;
			num = false;
			
		}

		if (board[0][0] == 'A') {
		cout << "The computer has won!!" << endl;
		num = false;
		}
	}

	//oppposite diagnol
	 if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == 'X') {
			cout << "You have won!!" << endl;
			num = false;
		}
		else if (board[0][2] == 'A')
		{
			cout << "The computer has won!!" << endl;
			num = false;
		}		
	}	
}




int main() {

	const int n = 3, m = 3;
	int choice;

	int block[n][m];
	char board[3][3] = {
			{'-', '-', '-'},
			{'-', '-', '-'},
			{'-', '-', '-'}
	};

	cout << "Hello! Welcome to the tic tac toe game!" << endl;
	cout << "Press 1 to start." << endl;
	cout << "Press 2 to quit." << endl;
	cin >> choice;





	while (choice == 1)
	{
		if (choice != 1 && choice != 2)
		{
			cout << "Oops! You entered the wrong option." << endl;
		}

		else
		{

			int turn = 2;
			int row, col;
			bool player1 = true;
			bool player2 = false;
			displayboard(board);
		
			
			while (num)
			{


				while (player1 == true)
				{
					cout << "\nYour turn now!!\n" << endl;
					cout << "Enter the row: " << endl;
					cin >> row;
					cout << "Enter the column: " << endl;
					cin >> col;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							if (i == row && j == col)
							{
								board[i][j] = 'X';
								displayboard(board);
								player1 = false;
								player2 = true;
								winchecker(board);
							}

						}

					}
				}



				while (player2 == true)
				{
					player2 = false;
					cout << "\nIts the computers turn!\n" << endl;
					computer(board);
					winchecker(board);
					player1 = true;
				}
			}



		}
		choice++;
	}


	return 0;
}
