#include "hagymi.h"
#include <random>
#include <iostream>

hagymi::hagymi(std::string& newHagymiChar, size_t newCols){
    hagymiChar = newHagymiChar;
    cols = newCols;
    rows = newCols;
}

size_t hagymi::decidePlace(std::vector<std::vector<std::string>>& map){
    // std::random_device rd;
    // std::uniform_int_distribution<int> randomPlace(0, freeSpaces - 1);

    // int randomIndex = randomPlace(rd);
    // size_t selectedPlace = freeSpacesVector[(size_t)randomIndex];

    // return selectedPlace;

    int hagymaCharInt = -((int)cols * (int)cols);
    int plrChar = -((int)cols * (int)cols) - 1;

    std::vector<std::vector<int>> decideMap;
    decideMap.resize(cols, std::vector<int>(cols, 0));
    for (size_t i = 0; i < map.size(); i++){
        for (size_t j = 0; j < map[0].size(); j++){
            if (map[i][j] == hagymiChar){
                decideMap[i][j] = hagymaCharInt;
            }else if (map[i][j] != " "){
               decideMap[i][j] = plrChar;
            }
        }
    }

    size_t mapSize = map.size();
    int num;
    int largestNum;
    size_t largestCoord;
    for (size_t i = 0; i < mapSize; i++){
        num = 0;
        for (size_t left = 0; left < rows; left++){
            if (decideMap[i][left] == hagymaCharInt){
                num++;
            }else if (decideMap[i][left] == plrChar){
                num--;
            }else{
                decideMap[i][left] += num;

                if (decideMap[i][left] > largestNum){
                    largestNum = decideMap[i][left];
                    largestCoord = i * rows + left;
                }
            }
        }
        num = 0;
        for (size_t right = rows; right-- > 0;){
            if (decideMap[i][right] == hagymaCharInt){
                num++;
            }else if (decideMap[i][right] == plrChar){
                num--;
            }else{
                decideMap[i][right] += num;
            }

            if (decideMap[i][right] > largestNum){
                largestNum = decideMap[i][right];
                largestCoord = i * rows + right;
            }
        }
    }
    for (size_t i = 0; i < mapSize; i++){
        num = 0;
        for (size_t up = 0; up < cols; up++){
            if (decideMap[up][i] == hagymaCharInt){
                num++;
            }else if (decideMap[up][i] == plrChar){
                num--;
            }else{
                decideMap[up][i] += num;

                if (decideMap[up][i] > largestNum){
                    largestNum = decideMap[up][i];
                    largestCoord = up * rows + i;
                }
            }
        }
        num = 0;
        for (size_t down = rows; down-- > 0;){
            if (decideMap[down][i] == hagymaCharInt){
                num++;
            }else if (decideMap[down][i] == plrChar){
                num--;
            }else{
                decideMap[down][i] += num;
            }

            if (decideMap[down][i] > largestNum){
                largestNum = decideMap[down][i];
                largestCoord = down * rows + i;
            }
        }
    }
     for (size_t i = 0; i < mapSize; i++) {
            num = 0;
            for (size_t diag1 = 0; diag1 < cols && diag1 < rows; diag1++) {
                size_t x = diag1;
                size_t y = (i + diag1) % cols;

                if (decideMap[x][y] == hagymaCharInt) {
                    num++;
                } else if (decideMap[x][y] == plrChar) {
                    num--;
                } else {
                    decideMap[x][y] += num;

                    if (decideMap[x][y] > largestNum) {
                        largestNum = decideMap[x][y];
                        largestCoord = x * rows + y;
                    }
                }
            }
            num = 0;
            for (size_t diag2 = cols; diag2-- > 0;) {
                size_t x = diag2;
                size_t y = (i + diag2) % cols;

                if (decideMap[x][y] == hagymaCharInt) {
                    num++;
                } else if (decideMap[x][y] == plrChar) {
                    num--;
                } else {
                    decideMap[x][y] += num;

                    if (decideMap[x][y] > largestNum) {
                        largestNum = decideMap[x][y];
                        largestCoord = x * rows + y;
                    }
                }
            }
        }



    std::cout << std::string(cols * 4, '-') << "---" << std::endl;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (j == 0) {
                std::cout << " | ";
            }
            std::cout << decideMap[i][j] << " | ";
        }
        std::cout << std::endl;
        std::cout << std::string(cols * 4, '-') << "---" << std::endl;
    }

    return 1;
}