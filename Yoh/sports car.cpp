#include <iostream>
#include <string>
using namespace std;
class car{
    public:
        string make;
        string model;
        int year;
        car():make("NULL"),model("NULL"),year(0){
            cout<<"Default car make : "<<make<<"   model :"<<model<<"   year: "<<year<<"\n";
        }
        car(const string& mk,const string& m,int y )
  : make(mk), model(m),year(y){ 
    cout<<"car make : "<<make<<"   model :"<<model<<"   year: "<<year<<"\n";
        }
        car(const car&other){
            make = other.make;
            model = other.model;
            year = other.year;
            cout<< "copy class\n";
            cout<<"other car make : "<<make<<"   model :"<<model<<"   year: "<<year<<"\n";   
        }
        car& operator=(const car&other){
            this->make = other.make;
            this->model = other.model;
            this ->year= other.year;
            cout<<"other car make : "<<make<<"   model :"<<model<<"   year: "<<year<<"\n";  
            return *this;
        }
        ~car(){
            cout<<"Destructoer: "<<model<<"\n";
     }
        void drive(){
            cout<<"make :"<<make<<"   model: "<<model<<"   year: "<<year<<"\n";

        }
};
class sportscar : public car{
    public:
        int topspeed;
    sportscar(): car(),topspeed(0){
        cout<<"default topspeed: "<<topspeed<<"\n";
    } 
    sportscar(const string& mk, const string& m, int y, int ts)
      : car(mk, m, y), topspeed(ts)
    {
        cout << "[sportscar Param] topspeed: " << topspeed << "\n";
    }
    sportscar(const sportscar& other)
      : car(other), topspeed(other.topspeed)
    {
        cout << "[sportscar Copy] copied topspeed: "
             << other.topspeed << "\n";
    }

   
    sportscar& operator=(const sportscar& other) {
        if (this != &other) {
            car::operator=(other);
            topspeed = other.topspeed;
            cout << "[sportscar Copy =] assigned topspeed: "
                 << other.topspeed << "\n";
        } else {
            cout << "[sportscar Copy =] self-assignment detected\n";
        }
        return *this;
    }


    ~sportscar()  {
        cout << "[sportscar Destructor] topspeed: " << topspeed << " destroyed\n";
    }

   
    void drive() {
        cout << "[sportscar drive] ";
        car::drive();
        cout << " at top speed: " << topspeed << "\n";
    }
};
int main(){
   car a;
   a.drive();
    car b("hyundai","tico",10);
    sportscar c;
    sportscar d("toyota","lexus",10,100);
    return 0;
}