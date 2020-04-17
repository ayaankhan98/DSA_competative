#include <iostream>
#include <algorithm>

using namespace std;

class maxHeap
{
private:
	int* heapArray;
	int capcaity;
	int heapSize;
public:
	maxHeap(int cap)
	{
		capcaity = cap;
		heapSize = 0;
		heapArray = new int[capcaity];
	}
	int parent(int i)
	{
		return (i - 1) / 2;
	}
	int leftChild(int i)
	{
		return (2 * i) + 1;
	}
	int rightChild(int i)
	{
		return (2 * i) + 2;
	}
	void _insert(int);
	void _delete();
	void _display();
	int _getMax();
	
};

void maxHeap::_display()
{
	int i = 0;
	while (i < heapSize)
	{
		cout << heapArray[i] << "\n";
		i++;
	}
}

int maxHeap::_getMax()
{

	if (heapSize == 0)
	{
		throw empty("Heap is empty");
		return NULL;
	}
	return heapArray[0];
}

void maxHeap::_insert(int data)
{
	// check if there is a possible space in heap or not
	if (heapSize >= capcaity)
	{
		throw overflow_error("Heap Overflow!");
	}

	// insert the new element at the last of the heapArray
	heapSize++;
	int i = heapSize - 1;
	heapArray[i] = data;

	// maintain the heap property by swaping
	while (i !=0 && heapArray[parent(i)] < heapArray[i])
	{
		swap(heapArray[parent(i)], heapArray[i]);
		i = parent(i);
	}
}

void maxHeap::_delete()
{
	if (heapSize == 0)
	{
		throw underflow_error("Heap UnderFlow!");
	}

	// delete the root element of the heap array and put the last element in place of root element
	// that is simply replace the root element and last element
	int i = 0;
	heapSize--;
	heapArray[i] = heapArray[heapSize];

	// maintain the heap property
	int maxChild;
	if (heapArray[leftChild(i)] < heapArray[rightChild(i)])
		maxChild = rightChild(i);
	else
		maxChild = leftChild(i);
	while (i < heapSize && heapArray[i] < heapArray[maxChild])
	{
		swap(heapArray[i], heapArray[maxChild]);
		i = maxChild;
		if (heapArray[leftChild(i)] < heapArray[rightChild(i)])
		maxChild = rightChild(i);
	else
		maxChild = leftChild(i);
	}
}

int main()
{
	maxHeap h(6);
	try
	{
		h._insert(1);
		h._insert(5);
		h._insert(3);
		h._insert(10);
		h._insert(12);
		h._insert(122);
		cout << h._getMax();
		cout << endl;
		h._display();
		h._delete();
		h._delete();
		cout << endl;
		h._display();
		cout << endl;
		cout << h._getMax();
	}
	catch(overflow_error & e)
	{
		cout << e.what() << endl;
	}
	catch (underflow_error & e)
	{
		cout << e.what() << endl;
	}
	return 0;
}