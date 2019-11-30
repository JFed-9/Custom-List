#include <string>
#include <iostream>

using namespace std;

#define func [&]()

template <typename T>
class list {
public:
	list();
	T at(int index) { if (index < s) { list* x = this; while (index--) x = x->next; return x->value; } else { throw out_of_range("Could not find that element"); } }
	void insert(unsigned int a, T el) { if (s == 0) { value = el;s++;return; } a-=2; list* x = this; while (a--) x = x->next; list<T>* n = new list<T>();n->value = el; n->next = x->next; x->next = n; s++; }
	void push_back(T el) { if (s == 0) { value = el;s++;return; }list<T>* x = this; while (x->next != 0) x = x->next; x->next = new list<T>();x->next->value = el; s++; }
	void push_front(T el) { if (s == 0) { value = el;s++;return; }list<T>* n = new list<T>();n->value = value;n->next = next;value = el;next = n;s++;}
	unsigned int size() { return s; }
	void clear() { if (next == 0) return; next->clear(); delete next; next = 0; s = 0; }
private:
	T value;
	list<T>* next;
	int s;
};
template <typename T>
list<T>::list() : value(T()), next(0), s(0) {}
class el {
public:
	el() :x(-1), y(false) {}
	el(int q, bool w) :x(q), y(w) {}
	int x;
	bool y;
};

template<typename Callable>
void dispTest(string test, Callable f)
{
	for (int i = 0; i < floor((double)(26 - test.length()) / 2);i++) cout << "*";
	cout << "      " << test << "      ";
	for (int i = 0; i < ceil((double)(26 - test.length()) / 2);i++) cout << "*";
	cout << "\n";
	f();
	cout << "**************************************\n";
}

int main(int argc, char* argv[])
{
	dispTest("Test Custom Objects", func {
		list<el> mylist;
		for (unsigned int i = 0; i < 15; i++) if (rand() % 2 == 1) mylist.push_back(el(rand() % 100, (rand() % 2 == 1))); else mylist.push_front(el(rand() % 100, (rand() % 2 == 1)));
		mylist.insert(5, el(150, true));
		for (unsigned int i = 0; i < mylist.size(); i++) cout << mylist.at(i).x << ": " << ((mylist.at(i).y) ? "True" : "False") << "\n";
		cout << "\n";
		mylist.clear();
		for (unsigned int i = 0; i < mylist.size(); i++) cout << mylist.at(i).x << ": " << ((mylist.at(i).y) ? "True" : "False") << "\n";
	});
	dispTest("TEST STRING", func {
		list<string> mylist;
		for (unsigned int i = 0; i < 10; i++) mylist.push_back(to_string(i + 1) + "Hello" + to_string(10 - i));
		for (unsigned int i = 0; i < mylist.size(); i++) cout << mylist.at(i) << "\n";
		mylist.clear();
		for (unsigned int i = 0; i < mylist.size(); i++) cout << mylist.at(i) << "\n";
	});
	dispTest("TEST ERROR", func {
		list<int> mylist;
		int max = 10;
		for (unsigned int i = 0; i < max; i++) mylist.push_back(i);
		try { cout << mylist.at(max); }
		catch (out_of_range e) { cout << "Encountered an error, " << max << " is not a valid reference\n"; }
		mylist.clear();
	});
	return 0;
}