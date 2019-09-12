#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
  //Initialize variables
  int input = 0;
  int playing = 1;
  int count = 1;
  char yninput[2];
  //While the player is playing the game
  while (playing == 1) {
    srand(time(0));
    int num = rand() % 101;
    //While the player hasn't guessed the number
    while (input != num) {
      // cout << num << endl; 
      cin >> input; 
      //If the guess is greater than the number
      if (input > num) {
	cout << " Your guess is too high!" << endl;
	count++;
      }
      //If the guess is less than the number
      else if (input < num) {
	cout << " Your guess is too low!" << endl;
	count++;
      }
      //If the player guesses the correct number
      else {
	cout << " You have guessed the number! It took you " << count << " guesses! Would you like to play again?" << endl;
	//Ask the play if they want to play again
	cin >> yninput[2];
	//If the player doesn't want to play again quit the program
	if (yninput[2] == 'n') {
	  playing = 0;
	  input = num;
	}
	//If the player wants to play again restart the program and randomize the number
	else if (yninput[2] == 'y') {
	  input != num;
	}
      }
    }
  }
}


