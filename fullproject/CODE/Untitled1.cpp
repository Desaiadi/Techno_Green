#include<iostream>
using namespace std;

int main()
{

int* p = new int(10);
int* q =new int(20);
int* r = p;
p=q;
delete p;
delete r;
return 0;
	
}
