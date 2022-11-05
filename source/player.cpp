#include "headers/player.hpp"

void Player::swapPlayers() {
    FirstPlayer = SecondPlayer;
    SecondPlayer = CurrentPlayer;
    CurrentPlayer = FirstPlayer;
}