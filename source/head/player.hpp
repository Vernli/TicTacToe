#pragma once

struct Player
{
    const char FirstPlayer = 'X';
    const char SecondPlayer = 'O';
    char CurrentPlayer = FirstPlayer;

    void swapPlayers();
};
