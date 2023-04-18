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
    deque<string> works;  // ����� ����� ������� �����.

    int n = 0;            // ���-�� ������� �����.
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string surname;
        string pos;
        cin >> surname >> pos;      //������ ��� � ������� ����� ������.

        for (char& c : pos)
            c = to_lowercase(c);      //�������� ������ �������� ��������� ����.

        if (pos == "bottom")       //� ������ ������� ��������� ����� � ���������.
        {
            works.push_back(surname);
        }
        else
        {
            works.push_front(surname);
        }
    }

    int count = 0;        // ��� ������ ����� ����� ����� ���������� ������.
    cin >> count;

    for (int i = 0; i < count; ++i)
    {
        int turn = 0;                       // �������
        cin >> turn;
        cout << works[turn - 1] << endl;       // ����� ��� �����������.
    }
}

void ZadanieTwo()
{
    map<int, set<string>> index;    // set ��������� ������� � ���������.  map<L1, L2> L1- ����. L2 - ��������

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string word;
        int page;
        cin >> word >> page;          // ����� ����� � ��������

        index[page].insert(word);     // �������� ����. ����� - ��������
    }

    for (const auto& i : index)
    {
        cout << i.first;             // ������� ��������
        for (const auto& word : i.second)
            cout << " " << word;      // ������� �����

        cout << endl;;
    }

}



int main()
{
    //ZadanieOne();
    //ZadanieTwo();

    return 0;

}