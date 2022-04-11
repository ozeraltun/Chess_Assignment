//
// Created by ozer on 7.04.2022.
//

#ifndef CHESS__PAWN_H_
#define CHESS__PAWN_H_

#include "ChessPieceI.h"
#include "Enums.h"
#include "ThreatCalculator.h"
class Pawn : public ChessPieceI{
 private:

 public:
  explicit Pawn(Color col=Color::white, PieceType piece_type=PieceType::pawn);
  std::vector<position> getThreatList(std::array<std::array<ChessPieceI *, 8>, 8> objMap, position objPosition) override;
};

#endif //CHESS__PAWN_H_
