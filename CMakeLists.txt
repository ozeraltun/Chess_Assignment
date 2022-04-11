cmake_minimum_required(VERSION 3.21)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess main.cpp TableLoader.cpp TableLoader.h Table.cpp Table.h Enums.h ChessPieceI.cpp ChessPieceI.h Pawn.cpp Pawn.h ThreatCalculator.cpp ThreatCalculator.h Bishop.cpp Bishop.h Rook.cpp Rook.h King.cpp King.h Queen.cpp Queen.h Knight.cpp Knight.h)
