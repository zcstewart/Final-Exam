//Final

/* 
 * Filename:    items.h
 * Purpose:     The purpose of this file is to provide template helper
 *              functions to be used with the set.h class.
 * Author:      kriehn
 * Created:     May 1, 2017, 4:17 PM
 */

#ifndef ITEM_H
#define ITEM_H

#include <cstdlib>

using namespace std;

//--------------------------------------------------------------------------//
// GENERIC TEMPLATE HELPER FUNCTION PROTOTYPES TO SUPPORT THE SET CLASS
//--------------------------------------------------------------------------//
    template <class Item>
    int first_greater(const Item data[], int n, const Item &entry);
    // Precondition: data is a partially filled array containing n
    // items sorted from small to large.

    // Postcondition: The return value i is the first location such that
    // data[i] >= entry. If there is no such location, then the return
    // value is n.

    // Note: Item may be any type with the >= operator defined.

    template <class Item>
    void insert_item(Item data[], int i, int &n, Item entry);
    // 0 <= i < n, and the array size is large enough to hold at least one
    // more item.
    
    // Postcondition: data is a partially filled array containing the
    // n original items plus the new entry. The new entry appears at data[i],
    // and the original entries from data[i] onward have all been shifted up
    // one spot. The value of n has also been increased by one.
    
    // Note: Item may be any type with an assignment operator.

    template <class Item>
    void delete_item(Item data[], int i, int &n, Item &entry);
    // Precondition: data is a partially filled array containing n items, and
    // n > 0.
    
    // Postcondition: The item that was originally at data[i] has been removed
    // from the partially filled array by shifting data[i+1]... down one spot.
    // The value of n has been decremented by one, so that data can now be
    // considered a partially filled array with one less item. A copy of the
    // removed item is now in the parameter entry.
    
    // Note: Item may be any type with an assignment operator.
    
    template <class Item>
    void attach_item(Item data[], int &n, const Item &entry);
    // Precondition: data is a partially filled array containing n items. The
    // array size is large enough to hold at least one more item.
    
    // Postcondition: data is a partially filled array containing the
    // n original items plus the new entry at the end. The value of n has
    // been increased by one.
    
    // Note: Item may be any type with an assignment operator.
    
    template <class Item>
    void detach_item(Item data[], int &n, Item &entry);
    // Precondition: data is a partially filled array containing n items, and
    // n > 0.
    
    // Postcondition: n has been decremented by one, so that data can now be
    // considered a partially filled array with one less item. A copy of this
    // removed item is now in the parameter entry.
    
    // Note: Item may be any type with an assignment operator.

    template <class Item>
    void merge(Item data1[], int &n1, Item data2[], int &n2);
    // Precondition: data1 is a partially filled array containing n1 items,
    // and data2 is a partially filled array containing n2 items.
    // The array data1 also has room for n2 more items.
    
    // Postcondition: All items have been copied from data2 to the end of
    // data 1. The value of n1 has been increased by n2, and n2 has been
    // set to zero.
    
    // Note: Item may be any type with an assignment operator.
    
    template <class Item>
    void split_item(Item data1[], int &n1, Item data2[], int &n2);
    // Precondition: data1 is a partially filled array containing n1 items,
    // and data2 is a partially filled array containing n2 items. 
    // The array data2 also has room for n1/2 more items.
    
    // Postcondition: The final n1/2 items have been copied from data1 to the
    // end of data2. The value of n2 has been increased by n1/2, and n1 has
    // been reduced by this same amount.
    
    // Note: Item may be any type with an assignment operator.  
//--------------------------------------------------------------------------//
     
//--------------------------------------------------------------------------//
// GENERIC TEMPLATE HELPER FUNCTION DEFINITIONS TO SUPPORT THE SET CLASS
//--------------------------------------------------------------------------//

//--------------------------------------------------------------------------//
// first_greater()
    template <class Item>
    int first_greater(const Item data[], int n, const Item &entry)
    {
//        // DEBUG -- Comment out when working
//        cout << "Entering first_greater(" << entry << ")" << endl;        

        // Index of data[]
        int i;

        // Move index i to where entry is no longer less than data[i]
        for (i = 0; (i < n) && !(entry <= data[i]); i++);
        
        return i;
    }
