/*****************************************************************************
*                    
*  Author:           Aashish Panta
*  Email:            liverpool.ashish.ap@gmail.com
*  Label:            A04
*  Title:            Commenting Code
*  Course:           CMPS 3013
*  Semester:         Spring 2023
* 
*  Description:
*        This program implements a class that allows an Array to be used just like 
*        an Queue. It overloads the "*" (asterik) to simulate accessing seperate 
*        array elements, but really it traverses the array to find the specified node using
*        an index value. It uses the "Push()" method to "add"
*        items onto the end of the Queue, as well as 
*        "Pop()" method to "remove" items from the end of
*        Queue.
*
*  Usage:
*       - $ ./main.cpp
*       - This will read in a file containing whatever values to be read into our list/array. 
*       - This will demonstrate the use of an array as a Queue. 
*       
*  Files:            
*       main.cpp    : The main driver program file with .cpp extension.
*  
*****************************************************************************/

#include <iostream>

using namespace std;

/**
 * Class Name: CircularArrayQue
 * 
 * Description:
 *      This class creates, traverses, and manipulates a dynamically allocated array based Queue.
 * 
 * Public Methods:
 *                          CircularArrayQue()    
 *                          CircularArrayQue(int size) 
 *      void                Push(int item)
 *      int                 Pop()
 * 
 * Private Methods:
 *      void                init(int size = 0)
 *      bool                full()
 * 
 * Usage: 
 * 
 *      CircularArrayQue C1(3);                         // Create Que array and initialize size as 3
 *      C1.Push(34);                                    // Push interger value onto the Que
 *      C1.Pop(54);                                     // Pops interger value off of the Que.
 */

class CircularArrayQue {
private:
    int *Container;     // Pointer Variable as int
    int Front;          // Front position value 
    int Rear;           // Rear position in Queue     
    int QueSize;        // Size of the Queue
    int CurrentSize;    // current index of Queue
    
    /**
     * Private : init
     * 
     * Description:
     *      Initialize member variables Front, Rear, CircularArrayQue as 0.
     *      Initiize QueSize as size whic is passed as Params
     * 
     * Params:
     *     int     :  initial value of member variables 
     * 
     * Returns:
     *      - No return
     */
    
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    /**
     * Private : Full
     * 
     * Description:
     *      Checks the status of the Queue by comparing the total size of Queue with the CurrentSize. 
     * 
     * Params:
     *      - No Params
     * 
     * Returns:
     *      bool   : Status of the Queue
     */
    
    bool Full() {
        //Return true when Queue is full 
        return CurrentSize == QueSize;
    }

public:
    
    /**
     * Public : CircularArrayQue()
     * 
     * Description:
     *      Creates an array of predetermined size 10.
     * 
     * Params:
     *      - No Params
     * 
     * Returns:
     *      - No Returns
     */
    
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    
    /**
     * Public : CircularArrayQue(int size)
     * 
     * Description:
     *      Creates an array to be used as a Que, of a size corresponding with the integer value passed to the function.
     * 
     * Params:
     *     int     :  array size
     *      
     * Returns:
     *      - nothing
     */
    
    
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    /**
     * Public : Push
     * 
     * Description:
     *      Checks the size of the Queue
     *      If Queue is not Full it pushes a value into the Queue and if Queue full it gives a message as "FULL!!!!". 
     * 
     * Params:
     *      int     :  size of Container
     * 
     * Returns:
     *      - nothing
     */
    
    void Push(int item) {
        if (!Full()) {
            //add item to the Queue
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            //
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

    /**
     * Public : Pop
     * 
     * Description:
     *      Pops value off of last item from the Que.
     * 
     * Params:
     *      No Params
     * 
     * Returns:
     *      int  : Removed item from the Que.
     */

    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        //Reduce the index of the Queue
        CurrentSize--;
        //returm the list item in Queue
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(3);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}