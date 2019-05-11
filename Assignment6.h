#include <iostream>

using namespace std;

class BubbleSort
{
  public:
    BubbleSort();
    BubbleSort(double g);
    void runBubbleSort(double array[], int n);
};

class SelectionSort
{
  public:
    SelectionSort();
    SelectionSort(double g);
    void runSelectionSort(double array[], int n);
    void switchNumbersS(int num1, int num2);
};

class InsertionSort
{
  public:
    InsertionSort();
    InsertionSort(double g);
    void runInsertionSort(double array[], int n);
};

class QuickSort
{
  public:
    QuickSort();
    QuickSort(double g);
    void runQuickSort(double array[], int low, int high);
    int partition (double array[], int low, int high);
};

class Simulator
{
  public:
    Simulator();
    Simulator(string filename);
    void Run();
    string answer;
    int length;
};
