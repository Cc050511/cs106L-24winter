// Blank header file
#include <string>

class cat {
  public:
    cat() = default;
    cat(int age, std::string name): age(age), name(name) {}

    int getAge() const { return age; }
    void setAge(int age) { this->age = age;}
  private:
    int age;
    std::string name;
};