#include <set>
#include <string>

class User {
public:
    // TODO: write special member functions, including default constructor!
    User() = default;

    User(std::string name);

    User(const User &other) = delete;
    User& operator=(const User &other) = delete;

    User(User &&other) noexcept = default;
    User& operator=(User &&other) noexcept = default;

    // getter functions
    std::string getName() const;
    std::set<User> getFriends() const;

    // setter functions
    void setName(std::string name);

    // TODO: add the < operator overload here!
    bool operator<(const User &rhs) const;

    friend User&& operator+(User &lhs, User &rhs);

private:
    std::string name;
    std::set<User> friends;

};