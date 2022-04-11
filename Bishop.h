//
// Created by ozer on 10.04.2022.
//

#ifndef CHESS__BISHOP_H_
#define CHESS__BISHOP_H_
#include "ChessPieceI.h"

class Bishop : public ChessPieceI{
 private:

 public:
  explicit Bishop(Color col=Color::white, PieceType piece_type=PieceType::bishop);
  std::vector<position> getThreatList(std::array<std::array<ChessPieceI *, 8>, 8> objMap, position objPosition) override;
};

#endif //CHESS__BISHOP_H_
