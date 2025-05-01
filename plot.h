#ifndef PLOT
#define PLOT
#include <iostream>
#include <vector>
#include <string>

class Plot {
    public:
        Plot(size_t newRows, size_t newCols);
        void setRow(size_t newRow);
        void setCol(size_t newCol);
        size_t getRow() const;
        size_t getCol() const;
        std::vector<std::vector<std::string>>& getMap();
        void display() const;
        void setDisplay();
        void reset();
        bool setCell(size_t selectedRow, size_t selectedCol, const std::string& value);
        std::string getCell(size_t selectedRow, size_t selectedCol) const;
        int getFreeSpaces() const;
        std::vector<size_t> getFreeSpacesVector() const;
    private:
        std::vector<std::vector<std::string>> map;
        size_t rows;
        size_t cols;
};

#endif // PLOT