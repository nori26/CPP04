#include "IMateriaSource.hpp"

IMateriaSource::~IMateriaSource() {}

IMateriaSource::IMateriaSource(IMateriaSource const &other) { *this = other; }

IMateriaSource &IMateriaSource::operator=(IMateriaSource const &other) {
  if (this == &other) {
    return *this;
  }
  return *this;
}
