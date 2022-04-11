//
// Created by ozer on 6.04.2022.
//

#ifndef CHESS__ENUMS_H_
#define CHESS__ENUMS_H_
#include <tuple>
enum class Color{black, white};
enum class PieceType{rook, knight, bishop, queen, king, pawn};
enum class Direction{up, down, left, right, upleft, upright, downleft, downright,
                     up_up_left, up_up_right, left_left_up, right_right_up, left_left_down,
                     right_right_down, down_down_left, down_down_right};
typedef std::tuple<Direction, int> movement;
typedef float point_t;
typedef std::tuple<int, int> position;
typedef int positionX_t;
typedef int positionY_t;

#endif //CHESS__ENUMS_H_
