//
// Created by ozer on 7.04.2022.
//

#include "Pawn.h"
Pawn::Pawn(Color col, PieceType piece_type) : ChessPieceI(col, piece_type) {
  this->pieceValue = 1;
  if(col==Color::white){
    this->m_movementList.push_back(std::make_tuple(Direction::upleft, 1));
    this->m_movementList.push_back(std::make_tuple(Direction::upright, 1));
  }else if(col == Color::black){
    this->m_movementList.push_back(std::make_tuple(Direction::downleft, 1));
    this->m_movementList.push_back(std::make_tuple(Direction::downright, 1));
  }
}
std::vector<position> Pawn::getThreatList(std::array<std::array<ChessPieceI *, 8>, 8> objMap, const position objPosition) {
  Color col = this->m_Color;
  return ThreatCalculator::CalculateThreat(objMap, objPosition, this->m_movementList, col);
}
