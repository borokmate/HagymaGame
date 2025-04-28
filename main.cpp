#include "plot.h"
#include "hagymi.h"
#include "gameManager.h"

int main(){
    Plot plot(3, 3);
    hagymi bot;
    gameManager::setCols(3);
    gameManager::setRows(3);
    bool playing = true;

    short playerChoise; // 1 for X, 2 for O
    do{
        std::cout << "Choose your character (1 for X, 2 for O): ";
        std::cin >> playerChoise;
        if (playerChoise != 1 && playerChoise != 2) {
            std::cerr << "Invalid choice. Please try again." << std::endl;
        }
    } while (playerChoise != 1 && playerChoise != 2);

    std::cout << std::endl;

    gameManager::setPlayerChar(playerChoise);
    plot.display();

    while (playing){

        size_t selectedRow, selectedCol;
        gameManager::askPlayerCoords(selectedRow, selectedCol, gameManager::getPlayerChar(), plot.getMap());

        plot.setCell(selectedRow, selectedCol, gameManager::getPlayerChar());

        gameManager::printWinner(plot.getMap(), gameManager::getPlayerChar(), gameManager::getBotChar(), playing);

        if (!playing){
            break;
        }

        int freeSpaces = plot.getFreeSpaces();
        std::vector<size_t> freeSpacesVector = plot.getFreeSpacesVector();

        size_t selectedPlace = bot.decidePlace(freeSpaces, freeSpacesVector);

        plot.setCell((size_t)selectedPlace / plot.getCol(), (size_t)selectedPlace % plot.getRow(), gameManager::getBotChar());
        plot.display();

        gameManager::printWinner(plot.getMap(), gameManager::getPlayerChar(), gameManager::getBotChar(), playing);
    }

    return 0;
    
    
}