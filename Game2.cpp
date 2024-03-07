
// Program: Players aim to be the first to reach a sum of 15 with three unique number selections from 1 to 9.

//  game2: Number scrabble  


// Author:Mahmoud Abdelnaby Abdelaliem Hassan 
//ID : 20230373


// Version: 2.1


// Date: 1/3/2024

#include <iostream>
#include <string>
#include <list>
#include<set>
#include <cmath>
using namespace std;
//Function to Check winner
bool win(const set<int>& numbers) {
  int target =15 ;
    for (int num : numbers) {
        for (int num2 : numbers) {
            // Skip if the numbers are equal
            if (num == num2) 
                continue;
            // Calculate the third number needed to make the target sum
            int num3 = target - num - num2;
            // Check if the third number is in the set
            if (numbers.count(num3) > 0) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    // Initialize the lists
    list<int> list1 = {1, 2, 3,4 ,5, 6,7,8, 9};
    set<int> num_player1 = { };
    set<int> num_player2 ={ };
    bool game_over=false;
  // Welcome message and instructions message
    cout << "welcome to the Number scrabble" << endl;
    cout << "Number Scrabble is a game where players take turns to select numbers from 1 to 9 \n without repeating any numbers previously used, and the first player with a sum of \n exactly 15 using any three of their number selections wins the game" << endl;
    while (!game_over) {
        cout << "selected on list :[" << endl;
        //print list1
        for (int num : list1)
            cout << num << ",";
        cout << "]"<< endl;

        cout << "player1 number : [" << endl;
        //print num_player1
        for (int num : num_player1)
            cout << num << ",";
        cout << "]"<< endl;
        double player1;
        //player1's turn.
        cout << "player1 : " ;
        cin >> player1;
        //Check if the number is correct
            while (1) {
                //Check if the entered number is incorrect
                if (cin.fail()){
                    
                    cin.clear( );
                    cin.ignore();
                    cout << "please select a valid number" << endl ;
                    cout << "player1 : " ;
                    cin >> player1;
                }
                // Check if the number is in range
                else if (player1 < 1 || player1 > 9) {
                    cout << "Please select a number from 1 to 9" << endl;
                    cout << "Player 1: " ;
                    cin >> player1;
                }
                // Check if the number is already used
                else if (num_player1.count(player1) > 0 || num_player2.count(player1) > 0) {
                    cout << "Please select a number that is not already used" << endl;
                    cout << "Player 1: " ;
                    cin >> player1;
                }
                //Ckeck if the number is integer
                else if (player1 != floor(player1)){
                    cout << "Please select a number integer" << endl;
                    cout << "player1 : " ;
                    cin >> player1;
                    }
                else 
                    break;
}
//Remove the number from the available numbers and add it to the used numbers and player 1's numbers
        num_player1.insert( player1);
        list1.remove(player1);
        //check if player1 is the winner
        if (win(num_player1)) {
            
            cout << "Player 1 is the winner" << endl;
            game_over = true;
        }
        //Check if there are any numbers left
        else if (list1.empty()) {
            cout << "The game is draw" << endl;
            game_over = true;}
        else if (!game_over){
            cout << "selected on list : [" << endl;
            //print list1
            for (int num : list1)
                cout << num << ",";
            cout << "]"<< endl;
            cout << "player2 number : [" << endl;
            //print num_player2
            for (int num : num_player2)
                cout << num << ",";
            cout << "]" << endl;
            double player2;
            cout << "player2 : " ;
            cin >> player2;
            //Check if the number is correct
                while (1) {
                    //Check if the entered number is incorrect
                    if (cin.fail()){
                        cin.clear( );
                        cin.ignore();
                        cout << "please select a valid number" << endl ;
                        cout << "player2 : " ;
                        cin >> player2;
                    }
                    // Check if the number is in range
                    else if (player2 < 1 || player2 > 9) {
                        cout << "Please select a number from 1 to 9" << endl;
                        cout << "Player 2: "  ;
                        cin >> player2;
                    }
                    // Check if the number is already used
                    else if (num_player1.count(player2) > 0 || num_player2.count(player2) > 0) {
                        cout << "Please select a number that is not already used" << endl;
                        cout << "Player 2: " ;
                        cin >> player2;
                    }
                    else if (player2 != floor(player2)){
                        cout << "Please select a number integer" << endl;
                        cout << "player2 : " ;
                        cin >> player2;
                    }
                    else {
                        break;}
    }
//Remove the number from the available numbers and add it to the used numbers and player 1's numbers
            num_player2.insert( player2);
            list1.remove(player2);
            //check if player2 is the winner
            if (win(num_player2)) {
                cout << "Player 2 is the winner" << endl;
                game_over = true;
            }
            //Check if there are any numbers left
            else if (list1.empty()) {
                cout << "The game is draw" << endl;
                game_over = true;
            }
    }
    }
    return 0;
}
