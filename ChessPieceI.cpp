//
// Created by ozer on 6.04.2022.
//

#include "ChessPieceI.h"
ChessPieceI::ChessPieceI(Color color, PieceType piece_type, bool isThreated, std::vector<movement> movementList) : m_Color(color), m_Piece_t(piece_type), isThreated(isThreated), m_movementList(movementList){

}
Color ChessPieceI::getColor() const {
  return m_Color;
}
PieceType ChessPieceI::getPieceType() const {
  return m_Piece_t;
}
void ChessPieceI::applyThreat() {
  this->isThreated = true;
}
bool ChessPieceI::getThreated() const {
  return this->isThreated;
}
int ChessPieceI::getPieceValue() const{
  return this->pieceValue;
}
void ChessPieceI::resetThreat(){
  this->isThreated = false;
}