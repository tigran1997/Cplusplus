#include <iostream>
#include <string.h>
using namespace std;


int main(){

const char  http[] ="http://example.com/aa/bb?n=4&t=8" ;
const char protocol_separator = '/';
const char separators[] = [':' , '/' , '?' ,'&'];

cout<<strrchr(http ,protocol_separator );
cout<<strlen(http);


//cout<<http;


}
