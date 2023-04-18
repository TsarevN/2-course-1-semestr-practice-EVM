#include <iostream> 
#include <deque> 
#include <string> 
#include <map> 
#include <set> 

using namespace std;

char to_lowercase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;

    return c;
}

void ZadanieOne()
{
    deque<string> works;  // Здесь будем хранить имена.

    int n = 0;            // кол-во сданных работ.
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string surname;
        string pos;
        cin >> surname >> pos;      //Вводим имя и вариант сдачи работы.

        for (char& c : pos)
            c = to_lowercase(c);      //избегаем случая введения заглавных букв.

        if (pos == "bottom")       //в нужном порядке вставляем имена в контейнер.
        {
            works.push_back(surname);
        }
        else
        {
            works.push_front(surname);
        }
    }

    int count = 0;        // для какого числа работ нужно определить автора.
    cin >> count;

    for (int i = 0; i < count; ++i)
    {
        int turn = 0;                       // очередь
        cin >> turn;
        cout << works[turn - 1] << endl;       // имена уже упорядочены.
    }
}

void ZadanieTwo()
{
    map<int, set<string>> index;    // set исключает повторы и сортирует.  map<L1, L2> L1- ключ. L2 - значение

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string word;
        int page;
        cin >> word >> page;          // пишем слово и страницу

        index[page].insert(word);     // страница ключ. слово - значение
    }

    for (const auto& i : index)
    {
        cout << i.first;             // выводим страницу
        for (const auto& word : i.second)
            cout << " " << word;      // выводим слово

        cout << endl;;
    }

}



int main()
{
    //ZadanieOne();
    //ZadanieTwo();

    return 0;

}