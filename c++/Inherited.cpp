#include <iostream>
#include <cstring>
#include <exception>
#include <sstream>

std::string Tick = "ww";

class exception {
    private: std::string a;
    public:
        exception(int n) : a(std::to_string(n)) {}
        const char *what() const throw() {
            return a.c_str();
        }
};

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        std::string a;
        std::cin >> a;
        try {
            if(a.size() < 5) throw(exception(a.size()));
            for(int i = 0; i != a.size() - 1; i++) {
                if (a[i] == 'w' and a[i+1] == 'w') {
                    std::cout << "Invalid" << std::endl;
                    break;
                } 
                if(i == a.size() - 2) {
                    std::cout << "Valid" << std::endl;
                }
            }
        }
        catch(exception b) {
            std::cout << "Too short: " << b.what() << std::endl;
        }
    }
}