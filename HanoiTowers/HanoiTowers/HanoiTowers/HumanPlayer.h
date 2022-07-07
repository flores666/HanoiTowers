#pragma once

#include "Hanoi.h"

class HumanPlayer {
protected:
    int _size;
    int _movesCounter;

public:
    int _gameField[20][3];

    HumanPlayer(int gameField[][3], int size) : _size(size), _movesCounter(0) {

        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < 3; j++) {
                _gameField[i][j] = gameField[i][j];
            }
        }
    }

    virtual void move(char from, char to, char buffer, int quantity) {
        for (int i = 0; i < quantity; i++) {
            if (_gameField[i][from - 97]) {

                int temp = _gameField[i][from - 97];
                _gameField[i][from - 97] = 0;

                for (int j = 0; j < quantity; j++) {
                    bool isEndOfArray = (j == quantity - 1 && _gameField[j][to - 97] == 0);
                    bool elementIsFound = (_gameField[j][to - 97] != 0);

                    if (elementIsFound) {
                        _gameField[j - 1][to - 97] = temp;
                        _movesCounter++;
                        printField();
                        return;
                    }

                    if (isEndOfArray) {
                        _gameField[j][to - 97] = temp;
                        _movesCounter++;
                        printField();
                        return;
                    }
                }

                return;
            }
        }
    }

    void printField() {
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << _gameField[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "Turn " << _movesCounter << "\n---------------\n";
    }

};
