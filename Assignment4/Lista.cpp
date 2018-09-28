#include "Lista.h"
#include <cstdlib>
#include <string>
using namespace std;

int id = 1; // assigns each player a number, important to iterate through the list and compare items from each player on the list
int numOfWords = 0;

Lista::Lista(){
  head = NULL;
  end = NULL;
}

Lista::~Lista(){
  nodePtr list = head;
  if(emptyList() == true){
    cout << " \n List is empty, it cant be deleted..." << endl;
  }
  else{
    while(head->next != NULL){
      head = head->next;
      delete list;
      list = head;
    }
    delete head;
    head = NULL;
    list = NULL;
    cout << "List has been deleted!" << endl;
  }
}

bool Lista::emptyList(){
  if(head == NULL){
    return true;
  }
  else{
    return false;
  }
}

void Lista::addPlayer(int numOfPlayers){
  if(emptyList()){
    id = 1;
  }
  int c = 0;
  string name;
  while(numOfPlayers !=0){

    nodePtr list;
    list = new node;
    cout<<"Name for player: ";
    if(c == 0){ //this if statement prevents names getting chewed by cin.
      cin.ignore();
      c++;
    }
    cin >> name;
    list->nombre = name;
    list->playerNum = id;
    list->next=NULL;
    if(head==NULL){
         head=list;
         head->next=head;
         end=list;
    }
    else{
         list->next = head;
         head = list;
         end->next = head;
    }
    id++;
    numOfWords++;
    numOfPlayers--;
  }
}

void Lista::addAtEnd(int n){
  if(emptyList()){
    id = 1;
  }
  int count = 0;
  while(n !=0){
  nodePtr list;
  list = new node;
  cout << "Name of player: ";
  if(count == 0){ //this if statement prevents names getting chewed by cin.
    cin.ignore();
    count++;
  }
  getline(cin,list->nombre);
  list->playerNum = id;
  list->next=NULL;

 if(head==NULL)
    {
         head=list;
         head->next=head;
         end=list;
    }
 else
    {
      end->next = list;
      list->next = head;
      end = list;
    }
    id++;
    numOfWords++;
    n--;
  }
  keepTrack = id-1;
}

void Lista::showPlayers(){
  nodePtr show;
  show = head;
  if(emptyList()){
    cout << "No players on the list!" << endl;
    return;
  }
  else{
    do {
      cout << "Player: " << show->playerNum << ", " << show->nombre << endl;
      show = show->next;
    } while(show != head);
  }
}

void Lista::searchForPlayer(){
  nodePtr point;
  int num = 0;
  int warning = 0;
  if(emptyList()){
    cout << "List is empty..." << endl;
    return;
  }
  cout << "Enter player number: ";
  cin >> num;

  point = head;
  do {
    if(point->playerNum == num){
      cout << "Player " << point->playerNum << ", " << point->nombre << endl;
      warning = 1;
      return;
    }
    else{
      point = point->next;
    }
  } while(point != head);

  if(warning == 0)
    cout << "Player not found!" << endl;
}

void Lista::deletePlayer(int n){
  if(emptyList()){
    cout << "List is empty..." << endl;
    return;
  }
  nodePtr p1, p2, p3;
  int warning = 0;
  p1 = head;

  do
  {
   if(p1->playerNum == n){
    if(p1 == head){//check if the item to eliminate is at the start of the list
      p2 = head;
      head = head->next;
      p1 = p1->next;
      end->next = head;
      p2->next = NULL;
      if(end->next == NULL)
      {
          head = NULL;
          p1 = NULL;
          delete(p2);
          cout << "Player has been eliminated!" << endl;
          return;
      }
      else
      {
          delete(p2);
          cout << "Player has been eliminated!" << endl;
          return;
      }
    }
   else{
    if(p1 == end){//check if the item to eliminate is at the end of the list
      p2 = p1;
      p1 = p1->next;
      p3->next = p1;
      end = p3;
      p2->next = NULL;
      delete(p2);
      cout << "Player has been eliminated!" << endl;
      return;
    }
    else{
      p2 = p1;
      p1 = p1->next;
      p3->next = p1;
      p2->next = NULL;
      delete(p2);
      cout << "Player has been eliminated!" << endl;
      return;
    }
  }
      warning = 1;
  }
    else{
      p3 = p1;
      p1 = p1->next;
    }
  }while(p1 != head);

  if(warning == 0)
  cout << "Player not found!" << endl;
}

void Lista::game(){
  int count = 0;
  int iterate = 0;
  bool veredict = false;
  string sentence[id];
  nodePtr show, before;
  show = head;
  if(emptyList()){
    cout << "No players on the list!" << endl;
    return;
  }
  else if(keepTrack == 1){
    return;
  }
    do {
      cout << "Player: " << show->playerNum << ", " << show->nombre << endl;
      if(once == 0){
        cout << "Enter a word (If the first person enters more than 2 words, it will be reduced to one): ";
        if(count == 0){
          cin.ignore();
          count++;
        }
        string discard;
        getline(cin,show->palabra,' ');
        getline(cin,discard);

        system("clear");
        sentence[iterate]= show->palabra;
        before = show;
        show = show->next;
        once++;
        iterate++;
      }
      else{
        for(int i = 0; i < iterate;i++){
          cout << "Enter the previous player words: ";
          string word;
          getline(cin,word);
          if(word == sentence[i]){
            veredict =true;
          }
          else{
            veredict = false;
            break;
          }
        }
        if(veredict == true){
          cout << "You passed the condition!" << endl;
          cout << "Now Enter Your Word (You can only add one word): ";
          string discard = "something";
          cin >> show->palabra;
          getline(cin,discard);
          if(discard[0] == ' '){
            int path = show->playerNum;
            system("clear");
            deletePlayer(path);
            keepTrack--;
            show = before->next;

          }
          else{
            system("clear");
            sentence[iterate]= show->palabra;
            before = show;
            show = show->next;
            iterate++;
          }
        }
        else if(veredict == false){
          int path = show->playerNum;
          deletePlayer(path);
          keepTrack--;
          show = before->next;
        }
      }
    } while(keepTrack != 1);
    cout << endl;
    cout << "The winner is: " << show->nombre << endl;
    cout << "The completed sentence by all players was " << '\"';
    for(int i = 0; i <iterate;i++){
      cout << sentence[i] << ' ';
    }
    cout << '\"' << endl;
    deletePlayer(show->playerNum);
    show = NULL;
    before = NULL;
    once =0;
  }
