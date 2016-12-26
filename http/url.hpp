#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

    const std::string protocol_separator = "://";
    const std::string variable_sseparator = "?";
    const std::string variable_separator = "&";
    const std::string equal_separator = "=";

class Url{

private:


    std::string url;
    std::string protocol;
    std::string uri;
    std::string vars;
    std::map<std::string , std::string> variables;
    std::string variables_string;
public :
    Url(std::string get_url){
        url = get_url;
        configureProtocol();
        configureVaraible();
    }
    Url (){

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

        }
    }

    std::string showvariables(){
        std::map<std::string,std::string>::iterator it_ = variables.begin();
        variables_string.clear();
        for (it_=variables.begin(); it_!=variables.end(); ++it_)
            variables_string.append(it_->first + " => " + it_->second +'\n' );
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

    std::string addVaraible(std::string ikey , std::string ivalue){
        variables.insert (std::pair<std::string,std::string>(ikey, ivalue) );
        url.append("&" + ikey + "=" + ivalue);
        return url;

    }
    std::string showUrl(){
        return url;
    }
    friend std::ostream& operator<<(std::ostream&, Url&);

	friend std::istream& operator >> (std::istream&, Url&);
};

std::istream& operator >> (std::istream& in, Url& s)
{
    in>>s.url;
    s.configureProtocol();
    s.configureVaraible();
    return in;
}

std::ostream& operator<<(std::ostream& out, Url& s)
{
    out << s.url;
}
