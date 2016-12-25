#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <exception>
#include <fstream>
using namespace std;


class http{

private:
    std::string protocol_separator = "://";
    std::string variable_sseparator = "?";
    std::string variable_separator = "&";
    std::string equal_separator = "=";

    std::string url;
    std::string protocol;
    std::string uri;
    std::string vars;
    std::map<std::string , std::string> variables;
    std::string variables_string;
public :
    http(std::string get_url){
        url = get_url;
        configureProtocol();
        configureVaraible();
    }
    http (){

    }

    std::string  showProtocol(){
        return protocol;
    }
    void configureProtocol(){
        size_t prot =  url.find(protocol_separator );
        protocol = url.substr(0 , prot); // http
        std::string http_sep = url.substr(prot ,3); // ://
        url.compare(prot , 3 , http_sep);

        uri = url.substr(prot+3);
    }
    bool checkVarState(){
        if(uri.find("?") != std::string::npos ){
            //cout<<uri.find("?");
            return true;
        }
    }
    void configureVaraible(){
        if(checkVarState()){
                vars = uri.substr(uri.find("?")+1 , uri.length() -  uri.find("?") );

                std::stringstream vals(vars);
                std::string getval;
                std::vector<std::string> variables_vector;

                while(getline(vals, getval, '&'))
                {
                    variables_vector.push_back(getval);
                    std::stringstream allval(getval);
                    std::string key;
                    std::string value;
                    getline(allval, key, '=');
                    getline(allval, value, '=');
                    variables.insert ( std::pair<std::string,std::string>(key, value) );
                }

        } else{
            //return false;
        }
    }

    std::string showvariables(){
        std::map<std::string,std::string>::iterator it = variables.begin();
        for (it=variables.begin(); it!=variables.end(); ++it)
            variables_string.append(it->first + " => " + it->second +'\n' );
        return variables_string;
    }

    std::string showDomein(){
        if(uri.find('/')  != std::string::npos){
            size_t dm = uri.find_first_of('/');
            return uri.substr(0,dm);
        } else{
            return uri;
        }




    }
    friend ostream& operator<<(ostream&, http&);

	friend istream& operator >> (istream&, http&);
};

std::istream& operator >> (istream& in, http& s)
{

    return in;
}

std::ostream& operator<<(ostream& out, http& s)
{
    out << s.url<<endl;
}




int main(){
//htpp h;
//cin >> h;
http a("wss://example.com/aa/hh/cc/bb?a&rr=66");
cin>>a;
cout<<a;
std::cout<<a.showProtocol();
//a.configureVaraible();
//cout << a;
std::cout<<a.showvariables();
std::cout<<a.showDomein();
}
