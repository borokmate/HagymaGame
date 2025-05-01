#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <string>
#include <vector>

class gameManager
{
    public:
        static void setPlayerChar(int newPlayerChar);
        static void setPlayerChar(std::string newPlayerChar);
        static void setBotChar(std::string newBotChar);
        static void setRows(size_t newRows);
        static void setCols(size_t newCols);
        static std::string getPlayerChar();
        static std::string getBotChar();
        static void askPlayerCoords(size_t& selectedRow, size_t& selectedCol, const std::string& playerChar, std::vector<std::vector<std::string>>& map);
        static void printWinner(std::vector<std::vector<std::string>>& map, const std::string& playerChar, const std::string& botChar, bool& playing);
        static int checkWin(std::vector<std::vector<std::string>>& map, const std::string& playerChar, const std::string& botChar);
        static void display(std::vector<std::vector<std::string>>& map);
        static bool askForReplay();
    private:
        static std::string playerChar;
        static std::string botChar;
        static size_t rows;
        static size_t cols;
};

#endif // GAMEMANAGER_H