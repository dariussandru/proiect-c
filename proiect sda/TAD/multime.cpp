#include <iostream>
#include "multime.h"
using namespace std;

Multime::Multime()
{
	this->capacitate = 10;
	this->elems = new TElem[capacitate];
	this->nr_elem = 0;
	cout << "Multimea a fost creata!" << endl;
}

void Multime::add(TElem e)
{
	if (nr_elem == capacitate) resize();
	int p = search(e);
	if (elems[p] != e)
	{
		for (int i = nr_elem - 1; i >= p; i--)
			elems[i + 1] = elems[i];
		elems[p] = e;
		nr_elem++;
	}
}

int Multime::search(TElem e)
{
	int i = 0;
	while (i<nr_elem && e>elems[i]) i++;
	return i;
}

bool Multime::exist(TElem e)
{
	for (int i = 0; i < nr_elem; i++)
		if (elems[i] == e) return true;
	return false;
}

int Multime::size()
{
	return nr_elem;
}

int Multime::get_elem(int poz)
{
	if (poz >= 0 && poz < nr_elem)
		return elems[poz];
	return -1;
}

void Multime::resize()
{
	TElem* new_elems = new TElem[2 * capacitate];
	for (int i = 0; i < nr_elem; i++)
		new_elems[i] = elems[i];
	capacitate *= 2;
	delete[] elems;
	elems = new_elems;
}

int Multime::remove(TElem elem)
{
	int poz = search(elem);
	if (elems[poz] == elem)
	{
		for (int i = poz; i < nr_elem - 1; i++)
			elems[i] = elems[i + 1];
		nr_elem--;
	}
	return 0;
}