#pragma once

typedef int TElem;

class Multime {
private:
	TElem* elems;
	int capacitate;
	int nr_elem;
	void resize();

public:
	/// <summary>
	/// constructorul va initializa datele membru
	/// </summary>
	Multime();

	/// <summary>
	/// adauga un element la multime
	/// </summary>
	/// <param name="e"> elementul de adaugat
	///					 prec: 'e' trebuie sa fie de tipul TElem
	///					 post: M'=M+{e} daca elementul nu apartine multimii, altfel nu este adaugat </param>
	void add(TElem e);

	/// <summary>
	/// cauta un element in multimea ordonata
	/// </summary>
	/// <param name="e"> elementul cautat </param>
	/// <returns> returneaza pozitia pe care se poate adauga elementul e in multime </returns>
	int search(TElem e);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="e"></param>
	/// <returns> True daca e apartine multimii, False altfel </returns>
	bool exist(TElem e);

	/// <summary>
	/// 
	/// </summary>
	/// <returns> returneaza numarul de elemente din multime </returns>
	int size();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="poz"></param>
	/// <returns> returneaza elementul de pe pozitia poz </returns>
	int get_elem(int poz);

	/// <summary>
	/// sterge un element din multime
	/// </summary>
	/// <param name="elem"> elementul de sters </param>
	/// <returns> 1 daca s-a sters, 0 daca nu </returns>
	int remove(TElem elem);
};