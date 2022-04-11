//
// Created by ozer on 6.04.2022.
//

#ifndef CHESS__CHESSPIECEI_H_
#define CHESS__CHESSPIECEI_H_

#include <tuple>
#include <vector>
#include "Enums.h"

class ChessPieceI {
 protected:
  Color m_Color;
  PieceType m_Piece_t;
  bool isThreated;
  std::vector<movement> m_movementList;
  int pieceValue;
 public:
  explicit ChessPieceI(Color color=Color::white, PieceType piece_type=PieceType::pawn, bool isThreated = false, std::vector<movement> movementList = {});
  Color getColor() const;
  PieceType getPieceType() const;
  virtual std::vector<position> getThreatList(std::array<std::array<ChessPieceI*, 8> ,8> objMap, position objPosition)=0;
  void applyThreat();
  bool getThreated() const;
  int getPieceValue() const;
  void resetThreat();
};

#endif //CHESS__CHESSPIECEI_H_
