#include "hagymi.h"
#include <random>
#include <iostream>

hagymi::hagymi(std::string& newHagymiChar, size_t newCols){
    hagymiChar = newHagymiChar;
    cols = newCols;
    rows = newCols;
}

size_t hagymi::decidePlace(std::vector<std::vector<std::string>>& map, std::vector<size_t> freeSpaces){

    int largestChars = 0;
    size_t selectedPlace = 0;
    int charsAround = 0;

    for (size_t i = 0; i < freeSpaces.size(); ++i){
        size_t selectedRow = freeSpaces[i] / cols;
        size_t selectedCol = freeSpaces[i] % cols;
        
        if (checkForCharactersInARow(map, selectedRow) == 2 || checkForCharactersInACol(map, selectedCol) == 2  || checkForCharactersInTheDiagonal(map) == 2 || checkForCharactersInTheAntiDiagonal(map) == 2){
            return freeSpaces[i];
        }
    }

    // Check for opponent's characters in rows, columns, and diagonals
    for (size_t i = 0; i < freeSpaces.size(); ++i){
        size_t selectedRow = freeSpaces[i] / cols;
        size_t selectedCol = freeSpaces[i] % cols;
        
        if (checkForOpponentCharactersInARow(map, selectedRow) == 2 || checkForOpponentCharactersInACol(map, selectedCol) == 2  || checkForOpponentCharactersInTheDiagonal(map) == 2 || checkForOpponentCharactersInTheAntiDiagonal(map) == 2){
            return freeSpaces[i];
        }
    }
    // Check for hagymi's characters in rows, columns, and diagonals

    for (size_t i = 0; i < freeSpaces.size(); ++i){
        size_t selectedRow = freeSpaces[i] / cols;
        size_t selectedCol = freeSpaces[i] % cols;

        charsAround = checkForCharactersInARow(map, selectedRow) + checkForCharactersInACol(map, selectedCol) + checkForCharactersInTheDiagonal(map) + checkForCharactersInTheAntiDiagonal(map);
        if (charsAround > largestChars){
            largestChars = charsAround;
            selectedPlace = freeSpaces[i];
        }
    }

    // If no winning move is found, select a random free space
    if (largestChars == 0){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<size_t> dis(0, freeSpaces.size() - 1);
        selectedPlace = freeSpaces[dis(gen)];
    }
    // If no free spaces are available, return 0
    return selectedPlace;
}

int hagymi::checkForCharactersInARow(std::vector<std::vector<std::string>>& map, size_t row){
    
    int count = 0;
    for (size_t i = 0; i < cols; ++i) {
        if (map[row][i] == hagymiChar) {
            ++count;
        }
        else if (map[row][i] != " ") {
            count = 0; // Reset count if we encounter a non-hagymiChar character
            break; // Stop checking if we encounter a non-hagymiChar character
        }
    }
    return count;
}

int hagymi::checkForCharactersInACol(std::vector<std::vector<std::string>>& map, size_t col){
    
    int count = 0;
    for (size_t i = 0; i < rows; ++i) {
        if (map[i][col] == hagymiChar) {
            ++count;
        }
        else if (map[i][col] != " ") {
            count = 0; // Reset count if we encounter a non-hagymiChar character
            break; // Stop checking if we encounter a non-hagymiChar character
        }
    }
    return count;
}

int hagymi::checkForCharactersInTheDiagonal(std::vector<std::vector<std::string>>& map){
    
    int count = 0;
    // Check the main diagonal
    for (size_t i = 0; i < rows; ++i) {
        if (map[i][i] == hagymiChar) {
            ++count;
        }
        else if (map[i][rows - 1 - i] != " ") {
            count = 0; // Reset count if we encounter a non-hagymiChar character
            break; // Stop checking if we encounter a non-hagymiChar character
        }
    }
    return count;
}

int hagymi::checkForCharactersInTheAntiDiagonal(std::vector<std::vector<std::string>>& map){
    
    int count = 0;
    // Check the anti-diagonal
    for (size_t i = 0; i < rows; ++i) {
        if (map[i][rows - 1 - i] == hagymiChar) {
            ++count;
        }
        else if (map[i][i] != " ") {
            count = 0; // Reset count if we encounter a non-hagymiChar character
            break; // Stop checking if we encounter a non-hagymiChar character
        }
    }
    return count;
}

int hagymi::checkForOpponentCharactersInARow(std::vector<std::vector<std::string>>& map, size_t row){
    
    int count = 0;
    for (size_t i = 0; i < cols; ++i) {
        if (map[row][i] != hagymiChar && map[row][i] != " ") {
            ++count;
        }
    }
    return count;
}

int hagymi::checkForOpponentCharactersInACol(std::vector<std::vector<std::string>>& map, size_t col){
    
    int count = 0;
    for (size_t i = 0; i < rows; ++i) {
        if (map[i][col] != hagymiChar && map[i][col] != " ") {
            ++count;
        }
    }
    return count;
}

int hagymi::checkForOpponentCharactersInTheDiagonal(std::vector<std::vector<std::string>>& map){
    
    int count = 0;
    // Check the main diagonal
    for (size_t i = 0; i < rows; ++i) {
        if (map[i][i] != hagymiChar && map[i][i] != " ") {
            ++count;
        }
    }
    std::cout << "Count in diagonal: " << count << std::endl;
    return count;
}

int hagymi::checkForOpponentCharactersInTheAntiDiagonal(std::vector<std::vector<std::string>>& map){
    
    int count = 0;
    // Check the anti-diagonal
    for (size_t i = 0; i < rows; ++i) {
        if (map[i][rows - 1 - i] != hagymiChar && map[i][rows - 1 - i] != " ") {
            ++count;
        }
    }
    return count;
}
