#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if (s) {
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else
			p = NULL;

	}
	~MyString() { if (p) delete[] p; }
	MyString(const MyString &MS) {
		if (MS.p) {
			p = new char[strlen(MS.p) + 1];
			strcpy(p, MS.p);
		}
		else
			p = NULL;
	}
	MyString &operator=(const char *s) {
		if (p) {
			delete[] p;
		}
		if (s) {
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else
			p = NULL;
		return *this;
	}
	MyString &operator=(const MyString &MS)
	{
		if (MS.p) {
			p = new char[strlen(MS.p) + 1];
			strcpy(p, MS.p);
		}
		else
			p = NULL;
		return *this;
	}
	void Copy(const char *s) {
		if (p) {
			delete[] p;
		}
		if (s) {
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else
			p = NULL;
	}
	friend ostream & operator<<(ostream &o, MyString &MS)
	{
		o << MS.p;
		return o;
	}
};
int main()
{
	char w1[200], w2[100];
	while (cin >> w1 >> w2) {
		MyString s1(w1), s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;

	}
}