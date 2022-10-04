#include "head/player.hpp"

void Player::swapPlayers(){
    if (CurrentPlayer == FirstPlayer) {
        CurrentPlayer = SecondPlayer;
    }
    else if (CurrentPlayer == SecondPlayer) {
        CurrentPlayer = FirstPlayer;
    }
}
