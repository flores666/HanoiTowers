#include <iostream>
#include "Hanoi.h"
#include "Bot.h"
#include "HumanPlayer.h"

using namespace std;

int main() {
    char startPillar = 'a',
        destinationPillar = 'c',
        bufferPillar = 'b';

    int numberOfRings = 3;

    Hanoi game(startPillar, destinationPillar, bufferPillar, numberOfRings);

    int choice;
    cout << "Who is playing?\n(1 - Bot, 2 - Human):\n";

    cin >> choice;
    cout << endl;

    switch (choice) {
    case 1: {
        Bot bot(game.gameField, numberOfRings);

        cout << "Bot is playing:\n\n";

        game.start(bot);
        break;
    }
    case 2: {
        HumanPlayer human(game.gameField, numberOfRings);

        cout << "Human is playing:\n";

        game.start(human);
        break;
    }
    default:
        break;
    }

}