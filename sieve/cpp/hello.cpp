#include <iostream>
#include <vector>
#include <list>

using namespace std;
void doit() {
  vector<string> SS;

  SS.push_back("The number is 10");
  SS.push_back("The number is 20");
  SS.push_back("The number is 30");

  cout << "Loop by index:" << endl;

  int ii;

  for (ii=0; ii < SS.size(); ii++) {
    cout << SS[ii] << endl;
  }

  cout << "Constant Iterator:" << endl;

  vector<string>::const_iterator cii;

  for (cii=SS.begin(); cii != SS.end(); cii++) {
    cout << *cii << endl;
  }

  cout << "Reverse Iterator:" << endl;  
  vector<string>::reverse_iterator rii;

  for (rii=SS.rbegin(); rii != SS.rend(); rii++) {
    cout << *rii << endl;
  }

  cout << "Simple output:" << endl;
  cout << SS.size() << endl;
  cout << SS[2] << endl;
  
  swap(SS[0], SS[2]);
  cout << SS[2] << endl;


}


void dolist() {

  list<int> L;
  L.push_back(0);
  L.push_front(0);
  L.insert(++L.begin(), 2);
  
  L.push_back(5);
  L.push_back(6);

  cout << "List iterator:" << endl;
  list<int>::iterator i;

  for (i=L.begin(); i!= L.end(); i++)
    cout << *i << endl;
}


void dov() {
  vector<int> v {34,23};
  cout << "vector:" << endl;
  cout << *(begin(v)) << endl;
  cout << "Size:" ;
  cout << v.size() << endl;
}


int main() {

  list<char> lst;

  for (char chs='A'; chs <= 'Z'; ++chs)
    lst.push_back(chs);


  list<char>::const_iterator pos;
  for(pos = lst.begin(); pos != lst.end(); ++pos)
    cout << *pos<<' ';

  cout <<endl;

  doit();

  dolist();

  dov();
}