// End first_greater()
//--------------------------------------------------------------------------//

//--------------------------------------------------------------------------//
// insert_item()
    template <class Item>
    void insert_item(Item data[], int i, int &n, Item entry)
    {
        // DEBUG -- Comment out when working
        cout << "Entering insert_item(" << entry << ")" << endl;

        // Index used to shift values in data[]
        int shift_index;

        // Shift values to the right by one for each index >i
        for (shift_index = n; shift_index > i; shift_index--)
            data[shift_index] = data[shift_index-1];

        // Place entry at data[i]
        data[i] = entry;
        
        // Increment array size
        n++;
    }
// End insert item()
//--------------------------------------------------------------------------//

//--------------------------------------------------------------------------//
// delete_item()
    template <class Item>
    void delete_item(Item data[], int i, int &n, Item &entry)
    {
        // DEBUG -- Comment out when working
        cout << "Entering delete_item(" << entry << ")" << endl;
        
        // Index used to shift values in data[]
        int shift_index;
        
        // i contains index of item to be deleted
        // Copy the value of data[i] into entry so that it is not lost
        entry = data[i];
        
        // Shift values to the left by one for each index >i
        for (shift_index = i+1; shift_index < n; shift_index++)
            data[shift_index-1] = data[shift_index];
        
        // Decrement array size
        n--;
    }
// End delete_item()
//--------------------------------------------------------------------------//

//--------------------------------------------------------------------------//
// attach_item()
    template <class Item>
    void attach_item(Item data[], int &n, const Item &entry)
    {
        // DEBUG -- Comment out when working
        cout << "Entering attach_item(" << entry << ")" << endl;
        
        // entry is guaranteed to be be greater than all values in data[]
        // Append entry to end of the array and increment the array size
        data[n++] = entry;
    }
// End attach_item()
//--------------------------------------------------------------------------//

//--------------------------------------------------------------------------//
// detach_item()
    template <class Item>
    void detach_item(Item data[], int &n, Item &entry)
    {
        // DEBUG -- Comment out when working
        cout << "Entering detach_item(" << data[n-1] << ")" << endl;
        
        // detach the last value from the array and store it in entry.
        // Decrement the array size
        entry = data[--n];
    }
// End detach_item()
//--------------------------------------------------------------------------//
    
//--------------------------------------------------------------------------//
// merge()    
    template <class Item>
    void merge(Item data1[], int &n1, Item data2[], int &n2)
    {
        // DEBUG -- Comment out when working
        cout << "Entering merge()" << endl;

        // Index
        int i;

        // Move all values from data2 to the end of data1.
        for (i = 0; i < n2; i++)
            data1[n1 + i] = data2[i];
        
        // Increase array size of n1 to n1 + n2.
        // Decrease array size of n2 to 0.
        n1 += n2;
        n2 = 0;
        
        // NOTE: The node containing the array data2[] is to be deleted, 
        // if necessary, elsewhere.  
        
        // This function merely adjusts the container size of data2[] to 0.
    }
// End merge()
//--------------------------------------------------------------------------//
    
//--------------------------------------------------------------------------//
// split_item()    
    template <class Item>
    void split_item(Item data1[], int &n1, Item data2[], int &n2)
    {
        // DEBUG -- Comment out when working
        cout << "Entering split_item()" << endl;
        
        // Indices
        int i;
        int new_size1;

        // The new size of n1 is n1/2
        new_size1 = n1 - n1/2;
    
        // Move the last half of the data from data1 to beginning of data2
        for (i = 0; i < n1/2; i++)
            data2[n2 + i] = data1[new_size1 + i];

        // Set size of n1 and n2 appropriately
        n2 += n1/2;
        n1 = new_size1;
        
        // NOTE: The starting size of n1 is MAX+1, which is odd.
        // The final length of n1 is therefore n2+1.

        // If n1 = 7, n1 = new_size = 4, and n2 = 3.

        // Once the data has been split, detach can be used elsewhere to 
        // remove the last value from data1[] (which is the center point of
        // original array).
    }
// End split_item()
//--------------------------------------------------------------------------//

#endif /* ITEM_H */


