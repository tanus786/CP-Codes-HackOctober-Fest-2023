#include <iostream>
#include <cmath>

struct Heap
{
    int array_size;
    int array[array_size];
    int last_index;
};

// Function to insert data in the heap
void HeapInsert(Heap heap, int value)
{
    if (heap.last_index == heap.array_size - 1) // Checking if the array has enough space to insert the data
    {
        // Increase array size
    }
    heap.last_index = heap.last_index + 1; // Increasing the last_index of the heap to map the next empty place
    heap.array[heap.last_index] = value;   // Inserting the data at the back of the array

    //#Swapping the inserted node up to the heap till it satisfies the max heap property

    int current = heap.last_index;   // Variables to iterate through the loop
    int parent = floor(current / 2); // Storing the parent of the current node in a local variable

    while (parent >= 1 && heap.array[parent] < heap.array[current]) // Loop to iterate traverse to the node to parent to maintain the max heap property
    {

        // Swap Function
        int temp = heap.array[parent];
        heap.array[parent] = heap.array[current];
        heap.array[current] = temp;

        current = parent;            // Changing the iterative varibles
        parent = floor(current / 2); // Changing the parent accoring to the current node
    }
}

// Function to remove the highest priority element from the max heap
int HeapRemoveMax(Heap heap)
{
    if (heap.last_index == 0) // Checking if the heap is empty or not
    {
        return NULL;
    }

    //#Swap out the root for the last element and shrink the heap
    // Swap Function
    int result = heap.array[1];
    heap.array[1] = heap.array[heap.last_index];
    heap.array[heap.last_index] = NULL;

    heap.last_index = heap.last_index - 1; // Changing the last elemt of the heap to mark the new end of the heap

    //#Bubble the new root down
    int i = 1; // Iterative variable

    while (i <= heap.last_index) // Loop to iterate down the heap
    {
        int swap = i;

        if (2 * i <= heap.last_index && heap.array[swap] < heap.array[2 * i]) // Checking if the left child is big or not
        {
            swap = 2 * i;
        }

        if ((2 * i + 1) <= heap.last_index && heap.array[swap] < heap.array[2 * i + 1]) // Checking if the right child is big or not
        {
            swap = 2 * i + 1;
        }

        // Check if we have to swap the new root node or not
        if (i != swap)
        {
            // Swap Function
            int temp = heap.array[i];
            heap.array[i] = heap.array[swap];
            heap.array[swap] = temp;
            i = swap;
        }
        else
        {
            break;
        }
    }

    return result; // Returning the highest prioro=ity element from the max heap
}

// Function to change the priority of the particular node
void UpdateValue(Heap heap, int index, int value)
{
    int old_value = heap.array[index]; // Storing the new priority
    heap.array[index] = value;         // Changing the new priority

    if (old_value < value)
    {
        // Bubble up the node with new value as in the HeapInsert Function
    }
    else
    {
        // Bubble sing the node with new value as in the HeapRemoveMax Function
    }
}