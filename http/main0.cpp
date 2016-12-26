#include <iostream>
#include "url.hpp"
int main(){
Url a("wss://example.com/aa/hh/cc/bb?a&rr=66");

std::cout<<a.showProtocol()<<std::endl;
std::cout << a<<std::endl;
std::cout<<a.showvariables()<<std::endl;
std::cout<<a.showDomein()<<std::endl;
a.addVaraible("bba" , "66");
std::cout<<a.showUrl()<<std::endl;
std::cout<<a.showvariables()<<std::endl;

}
