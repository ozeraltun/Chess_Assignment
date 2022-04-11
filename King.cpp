//
// Created by ozer on 10.04.2022.
//

#include "King.h"
King::King(Color col, PieceType piece_type) : ChessPieceI(col, piece_type) {
  this->pieceValue = 100;
  //this->m_movementList.push_back(std::make_tuple(Direction::up, 1));
  //this->m_movementList.push_back(std::make_tuple(Direction::down, 1));
  //this->m_movementList.push_back(std::make_tuple(Direction::left, 1));
  //this->m_movementList.push_back(std::make_tuple(Direction::right, 1));
  //this->m_movementList.push_back(std::make_tuple(Direction::upright, 1));
  //this->m_movementList.push_back(std::make_tuple(Direction::upleft, 1));
  //this->m_movementList.push_back(std::make_tuple(Direction::downright, 1));
  //this->m_movementList.push_back(std::make_tuple(Direction::downleft, 1));

}
std::vector<position> King::getThreatList(std::array<std::array<ChessPieceI *, 8>, 8> objMap, const position objPosition) {
  Color col = this->m_Color;
  return ThreatCalculator::CalculateThreat(objMap, objPosition, this->m_movementList, col);
}