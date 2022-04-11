//
// Created by ozer on 6.04.2022.
//

#include "TableLoader.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

Table* TableLoader::loadRawTableFromPath(const std::string& path) { // it is better to return r&
  Table* constructtedTable = new Table();

  //since ifstream wants char* instead of a std::string
  int len = path.size(); //Narrowing conversion!
  char* pathP = new char[len+1];
  std::copy(path.begin(), path.end(), pathP);
  pathP[len] = '\0';

  //reading begins
  std::ifstream input(path);
  std::string readStr;
  positionX_t xPosition = 0;
  positionY_t yPosition = 0;
  ChessPieceI* chess_piece;
  Color pieceColor = Color::white;

  while(input >> readStr) {
    if(xPosition == 8){
      if(yPosition == 8){break;}
      yPosition++;
      xPosition = 0;
    }

    //Getting empty position or the color
    if(readStr.at(1) == '-'){
      goto EMPTY_ELEMENT;
    }
    else if(readStr.at(1) == 'b'){
      pieceColor = Color::white;
    }else if(readStr.at(1) == 's'){
      pieceColor = Color::black;
    }

    //Getting peaceType, and creating the object accordingly
    switch(readStr.at(0)){
      case 'p':
        chess_piece = new Pawn(pieceColor);
        break;
      case 'k':
        chess_piece = new Rook(pieceColor);
        break;
      case 'a':
        chess_piece = new Knight(pieceColor);
        break;
      case 'f':
        chess_piece = new Bishop(pieceColor);
        break;
      case 'v':
        chess_piece = new Queen(pieceColor);
        break;
      case 's':
        chess_piece = new King(pieceColor);
        break;
      default:
        std::cout << "Error at reading pieceType" << std::endl;
    }

    constructtedTable->addChessPiece(chess_piece, xPosition, yPosition);
    EMPTY_ELEMENT:
    xPosition++;
  } //while ends
  return constructtedTable;
}