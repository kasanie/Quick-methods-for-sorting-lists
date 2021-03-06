using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <random>
#include <iostream>
#include <functional>
#include <list>
#include <cassert>

#pragma region Methods
ostream& operator<<(ostream& ostr, const list<int>& list) // переопределение вывода списка
{
    for (auto& i : list) {
        ostr << " " << i;
    }
    return ostr;
}
list<int> createIncreasingList(int count)
{
    list<int> st;
    cout << "\nIncreasing list:\n";
    for (int i = 1; i <= count; i++)
    {
        cout << i << " ";
        st.push_back(i);
    }
    cout << "\n";
    return st;
}
list<int> createDecreasingList(int count)
{
    list<int> st;
    cout << "\nDecreasing list:\n";
    for (int i = count; i >=1 ; i--)
    {
        cout << i << " ";
        st.push_back(i);
    }
    cout << "\n";
    return st;
}
list<int> createRandomList(int count)
{
    list<int> st;
    cout << "\nRandom list:\n";
    for (int i = 1; i <= count ; i++)
    {
        int n = rand() % count + 1;
        cout << n << " ";
        st.push_back(n);
    }
    cout << "\n";
    return st;
}
void checksums(list<int>& list1, list<int>& list2, list<int>& list3) //проверка контрольной суммы первоначального и отсортированного листа
{
    int sum1 = 0;
    for_each(list1.begin(), list1.end(), [&](int n) {
        sum1 += n;
        });
    int sum2 = 0;
    for_each(list2.begin(), list2.end(), [&](int n) {
        sum2 += n;
        });
    int sum3 = 0;
    for_each(list3.begin(), list3.end(), [&](int n) {
        sum3 += n;
        });
    if (sum1 + sum2 == sum3)
    {
        printf("Checksums are equal\n");
    }
    else
    {
        printf("\nChecksums are not equal\n");
    }
}
void checkseries(list<int>& list,int size) //проверка числа серий в отсортированном листе, она должна быть равна 1
{
    
    std::list <int> copy = list;
    int series = 1;
    for (int i=0; i < size-1; i++)
    {
        int firsttemp = copy.front();
        copy.pop_front();
        int secondtemp = copy.front();
        if (firsttemp > secondtemp)
        {
            series += 1;
        }
    }
    if (series == 1)
    {
        printf("The number of series in the array: 1. The array is sorted");
        printf("\n");
    }
    else
    {
        printf("The number of series in the array: %d. The array is not sorted", series);
        printf("\n");
    }
}
void split(list<int>& list1, list<int>& list2)
{
    list2.splice(list2.begin(),
        list1,
        list1.begin(),
        next(list1.begin(), list1.size() / 2));

}
double logbase(double a, double base)
{
    return log(a) / log(base);
}
void computeMC(double size)
{
    double result;
    result = logbase(size, 2);
    double mc = result * size*2;
    printf("M + C = %lf \n", mc);
}
#pragma endregion


