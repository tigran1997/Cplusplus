#include <iostream>
#include <string.h>
using namespace std;


int main(){

char * t;
const char ex2[] =  "http://example.com";
const char  http[] ="http://example.com/aa/bb?n=4&t=8" ;
const char protocol_separator[] = "://";
// const char separators[] = [':' , '/' , '?' ,'&'];
t = strstr(http, protocol_separator);
cout<<t;
for(int i =0; i< strlen(http); i++){
    if(http[i] == ':'){
        //cout<<http[i];
        //*t = http[i];
        //while(*t == '.'){
            //cout<<*t;
        //}

    }
}
//cout<<strchr(http ,protocol_separator );
//cout<<strlen(http);


//cout<<http;


}
