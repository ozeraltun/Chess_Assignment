//
// Created by ozer on 10.04.2022.
//

#ifndef CHESS__KNIGHT_H_
#define CHESS__KNIGHT_H_
#include "ChessPieceI.h"
#include "ThreatCalculator.h"
#include <vector>
class Knight :public ChessPieceI{
 private:

 public:
  explicit Knight(Color col=Color::white, PieceType piece_type=PieceType::knight);
  std::vector<position> getThreatList(std::array<std::array<ChessPieceI *, 8>, 8> objMap, position objPosition) override;

};

#endif //CHESS__KNIGHT_H_
