 /*
 -------------------------------------------------------
 Project: Tic Tac Toe
 File:  tic_tac_toe.c
 -------------------------------------------------------
 Author:  Nathaniel Carr
 Version  2018-01-09
 -------------------------------------------------------
 */

#include <stdio.h>
#include <stdbool.h>

int print_board();
bool check_win();
bool check_tie();

int main(){
	
	char board[3][3];
	char p1, p2;
	int row, col;
	char i, j;
	int in;
	bool over = 0;
	
	while (!over) {
	
		//fill board with blanks.
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				board[i][j] = ' ';
			}
		}
		
		//get first player's character.
		printf("Please enter the first player's character: ");
		p1 = getchar();
		
		//clear input.
		while (getchar() != '\n');
		
		while (p1 == '\n' || p1 == ' '){
			printf("Please enter a character: ");
			p1 = getchar();
			
			//clear input.
			while (getchar() != '\n');
		}
		
		//get second player's character.
		printf("Please enter the second player's character: ");
		p2 = getchar();
		
		//clear input.
		while (getchar() != '\n');
		
		while (p2 == '\n' || p2 == ' ' || p2 == p1){		
			if (p2 == '\n' || p2 == ' '){
				printf("Please enter a character: ");
			} else {
				printf("Please choose a different character: ");
			}
			
			p2 = getchar();
			
			//clear input.
			while (getchar() != '\n');
		}

		while (!over){
			
			//print board.
			printf("\n");
			print_board(board);
			
			//accept player 1's input.
			printf("\nPlayer 1's turn. Enter in C,R format (C: column, R: row): ");
			in = scanf("%d,%d", &col, &row);
			
			//clear input.
			while (getchar() != '\n');
			
			while (in != 2 || !(0 <= row && row <= 2) || !(0 <= col && col <= 2) || board[col][row] != ' '){
				
				if (in != 2){
					printf("Enter in C,R format (C: column, R: row): ");
				} else if (!(0 <= row && row <= 2) || !(0 <= col && col <= 2)){
					printf("The row and column values must be between 0 and 2: ");
				} else {
					printf("This position is already occupied: ");
				}
				
				in = scanf("%d,%d", &col, &row);
				
				//clear input.
				while (getchar() != '\n');
			}
			
			//place player 1's character.
			board[col][row] = p1;
			
			//print board.
			printf("\n");
			print_board(board);
			
			//check for a win or a tie.
			if (check_win(board)){
				over = 1;
				printf("\nPlayer 1 wins!\n");
			} else if (check_tie(board)) {
				over = 1;
				printf("\nIt's a tie!\n");
			} else {
			
				//accept player 2's input.
				printf("\nPlayer 2's turn. Enter in C,R format (C: column, R: row): ");
				in = scanf("%d,%d", &col, &row);
				
				//clear input.
				while (getchar() != '\n');
				
				while (in != 2 || !(0 <= row && row <= 2) || !(0 <= col && col <= 2) || board[col][row] != ' '){
					
					if (in != 2){
						printf("Enter in C,R format (C: column, R: row): ");
					} else if (!(0 <= row && row <= 2) || !(0 <= col && col <= 2)){
						printf("The row and column values must be between 0 and 2: ");
					} else {
						printf("This position is already occupied: ");
					}
					
					in = scanf("%d,%d", &col, &row);
					
					//clear input.
					while (getchar() != '\n');
					
				}	
				
				//place player 2's character.
				board[col][row] = p2;
				
				//check for a win. Tie never possible after second player's turn.
				if (check_win(board)){
					over = 1;
					printf("\nPlayer 2 wins!\n");
					getchar();
				}	
			}
		
		}
	
		//ask to play again.
		printf("\nWould you like to play again (Y/N)? ");
		p1 = getchar();
		if (p1 == 'Y' || p1 == 'y'){			
			over = 0;
			
			//clear input.
			while (getchar() != '\n');
			
			printf("\n");
		}
		
	}
	
	return 0;
	
}
	
int print_board(char board[3][3]){
	/*
    -------------------------------------------------------
    Draws a board from a 2d array of char with 3 indices in 
        each dimension
    Use: draw_board(board)
    -------------------------------------------------------
    Preconditions:
        board - a 2d array of char with 3 indices in each
			dimension.
    Postconditions:
        prints - the board.
    -------------------------------------------------------
    */
	
	printf("  0 1 2\n");
	printf("0 %c|%c|%c\n",board[0][0], board[1][0], board[2][0]);
	printf("  -----\n");
	printf("1 %c|%c|%c\n",board[0][1], board[1][1], board[2][1]);
	printf("  -----\n");
	printf("2 %c|%c|%c\n",board[0][2], board[1][2], board[2][2]);
	
	return 0;
	
}

bool check_win(char board[3][3]){
	/*
    -------------------------------------------------------
    Checks if the game has been won.
    Use: won = check_win(board)
    -------------------------------------------------------
    Preconditions:
        board - a 2d array of char with 3 indices in each
			dimension.
    Postconditions:
        returns
        1 if the game has been won, 0 otherwise.
    -------------------------------------------------------
    */
	
	bool won = 0;
	char i;
	
	//check win on complete column.
	for (i = 0; i<3; i++){
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]){
			won = 1;
			break;
		}
	}
	
	//check win on complete row.
	if (!won){
		for (i = 0; i<3; i++){
			if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i]){
				won = 1;
				break;
			}
		}
	}
	
	//check win on diagonal.
	if ((board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) || 
		(board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0])){
		won = 1;
	}
	
	return won;
	
}

bool check_tie(char board[3][3]){
	/*
    -------------------------------------------------------
    Checks if a tie has occurred (all spaces used).
    Use: tie = check_tie(board)
    -------------------------------------------------------
    Preconditions:
        board - a 2d array of char with 3 indices in each
			dimension.
    Postconditions:
        returns
        1 if the game has been tied, 0 otherwise.
    -------------------------------------------------------
    */
	
	bool tie = 1;
	char i, j;
	
	//check if there is any place on the board that is empty.
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if (board[i][j] == ' '){
				tie = 0;
				break;
			}
		}
		
		if (!tie){
			break;
		}
	}
	
	return tie;
}
	