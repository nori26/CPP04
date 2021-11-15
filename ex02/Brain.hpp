#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
class Brain {
 private:
  static const size_t size_ = 100;
  std::string idea[size_];

 public:
  Brain();
  ~Brain();
  Brain(const Brain &src);
  Brain &operator=(const Brain &rhs);
  void showIdea();
};

#endif
