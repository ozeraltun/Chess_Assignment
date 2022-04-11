//
// Created by ozer on 10.04.2022.
//

#include "Knight.h"
Knight::Knight(Color col, PieceType piece_type) : ChessPieceI(col, piece_type) {
  this->pieceValue = 3;
  this->m_movementList.push_back(std::make_tuple(Direction::up_up_left, 1));
  this->m_movementList.push_back(std::make_tuple(Direction::up_up_right, 1));
  this->m_movementList.push_back(std::make_tuple(Direction::left_left_up, 1));
  this->m_movementList.push_back(std::make_tuple(Direction::right_right_up, 1));
  this->m_movementList.push_back(std::make_tuple(Direction::left_left_down, 1));
  this->m_movementList.push_back(std::make_tuple(Direction::right_right_down, 1));
  this->m_movementList.push_back(std::make_tuple(Direction::down_down_left, 1));
  this->m_movementList.push_back(std::make_tuple(Direction::down_down_right, 1));

}
std::vector<position> Knight::getThreatList(std::array<std::array<ChessPieceI *, 8>, 8> objMap, const position objPosition) {
  Color col = this->m_Color;
  return ThreatCalculator::CalculateThreatLshape(objMap, objPosition, this->m_movementList, col);
}