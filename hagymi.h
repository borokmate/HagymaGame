#ifndef HAGYMI_H
#define HAGYMI_H
#include <string>
#include <vector>

class hagymi
{
    public:
        hagymi(std::string& newHagymiChar, size_t newCols);
        size_t decidePlace(std::vector<std::vector<std::string>>& map, std::vector<size_t> freeSpaces);
        int checkForCharactersInARow(std::vector<std::vector<std::string>>& map, size_t row);
        int checkForCharactersInACol(std::vector<std::vector<std::string>>& map, size_t col);
        int checkForCharactersInTheDiagonal(std::vector<std::vector<std::string>>& map, size_t row, size_t col);
        int checkForCharactersInTheAntiDiagonal(std::vector<std::vector<std::string>>& map, size_t row, size_t col);

        int checkForOpponentCharactersInARow(std::vector<std::vector<std::string>>& map, size_t row);
        int checkForOpponentCharactersInACol(std::vector<std::vector<std::string>>& map, size_t col);
        int checkForOpponentCharactersInTheDiagonal(std::vector<std::vector<std::string>>& map, size_t row, size_t col);
        int checkForOpponentCharactersInTheAntiDiagonal(std::vector<std::vector<std::string>>& map, size_t row, size_t col);

    private:
        std::string hagymiChar;
        size_t cols;
        size_t rows;
};

#endif // HAGYMI_H