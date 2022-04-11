//
// Created by ozer on 6.04.2022.
//

#ifndef CHESS__TABLE_H_
#define CHESS__TABLE_H_

#include <string>
#include <array>
#include <iostream>
#include <vector>

#include "Enums.h"
#include "ChessPieceI.h"

class Table {
 private:
  std::array<std::array<ChessPieceI*, 8>, 8> m_objMap{};

  /**
   * @brief updates the threats according to current map
   */
  void updateThreats();

  /**
   * @brief resets the threats (all of them are "not threated" anymore)
   */
  void resetThreats();

  /**
   * @brief returns the threat positions of the given chess piece
   * @param p chess piece
   * @return all possible threat positions
   */
  std::vector<position> getThreatLocations(ChessPieceI* p, position currentPosition);

 public:

  /**
   * @brief ctor
   */
  Table();

  /**
   * @brief move assignment
   */
  //Table& operator= ( Table && t ) noexcept;

  /**
   * @brief prints the current raw map
   */
  void print() const;

  /**
   * @brief calculates the value requested in the assignment
   * @param col color
   * @return calculated value
   */
  double calculateForColor(Color col);

  /**
   * @brief adds the chess piece
   * @param chessPiece The ChessPieceI* which will be added
   * @param xPos X-position parameter of the location which piece will be added
   * @param yPos Y-position parameter of the location which piece will be added
   */
  void addChessPiece(ChessPieceI *chessPiece, positionX_t xPos, positionY_t yPos);

  /**
   * @brief prints the threat map, threated ones are printed as -1-, else -0-
   */
  void printThreatMap();
};

#endif //CHESS__TABLE_H_
