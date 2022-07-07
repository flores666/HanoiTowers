#pragma once

#include <iostream>
#include "HumanPlayer.h"

class Bot : public HumanPlayer {
public:
    Bot(int gameField[][3], int size) : HumanPlayer(gameField, size) {

    }

    void move(char startPillar, char destinationPillar, char bufferPillar, int quantity) {

        if (quantity > 0) {
            move(startPillar, bufferPillar, destinationPillar, quantity - 1);

            replaceRings(startPillar - 97, destinationPillar - 97);
            _movesCounter++;
            printField();

            move(bufferPillar, destinationPillar, startPillar, quantity - 1);
        }
    }

private:
    void replaceRings(int from, int to) {
        for (int i = 0; i < _size; i++) {
            if (_gameField[i][from]) {

                int temp = _gameField[i][from];
                _gameField[i][from] = 0;

                for (int j = 0; j < _size; j++) {
                    bool isEndOfArray = (j == _size - 1 && _gameField[j][to] == 0);
                    bool elementIsFound = (_gameField[j][to] != 0);

                    if (elementIsFound) {
                        _gameField[j - 1][to] = temp;
                        return;
                    }

                    if (isEndOfArray) {
                        _gameField[j][to] = temp;
                        return;
                    }
                }

                return;
            }
        }
    }
};
