//
// Created by ozer on 10.04.2022.
//

#include <iostream>
#include "ThreatCalculator.h"
std::vector<position> ThreatCalculator::CalculateThreat(const std::array<std::array<ChessPieceI *, 8>, 8> objMap,
                                                        const position objPosition,
                                                        const std::vector<movement> &movementList,
                                                        const Color unthreatableColor) {
  std::vector<position> threatPositionList= {};
  for(auto threat : movementList){
    //check range
    //check obj exists
    //check different color
    //  add to the threatPositionList

    int range = ThreatCalculator::checkRange(objPosition, threat);
    for(int i=0; i<range; i++){
      int xElement;
      int yElement;

      xElement = ThreatCalculator::getDirectionXelement(std::get<0>(threat)) *(i+1);
      yElement = ThreatCalculator::getDirectionYelement(std::get<0>(threat)) *(i+1);

      if((objMap[std::get<1>(objPosition)+yElement][std::get<0>(objPosition)+xElement]) != nullptr){
        if(objMap[std::get<1>(objPosition)+yElement][std::get<0>(objPosition)+xElement]->getColor() == unthreatableColor){
          break;
        }
        else{


          threatPositionList.push_back(std::make_tuple(std::get<0>(objPosition)+xElement,std::get<1>(objPosition)+yElement));
          break;
        }
      }
    }
  }
  return threatPositionList;
}
int ThreatCalculator::getDirectionXelement(Direction direction){
  int XElement = 0;
  switch(direction){
    case Direction::up:
      break;
    case Direction::down:
      break;
    case Direction::left:
      XElement = -1;
      break;
    case Direction::right:
      XElement = 1;
      break;
    case Direction::upleft:
      XElement = -1;
      break;
    case Direction::upright:
      XElement = 1;
      break;
    case Direction::downleft:
      XElement = -1;
      break;
    case Direction::downright:
      XElement = 1;
      break;
    default:
      std::cout << "Error xElement" << std::endl;
  }
  return XElement;
}

int ThreatCalculator::getDirectionYelement(Direction direction){
  int YElement = 0;
  switch(direction){
    case Direction::up:
      YElement = -1;
      break;
    case Direction::down:
      YElement = 1;
      break;
    case Direction::left:
      break;
    case Direction::right:
      break;
    case Direction::upleft:
      YElement = -1;
      break;
    case Direction::upright:
      YElement = -1;
      break;
    case Direction::downleft:
      YElement = 1;
      break;
    case Direction::downright:
      YElement = 1;
      break;
    default:
      std::cout << "Error yElement" << std::endl;
  }
  return YElement;
}
int ThreatCalculator::checkRange(position objPosition, std::tuple<Direction, int> threatLoc) {
  int range = 0;
  position checkPosition = objPosition;
  position positionAdder = std::make_tuple(0,0);
  switch(std::get<0>(threatLoc)){
    case Direction::up:
      positionAdder = std::make_tuple(0,-1);
      break;
    case Direction::down:
      positionAdder = std::make_tuple(0,1);
      break;
    case Direction::left:
      positionAdder = std::make_tuple(-1,0);
      break;
    case Direction::right:
      positionAdder = std::make_tuple(1,0);
      break;
    case Direction::upleft:
      positionAdder = std::make_tuple(-1,-1);
      break;
    case Direction::upright:
      positionAdder = std::make_tuple(1,-1);
      break;
    case Direction::downleft:
      positionAdder = std::make_tuple(-1,1);
      break;
    case Direction::downright:
      positionAdder = std::make_tuple(1,1);
      break;
    default:
      std::cout << "No such state exists"<< std::endl;

  }

  for(int i=0; i<std::get<1>(threatLoc); i++){
    if((std::get<1>(checkPosition) + std::get<1>(positionAdder) >= 8) || (std::get<1>(checkPosition) + std::get<1>(positionAdder) < 0)) {
      return range;
    }else if((std::get<0>(checkPosition) + std::get<0>(positionAdder)) >=8 || (std::get<0>(checkPosition) + std::get<0>(positionAdder)) < 0){
      return range;
    }else{
      std::get<1>(checkPosition) = std::get<1>(checkPosition)+ std::get<1>(positionAdder);
      std::get<0>(checkPosition) = std::get<0>(checkPosition)+ std::get<0>(positionAdder);
      range++;
    }
  }
  return range;
}


std::vector<position> ThreatCalculator::CalculateThreatLshape(const std::array<std::array<ChessPieceI *, 8>, 8> objMap,
                                                              const position objPosition,
                                                              const std::vector<movement> &movementList,
                                                              const Color unthreadableColor) {
  //check range
  //check obj exists
  //check different color
  //  add to the threatPositionList
  std::vector<position> threatPositionList= {};
  for(auto threat : movementList){
    std::tuple<int, int> adderValue = ThreatCalculator::getAdderValue(threat);
    if(checkAdder(adderValue, objPosition) == true){ //range is ok
      if(objMap[std::get<1>(objPosition)+std::get<1>(adderValue)][std::get<0>(objPosition)+std::get<0>(adderValue)] != nullptr){ //obj exists
        if(objMap[std::get<1>(objPosition)+std::get<1>(adderValue)][std::get<0>(objPosition)+std::get<0>(adderValue)]->getColor() != unthreadableColor){
          position threatPosition = std::make_tuple(std::get<0>(objPosition)+std::get<0>(adderValue), std::get<1>(objPosition)+std::get<1>(adderValue));
          threatPositionList.push_back(threatPosition);
        }

      }
    }
  }

  return threatPositionList;
}

bool ThreatCalculator::checkAdder(std::tuple<int,int> adder, position obj){
  if(std::get<0>(adder)+std::get<0>(obj) >= 8 || std::get<0>(adder)+std::get<0>(obj) < 0){
    return false;
  }else if(std::get<1>(adder)+std::get<1>(obj) >= 8 || std::get<1>(adder)+std::get<1>(obj) < 0){
    return false;
  }else{
    return true;
  }
}

std::tuple<int, int> ThreatCalculator::getAdderValue(std::tuple<Direction, int> threat){
  std::tuple<int,int> adder;
  switch(std::get<0>(threat)){
    case Direction::up_up_left:
      adder = std::make_tuple(-1,-2);
      break;
    case Direction::up_up_right:
      adder = std::make_tuple(1,-2);
      break;
    case Direction::right_right_up:
      adder = std::make_tuple(2,-1);
      break;
    case Direction::left_left_up:
      adder = std::make_tuple(-2,-1);
      break;
    case Direction::right_right_down:
      adder = std::make_tuple(2,1);
      break;
    case Direction::left_left_down:
      adder = std::make_tuple(-2, 1);
      break;
    case Direction::down_down_left:
      adder = std::make_tuple(-1, 2);
      break;
    case Direction::down_down_right:
      adder = std::make_tuple(1, 2);
      break;
    default:
      std::cout << "Error finding adderValue" << std::endl;
  }
  return adder;

}