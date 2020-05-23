// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "string.h"
#include <cstring>

using namespace std;

template <typename a, typename b>
class ApplicationDevelopment {
public:
	ApplicationDevelopment(); // Конструктор по умолчанию
	ApplicationDevelopment(const a * nameVal, const a * versionVal, b costVal, const a * platformVal, const a * languageVal); // Конструктор со всеми параметрами
	ApplicationDevelopment<a, b>(const ApplicationDevelopment<a, b> &val); // Копирующий конструктор
	~ApplicationDevelopment(); // Деструктор
	ApplicationDevelopment operator +(ApplicationDevelopment<a, b> val); // Функциия суммы (перегрузка оператора +)
	void operator =(ApplicationDevelopment<a, b> &val); // Функция присваивания (перегрузка оператора =)
	void print(); // Функция вывода информации об объекте
private:
	a * name;
	a * version;
	b cost;
	a * platform;
	a * language;
};

//конструктор по умолчанию
template <typename a, typename b>
ApplicationDevelopment<a, b>::ApplicationDevelopment() {
	cost = 0;
	name = new a[7];
	strcpy_s(name, 7, "Noname");
	version = new a[7];
	strcpy_s(version,7, "Noname");
	platform = new a[7];
	strcpy_s(platform,7, "Noname");
	language = new a[7];
	strcpy_s(language,7, "Noname");
}

//конструктор с параметрами
template <typename a, typename b>
ApplicationDevelopment<a, b>::ApplicationDevelopment(const a * nameVal, const a * versionVal, b costVal, const a * platformVal, const a * languageVal) {
	cost = costVal;
	name = new char[strlen(nameVal) + 1];
	strcpy_s(name, strlen(nameVal) + 1,nameVal);
	version = new char[strlen(versionVal) + 1];
	strcpy_s(version, strlen(versionVal) + 1, versionVal);
	platform = new char[strlen(platformVal) + 1];
	strcpy_s(platform, strlen(platformVal) + 1, platformVal);
	language = new char[strlen(languageVal) + 1];
	strcpy_s(language, strlen(languageVal) + 1, languageVal);
}

//копирование
template <typename a, typename b>
ApplicationDevelopment<a,b>::ApplicationDevelopment(const ApplicationDevelopment<a, b> &val) {
	cost = val.cost;
	name = new char[strlen(val.name) + 1];
	strcpy_s(name, strlen(val.name) + 1, val.name);
	version = new char[strlen(val.version) + 1];
	strcpy_s(version, strlen(val.version) + 1, val.version);
	platform = new char[strlen(val.platform) + 1];
	strcpy_s(platform, strlen(val.platform) + 1, val.platform);
	language = new char[strlen(val.language) + 1];
	strcpy_s(language, strlen(val.language) + 1,val.language);
}

//деструктор
template <typename a, typename b>
ApplicationDevelopment<a, b>::~ApplicationDevelopment() {
	delete[] name;
	delete[] version;
	delete[] platform;
	delete[] language;
}

//перегузка =
template <typename a, typename b>
void ApplicationDevelopment<a, b>::operator =(ApplicationDevelopment<a, b> &val) {
	cost = val.cost;
	name = new char[strlen(val.name) + 1];
	strcpy_s(name, strlen(val.name) + 1, val.name);
	version = new char[strlen(val.version) + 1];
	strcpy_s(version, strlen(val.version) + 1, val.version);
	platform = new char[strlen(val.platform) + 1];
	strcpy_s(platform, strlen(val.platform) + 1, val.platform);
	language = new char[strlen(val.language) + 1];
	strcpy_s(language, strlen(val.language) + 1, val.language);
}

//перегрузка +
template <typename a, typename b>
ApplicationDevelopment<a, b> ApplicationDevelopment<a, b>::operator +(ApplicationDevelopment<a, b> val) {
	ApplicationDevelopment created;
	created.cost = cost + val.cost;

	created.name = new char[strlen(name) + strlen(val.name) + 8];
	strcpy_s(created.name, strlen(name) + strlen(val.name) + 8, name);
	strcat_s(created.name, strlen(name) + strlen(val.name) + 8, " and ");
	strcat_s(created.name, strlen(name) + strlen(val.name) + 8, val.name);

	created.version = new char[strlen(version) + strlen(val.version) + 8];
	strcpy_s(created.version, strlen(version) + strlen(val.version) + 8, version);
	strcat_s(created.version, strlen(version) + strlen(val.version) + 8, " and ");
	strcat_s(created.version, strlen(version) + strlen(val.version) + 8, val.version);

	created.platform = new char[strlen(platform) + strlen(val.platform) + 8];
	strcpy_s(created.platform, strlen(platform) + strlen(val.platform) + 8, platform);
	strcat_s(created.platform, strlen(platform) + strlen(val.platform) + 8, " and ");
	strcat_s(created.platform, strlen(platform) + strlen(val.platform) + 8, val.platform);

	created.language = new char[strlen(language) + strlen(val.language) + 8];
	strcpy_s(created.language, strlen(language) + strlen(val.language) + 8, language);
	strcat_s(created.language, strlen(language) + strlen(val.language) + 8, " and ");
	strcat_s(created.language, strlen(language) + strlen(val.language) + 8, val.language);

	return(created);
}

template <typename a, typename b>
void ApplicationDevelopment<a, b>::print() {
	cout << "Название: " << name << endl;
	cout << "Версия: " << version << endl;
	cout << "Цена: " << cost << endl;
	cout << "Поддерживается на платформах: " << platform << endl;
	cout << "Поддерживаемые языки программирования: " << language << endl;
}


int main()
{
	setlocale(LC_ALL, "RUS");
	ApplicationDevelopment<char, int> NoName;
	ApplicationDevelopment<char, int> VisualStudio("Visual Studio", "1.1.0", 699, "WinOS", "Ajax, ASP.NET, DHTML, JavaScript, JScript, Visual Basic, Visual C#, Visual C++, Visual F#, XAML");
	ApplicationDevelopment<char, int> NetBeans("NetBeans", "1.1.0", 0, "WinOS", "Java");
	ApplicationDevelopment<char, int> VisualStudio_NetBeans(VisualStudio + NetBeans);
	ApplicationDevelopment<char, int> VisualStudio_2(VisualStudio);
	
	NoName.print();
	cout << endl;
	
	VisualStudio_2.print();
	cout << endl;
	
	VisualStudio_NetBeans.print();
	
	VisualStudio = NetBeans;
	cout << endl;
	VisualStudio.print();
	cout << endl;

	system("pause");
    return 0;
}

