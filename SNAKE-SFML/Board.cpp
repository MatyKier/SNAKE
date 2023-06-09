#include "Board.h"


Board::Board(int Height, int Width)
{
    winHeight = Height;
    winWidth = Width;
    height = winHeight / 40;
    width = winWidth / 40;
    state = RUNNING;
    direction = RIGHT;
    for (int i = 0; i < height; ++i)
    {
        for (int k = 0; k < width; ++k)
        {
            board[i][k].hasFruit = false;
            board[i][k].hasSnake = false;
            board[i][k].isWall = false;
        }
    }
    for (int j = 0; j < 100; ++j)
    {
        board[j][0].isWall = true;
        board[j][width - 1].isWall = true;
        board[0][j].isWall = true;
        board[height - 1][j].isWall = true;
    }
    snakePosition hP = { width / 2, height / 2 };
    snakePos.push_back(hP);

    snakePosition sP = { width / 2, height / 2 - 1 };
    snakePos.push_back(sP);

    for (int i3 = 0; i3 < snakePos.size(); ++i3)
    {
        board[snakePos[i3].y][snakePos[i3].x].hasSnake = true;
    }
    setFruit();
}

void Board::debug_display()
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cout << getFieldInfo(i, j);
        }
        std::cout << std::endl;
    }
}

int Board::getHeight() const
{
    return winHeight;
}

int Board::getWidth() const
{
    return winWidth;
}

int Board::getBoardHeight() const
{
    return height;
}

int Board::getBoardWidth() const
{
    return width;
}

void Board::setFruit()
{
    int x = 0;
    int y = 0;
    do
    {
        x = rand() % height;
        y = rand() % width;
    } while (board[x][y].hasSnake == true || board[x][y].isWall == true);
    board[x][y].hasFruit = true;
}


bool Board::hasSnake(int x, int y) const
{
    if (board[y][x].hasSnake == true && board[y][x].isWall == false)
        return true;
    else
        return false;
}

bool Board::isWall(int x, int y) const
{
    if (board[y][x].isWall == true)
        return true;
    else
        return false;
}


bool Board::hasFruit(int x, int y) const
{
    if (board[y][x].hasFruit == true)
        return true;
    else
        return false;
}

bool Board::isCollision(int x, int y) const
{
    if (board[y][x].isWall) return true;
    for (int i = 0; i < snakePos.size(); ++i)
    {
        if (snakePos[i].x == x && snakePos[i].y == y)
        {
            return true;
        }
    }
    return false;
}

GameState Board::getGameState() const
{
    return state;
}

int Board::getSnakeLength() const
{
    return snakePos.size() - 2;
}

void Board::changeDirection(Direction dir)
{
    if (dir == RIGHT && direction != LEFT)
    {
        direction = RIGHT;
    }
    if (dir == LEFT && direction != RIGHT)
    {
        direction = LEFT;
    }
    if (dir == UP && direction != DOWN)
    {
        direction = UP;
    }
    if (dir == DOWN && direction != UP)
    {
        direction = DOWN;
    }
}

void Board::move()
{
    snakePosition newPos;
    if (direction == RIGHT)
    {
        newPos.x = snakePos[0].x + 1;
        newPos.y = snakePos[0].y;
    }
    if (direction == LEFT)
    {
        newPos.x = snakePos[0].x - 1;
        newPos.y = snakePos[0].y;
    }
    if (direction == UP)
    {
        newPos.x = snakePos[0].x;
        newPos.y = snakePos[0].y - 1;
    }
    if (direction == DOWN)
    {
        newPos.x = snakePos[0].x;
        newPos.y = snakePos[0].y + 1;
    }

    if (isCollision(newPos.x, newPos.y) == false)
    {
        if (isFruitEaten())
        {
            board[newPos.y][newPos.x].hasSnake = true;
            snakePos.insert(snakePos.begin(), newPos);

            setFruit();
        }
        else
        {
            board[newPos.y][newPos.x].hasSnake = true;
            snakePos.insert(snakePos.begin(), newPos);
            board[snakePos[snakePos.size() - 1].y][snakePos[snakePos.size() - 1].x].hasSnake = false;
            snakePos.pop_back();
        }
    }
    else state = FINISHED_LOSS;
}

bool Board::isFruitEaten()
{
    for (int i = 0; i < snakePos.size(); ++i)
    {
        if (board[snakePos[0].y][snakePos[0].x].hasFruit == true)
        {
            board[snakePos[0].y][snakePos[0].x].hasFruit = false;
            return true;
        }
    }
    return false;
}


char Board::getFieldInfo(int x, int y) const
{
    if (board[y][x].hasFruit == true)
        return 'F';
    if (board[y][x].hasSnake == true)
        return 'S';
    if (board[y][x].isWall == true)
        return 'W';
    else return '_';
}
