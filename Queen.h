//
// Created by ozer on 10.04.2022.
//

#ifndef CHESS__QUEEN_H_
#define CHESS__QUEEN_H_

#include "ChessPieceI.h"
#include "ThreatCalculator.h"
#include <vector>
class Queen : public ChessPieceI{
 private:

 public:
  explicit Queen(Color col=Color::white, PieceType piece_type=PieceType::queen);
  std::vector<position> getThreatList(std::array<std::array<ChessPieceI *, 8>, 8> objMap, position objPosition) override;

};

#endif //CHESS__QUEEN_H_
