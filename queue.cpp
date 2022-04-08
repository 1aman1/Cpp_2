#include<queue>
#include<iostream>

using namespace std;

int main() {
  queue<int> Myqueue;

  cout << "is queue empty[0/1] : " << Myqueue.empty() << endl;
  for(int i = 0; i < 4; ++i)
		Myqueue.push(i+1);

  cout << "--*--\n";
  cout << "size : " <<  Myqueue.size() << endl;
  cout << "front : " << Myqueue.front() << endl;
	cout << "rear : " << Myqueue.back() << endl;

  Myqueue.emplace(404);
 
  cout << "--*--\n";
  cout << "size : " << Myqueue.size() << endl;
  cout << "front : " << Myqueue.front() << endl;
	cout << "rear : " << Myqueue.back() << endl;

  Myqueue.pop();
	
  cout << "--*--\n";
  cout << "size : " << Myqueue.size() << endl;
  cout << "front : " << Myqueue.front() << endl;
	cout << "rear : " << Myqueue.back() << endl;

  //	system("pause");
	return 0;
}
 
