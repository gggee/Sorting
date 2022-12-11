#include <iostream>
#include <algorithm> // для ф-ции std::sort()
#include <time.h>  // time()
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* mas = new int[size];
    int min, max;
    cout << "Enter the minimum. maximum range: ";
    cin >> min >> max;
    if (min > max)
    {
        swap(min, max);
    }

    for (int i = 0; i < size; i++)
    {
        mas[i] = rand() % (max - min + 1) + min;
        //cout << mas[i]<<" ";
    }
    cout << endl;

    cout << "Sort in which direction: " << endl;
    cout << "If 1 - ascending. 2-desc." << endl;
    cout << "3-use the sort() function in ascending order." << endl;
    cout << "4-use the sort() function in descending order." << endl;
    int choise;
    cin >> choise;

    clock_t tStart = clock(); // sort start time - milliseconds, CLOCKS_PER_SEC

    switch (choise)
    {
    case 1:
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j > i; j--)
            {
                if (mas[j - 1] > mas[j])
                {
                    swap(mas[j], mas[j - 1]);
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if (mas[j + 1] > mas[j])
                {
                    swap(mas[j + 1], mas[j]);
                }
            }
        }
        break;
    case 3: // sort() - ascending
        sort(mas, mas + size); 
        break;
    case 4: // sort() - descending
        sort(mas, mas + size,
            [](int e1, int e2) { // unnamed lambda function
                if (e1 > e2) { return true; } // swap(e1,e2)
                else { return false; } // array elements e1,e2 - leave in place, do not exchange
                //return e1 < e2; - the same, one line
            }
        );
        break;
    default:
        cout << "Error. Wrong number selected." << endl;
        break;
    } // switch(choise)
    clock_t tFinish = clock(); 

    /*for (int i = 0; i < size; i++)
    {
      cout << mas[i] << " ";
    }
    cout << endl;*/

    cout << "clock start : " << tStart << " msec" << endl;
    cout << "clock finish: " << tFinish << " msec" << endl;
    cout << "elapsed: " << tFinish - tStart << " msec" << endl;
    cout << "elapsed: "
        << (double)(tFinish - tStart) / CLOCKS_PER_SEC
        << " sec" << endl;

    cin.get(); cin.get();
}
