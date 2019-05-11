#include "Assignment6.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

BubbleSort::BubbleSort()
{}

BubbleSort::BubbleSort(double g)
{}

void BubbleSort::runBubbleSort(double array[], int n)
{
  for (int i = 0; i < n-1; i++)
  {
    for (int j = 0; j < n-i-1; j++)
    {
      if (array[j] > array[j+1])
      {
        swap(array[j], array[j+1]);
      }
    }
  }
}


SelectionSort::SelectionSort()
{}

SelectionSort::SelectionSort(double g)
{}

void SelectionSort::runSelectionSort(double array[], int n)
{
  for (int i = 0; i < n-1; i++)
  {
    int minIndex = i;
    for (int j = i+1; j < n; j++)
    {
      if (array[j] < array[minIndex])
      {
        minIndex = j;
      }
    }
    swap(array[minIndex], array[i]);
  }

}


InsertionSort::InsertionSort()
{}

InsertionSort::InsertionSort(double g)
{}

void InsertionSort::runInsertionSort(double array[], int n)
{
  for (int i = 1; i < n; i++)
  {
      int key = array[i];
      int j = i - 1;

      while (j >= 0 && array[j] > key)
      {
          array[j + 1] = array[j];
          j = j - 1;
      }
      array[j + 1] = key;
    }
}


QuickSort::QuickSort()
{}

QuickSort::QuickSort(double g)
{}

int QuickSort::partition (double array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void QuickSort::runQuickSort(double array[], int low, int high)
{
  if (low < high)
    {
        int partitionIndex = partition(array, low, high);
        runQuickSort(array, low, partitionIndex - 1);
        runQuickSort(array, partitionIndex + 1, high);
    }
}


Simulator::Simulator()
{
  answer = "";
}

Simulator::Simulator(string filename)
{
  answer = filename;
}

void Simulator::Run()
{
  cout << "What is the name of the file?" << endl;
  cin >> answer;

  ifstream myFile (answer);
  if (myFile)
  {
    string firstLine;
    getline (myFile, firstLine);
    length = stoi(firstLine);
  }

  double array[length];
  double array2[length];
  double array3[length];
  double array4[length];

  if (myFile)
  {
    for(int i = 0; i < length; ++i)
    {
      myFile >> array[i];
    }
  }

  for(int i = 0; i < length; ++i)
  {
    array2[i] = array[i];
    array3[i] = array[i];
    array4[i] = array[i];
  }

  BubbleSort bubble;
  SelectionSort select;
  InsertionSort insert;
  QuickSort quick;

  int n = sizeof(array)/sizeof(array[0]);

  //BubbleSort
  auto start = high_resolution_clock::now();
  bubble.runBubbleSort(array, n);
  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);

  cout << "" << endl;
  cout << "BubbleSort: " << endl;
  cout << "Time taken by function: "
           << duration.count() << " microseconds" << endl;
  cout << "" << endl;

  //SelectionSort
  start = high_resolution_clock::now();
  select.runSelectionSort(array2, n);
  stop = high_resolution_clock::now();

  duration = duration_cast<microseconds>(stop - start);

  cout << "SelectionSort: " << endl;
  cout << "Time taken by function: "
          << duration.count() << " microseconds" << endl;
  cout << "" << endl;

  //InsertionSort
  start = high_resolution_clock::now();
  insert.runInsertionSort(array3, n);
  stop = high_resolution_clock::now();

  duration = duration_cast<microseconds>(stop - start);

  cout << "InsertionSort: " << endl;
  cout << "Time taken by function: "
           << duration.count() << " microseconds" << endl;
  cout << "" << endl;

  //QuickSort
  start = high_resolution_clock::now();
  quick.runQuickSort(array4, 0, n-1);
  stop = high_resolution_clock::now();

  duration = duration_cast<microseconds>(stop - start);

  cout << "QuickSort: " << endl;
  cout << "Time taken by function: "
           << duration.count() << " microseconds" << endl;
  cout << "" << endl;
}
