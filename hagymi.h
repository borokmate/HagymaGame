#ifndef HAGYMI_H
#define HAGYMI_H
#include <string>
#include <vector>

class hagymi
{
    public:
        hagymi(std::string& newHagymiChar, size_t newCols);
        size_t decidePlace(std::vector<std::vector<std::string>>& map);
    private:
        std::string hagymiChar;
        size_t cols;
        size_t rows;
};

#endif // HAGYMI_H