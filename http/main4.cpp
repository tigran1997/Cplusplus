#include <iostream>
#include <string>
using namespace std;


int main(){

char * t;
//const char ex2[] =  "http://example.com";
const char  http1[] ="http:example.com/aa/bb?n=4&t=8" ;
string http = "http://example.com/aa/bb?n=4&t=8";
string protocol_separator = "://";
string variable_sseparator = "?";
string variable_separator = "&";
size_t prot =  http.find(protocol_separator );
//cout<<http.substr(0 , prot);
cout<<http.substr(prot ,3);
cout<<http.compare(prot  , 3 , "://"); // qcel try-i mej
//const char protocol_separator[] = "://";

}
