#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

/*Tic Tac Toe game:
 * 
 * Player 1 will be X and player 2 will be O. The first to play will be chosen randomly.
 * 
 * */

//***********Functions Prototypes***********:
void Welcome();
void Display_board(char gb[], char ava[]);
void Get_input(char gb[], char ava[], char marker);
void Place_marker(char gb[], char ava[], int num, char marker);
bool Check_if_win(char gb[], char marker);
bool Check_if_full(char gb[]);
bool Play_again();
//***********End of Functions Prototypes***********.


//***********Functions Definitions***********:
void Welcome() {
    std::cout << "---------------------WELCOME---------------------\n\n";
    std::cout << "Welcome to the Tic Tac Toe game.\n";
    std::cout << "This is a 2 player game. Player 1 will be X, Player 2 will be O.\n";
    std::cout << "The first to go will randomly. Hope will enjoy !\n";
    std::cout << "I think you already know the rules and how to win\n";
    std::cout << "-------------------------------------------------\n\n";
    system("pause");
}
void Display_board(char gb[], char ava[]) {
    //Display the board and also the available options.
    system("cls");
    std::cout << std::endl;
    std::cout<< std::setw(8) << "BOARD" << std::setw(25) << "AVAILABLE" << std::endl;
    std::cout<< " " << gb[7] << " | " << gb[8] << " | " << gb[9] << std::setw(15) << ava[7] << " | " << ava[8] << " | " << ava[9] << std::endl;
    std::cout<< " " << gb[4] << " | " << gb[5] << " | " << gb[6] << std::setw(15) << ava[4] << " | " << ava[5] << " | " << ava[6] << std::endl;
    std::cout<< " " << gb[1] << " | " << gb[2] << " | " << gb[3] << std::setw(15) << ava[1] << " | " << ava[2] << " | " << ava[3] << std::endl;
    std::cout << std::endl;
}

void Get_input(char gb[], char ava[], char marker) {
    //Get input and test too. If input is available, will place the marker.
    int temp{};    
    
    while(true) {
        std::cin>> temp;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<< "Invalid Data. Enter again: ";
        }
        else if (ava[temp] == ' ' || temp < 1 || temp > 9) {
            std::cout<< "Position not available, try again: ";
        }
        else{
            Place_marker(gb, ava, temp, marker);
            break;
        }
    }
}
void Place_marker(char gb[], char ava[], int num, char marker) {
    gb[num] = marker;
    ava[num] = ' ';
}

bool Check_if_win(char gb[], char marker) {
    return ((gb[1] == marker && gb[2] == marker && gb[3] == marker) ||
            (gb[4] == marker && gb[5] == marker && gb[6] == marker) ||
            (gb[7] == marker && gb[8] == marker && gb[9] == marker) ||
            (gb[1] == marker && gb[4] == marker && gb[7] == marker) ||
            (gb[2] == marker && gb[5] == marker && gb[8] == marker) ||
            (gb[3] == marker && gb[6] == marker && gb[9] == marker) ||
            (gb[1] == marker && gb[5] == marker && gb[9] == marker) ||
            (gb[3] == marker && gb[5] == marker && gb[7] == marker));
}

bool Check_if_full(char gb[]) {
    for (size_t i{}; i < 10 ; i++) {
        if (gb[i] == ' ')
            return false;
    }
    return true;
}

bool Play_again() {
    std::string temp{false};
    char c{};
    
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    
    while(true) {
        std::cout << "Do you want to play again? (Y/N)";
        std::getline (std::cin, temp);
        c = toupper(temp[0]);
        
        if (c == 'Y') {
            return true;
        } else if (c == 'N') {
            std::cout << "Thanks for playing. Have a nice day." << std::endl;
            return false;
        } else{
            continue;
        }
    }
}
//***********End of functions definitions***********


int main() {
    bool game_on {true};
    
    //random number used to check who will go first. If it is 1, player 1 will go first. If it is 2, player 2 will go first.
    int random_num{};
    srand(time(nullptr));
    random_num = rand() % 2 + 1;
    
    Welcome();
    
    while(game_on) {
    char game_board[10] = {'K', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char availables[10] = {'K','1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
        while (true) {
            //Player 1 turn:
            if (random_num % 2 != 0) {
                random_num++;
                Display_board(game_board, availables);
                std::cout << "Player 1 (X), type your position: ";
                Get_input(game_board, availables, 'X');
                
                if (Check_if_win(game_board, 'X')) {
                    Display_board(game_board, availables);
                    std::cout<< "**** Congrats Player 1(X), you won ****\n" << std::endl;
                    break;
                }
                else if (Check_if_full(game_board)){
                    Display_board(game_board, availables);
                    std::cout << "Haha, no one won. That is a draw! XD\n" << std::endl;
                    break;
                }
            }
            
            //Player 2 turn:
            else if(random_num % 2 == 0) {
                random_num++;
                Display_board(game_board, availables);
                std::cout << "Player 2 (O), type your position: ";
                Get_input(game_board, availables, 'O');
                
                if (Check_if_win(game_board, 'O')) {
                    Display_board(game_board, availables);
                    std::cout<< "**** Congrats Player 2(O), you won ****\n" << std::endl;
                    break;
                }
                else if (Check_if_full(game_board)){
                    Display_board(game_board, availables);
                    std::cout << "Haha, no one won. That is a draw! XD\n" << std::endl;
                    break;
                }
            }
        }
        game_on = Play_again();
    }
    
    return 0;
}
