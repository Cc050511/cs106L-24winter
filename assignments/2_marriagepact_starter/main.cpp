/* 
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and pointers.
There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>

std::set<std::string> get_applicants(std::string filename) {
    // TODO: Implement this function. Feel free to change std::set to std::unordered_set if you wish!
    std::set<std::string> applicants;
    std::ifstream file{filename};
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            applicants.insert(line);
            std::cout << line << std::endl;
        }
    }
    return applicants;
}

std::queue<std::string*> find_matches(std::set<std::string> &students) {
    // TODO: Implement this function.
    std::queue<std::string*> matches;
    std::string name1;
    std::string name2;
    for (auto it = students.begin(); it != students.end(); ++it) {
        std::istringstream iss(*it);
        std::getline(iss, name1, ' ');
        std::getline(iss, name2, ' ');
        // std::cout << name1 << "***" << name2 << std::endl;
        if (name1[0] == 'Z' && name2[0] == 'M') {
            std::string *student = new std::string(*it);
            matches.push(student);
            delete student;
        }
    }
    return matches;
}



int main() {
    // Your code goes here. Don't forget to print your true love!
    auto students = get_applicants("students.txt");
    auto mathces = find_matches(students);
    if (mathces.empty()) {
        std::cout << "NO MATCHES" << std::endl;
    }
    else {
        // std::random_shuffle(mathces.front(), mathces.back());
        std::cout << "Your true love is: " << *mathces.front() << std::endl;
    }
    
    return 0;
}
