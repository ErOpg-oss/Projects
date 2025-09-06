#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
vector<pair<int, int>> snake;
int tailX, tailY;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    snake.push_back({x, y});
    srand(time(0));
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw() {
    clear();
    for (int i = 0; i < width + 2; i++)
        mvprintw(0, i, "#");
    for (int i = 0; i < height + 2; i++) {
        for (int j = 0; j < width + 2; j++) {
            if (j == 0 || j == width + 1)
                mvprintw(i, j, "#");
        }
    }
    for (int i = 0; i < width + 2; i++)
        mvprintw(height + 1, i, "#");

    mvprintw(fruitY, fruitX, "F");
    for (auto &part : snake)
        mvprintw(part.second, part.first, "O");

    mvprintw(height + 3, 0, "Score: %d", score);
    refresh();
}

void Input() {
    int key = getch();
    switch (key) {
        case KEY_LEFT:
            if (dir != RIGHT)
                dir = LEFT;
            break;
        case KEY_RIGHT:
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case KEY_UP:
            if (dir != DOWN)
                dir = UP;
            break;
        case KEY_DOWN:
            if (dir != UP)
                dir = DOWN;
            break;
        case 'q':
            gameOver = true;
            break;
    }
}

void Logic() {
    tailX = snake.back().first;
    tailY = snake.back().second;
    snake.pop_back();

    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
    }

    snake.insert(snake.begin(), {x, y});

    if (x >= width || x < 0 || y >= height || y < 0)
        gameOver = true;

    for (int i = 1; i < snake.size(); i++)
        if (snake[i].first == x && snake[i].second == y)
            gameOver = true;

    if (x == fruitX && y == fruitY) {
        score += 10;
        snake.push_back({tailX, tailY});
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        usleep(100000);
    }
    endwin();
    return 0;
}

