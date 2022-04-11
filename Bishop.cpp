//
// Created by ozer on 10.04.2022.
//

#include "Bishop.h"
#include "ThreatCalculator.h"
Bishop::Bishop(Color col, PieceType piece_type) : ChessPieceI(col, piece_type) {
  this->pieceValue = 3;
  //this->m_movementList.push_back(std::make_tuple(Direction::upleft, 8));
  //this->m_movementList.push_back(std::make_tuple(Direction::upright, 8));
  //this->m_movementList.push_back(std::make_tuple(Direction::downleft, 8));
  //this->m_movementList.push_back(std::make_tuple(Direction::downright, 8));
}
std::vector<position> Bishop::getThreatList(std::array<std::array<ChessPieceI *, 8>, 8> objMap, const position objPosition) {
  Color col = this->m_Color;
  return ThreatCalculator::CalculateThreat(objMap, objPosition, this->m_movementList, col);
}