//
// Created by ozer on 10.04.2022.
//

#ifndef CHESS__THREATCALCULATOR_H_
#define CHESS__THREATCALCULATOR_H_

#include <array>
#include <vector>
#include "Enums.h"
#include "ChessPieceI.h"


class ThreatCalculator {
  /**
   * @brief checks the range for the given chessPiece position with the given movement
   * @param objPosition is the chessPiece position
   * @param threatLoc is the threatening movement for the obj
   * @return integer value for the range
   */
  static int checkRange(position objPosition, movement threatLoc);

  /**
   * @brief gets the X element of the given direction
   * @param direction is the given direction
   * @return X-element of the direction
   */
  static int getDirectionXelement(Direction direction);

  /**
   * @brief gets the Y element of the given direction
   * @param direction is the given direction
   * @return Y-element of the direction
   */
  static int getDirectionYelement(Direction direction);

  /**
   * @brief gets the adder value for the L movement of the knight
   * @param threat is the threatening movement
   * @return position value which will be used at the summation
   */
  static position getAdderValue(movement threat);

  /**
   * @brief checks the range for the given chessPiece position with the given position
   * @param adder value that will be added
   * @param obj objects position
   * @return if total summation(which is a position) is in the range
   */
  bool static checkAdder(position adder, position obj);
 public:
  /**
   * @brief calculates the all possible threats
   * @param objMap current object map
   * @param objPosition current object position
   * @param movementList all possible movements for the chess piece
   * @param unthreatableColor same colors cannot be threatened
   * @return all possible threatening positions
   */
  static std::vector<position> CalculateThreat(std::array<std::array<ChessPieceI *, 8>, 8> objMap,
                                        position objPosition,
                                        const std::vector<movement> &movementList,
                                        Color unthreatableColor);
  /**
   * @brief calculates the all possible threats for the KNIGHT
   * @param objMap current object map
   * @param objPosition current object position
   * @param movementList all possible movements for the chess piece
   * @param unthreatableColor same colors cannot be threatened
   * @return all possible threatening positions
   */
  static std::vector<position> CalculateThreatLshape(std::array<std::array<ChessPieceI *, 8>, 8>objMap,
                                                     position objPosition,
                                                     const std::vector<movement> &movementList,
                                                     Color unthreadableColor);


};

#endif //CHESS__THREATCALCULATOR_H_
