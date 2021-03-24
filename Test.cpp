#include "Board.hpp"
#include "doctest.h"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

TEST_CASE("Empty board") {
ariel:: Board board;
CHECK(board.read(0, 0, Direction::Horizontal,6) == (string)("__"));
CHECK(board.read(0, 0, Direction::Vertical,6) == (string)("__"));
}

TEST_CASE("good space"){
ariel:: Board board;
board.post(0,0, Direction::Horizontal, "  ");
CHECK(board.read(0, 0, Direction::Vertical,1) == (string)(" "));
CHECK(board.read(0, 0, Direction::Horizontal,2) == (string)("  "));
}

TEST_CASE("randon good post & read test"){
ariel:: Board board;
board.post(15,15, Direction::Horizontal, "good day");
CHECK(board.read(15, 15, Direction::Horizontal,1) == (string)("g"));
CHECK(board.read(15, 15, Direction::Vertical,1) == (string)("g"));
CHECK(board.read(15, 15, Direction::Horizontal,4) == (string)("good"));
CHECK(board.read(15, 15, Direction::Vertical,4) == (string)("g___"));

board.post(20,21, Direction::Vertical, "good board");
CHECK(board.read(20, 21, Direction::Vertical,1) == (string)("g"));
CHECK(board.read(20, 21, Direction::Vertical,2) == (string)("go"));
CHECK(board.read(20, 21, Direction::Vertical,3) == (string)("goo"));
CHECK(board.read(20, 21, Direction::Vertical,4) == (string)("good"));

board.post(20,21, Direction::Horizontal, "good board");
CHECK(board.read(20, 21, Direction::Horizontal,6) == (string)("good b"));
CHECK(board.read(20, 21, Direction::Horizontal,7) == (string)("good bo"));
CHECK(board.read(20, 21, Direction::Horizontal,8) == (string)("good boa"));
CHECK(board.read(20, 21, Direction::Horizontal,9) == (string)("good boar"));
CHECK(board.read(20, 21, Direction::Horizontal,10) == (string)("good board"));
}

TEST_CASE("oveloding post"){
ariel:: Board board;
board.post(15,15, Direction::Vertical, "nice day");
CHECK(board.read(15, 15, Direction::Vertical,4) == (string)("nice"));
CHECK(board.read(15, 15, Direction::Horizontal,4) == (string)("nood"));

board.post(22,15, Direction::Horizontal, "bad day");
CHECK(board.read(22, 15, Direction::Vertical,1) == (string)("b"));
CHECK(board.read(22, 15, Direction::Horizontal,1) == (string)("b"));
CHECK(board.read(22, 15, Direction::Vertical,3) == (string)("b__"));
CHECK(board.read(22, 15, Direction::Horizontal,3) == (string)("bad"));
}