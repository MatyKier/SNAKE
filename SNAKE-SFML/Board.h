#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

enum GameState { RUNNING, FINISHED_LOSS };
enum GameMode { NONE, EASY, NORMAL, HARD };
enum Direction {RIGHT, LEFT, UP, DOWN};

struct Field
{
    bool hasFruit;
    bool isWall;
    bool hasSnake;
};

struct snakePosition
{
    int x;
    int y;
};

class Board
{
public:
    Board(int Height, int Width);
    void debug_display();
    int getHeight() const;
    int getWidth() const;
    int getBoardHeight() const;
    int getBoardWidth() const;
    bool hasSnake(int x, int y) const;
    bool isWall(int x, int y) const;
    bool hasFruit(int x, int y) const;
    bool isCollision(int x, int y) const;
    GameState getGameState() const;
    int getSnakeLength() const;
    void changeDirection(Direction dir);
    void move();
    bool isFruitEaten();
    char getFieldInfo(int x, int y) const;

private:
    Field board[100][100];
    int winHeight;
    int winWidth;
    int height;
    int width;
    GameState state;
    GameMode mode;
    GameMode selectedMode;
    Direction direction;
    std::vector <snakePosition> snakePos;
    void setFruit();
};

#endif // BOARD_H
