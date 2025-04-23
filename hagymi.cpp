#include "hagymi.h"
#include <random>

size_t hagymi::decidePlace(int freeSpaces, std::vector<size_t>& freeSpacesVector){
    std::random_device rd;
    std::uniform_int_distribution<int> randomPlace(0, freeSpaces - 1);

    int randomIndex = randomPlace(rd);
    size_t selectedPlace = freeSpacesVector[(size_t)randomIndex];

    return selectedPlace;
};