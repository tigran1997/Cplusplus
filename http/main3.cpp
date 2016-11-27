#include <iostream>
#include <string>

using namespace std;

void print_host_and_port(string url) {
  cout << "Parsing " << url << endl;
  string http("http://");
  if (url.compare(0, http.size(), http) == 0) {
    unsigned int pos = url.find_first_of("/:", http.size());

    if (pos == string::npos) {
      // No port or path
      pos = url.size();
    }

    string host(url.substr(http.size(), pos-http.size()));
    cout << "Host is " << host << endl;

    if (pos < url.size() && url[pos] == ':') {
      // A port is provided
      unsigned int ppos = url.find_first_of("/", pos);
      if (ppos == string::npos) {
        // No path provided, assume port is rest of string
        ppos = url.size();
      }
      string port(url.substr(pos+1, ppos-pos-1));
      if (port.size() > 0) {
        // Port is provided and has length
        cout << "Port is " << port << endl;
      }
    } else {
      cout << "No port number was provided" << endl;
    }

  } else {
    cerr << "Not an HTTP url" << endl;
  }
  cout << endl;
}

int main ()
{
  print_host_and_port("http://1.2.3.4:5678/something");
  print_host_and_port("http://1.2.3.4:1/something");
  print_host_and_port("http://1.2.3.4:/something");
  print_host_and_port("http://1.2.3.4:5678");
  print_host_and_port("http://1.2.3.4/something");
  print_host_and_port("http://1.2.3.4");

  return 0;
}
