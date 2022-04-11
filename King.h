//
// Created by ozer on 10.04.2022.
//

#ifndef CHESS__KING_H_
#define CHESS__KING_H_

#include "ChessPieceI.h"
#include "ThreatCalculator.h"
#include <vector>
class King : public ChessPieceI{
 private:

 public:
  explicit King(Color col=Color::white, PieceType piece_type=PieceType::king);
  std::vector<position> getThreatList(std::array<std::array<ChessPieceI *, 8>, 8> objMap, position objPosition) override;

};

#endif //CHESS__KING_H_
