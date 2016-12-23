#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main(){

char * t;
const char ex2[] =  "http://example.com";
const char  http1[] ="http:example.com/index.php/?n=4&t=8" ;

string http = "https://example.com/aa/hh/cc/bb?n=4&t=8&kk=8";
string protocol_separator = "://";
string variable_sseparator = "?";
string variable_separator = "&";


size_t prot =  http.find(protocol_separator );
string protocol = http.substr(0 , prot); // http
string http_sep = http.substr(prot ,3); // ://
//cout<<http.compare(prot  , 3 , http_sep); // qcel try-i mej  if
string uri = http.substr(prot+3); // example.com/aa/bb?n=4&t=8
//cout<<uri;

stringstream  div(uri);
string segment;
//cout<<string::npos;
while(getline(div, segment, '/'))
{
    cout<<segment<<endl;
}

if(uri.find("?") != string::npos ){
    cout<<uri.find("?");
}
string vars = uri.substr(uri.find("?")+1 , uri.length() -  uri.find("?") );
cout<<vars;

stringstream vals(vars);
string value;
while(getline(vals, value, '&'))
{
    cout<<value<<endl;
}









//const char protocol_separator[] = ":0//";

}
