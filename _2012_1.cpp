#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

void read(int& n, int e[], int s[], int pradinis_penketukas[]);
void write(int n, int e[], int s[], int pradinis_penketukas[]);
int didz(int arr[], int n);

int main()
{
    int n;
    int e[99] = { 0 }; // zaideju laikas eikleteleje
    int s[99] = { 0 }; // zaideju laikas ant suoliuko
    int pradinis_penketukas[99] = { 0 };
    read(n, e, s, pradinis_penketukas);
    write(n, e, s, pradinis_penketukas);
    return 0;
}

void read(int& n, int e[], int s[], int pradinis_penketukas[])
{
    ifstream duom("Duomenys.txt");
    duom >> n;
    for (size_t i = 0; i < n; i++)
    {
        int k, t, temp;
        duom >> k >> t;
        for (size_t j = 0; j < t; j++)
        {
            duom >> temp;
            if (temp < 0)
            {
                s[k] -= temp;
            }
            else
            {
                e[k] += temp;
            }
            if (temp > 0 && pradinis_penketukas[k] == 0)
            {
                pradinis_penketukas[k] = 1;
            }
            else if (pradinis_penketukas[k] == 0)
            {
                pradinis_penketukas[k] = -1;
            }
        }
    }
}

void write(int n, int e[], int s[], int pradinis_penketukas[])
{
    ofstream rez("Rezultatai.txt");
    int temp = 99;
    for (size_t i = 0; i < temp ; i++)
    {
        if (pradinis_penketukas[i] == 1)
        {
            rez << i << ' ';
        }
    }
    rez << '\n' << didz(e, temp) << ' ' << e[didz(e, temp)] << '\n';
    rez << didz(s, temp) << ' ' << s[didz(s, temp)];
}

int didz(int arr[], int n)
{
    int x = 0;
    int y = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (x<arr[i])
        {
            x = arr[i];
            y = i;
        }
    }
    return y;
}   