#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <exception>
using namespace std;


class http{

private:
      string protocol_separator = "://";
    string variable_sseparator = "?";
    string variable_separator = "&";
    string equal_separator = "=";

    string url;
    string protocol;
    string uri;
    string vars;
    map<string , string> variables;
    string variables_string;
public :
    http(string get_url){
        url = get_url;
        configureProtocol();
    }

    string  showProtocol(){
        return protocol;
    }
    void configureProtocol(){
        size_t prot =  url.find(protocol_separator );
        protocol = url.substr(0 , prot); // http
        string http_sep = url.substr(prot ,3); // ://

        try {
            url.compare(prot , 3 , http_sep);
        } catch (...) {
            cout<<"Something went wrong";
        }
        uri = url.substr(prot+3);
    }
    bool checkVarState(){
        if(uri.find("?") != string::npos ){
            //cout<<uri.find("?");
            return true;
        }
    }
    void configureVaraible(){
        if(checkVarState()){
                vars = uri.substr(uri.find("?")+1 , uri.length() -  uri.find("?") );

                stringstream vals(vars);
                string getval;
                vector<string> variables_vector;

                while(getline(vals, getval, '&'))
                {
                    variables_vector.push_back(getval);
                    stringstream allval(getval);
                    string key;
                    string value;
                    getline(allval, key, '=');
                    getline(allval, value, '=');
                    variables.insert ( std::pair<string,string>(key, value) );
                }

        } else{
            cout<<"No vars";
        }
    }

    string showvariables(){
        configureVaraible();
        std::map<string,string>::iterator it = variables.begin();
        for (it=variables.begin(); it!=variables.end(); ++it)
            variables_string.append(it->first + " => " + it->second +'\n' );
            //std::cout << it->first << " => " << it->second << '\n';
        return variables_string;
    }
};


int main(){

htpp h;
cin >> h;
http a("wss://example.com/aa/hh/cc/bb?a&rr=66");
cout<<a.showProtocol();
//a.configureVaraible();
cout << a;
cout<<a.showvariables();
}
