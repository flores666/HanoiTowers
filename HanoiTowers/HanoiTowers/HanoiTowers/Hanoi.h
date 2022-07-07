#pragma once

#include <iostream>
#include "HumanPlayer.h"
#include "Bot.h"

class Hanoi {
private:
    const char _startPillar,
            _destinationPillar,
            _bufferPillar;

    const int _ringsNumber;
    const int _pillarsCount;
    int _movesNumber;

public:
    int gameField[20][3];

    Hanoi(char startPillar, char destPillar, char buffPillar, int ringsNum) :
            _startPillar(startPillar), _destinationPillar(destPillar), _bufferPillar(buffPillar), _ringsNumber(ringsNum), _pillarsCount(3) {
        _movesNumber = 0;
        nullArray();
        fillPillar();
    }

    void fillPillar() {
        for (int i = 0; i < _ringsNumber; i++) {
            gameField[i][_startPillar - 97] = i + 1;
        }
    }

    void printField() {
        for (int i = 0; i < _ringsNumber; i++) {
            for (int j = 0; j < _pillarsCount; j++) {
                std::cout << gameField[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "Turn " << _movesNumber << "\n---------------\n";
    }

    void nullArray() {
        for (int i = 0; i < _ringsNumber; i++) {
            for (int j = 0; j < _pillarsCount; j++) {
                gameField[i][j] = 0;
            }
        }
    }

    void start(Bot bot) {
        nullArray();
        fillPillar();
        printField();

        int quantity = _ringsNumber;

        bot.move(_startPillar, _destinationPillar, _bufferPillar, quantity);

        printWinMessage();
    }

    void start(HumanPlayer human) {
        nullArray();
        fillPillar();
        printField();

        char from, to;

        while (gameContinues(human)) {
            do {
                std::cout << "Choose start pillar and destination pillar (a - c):\n";
                std::cin >> from >> to;
                std::cout << std::endl;
            } while (!isRightChoice(from, to, human));

            human.move(from, to, _bufferPillar, _ringsNumber);
        }

        printWinMessage();
    }

    bool isRightChoice(char from, char to, HumanPlayer human) {
        if (from == to) {
            return false;
        }

        if ((from != 'a' && from != 'b' && from != 'c') ||
                ((to != 'a' && to != 'b' && to != 'c'))) {
            return false;
        }

        if (human._gameField[_ringsNumber - 1][from - 97] == 0 || human._gameField[0][to - 97] != 0) { // if circles on start pillar are exists and enough space in destination pillar
            return false;
        }

        for (int i = 0; i < _ringsNumber; i++) {
            for (int j = 0; j < _ringsNumber; j++) {
                if ((human._gameField[i][from - 97] > human._gameField[j][to - 97]) &&
                        (human._gameField[i][from - 97] != 0 && human._gameField[j][to - 97] != 0)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool gameContinues(HumanPlayer human) {
        if (human._gameField[0][_destinationPillar - 97] != 0) {
            return false;
        }
        return true;
    }

    void printWinMessage() {
        std::cout << "You are won!\n";
    }
};
