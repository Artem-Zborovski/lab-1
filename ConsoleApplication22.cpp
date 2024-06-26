#include <iostream>
#include<stdio.h>
#include<list>
#include<algorithm>

using namespace std;
void show(list<int>& a) {
	if (a.size() == 0) {
		cout << "Список пуст" << endl;
	}
	else {
		copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}
bool comp(int l, int r)
{
	if (abs(l % 2) < abs(r % 2)) return true;
	if (abs(l % 2) > abs(r % 2)) return false;
	if (abs(l % 2) == 0 && abs(r % 2) == 0) return l > r;
	if (abs(l % 2) == 1  && abs(r % 2) == 1) return l > r;
	return false;
}
	
int mul(int x,int y) { return (x *y); }

int main() {
	setlocale(LC_ALL, "rus");
	cout << "1.Просмотреть состояние списка" << "\n"
		<< "2.Добавить элемент" << "\n"
		<< "3.Добавить несколько элементов" << "\n"
		<< "4.Удалить элемент" << "\n"
		<< "5.Разделить элементы на две группы, использовать (Sort)" << "\n"
		<< "6.Перемножить поэлементно два списка, использовать алгоритм (transform)" << "\n"
		<< "7.Выход из программы" << "\n";
	list<int> a = { 46,81,-3,98,0,71,231,882,-111 };
	list<int>a2 = { 7,38,0,-22,77,1,28,999,12};
	auto r_begin = a.begin(); auto r_end = a.begin();
	auto r_begin2 = a2.begin(); auto r_end2 = a2.begin();
	char ch;
	auto max_range_start = a.begin();
	auto max_range_end = a.begin();
	auto range_start = a.begin();
	cout << "Выберите операцию:" << endl;
	cin >> ch;
	while (true) {
		switch (ch) {
		case '1':cout << "Лист:" << endl; show(a); break;
		case '2':cout << "Введите число:" << endl; int el; cin >> el; a.push_back(el); break;
		case '3':cout << "Введите количество:" << endl; int kol; cin >> kol; 
			while (kol) {
				cout << "Введите число:" << endl;
				int el2;
				cin >> el2;
				a.push_back(el2);
				kol--;
			}
			break;
		case '4':cout << "Введите позицию:" << endl; int pos; cin >> pos; advance(r_begin, pos); advance(r_end, pos + 1); a.erase(r_begin, r_end); break;
		case '5':a.sort(comp); break;
		case '6':transform(a.begin(), a.end(), a2.begin(), a.begin(), mul); break;
		case '7':cout << "Конец программы."; exit(EXIT_SUCCESS); break;
		default:
			cout << "Ошибка" << endl;
		}
		cout << "Выберите операцию:" << endl;
		cin >> ch;
	}
	return 0;
}

