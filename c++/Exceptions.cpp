#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>

class Solution {
    private:
        static int load;
    public:
        static int compte(long long a, long long b) {
            load++;
            if(a < 0) {
                throw std::invalid_argument("A is negative");
            }
            std::vector <int> v(a, 0);
            int real = -1, complx = sqrt(-1);
            if (b == 0) throw  0;
            real = (a / b) * real;
            int ans = v.at(b);
            return real + a - b * ans;
        }
        static int getload() {
            return load;
        }

};
int Solution::load = 0;
int main() {
    int t;
    std::cin >> t;
    while(t--) {
        long long a, b;
        std::cin >> a >> b;
        try {
            std::cout << Solution::compte(a, b) << std::endl;
        }
        catch (std::bad_alloc& error) {
            std::cout << "Not enough memory" << std::endl;
        }
        catch (std::exception& error) {
            std::cout << "Exception: " << error.what() << std::endl; 
        }
        catch(...){
            std::cout << "Other Exception" << std::endl;
        }
    }
    std::cout  << Solution::getload() << std::endl;

    return 0;
}