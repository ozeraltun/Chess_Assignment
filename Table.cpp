//
// Created by ozer on 6.04.2022.
//

#include "Table.h"

Table::Table() {
  this->m_objMap = {{
                        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
                        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr}
                                                                                                }};
}
/*Table& Table::operator=(Table&& other) noexcept{
  this->m_objMap= std::move(other.m_objMap);
  return *this;
}*/
void Table::print() const{
  std::cout << "************************************" << std::endl;
  for(const auto &row : m_objMap){
    for(const auto &val : row){
      std::string printValue1 = "-";
      std::string printValue2 = "-";
      if(val!=nullptr) {
        printValue2 = val->getColor() == Color::white ? "b" : "s";
        printValue1 = val->getColor() == Color::white ? "b" : "s";
        switch (val->getPieceType()) {
          case PieceType::rook:printValue1 = "k";
            break;
          case PieceType::knight:printValue1 = "a";
            break;
          case PieceType::bishop:printValue1 = "f";
            break;
          case PieceType::queen:printValue1 = "v";
            break;
          case PieceType::king:printValue1 = "s";
            break;
          case PieceType::pawn:printValue1 = "p";
            break;
          default:std::cout << "Error: could not figure out piece type " << std::endl;
        }
      }
      std::cout << printValue1+printValue2 << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "************************************" << std::endl;
}

void Table::addChessPiece(ChessPieceI *chessPiece, positionX_t xPos, positionY_t yPos) {
  this->m_objMap[yPos][xPos] = chessPiece;
}

std::vector<position> Table::getThreatLocations(ChessPieceI *p, position currentPosition) {
  std::vector<position> threatList = p->getThreatList(this->m_objMap, currentPosition);
  return threatList;
}

void Table::updateThreats(){
  int x_Index = 0;
  int y_Index = 0;
  for(auto row : m_objMap) {
    for (auto val : row) {
      if(val != nullptr) {
        std::vector<position> applythreats = getThreatLocations(val, std::make_tuple(x_Index, y_Index));
        for(auto threat: applythreats){
          this->m_objMap[std::get<1>(threat)][std::get<0>(threat)]->applyThreat();
        }
      }
      x_Index++;
    }
    x_Index=0;
    y_Index++;
  }
}

double Table::calculateForColor(Color col){
  this->resetThreats(); //if positions are changed, it is better to reset all of them..
  this->updateThreats();
  double result = 0;
  for(const auto &row : m_objMap){
    for(const auto &val : row) {
      if(val!=nullptr){
        if(val->getColor() == col){
          double pieceValue = val->getPieceValue();
          if(val->getThreated()){
            pieceValue = pieceValue/2;
          }
          result = result + pieceValue;
        }
      }
    }
  }
  return result;
}
void Table::printThreatMap(){
  for(const auto &row : m_objMap){
    for(const auto &val : row) {
      if(val!=nullptr){
        if(val->getThreated()){
          std::cout << "-1-";
        }else{
          std::cout << "-0-";
        }
      }else{
        std::cout << "---";
      }
    }
    std::cout << std::endl;
  }
}
void Table::resetThreats(){
  for(const auto &row : m_objMap) {
    for (const auto &val : row) {
      if (val != nullptr) {
        val->resetThreat();
      }
    }
  }
}