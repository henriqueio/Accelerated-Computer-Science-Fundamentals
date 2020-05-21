#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <vector>

int insert(int value, std::vector<int> &table) {
  // Code to insert value into a hashed location in table
  // where table is a vector of length 1000.
  // Returns the number of collisions encountered when
  // trying to insert value into table.

  int index = 0;
  if (value < 1000) {
    index = value;
  } else {
    int tenPower = 1;

    for (int i = 0; i < 3; ++i) {
      int number = (value / tenPower) % 10;
      index += tenPower * number;
      tenPower *= 10;
    }
  }

  int collisions = 0;
  bool inserted = false;

  while (!inserted) {
    if (table[index] == -1) {
      table[index] = value;
      inserted = true;
      return collisions;
    } else {
      ++collisions;
      ++index;
      if (index == table.size()) index = 0;
    }
  }
}

int main() {
  int i, j, hit, max_hit = 0, max_value = -1;

  std::vector<int> value(500);

  int old_value = 0;
  for (i = 0; i < 500; i++) {
    old_value += rand() % 100;
    value[i] = old_value;
  }

  // create hash table of size 1000 initialized with -1
  std::vector<int> table(1000, -1);

  for (i = 0; i < 500; i++) {
    hit = insert(value[i], table);
    if (hit > max_hit) {
      max_hit = hit;
      max_value = value[i];
    }
  }

  std::cout << "Hashing value " << max_value << " experienced " << max_hit
            << " collisions." << std::endl
            << std::endl;

  for (j = 0; j < 1000; j += 10) {
    std::cout << std::setw(3) << j << ":";
    for (i = 0; i < 10; i++) {
      if (table[j + i] == -1)
        std::cout << "      ";
      else
        std::cout << std::setw(6) << table[j + i];
    }
    std::cout << std::endl;
  }

  return 0;
}