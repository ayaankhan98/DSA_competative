#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class Hash
{
private:
	int hashTableSize;
	list<int>* table;
public:
	Hash(int tableSize)
	{
		hashTableSize = tableSize;
		table = new list<int>[hashTableSize];
	}
	int hashFunction(int key)
	{
		return key % hashTableSize;
	}
	void insert(int key);
	void del(int key);
	void display();
};

void Hash::insert(int key)
{
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::del(int key)
{
	int index = hashFunction(key);
	for (auto i = table[index].begin(); i != table[index].end(); i++)
	{
		if (*i == key)
		{
			table[index].erase(i);
			break;
		}
	}
}

void Hash::display()
{
	for (int i = 0; i < hashTableSize; i++)
	{
		cout << "--->";
		copy(table[i].cbegin(), table[i].cend(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}

const int SIZE = 5;

int main()
{
	int a[SIZE] = { 12, 15, 17, 38, 132 };
	Hash h(7);
	for (int i = 0; i < SIZE; i++)
		h.insert(a[i]);
	
	h.display();
	
	h.del(12);
	cout << endl << endl;
	h.display();

	return 0;
}