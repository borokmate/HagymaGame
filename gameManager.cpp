#include "gameManager.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <limits>


std::string gameManager::playerChar;
std::string gameManager::botChar;
size_t gameManager::rows;
size_t gameManager::cols;

void gameManager::setPlayerChar(int newPlayerChar){
    if (newPlayerChar == 1){
        playerChar = "X";
        botChar = "O";
    }else{
        playerChar = "O";
        botChar = "X"; 
    }
};
void gameManager::setPlayerChar(std::string newPlayerChar){
    playerChar = newPlayerChar;
};
void gameManager::setBotChar(std::string newBotChar){
    botChar = newBotChar;
};
std::string gameManager::getPlayerChar(){
    return playerChar;
};
std::string gameManager::getBotChar(){
    return botChar;
};
void gameManager::askPlayerCoords(size_t& selectedRow, size_t& selectedCol, const std::string& playerChar, std::vector<std::vector<std::string>>& map){
    selectedCol--;
    selectedRow--;
    do{
        std::cout << "Enter the coordinates for " << playerChar << " (row and column, seperate with space, for example: 1 2): ";
        std::cin >> selectedRow >> selectedCol;
        std::cout << std::endl;
        selectedCol--;
        selectedRow--;
        if ((selectedRow > rows || selectedCol > cols) || map[selectedRow][selectedCol] != " "){
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
            std::cerr << "Invalid coordinates. Please try again." << std::endl;
        }
    }while((selectedRow > rows || selectedCol > cols) || map[selectedRow][selectedCol] != " ");
}

void gameManager::setRows(size_t newRows){
    rows = newRows;
};
void gameManager::setCols(size_t newCols){
    cols = newCols;
};
void gameManager::display(std::vector<std::vector<std::string>>& map){
    std::cout << std::string(cols * 4, '-') << "---" << std::endl;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (j == 0) {
                std::cout << " | ";
            }
            std::cout << map[i][j] << " | ";
        }
        std::cout << std::endl;
        std::cout << std::string(cols * 4, '-') << "---" << std::endl;
    }
}

void gameManager::printWinner(std::vector<std::vector<std::string>>& map, const std::string& playerChar, const std::string& botChar, bool& playing){
    int winner = gameManager::checkWin(map, playerChar, botChar);
    if (winner == 1){
        display(map);
        std::cout << "Player " << playerChar << " wins!" << std::endl;
        playing = false;
    }else if (winner == 2){
        display(map);
        std::cout << "Bot " << botChar << " wins!" << std::endl;
        playing = false;
    }else if (winner == 3){
        display(map);
        playing = false;
        std::cout << "It's a draw!" << std::endl;
    }
}

int gameManager::checkWin(std::vector<std::vector<std::string>>& map, const std::string& playerChar, const std::string& botChar){
    // Check rows
    for (size_t i = 0; i < rows; ++i) {
        if (map[i][0] == playerChar && map[i][1] == playerChar && map[i][2] == playerChar) {
            return 1; // Player wins
        } else if (map[i][0] == botChar && map[i][1] == botChar && map[i][2] == botChar) {
            return 2; // Bot wins
        }
    }
    // Check columns
    for (size_t j = 0; j < cols; ++j) {
        if (map[0][j] == playerChar && map[1][j] == playerChar && map[2][j] == playerChar) {
            return 1; // Player wins
        } else if (map[0][j] == botChar && map[1][j] == botChar && map[2][j] == botChar) {
            return 2; // Bot wins
        }
    }
    // Check diagonals
    if ((map[0][0] == playerChar && map[1][1] == playerChar && map[2][2] == playerChar) ||
        (map[0][2] == playerChar && map[1][1] == playerChar && map[2][0] == playerChar)) {
        return 1; // Player wins
    } else if ((map[0][0] == botChar && map[1][1] == botChar && map[2][2] == botChar) ||
               (map[0][2] == botChar && map[1][1] == botChar && map[2][0] == botChar)) {
        return 2; // Bot wins
    }
    
    // Check for draw
    bool draw = true;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (map[i][j] == " ") {
                draw = false;
                break;
            }
        }
    }
    if (draw) {
        return 3; // Draw
    }
    return 0; // No winner yet
}

bool gameManager::askForReplay(){
    char replay;
    do{
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> replay;
        if (replay != 'y' && replay != 'Y' && replay != 'n' && replay != 'N') {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
            std::cerr << "Invalid input. Please enter 'y' or 'n'." << std::endl;
        }
    } while (replay != 'y' && replay != 'Y' && replay != 'n' && replay != 'N');
    return (replay == 'y' || replay == 'Y');
}

void gameManager::decideStartingPlayer(bool& playerStart, bool& firstRound){
    firstRound = true;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1);
    playerStart = dis(gen);
    if (playerStart) {
        std::cout << "Bot starts first." << std::endl;
    } else {
        std::cout << "Player starts first." << std::endl;
    }
}