/**
 * Design snake game
 * Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

Example:
Given width = 3, height = 2, and food = [[1,2],[0,1]].

Snake snake = new Snake(width, height, food);

Initially the snake appears at position (0,0) and the food at (1,2).

|S| | |
| | |F|

snake.move("R"); -> Returns 0

| |S| |
| | |F|

snake.move("D"); -> Returns 0

| | | |
| |S|F|

snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

| |F| |
| |S|S|

snake.move("U"); -> Returns 1

| |F|S|
| | |S|

snake.move("L"); -> Returns 2 (Snake eats the second food)

| |S|S|
| | |S|

snake.move("U"); -> Returns -1 (Game over because snake collides with border)

solution: 使用unordered_map<int, unordered_set<int>> 来记录snake所占的格子。使用list来记录snake从
头到尾所占的格子。
首先判断snake是否越界
其次如果下一个格子是食物，则直接更新蛇长和hashmap；否则将蛇尾去掉，然后判断下一个格子是否为空，如果为空，更新snake
身体和hashmap，否则返回-1.

time complexity： O(1)
space complexity: O(m*n)
 */

#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

namespace design_snake_game {
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int> > food) {
        this->food = food;
        graph[0].insert(0);
        snake.push_back(make_pair(0,0));
        index = 0;
        m = height;
        n = width;
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int newx = snake.front().first, newy = snake.front().second;
        if (direction == "U")
            newx--;
        else if (direction == "L")
            newy--;
        else if (direction == "R")
            newy++;
        else
            newx++;
        if (newx < 0 || newx == m || newy < 0 || newy == n)
            return -1;
        if (index < food.size() && newx == food[index].first && newy == food[index].second) {
            graph[newx].insert(newy);
            snake.push_front(make_pair(newx, newy));
            index++;
        } else {
            graph[snake.back().first].erase(snake.back().second);
            snake.pop_back();
            if (graph.find(newx) == graph.end() || graph[newx].find(newy) == graph[newx].end()) {
                graph[newx].insert(newy);
                snake.push_front(make_pair(newx, newy));
            } else
                return -1;
        }
        return snake.size() - 1;
    }
private:
    unordered_map<int, unordered_set<int> > graph;
    vector<pair<int,int> > food;
    int index;
    list<pair<int,int> > snake;
    int m, n;
};
}

int main_design_snake_game() {
  vector<pair<int,int> > food;
  food.push_back(make_pair(2,0));
  food.push_back(make_pair(0,0));
  food.push_back(make_pair(0,2));
  food.push_back(make_pair(2,2));
  design_snake_game::SnakeGame game(3,3, food);
  game.move("D");
  game.move("D");
  game.move("R");
  game.move("U");
  game.move("U");
  game.move("L");
  game.move("D");
  game.move("R");
  game.move("R");
  game.move("U");
  game.move("L");
  game.move("D");
}
