#include "gameManager.h"
#include <iostream>
#include <vector>
#include <string>

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
    do{
        std::cout << "Enter the coordinates for " << playerChar << " (row and column): ";
        std::cin >> selectedRow >> selectedCol;
        std::cout << std::endl;
        if ((selectedRow > rows || selectedCol > cols) || map[selectedRow][selectedCol] != " "){
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
    return 0; // No winner yet
}