//
// Created by ozer on 10.04.2022.
//

#include "Rook.h"
#include "ThreatCalculator.h"
Rook::Rook(Color col, PieceType piece_type) : ChessPieceI(col, piece_type) {
  this->pieceValue = 5;
  this->m_movementList.push_back(std::make_tuple(Direction::up, 8));
  this->m_movementList.push_back(std::make_tuple(Direction::down, 8));
  this->m_movementList.push_back(std::make_tuple(Direction::left, 8));
  this->m_movementList.push_back(std::make_tuple(Direction::right, 8));
}
std::vector<position> Rook::getThreatList(std::array<std::array<ChessPieceI *, 8>, 8> objMap, const position objPosition) {
  Color col = this->m_Color;
  return ThreatCalculator::CalculateThreat(objMap, objPosition, this->m_movementList, col);
}