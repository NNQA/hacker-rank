
#include <iostream>
#include <stack>

int main() {
    unsigned long n, m ,tmp;
    std::cin >> n;
    
    std::stack<unsigned long> sroces;
    
    for(int i = 0 ; i != n; i++) {
        std::cin >> tmp;
        if(sroces.empty() || tmp != sroces.top()) {
            sroces.push(tmp);
        }
    }
    
    std::cin >> m;
    for(int i = 0 ; i != m; i++) {
        std::cin >> tmp;
        while(!sroces.empty() && tmp >= sroces.top()) {
            sroces.pop();
        }
        std::cout << (sroces.size() + 1) << std::endl;
    }
    
}
