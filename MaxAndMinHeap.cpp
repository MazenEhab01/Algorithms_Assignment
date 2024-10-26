#include <iostream>
using namespace std;

class maxHeap
{
    int size = 0;
    int capacity = 10;
    int *array;

    int getParent(int i)
    {
        return (i - 1) / 2;
    }
    int getLeft(int i)
    {
        return 2 * i + 1;
    }
    int getRight(int i)
    {
        return 2 * i + 2;
    }

    int getParentValue(int i)
    {
        return array[getParent(i)];
    }
    int getLeftValue(int i)
    {
        return array[getLeft(i)];
    }
    int getRightValue(int i)
    {
        return array[getRight(i)];
    }
    void heapifyDown(int i)
    {
        int largest = i;
        int l = getLeft(i);
        int r = getRight(i);
        if (l < size && array[l] > array[largest])
        {
            largest = l;
        }
        if (r < size && array[r] > array[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(array[i], array[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i)
    {
        while (i > 0 && array[i] > array[getParent(i)])
        {
            swap(array[i], array[getParent(i)]);
            i = getParent(i);
        }
    }

    void ensureSize()
    {
        if (size == capacity)
        {
            capacity *= 1.5;
            int *newArray = new int[capacity];
            for (int i = 0; i < capacity; i++)
            {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
    }

public:
    maxHeap()
    {
        array = new int[capacity];
    }
    maxHeap(int initialCapacity)
    {
        array = new int[initialCapacity];
        capacity = initialCapacity;
    }

    int peek()
    {
        if (size == 0)
        {
            throw runtime_error("Heap is empty");
        }
        return array[0];
    }
    int getValue(int index)
    {
        if (index < 0 || index >= size)
        {
            throw runtime_error("Invalid index");
        }
        return array[index];
    }

    void insertElement(int element)
    {
        ensureSize();
        array[size++] = element;
        heapifyUp(size - 1);
    }

    void removeMax()
    {
        if (size == 0)
        {
            throw runtime_error("Heap is empty");
        }
        swap(array[0], array[--size]);
        heapifyDown(0);
    }

    int length()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    ~maxHeap()
    {
        delete[] array;
    }
};

class minHeap
{
    int size = 0;
    int capacity = 10;
    int *array;

    int getParent(int i)
    {
        return (i - 1) / 2;
    }
    int getLeft(int i)
    {
        return 2 * i + 1;
    }
    int getRight(int i)
    {
        return 2 * i + 2;
    }

    int getParentValue(int i)
    {
        return array[getParent(i)];
    }
    int getLeftValue(int i)
    {
        return array[getLeft(i)];
    }
    int getRightValue(int i)
    {
        return array[getRight(i)];
    }

    // Maintain min-heap property by pushing down the element at index i
    void heapifyDown(int i)
    {
        int smallest = i;
        int l = getLeft(i);
        int r = getRight(i);

        if (l < size && array[l] < array[smallest])
        {
            smallest = l;
        }
        if (r < size && array[r] < array[smallest])
        {
            smallest = r;
        }

        if (smallest != i)
        {
            swap(array[i], array[smallest]);
            heapifyDown(smallest);
        }
    }

    // Maintain min-heap property by pushing up the element at index i
    void heapifyUp(int i)
    {
        while (i > 0 && array[i] < array[getParent(i)])
        {
            swap(array[i], array[getParent(i)]);
            i = getParent(i);
        }
    }

    // Resize the heap array if it reaches capacity
    void ensureSize()
    {
        if (size == capacity)
        {
            capacity *= 1.5;
            int *newArray = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
    }

public:
    minHeap()
    {
        array = new int[capacity];
    }
    minHeap(int initialCapacity)
    {
        array = new int[initialCapacity];
        capacity = initialCapacity;
    }

    int peek()
    {
        if (size == 0)
        {
            throw runtime_error("Heap is empty");
        }
        return array[0];
    }
    int getValue(int index)
    {
        if (index < 0 || index >= size)
        {
            throw runtime_error("Invalid index");
        }
        return array[index];
    }

    void insertElement(int element)
    {
        ensureSize();
        array[size++] = element;
        heapifyUp(size - 1);
    }

    void removeMin()
    {
        if (size == 0)
        {
            throw runtime_error("Heap is empty");
        }
        swap(array[0], array[--size]);
        heapifyDown(0);
    }

    int length()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    ~minHeap()
    {
        delete[] array;
    }
};

class PriorityQueue
{
    maxHeap maxPQ;

public:
    void insert(int element)
    {
        maxPQ.insertElement(element);
    }

    int extractMax()
    {
        if (maxPQ.isEmpty())
        {
            throw runtime_error("Priority Queue is empty");
        }
        int maxElement = maxPQ.peek();
        maxPQ.removeMax();
        return maxElement;
    }

    int maximum()
    {
        if (maxPQ.isEmpty())
        {
            throw runtime_error("Priority Queue is empty");
        }
        return maxPQ.peek();
    }



    void removeMax()
    {
        if (maxPQ.isEmpty())
        {
            throw runtime_error("Priority Queue is empty");
        }
        maxPQ.removeMax();
    }


    bool isEmpty()
    {
        return maxPQ.isEmpty();
    }


    void display()
    {
        cout << "Priority Queue : ";
        maxPQ.display();
    }
};


void heapSort(int arr[], int n)
{
    maxHeap heap;

    for (int i = 0; i < n; i++)
    {
        heap.insertElement(arr[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = heap.peek();
        heap.removeMax();
    }
}




void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

#include <iostream>
using namespace std;


int main()
{
    // Part 1: Demonstrate Heap Operations (Using maxHeap and minHeap)
    cout << "=== Max Heap Demonstration ===" << endl;

    // Max Heap Demo
    maxHeap maxH;
    maxH.insertElement(15);
    maxH.insertElement(10);
    maxH.insertElement(25);
    maxH.insertElement(5);
    cout << "Max Heap Elements: ";
    maxH.display();

    cout << "Peek (Max): " << maxH.peek() << endl;
    cout << "Heap Length: " << maxH.length() << endl;
    cout << "Is Heap Empty? " << (maxH.isEmpty() ? "Yes" : "No") << endl;

    maxH.removeMax();
    cout << "After removing max element: ";
    maxH.display();

    cout << "Element at index 1: " << maxH.getValue(1) << endl;

    cout << "\n=== Min Heap Demonstration ===" << endl;

    // Min Heap Demo
    minHeap minH;
    minH.insertElement(15);
    minH.insertElement(10);
    minH.insertElement(25);
    minH.insertElement(5);
    cout << "Min Heap Elements: ";
    minH.display();

    cout << "Peek (Min): " << minH.peek() << endl;
    cout << "Heap Length: " << minH.length() << endl;
    cout << "Is Heap Empty? " << (minH.isEmpty() ? "Yes" : "No") << endl;

    minH.removeMin();
    cout << "After removing min element: ";
    minH.display();

    cout << "Element at index 1: " << minH.getValue(1) << endl;

    cout << "\n=== Priority Queue Demonstration ===" << endl;

    // Part 2: Demonstrate Priority Queue using Max Heap
    PriorityQueue pq;
    pq.insert(50);
    pq.insert(20);
    pq.insert(30);
    pq.insert(60);
    cout << "Priority Queue Elements: ";
    pq.display();

    cout << "Current Maximum: " << pq.maximum() << endl;
    cout << "Is Priority Queue Empty? " << (pq.isEmpty() ? "Yes" : "No") << endl;

    cout << "Extract Max (Highest Priority): " << pq.extractMax() << endl;
    cout << "After extracting max: ";
    pq.display();

    pq.removeMax();
    cout << "After removing another max element: ";
    pq.display();

    cout << "\n=== Heap Sort Demonstration ===" << endl;

    // Part 3: Demonstrate Heap Sort
    int arr[] = { 15, 3, 17, 10, 84, 19, 6, 22, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted Array using Heap Sort: ";
    printArray(arr, n);

    return 0;
}