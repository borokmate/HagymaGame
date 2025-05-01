#include "plot.h"
#include "hagymi.h"
#include "gameManager.h"

int main(){
    Plot plot(3, 3);
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
    std::string botChar = gameManager::getBotChar();
    hagymi bot(botChar, 3);
    plot.display();

    plot.setCell(1, 1, botChar);
    plot.setCell(1, 0, botChar);

    bot.decidePlace(plot.getMap());

    // while (playing){
        
    //     size_t selectedRow, selectedCol;
    //     gameManager::askPlayerCoords(selectedRow, selectedCol, gameManager::getPlayerChar(), plot.getMap());

    //     if (plot.setCell(selectedRow, selectedCol, gameManager::getPlayerChar()) == false){
    //         continue;
    //     }

    //     gameManager::printWinner(plot.getMap(), gameManager::getPlayerChar(), gameManager::getBotChar(), playing);

    //     if (!playing){
    //         break;
    //     }

    //     int freeSpaces = plot.getFreeSpaces();
    //     std::vector<size_t> freeSpacesVector = plot.getFreeSpacesVector();

    //     size_t selectedPlace = bot.decidePlace(freeSpaces, freeSpacesVector);

    //     plot.setCell((size_t)selectedPlace / plot.getCol(), (size_t)selectedPlace % plot.getRow(), gameManager::getBotChar());
    //     plot.display();

    //     gameManager::printWinner(plot.getMap(), gameManager::getPlayerChar(), gameManager::getBotChar(), playing);
    // }

    return 0;
    
    
}