#include <string>

using namespace std;

class MinHeap
{
public:

    int current_length;
    int *heap_arr;
    int heap_size;
    MinHeap(); //Constructor
    ~MinHeap();

    void insertKey(int k);

    void sift_down(int index);

    int parent(int n);

    int leftChild(int n);

    int rightChild(int n);

    int getMin();

    void swap(int *x, int *y);

    int get_size();

    void extract();

};

#include <iostream>
#include <string>
#include <numeric>
#include <math.h>
#include <stdexcept>

using namespace std;

MinHeap::MinHeap()
{
    heap_arr = new int[10];
    current_length = 0;
    heap_size = 10;
}

MinHeap::~MinHeap()
{
    delete[] heap_arr;
}


int MinHeap::parent(int n)
{
    int cell = (n - 1) / 2;
    if (cell < 0 || cell >= n) return -1;
    return cell;
}  // index of parent

int MinHeap::leftChild(int n)
{
    int cell = n * 2 + 1;
    if (cell >= current_length || cell <= n) return -1;
    return cell;
}  // index of leftChild

int MinHeap::rightChild(int n)
{
    int cell = n * 2 + 2;
    if (cell >= current_length || cell <= n) return -1;
    return cell;

}  // index of rightChild

void MinHeap::swap(int *x, int *y){
    int temporary = *x;
    *x = *y;
    *y = temporary;
}

void MinHeap::insertKey(int k)
{
    if (heap_size == current_length) // Avoid overflow
    {
        int *tempora = new int[2*heap_size];
        heap_size *= 2;

        for(int i = 0; i < heap_size; i++)
        {
            tempora[i] = heap_arr[i];
        }

        delete[] heap_arr;
        heap_arr = tempora;
    }

    int i = current_length;
    heap_arr[i] = k;

    while (i != 0 && heap_arr[parent(i)] > heap_arr[i])   // Fix the minHeap property
    {
       swap(&heap_arr[i], &heap_arr[parent(i)]);
       i = parent(i);
    }
    current_length++;
}


int MinHeap::getMin()
{
    return heap_arr[0];
}


// shifting down
void MinHeap::sift_down(int index)
{
    while (true)
    {
        int left_index = leftChild(index), right_index = rightChild(index);

        // έχει και αριστερό και δεξί παιδί
        if (left_index != -1 && right_index != -1)
        {
            int min_index;
            if (heap_arr[left_index] < heap_arr[right_index] || heap_arr[left_index] == heap_arr[right_index])
            {
                min_index = left_index;
            }
            else {
                min_index = right_index;
            }

            if (heap_arr[min_index] < heap_arr[index])
            {
                swap(&heap_arr[index], &heap_arr[min_index]);
                index = min_index;
            }
            else {
                break;
            }
        }

            // only left child
        else if (left_index != -1)
        {
            if (heap_arr[left_index] < heap_arr[index])
            {
                swap(&heap_arr[index], &heap_arr[left_index]);
                index = left_index;
            }
            else {
                break;
            }
        }

            // only right child
        else if (right_index != -1)
        {
            if (heap_arr[right_index] < heap_arr[index])
            {
                swap(&heap_arr[index], &heap_arr[right_index]);
                index = right_index;
            }
            else {
                break;
            }
        }

            // no child
        else {
            break;
        }
    }
}


int MinHeap::get_size()
{
    return current_length;
}

void MinHeap::extract(){
    if (current_length == 0) throw runtime_error("Esta vacio.");
    heap_arr[0] = heap_arr[current_length - 1];
    current_length--;
    sift_down(0);
}
