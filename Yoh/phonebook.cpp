#include <iostream>
#include <vector>
#include <string>
using namespace std;

class book{
    public:
    string name, number, nick;
};
class indexbook{
    public:
    string name, number, nick;
};
void add(vector<book>& namelist);
void search(vector<book>& namelist, vector<book>& bookmark);
void removefunc(vector<book>& namelist, vector<book>& bookmark);
void bookmarklist(vector<book>& bookmark);
int main(){
    book mybook;
    vector<book> namelist;
    vector<book> bookmark;
    while(1){
    cout<<"choose the commands(press number)\n";
    cout<<"===================================\n";
    cout<<"1. ADD\n2. SEARCH\n3. REMOVE\n4. BOOKMARK\n5. EXIT\n";
    cout<<"===================================\n";
    int com;
    cin>>com;
    if(com==1){
        add(namelist);
    }
    else if(com==2){
        search(namelist, bookmark);
    }
    else if(com==3){
        removefunc(namelist,bookmark);
    }
    else if(com==4){
        bookmarklist(bookmark);
    }
    else if(com==5){
        return 0;
    }
    else{
        cout<<"invaild number press enter...\n";
        cin.ignore();
        cin.get();
        system("clear");
    }
}
    return 0;
}
void add(vector<book>&  namelist){
    book mybook;
 cout<<"enter name, number, nickname\n";
        cout<<"name : ";
        cin.ignore();
        getline(cin,mybook.name);
       
        cout<<"number : ";
        getline(cin,mybook.number);
        cout<<"nickname : ";
        getline(cin,mybook.nick);
        namelist.push_back(mybook);
        cout<<"saving... press enter...\n";
        cin.get();
        system("clear");
}
void search(vector<book>& namelist,vector<book>& bookmark){
    if(namelist.empty()){
            cout<<"the phonebook is empty.. press enter...\n";
            cin.ignore();
            cin.get();
            system("clear");
        }
        else{
            size_t n=namelist.size();
            //cout<<n;
            cout<<"phone book list\n";
            cout<<"-------------------\n";
            for(size_t i=0; i<n; i++){
                cout<<i+1<<". "<<namelist[i].name<<"\n";
            }
            cout<<"-------------------\n";
            cout<<"choose index display details of the contact\n";
            int num;
            cin>>num;
            cout<<"name: "<<namelist[num-1].name<<"\n";
            cout<<"number: "<<namelist[num-1].number<<"\n";
            cout<<"nickname: "<<namelist[num-1].nick<<"\n\n";
            cout<<"Would you like to add to bookmarks this index?(yes or no)\n";
            string com;
            cin>>com;
            if(com=="yes"|| com=="YES"){
                bookmark.push_back(namelist[num-1]);
                cout<<"save complete. press enter...";
                cin.ignore();
                cin.get();
                system("clear");
            }
        }

    }
void removefunc(vector<book>& namelist, vector<book>& bookmark){
    size_t n= namelist.size();
    size_t m= bookmark.size();
    if(namelist.empty()){
            cout<<"the phonebook is empty.. press enter...\n";
            cin.ignore();
            cin.get();
            system("clear");
        }
    else{
    cout<<"which one do you want to remove?(press number)\n";
            cout<<"-------------------\n";
            for(size_t i=0; i<n; i++){
                cout<<i+1<<". "<<namelist[i].name<<"\n";
            }
            cout<<"-------------------\n";
            int num;
            cin>>num;
            book removed = namelist[num-1];
            if(num>0 && num<=n){
                namelist.erase(namelist.begin() + (num - 1));
            
            for(int i=0; i<m; i++){
                if(removed.name==bookmark[i].name){
                    bookmark.erase(bookmark.begin()+i);
                    break;
                }
            }
            cout<<"remove complete press enter...\n";
            cin.ignore();
            cin.get();
        }
        else{
            cout<<"invaild number press enter...\n";
            cin.ignore();
            cin.get();
            
        }
        system("clear");
        }
}
void bookmarklist(vector<book>& bookmarklist){
    size_t n= bookmarklist.size();
    if(bookmarklist.empty()){
            cout<<"the bookmark is empty.. press enter...\n";
            cin.ignore();
            cin.get();
            system("clear");
        }
    else{
    cout<<"-------------------\n";
    for(size_t i=0; i<n; i++){
                cout<<i+1<<". "<<bookmarklist[i].name<<"\n";
            }
    cout<<"-------------------\n";
    cout<<"choose index display details of the contact\n";
            int num;
            cin>>num;
            cout<<"name: "<<bookmarklist[num-1].name<<"\n";
            cout<<"number: "<<bookmarklist[num-1].number<<"\n";
            cout<<"nickname: "<<bookmarklist[num-1].nick<<"\n";
            cout<<"press enter...";
            cin.ignore();
            cin.get();
            system("clear");
        }
    }