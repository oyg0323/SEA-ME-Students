#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
   // cout<<argc;
  
    if(argc<3){ // check argument” number
        cout<<"write command and string\n";
        return 0;
    }
     string com=argv[1];
     string input = argv[2];
    for(int i=3; i<argc; i++){
        input=input.append(" ");
        input=input.append(argv[i]);
    }
    
    if(com=="UP" || com=="up"){
       transform(input.begin(), input.end(), input.begin(), ::toupper);
       cout<<input<<"\n";
    }
    else if(com=="DOWN"|| com=="down"){
        transform(input.begin(), input.end(), input.begin(), ::tolower);
       cout<<input<<"\n";
    }
    else{ 
        cout<<"you only use up or down\n";
        return 0;
    }
    return 0;
}
