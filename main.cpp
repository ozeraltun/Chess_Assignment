#include <iostream>
#include <string>

#include "Table.h"
#include "TableLoader.h"
#include "Enums.h"
int main(int argc, char** argv) {
  std::cout << "Main started.." << std::endl;
  std::string path(reinterpret_cast<const char *>(argv[1])); //Note that this might be OS specific!
  Table* myChessTable = TableLoader::loadRawTableFromPath(path);
  myChessTable->print();

  std::cout << "Siyah = " << myChessTable->calculateForColor(Color::black) << std::endl;
  std::cout << "Beyaz = " << myChessTable->calculateForColor(Color::white) << std::endl;
  std::cout << std::endl;

  //std::cout << "Printing threat map: " << std::endl;
  //myChessTable->printThreatMap();
  return 0;
}
