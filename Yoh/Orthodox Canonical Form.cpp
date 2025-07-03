#include <iostream>
#include <string>
using namespace std;
class car{
    public:
        string name;
        int speed;
        car():name("NULL"),speed(0){
            cout<<"Default car name : "<<name<<"   speed :"<<speed<<"\n";
        }
        car(const string& n, int s)
  : name(n), speed(s)
{ cout<<"car name : "<<name<<"   speed :"<<speed<<"\n";
        }
        car(const car&other){
            name = other.name;
            speed = other.speed;
            cout<< "copy class\n";
            cout<<"other name: "<<other.name<<"   other speed: "<<other.speed<<"\n";     
        }
        car& operator=(const car&other){
            this->name = other.name;
            this->speed = other.speed;
            cout<<"other name: "<<other.name<<"   other speed: "<<other.speed<<"\n";     
            return *this;
        }
        ~car(){
            cout<<"Destructoer: "<<name<<"\n";
        }
        
};
int main(){
    car a;
    car b("Tico",100);
    car c("Bongo",50);
    a=c;
    car d(c);  
    return 0;
}