//
// Created by ozer on 6.04.2022.
//

#ifndef CHESS__TABLELOADER_H_
#define CHESS__TABLELOADER_H_

#include "Table.h"
#include <string>
#include <fstream>
class TableLoader {
 public:
  /**
   * @brief Loads the table from the given path
   * @param path is the given path
   * @return constructed table is returned
   */
  static Table* loadRawTableFromPath(const std::string& path);
};

#endif //CHESS__TABLELOADER_H_
