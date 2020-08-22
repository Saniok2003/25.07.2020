#include <iostream>
#include <string>
using namespace std;

struct autoo
{
	string name = "";
	int year = 0;
	int price = 0;
	float engineCapacity = 0;
	autoo* next = nullptr;
};
class AutoSalon
{
public:
	bool FindYear(autoo* Head, int NumberItem)
	{
		autoo* ptr;
		ptr = Head;
		while (ptr != nullptr) {
			if (NumberItem == ptr->year)
			{
				return true;
			}
			else ptr = ptr->next;
		}
		return false;
	}
	autoo* AddAuto(autoo* Head, int Number) {
		Number--;
		autoo* NewItem = new(autoo);
		cout << "Year of car production: ";
		cin >> NewItem->year;
		cout << "Name: ";
		cin >> NewItem->name;
		cout << "Price: ";
		cin >> NewItem->price;
		cout << "Engine capacity: ";
		cin >> NewItem->engineCapacity;
		NewItem->next = nullptr;
		if (Head == nullptr)
		{
			Head = NewItem;
		}
		else {
			autoo* Current = Head;
			for (int i = 1; i < Number && Current->next != nullptr; i++)
			{
				Current = Current->next;
			}
			if (Number == 0) {

				NewItem->next = Head;
				Head = NewItem;
			}
			else {
				if (Current->next != nullptr)
				{
					NewItem->next = Current->next;
				}

				Current->next = NewItem;
			}
		}
		return Head;
	}
	void Print(autoo* Head)
	{
		if (Head == nullptr)
		{
			cout << "List is empty!";
		}
		else
		{
			while (Head != nullptr)
			{
				cout << "Name: " << Head->name << "\nYear: " << Head->year << "\nEngine capacity: " 
					<< Head->engineCapacity << "\nPrice: " << Head->price << endl << "~~~" << endl;
				Head = Head->next;
			}
		}
	}
	void Show(autoo* Head)
	{
		cout << "Name: " << Head->name << "\nYear: " << Head->year << "\nEngine capacity: "
			<< Head->engineCapacity << "\nPrice: " << Head->price << endl << "~~~" << endl;
	}
	void Delete(autoo* Head)
	{
		if (Head != NULL)
		{
			Delete(Head->next);
			delete Head;
		}
	}
	void FindName(autoo* Head)
	{
		autoo* ptr = Head;
		string name = "";
		cout << "Input name auto: ";
		cin >> name;
		while (ptr != nullptr)
		{
			if (name == ptr->name)
			{
				Show(ptr);
				return;
			}
			else
			{
				ptr = ptr->next;
			}
		}
		cout << "No such name was found" << endl;
	}
	void FindYear(autoo* Head) {
		autoo* ptr;
		ptr = Head;
		int NumberItem = 0;
		cout << "Input auto year: ";
		cin >> NumberItem;
		while (ptr != NULL)
		{
			if (NumberItem == ptr->year)
			{
				Show(ptr);
				return;
			}
			else ptr = ptr->next;
		}
		cout << "No such year was found" << endl;
	}
};


int main()
{
	AutoSalon tr;
	autoo* Head = nullptr;
	int n = 1;
	int d;
	do {

		cout << "1 - Add auto info to DB" << endl;
		cout << "2 - Show DB" << endl;
		cout << "3 - Show info about auto for year" << endl;
		cout << "4 - Show info about auto for name" << endl;
		cout << "5 - Exit!" << endl;
		cout << "Please select: ";
		cin >> d;
		switch (d)
		{
		case 1:
		{
			Head = tr.AddAuto(Head, n);
			n++;
		}break;
		case 2:
		{
			tr.Print(Head);
		}break;
		case 3:
		{
			tr.FindYear(Head);
		}break;
		case 4:
		{
			tr.FindName(Head);
		}break;
		case 5:
		{
			cout << "Goodbye" << endl;
			tr.Delete(Head);
			exit(0);
		}break;

		default:
			cout << "Error" << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (d != 5);

	return 0;
}