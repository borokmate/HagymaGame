#include "plot.h"

Plot::Plot(size_t newRow, size_t newCols){
    cols = newRow;
    rows = newCols;
    setDisplay();
}

void Plot::setDisplay(){
    map.resize(rows, std::vector<std::string>(cols, " "));
}

void Plot::setRow(size_t newRow){
    rows = newRow;
}
void Plot::setCol(size_t newCol){
    cols = newCol;
}
size_t Plot::getRow() const{
    return rows;
}
size_t Plot::getCol() const{
    return cols;
}

void Plot::display() const{
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
void Plot::reset(){
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            map[i][j] = " ";
        }
    }
}
void Plot::setCell(size_t selectedRow, size_t selectedCol, const std::string& value){
    if (selectedRow < rows && selectedCol < cols) {
        map[selectedRow][selectedCol] = value;
    } else {
        std::cerr << "Error: Invalid cell coordinates." << std::endl;
    }
}
std::string Plot::getCell(size_t selectedRow, size_t selectedCol) const{
    if (selectedRow < rows && selectedCol < cols) {
        return map[selectedRow][selectedCol];
    } else {
        std::cerr << "Error: Invalid cell coordinates." << std::endl;
        return " ";
    }
}

int Plot::getFreeSpaces() const{
    int freeSpaces = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (map[i][j] == " ") {
                freeSpaces++;
            }
        }
    }
    return freeSpaces;
}

std::vector<size_t> Plot::getFreeSpacesVector() const{
    std::vector<size_t> freeSpacesVector;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (map[i][j] == " ") {
                freeSpacesVector.push_back(i * cols + j); // Store the index as a single integer
            }
        }
    }
    return freeSpacesVector;
}

std::vector<std::vector<std::string>>& Plot::getMap() {
    return map;
}