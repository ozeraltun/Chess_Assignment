//
// Created by ozer on 10.04.2022.
//

#ifndef CHESS__ROOK_H_
#define CHESS__ROOK_H_
#include "Enums.h"
#include "ChessPieceI.h"
#include <vector>

class Rook : public ChessPieceI{
 private:

 public:
  explicit Rook(Color col=Color::white, PieceType piece_type=PieceType::rook);
  std::vector<position> getThreatList(std::array<std::array<ChessPieceI *, 8>, 8> objMap, position objPosition) override;
};

#endif //CHESS__ROOK_H_
