#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;
class MyClass {
public:
	int n;
	MyClass(int m) :n(m) { }
	void f() { cout << n << " func." << endl; }
};

class MyAny {
public:
	class base {
	public:
		virtual ~base() {}
	};

	template<class T>
	class MyValue :public base {
	public:
		T * v;
		MyValue(const T &_v) {
			v = new T(_v);
		}
		~MyValue() {
			delete v;
		}
	};
	base *content;

	template <class T>
	MyAny(const T &_v) :content(new MyValue<T>(_v)) {}
	~MyAny() {
	}
};
template <class T>
T MyAny_cast(const MyAny& m)
{
	return *(static_cast < MyAny::MyValue<T>* > (m.content))->v;
}
template <class T>
T* MyAny_cast(MyAny* m)
{
	MyAny::MyValue<T> *p;
	p = (dynamic_cast < MyAny::MyValue<T>* > (m->content));
	if (p)
		return p->v;
	return NULL;
}

int main()
{
	while (true) {
		int n;
		string s;
		cin >> n >> s;
		if (n == 0)
			break;
		MyAny a = n;
		cout << MyAny_cast<int>(a) << endl;
		a = s;
		cout << MyAny_cast<string>(a) << endl;
		a = MyClass(n + 1);
		MyAny b = n + 2;
		MyAny * p = new MyAny(MyClass(n + 3));
		MyAny c = MyClass(n + 4);
		c = *p;
		b = *p;
		delete p;
		MyAny d = b;
		MyAny_cast<MyClass>(&a)->f();
		MyAny_cast<MyClass>(&b)->f();
		MyAny_cast<MyClass>(&c)->f();
		MyAny_cast<MyClass>(&d)->f();
		c = s + "OK";
		cout << MyAny_cast<string>(c) << endl;
		int * pi = MyAny_cast<int> (&c);
		if (pi == NULL)
			cout << "not a int" << endl;
		else
			cout << "the int is " << *pi << endl;
		string * ps = MyAny_cast<string> (&c);
		if (ps == NULL)
			cout << "not a string" << endl;
		else
			cout << "the string is " << *ps << endl;
	}
}