int main()
{
#pragma region 100
    list<int> part;
    list<int> res;

    list<int> inc = createIncreasingList(100);
    split(inc, part);
    merge(part.begin(), part.end(), inc.begin(), inc.end(), back_inserter(res)); // слияние
    checksums(inc, part, res);
    checkseries(res, 100);
    cout << "Sorted list: " << res << "\n";  // печать элементов cортрованного списка
    computeMC(100);
    inc.clear();part.clear(); res.clear();
    
    list<int> dec = createDecreasingList(100);
    split(dec, part);
    dec.sort();part.sort(); // встроенный метод сортировки со сложностью n log n (по сути тот же merge sort только разделенный и упрощенный, сложность алгоритмов одинаковая, я решил использовать этот путь, так как это более удобно для класса list)
    merge(part.begin(), part.end(), dec.begin(), dec.end(), back_inserter(res));
    checksums(dec, part, res);
    checkseries(res, 100);
    cout << "Sorted list: " << res << "\n";
    computeMC(100);
    dec.clear();part.clear(); res.clear();

    list<int> rnd = createRandomList(100);
    split(rnd, part);
    rnd.sort();part.sort();
    merge(part.begin(), part.end(), rnd.begin(), rnd.end(), back_inserter(res));
    checksums(rnd, part, res);
    checkseries(res, 100);
    cout << "Sorted list: " << res << "\n";
    computeMC(100);
    rnd.clear();part.clear(); res.clear();
#pragma endregion
#pragma region 200
    inc = createIncreasingList(200);
    split(inc, part);
    merge(part.begin(), part.end(), inc.begin(), inc.end(), back_inserter(res));
    checksums(inc, part, res);
    checkseries(res, 200);
    cout << "Sorted list: " << res << "\n";
    computeMC(200);
    inc.clear();part.clear(); res.clear();

    dec = createDecreasingList(200);
    split(dec, part);
    dec.sort();part.sort();
    merge(part.begin(), part.end(), dec.begin(), dec.end(), back_inserter(res));
    checksums(dec, part, res);
    checkseries(res, 200);
    cout << "Sorted list: " << res << "\n";
    computeMC(200);
    dec.clear();part.clear(); res.clear();

    rnd = createRandomList(200);
    split(rnd, part);
    rnd.sort();part.sort();
    merge(part.begin(), part.end(), rnd.begin(), rnd.end(), back_inserter(res));
    checksums(rnd, part, res);
    checkseries(res, 200);
    cout << "Sorted list: " << res << "\n";
    computeMC(200);
    rnd.clear();part.clear(); res.clear();
#pragma endregion
#pragma region 300
    inc = createIncreasingList(300);
    split(inc, part);
    merge(part.begin(), part.end(), inc.begin(), inc.end(), back_inserter(res));
    checksums(inc, part, res);
    checkseries(res, 300);
    cout << "Sorted list: " << res << "\n";
    computeMC(300);
    inc.clear();part.clear(); res.clear();

    dec = createDecreasingList(300);
    split(dec, part);
    dec.sort();part.sort();
    merge(part.begin(), part.end(), dec.begin(), dec.end(), back_inserter(res));
    checksums(dec, part, res);
    checkseries(res, 300);
    cout << "Sorted list: " << res << "\n";
    computeMC(300);
    dec.clear();part.clear(); res.clear();

    rnd = createRandomList(300);
    split(rnd, part);
    rnd.sort();part.sort();
    merge(part.begin(), part.end(), rnd.begin(), rnd.end(), back_inserter(res));
    checksums(rnd, part, res);
    checkseries(res, 300);
    cout << "Sorted list: " << res << "\n";
    computeMC(300);
    rnd.clear();part.clear(); res.clear();
#pragma endregion
#pragma region 400
    inc = createIncreasingList(400);
    split(inc, part);
    merge(part.begin(), part.end(), inc.begin(), inc.end(), back_inserter(res));
    checksums(inc, part, res);
    checkseries(res, 400);
    cout << "Sorted list: " << res << "\n";
    computeMC(400);
    inc.clear();part.clear(); res.clear();

    dec = createDecreasingList(400);
    split(dec, part);
    dec.sort();part.sort();
    merge(part.begin(), part.end(), dec.begin(), dec.end(), back_inserter(res));
    checksums(dec, part, res);
    checkseries(res, 400);
    cout << "Sorted list: " << res << "\n";
    computeMC(400);
    dec.clear();part.clear(); res.clear();

    rnd = createRandomList(400);
    split(rnd, part);
    rnd.sort();part.sort();
    merge(part.begin(), part.end(), rnd.begin(), rnd.end(), back_inserter(res));
    checksums(rnd, part, res);
    checkseries(res, 400);
    cout << "Sorted list: " << res << "\n";
    computeMC(400);
    rnd.clear();part.clear(); res.clear();
#pragma endregion
#pragma region 500
    inc = createIncreasingList(500);
    split(inc, part);
    merge(part.begin(), part.end(), inc.begin(), inc.end(), back_inserter(res));
    checksums(inc, part, res);
    checkseries(res, 500);
    cout << "Sorted list: " << res << "\n";
    computeMC(500);
    inc.clear();part.clear(); res.clear();

    dec = createDecreasingList(500);
    split(dec, part);
    dec.sort();part.sort();
    merge(part.begin(), part.end(), dec.begin(), dec.end(), back_inserter(res));
    checksums(dec, part, res);
    checkseries(res, 500);
    cout << "Sorted list: " << res << "\n";
    computeMC(500);
    dec.clear();part.clear(); res.clear();

    rnd = createRandomList(500);
    split(rnd, part);
    rnd.sort();part.sort();
    merge(part.begin(), part.end(), rnd.begin(), rnd.end(), back_inserter(res));
    checksums(rnd, part, res);
    checkseries(res, 500);
    cout << "Sorted list: " << res << "\n";
    computeMC(500);
    rnd.clear();part.clear(); res.clear();
#pragma endregion
}
