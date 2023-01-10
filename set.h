//Final Exam

/* 
 * Filename:        set.h
 * Purpose:         The purpose of this file is to implement the set.h class
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       May 4, 2017, 8:51 AM
 */

#ifndef SET_H
#define SET_H

//Preprocessor Directives
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <iomanip>

#include "item.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//

//Member Function Declaration

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//

template <class Item>
class set
{
public:
    //CONSTRUCTORS AND DESTRUCTORS
    set();
    // Default Constructor
    // Postcondition:
    //  The set is empty
    set(const set &source);
    // Copy Constructor
    // Postcondition:
    //  The set is initialized with source
    ~set();
    // Destructor
    // Postcondition:
    //  The set is cleared
    
    // MODIFICATION MEMBER FUNCTIONS
    

    void operator=(const set &source);
    // Overload assignment operator
    // Postcondition:
    //  The set is assigned the value of source.
    

    void clear();
    // clear()
    // Postcondition:
    //  The set is empty.
    

    bool insert(const Item &entry);
    // insert()
    // Postcondition:
    // If an equal entry was already in the set the set is unchanged and the 
    // return value is false. Otherwise, entry was added to the set and the 
    // return value is true.
    

    bool remove(const Item &target);
    // remove()
    // Postcondition:
    //  If target was in the set, then it has been removed from the set and 
    //  the return value is true. Otherwise the set is unchanged and the 
    //  return value is false.
    
    // CONSTANT MEMBER FUNCTIONS
     
    bool contains(const Item &target) const;
    // contains()
    // Postcondition:
    //  Returns a true/false value depending on whether target is found in 
    //  the B-Tree
     
    bool is_empty() const;
    // is_empty()
    // Postcondition:
    //  Returns true if the set is empty; otherwise returns false.
    
    void print(int indent) const;
    // print()
    // Postcondition:
    //  Prints the B-Tree visually in tree format from left to right
    
private:
    
    // MEMBER CONSTANTS
    static const int MINIMUM = 2;
    static const int MAXIMUM = 2*MINIMUM;
    
    // MEMBER VARIABLES
    int data_count;
    int child_count;
    Item data[MAXIMUM + 1];
    set *subset[MAXIMUM + 2];
    
    // MEMBER HELPER FUNCTIONS
    bool is_leaf() const;
    // is_leaf()
    // Postcondition:
    //  Returns true/false value depending on whether the set has any
    //  children.
    
    bool loose_insert(const Item &entry);
    // loose_insert()
    // Precondition:
    //  The entire B-Tree is valid.
    // Postcondition:
    //  If entry was already in the set, then the set is unchanged. 
    //  Otherwise, entry has been added to the set, and the entire B-tree is 
    //  still valid EXCEPT that the number of entries in the root of this set 
    //  may be one more than the allowed maximum.
    
    bool loose_remove(const Item &target);
    // loose_remove()
    // Precondition:
    //  The entire B-Tree is valid.
    // Postcondition:
    //  If target was in the set, then it has been removed from the set; 
    //  otherwise the set is unchanged. The entire B-Tree is still valid 
    //  EXCEPT that the number of entries in the root of this set may be one 
    //  less than the allowed minimum.
    
    void remove_biggest(Item &removed_entry);
    // remove_biggest()
    // Precondition:
    //  (data_count > 0) and the entire B-Tree is valid.
    // Postcondition:
    //  The largest item in the set has been removed, and removed_entry has 
    //  been set equal to a copy of this removed item. The B-Tree is still 
    //  valid EXCEPT that the number of entries in the root of this set may 
    //  be ones less than the allowed minimum.
    
    void fix_excess(int i);
    // fix_excess()
    // Precondition:
    //  (i < child_count) and the entire B-Tree is valid EXCEPT that 
    //  subset[i] has MAXIMUM+1 entries. Also, the root is allowed to have 
    //  zero entries and one child.
    // Postcondition:
    //  The tree has been rearranged so that the entire B-Tree is valid 
    //  EXCEPT that the number of entries in the root of this set may be on 
    //  more than the allowed maximum.
    
    void fix_shortage(int i);
    // fix_shortage()
    // Precondition:
    //  (i < child_count) and the entire B-Tree is valid EXCEPT that 
    //  subset[i] has only MINIMUM-1 entries.
    // Postcondition:
    //  the tree has been rearranged so that the entire B-Tree is valid EXCEPT 
    //  that the number of entries in the root of this set may be one less 
    //  than the allowed minimum
    
    void transfer_left(int i);
    // transfer_left()
    // Precondition:
    //  (0 < i < child_count) and (subset[i]->data_count >  MINIMUM) and the
    //  entire B-Tree is valid EXCEPT that subset[i - 1] has only MINIMUM - 1 
    //  entries.
    // Postcondition:
    //  One entry has been shifted from the front of subset[i] up to 
    //  data[i-1], and the original data[i-1] has been shifted down to the 
    //  last entry of subset[i-1]. Also, if subset[i] is not a leaf, then its 
    //  first subset has been transferred over to be the last subset of 
    //  subset[i - 1]. As a result, the entire B-Tree is now valid.
    
    void transfer_right(int i);
    // transfer_right()
    // Precondition:
    //  (i+1 < child_count) and (subset[i]->data_count > MINIMUM) and the 
    //  entire B-Tree is valid EXCEPT that subset [i] has only MINIMUM - 1 
    //  entries.
    // Postcondition:
    //  One entry has been shifted from the end of subset[i] up to data[i], 
    //  and the original data[i] has been shifted down to the first entry of 
    //  subset[i + 1]. Also, if subset[i] is not a leaf, then its last subset 
    //  has been transferred over to be the first subset of subset[i + 1]. 
    //  As a result, the entire B-Tree is now valid.
    
    void merge_with_next_subset(int i);
    // merge_with_next_subset()
    
    // Precondition:
    //  (i + 1 < child_count) and the entire B-Tree is valid EXCEPT that the 
    //  total number of entries in subset[i] and subset[i + 1] is 
    //  2*MINIMUM - 1.
    
    // Postcondition:
    //  subset[i] and subset[i + 1] have been merged into one subset (now at 
    //  subset[i]), and data[i] has been passed down to be the median entry 
    //  of the new subset[i]. As a result, the entire B-Tree is valid EXCEPT 
    //  that the number of entries in the root of this set might be one less 
    //  than the allowed minimum.
};

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//

//Member Function Definitions

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//

//CONSTRUCTORS AND DESTRUCTORS

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//

//Function:     set()
//
//Input:        None | Constructor Implementation
//Output:       None | Constructor Implementation
//Purpose:      The purpose of this function is to define the constructor 
//              implementation for the set class. When an object of the set 
//              class is instantiated, the constructor is called. The private 
//              member variables data_count and child_count are initialized to 
//              zero, while the data[MAXIMUM+1] and subset[MAXIMUM+2] arrays 
//              are dynamically created. 
template<class Item>
set<Item>::set()
{
    data_count = 0;     //Initial values for empty set
    child_count = 0;    //Initial values for empty set
    for(int i = 0; i < MAXIMUM + 2; i++)
    {
        //Initialize subset array to nullptr
        subset[i] = nullptr;
    }
}

//--------------------------------------------------------------------------//

//Function:     set(const set &source)
//
//Input:        None | Constructor Implementation
//Output:       None | Constructor Implementation
//Purpose:      The purpose of this function is to define the implementation 
//              of the copy constructor. The function will clear the current 
//              set if it is not empty. It will then copy the private member
//              variables data_count and child_count from the set source
//              passed in the formal parameter of the function. It will then
//              traverse the data arrays of both sets copying from source
//              to the set calling the function. In a similar fashion it will
//              copy the pointers contained in subset from source to the set
//              calling the function.
template<class Item>
set<Item>::set(const set &source)
{
    int x = 0;
    //If current set is not empty
    
    //Copy data_count and child_count from source set to current set
    data_count = source.data_count;
    child_count = source.child_count;
    //Copy data members (data[]) from source set to current set
    for(x = 0; x < data_count; x++)
    {
        data[x] = source->data[x];
    }
    //Copy pointers to child sets (subset[]) from source set to current set
    for(x = 0; x < child_count; x++)
    {
        subset[x] = new set(*(source.subset[x]));
    }
}

//--------------------------------------------------------------------------//

//Function:     ~set()
//
//Input:        None | Destructor Implementation
//Output:       None | Destructor Implementation
//Purpose:      The purpose of this function is to define the destructor 
//              implementation for the set class. The destructor is invoked 
//              by calling the clear() function of the set class.
template<class Item>
set<Item>::~set()
{
    //Initialize set
    clear();
}

//--------------------------------------------------------------------------//

//Function:     operator=(const set &source)
//
//Input:        const set &source
//Output:       Return type void
//Purpose:      The purpose of this function is to define the equality 
//              operator (=) for the set class. The function will test
//              to avoid self-assignment, then will copy the data_count,
//              child_count, data array, and subset array from the source
//              set to the set calling the function in a similar manner
//              to the copy constructor.
template<class Item>
void set<Item>::operator=(const set &source)
{
    if (this != &source) //avoid self-copy
    {
        int x;
        clear();
        
        
         //Copy data_count and child_count from source set to current set
        data_count = source.data_count;
        child_count = source.child_count;
        //Copy data members (data[]) from source set to current set
        for(x = 0; x < MAXIMUM + 1; x++)
        {
            data[x] = source->data[x];
        }
        //Copy pointers to child sets (subset[]) from source to current set
        for(x = 0; x < MAXIMUM+2; x++)
        {
            subset[x] = new set(*(source->subset[x]));
        }  
    }//end else
}

//--------------------------------------------------------------------------//

//Function:     clear()
//
//Input:        None
//Output:       Return type void
//Purpose:      The purpose of this function is to clear the B-Tree to its
//              initial values. This is accomplished by deleting the pointers 
//              contained in subset. The data_count and child_count member
//              variables are then set to zero.
template<class Item>
void set<Item>::clear()
{
    int i;
    //Traverse subset, delete set objects being pointed to
    for(i = 0; i < child_count; i++)
    {
        delete subset[i];
    }
    
    //Set data_count and child_count back to original values
    data_count = 0;
    child_count = 0;
}

//Function:     insert(const Item &entry)
//
//Input:        const Item &entry
//Output:       Return type bool
//Purpose:      The purpose of this function is to insert an item of type
//              Item into the set. The function returns true if successful,
//              and false if not. This is accomplished with the loose_insert()
//              and fix_excess() functions.
template<class Item>
bool set<Item>::insert(const Item &entry)
{
    int x;
    bool found;
    
    found = loose_insert(entry);
    
//    if(!found)
//    {
//        return false;
//    }
    if(data_count >  MAXIMUM)
    {
        //Create copy of set using copy constructor
        set *copySet = new set;
        
        copySet->data_count = data_count;
        copySet->child_count = child_count;
        for(x = 0; x < data_count; x++)
        {
            copySet->data[x] = data[x];
        }
        
        for(x = 0; x < child_count; x++)
        {
            copySet->subset[x] = subset[x];
        }
        
        //Initialize the current set (empty root set)
        data_count = 0;
        child_count = 1;
        subset[0] = copySet;
        
        fix_excess(0);        
    }
    return true;
}

//--------------------------------------------------------------------------//

//Function:     remove(const Item &target)
//
//Input:        const Item &target
//Output:       Return type bool
//Purpose:      The purpose of this function is to remove an item of type 
//              Item from the set. The function will return true if the 
//              removal was successful, and false if not. This is accomplished
//              with the loose_remove() function
template<class Item>
bool set<Item>::remove(const Item &target)
{
    int i;
    //target unable to be removed from set
    if(!(loose_remove(target)))
    {
        return false;
    }
    //If root doesn't contain data but has children
    if((data_count == 0) && (child_count == 1))
    {
        //Create new temporary pointer
        set *temp;
        
        //Have temporary pointer point to current set
        temp = subset[0];
        

        //Copy data members from current child set to root set
        for(i = 0; i < (temp->data_count); i++)
        {
            data[i] = temp->data[i];
        }
        
        //Assign root pointers to child sets of child set
        //...grandchildren?
        for(i = 0; i < (temp->child_count); i++)
        {
            subset[i] = temp->subset[i];
        }
        
        data_count = temp->data_count;
        child_count = temp->child_count;
        
        for(i = 0; i < temp->child_count; i++)
        {
            temp->subset[i] = nullptr;
        }
        
        
        delete temp;
    }
    return true;    //Target removed from set
}

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//

// CONSTANT MEMBER FUNCTIONS

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//

//Function:     contains(const Item &target) const
//
//Input:        const Item &target
//Output:       Return type bool
//Purpose:      The purpose of this function is to recursively traverse a 
//              binary tree to determine if and item of type Item (target) 
//              is contained in the B-Tree. The function returns 1 if found, 
//              otherwise returns 0.
template<class Item>
bool set<Item>::contains(const Item &target) const
{
    cout << "Entering contains(" << target << ")" << endl;
    //Steps for searching for a target in a set
    
    //Step One:
    //              Find first index such that data[i] is not less than the 
    //              target. If there is no such index, then set i equal to 
    //              data_count, indicating that all of the entries are less 
    //              than the target.
    
    int i = first_greater(data, data_count, target);   
    
    //Step Two:
    //              If found, return one. If the root has no children, 
    //              return zero (end of traversal). Otherwise, recursively 
    //              call the contains function.
    if((i < data_count) && !(target < data[i]))
    {
        //In case equality operator(==) is not defined. If i is not equal to 
        //              data_count (which means it is contained in set, 
        //              otherwise it would be equal to data_count and the 
        //              "<" comparison would return false). Using similar 
        //              logic, if target is also not less than data[i], 
        //              then the target is deduced to have been found.
        return true;
    }
    else if(child_count == 0)
    {
        //If child_count == 0, B-Tree cannot be traversed because set
        //is a leaf. Return 0, target not contained in B-Tree.
        return false;
    }
    else
    {
        //Otherwise, traverse B-Tree
        return subset[i]->contains(target); 
        //Recursive call to contains(target)
    }
}

//--------------------------------------------------------------------------//

//Function:     is_empty() const
//
//Input:        None
//Output:       Return type bool
//Purpose:      The purpose of this function is to determine whether the 
//              B-Tree is empty. The function will check if data_count is 
//              equal to 0. If it is, the function returns true. Otherwise, 
//              the function returns false.
template<class Item>
bool set<Item>::is_empty() const
{
    return (data_count == 0); //True if 0, false otherwise
}

//--------------------------------------------------------------------------//

//Function:     print(int indent) const
//
//Input:        int indent
//Output:       Return type void
//Purpose:      The purpose of this function is to print the B-Tree.
template<class Item>
void set<Item>::print(int indent) const
{
    cout << "Entering print()" << endl;
    int i;
    if (child_count > 0)
        subset[child_count-1]->print(indent+4);
    for (i = data_count; i > 0; i--)
    {
        cout << setw(indent) << " " << data[i-1] << endl;
        if (child_count > 0)
            subset[i-1]->print(indent+4);
    }
}

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//

// PRIVATE MEMBER HELPER FUNCTIONS

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//

//Function:     is_leaf() const
//Input:        None
//Output:       Return type bool
//
//Purpose:      The purpose of this function is to determine whether the 
//              current set is a leaf. This is determined by returning true 
//              if the child_count is equal to zero, and returning false 
//              otherwise.
template <class Item>
bool set<Item>::is_leaf() const
{
    return(child_count == 0);
}

//--------------------------------------------------------------------------//

//Function:     loose_insert(const Item &entry)
//Input:        const Item &entry
//Output:       Return type bool
//
//Purpose:      The purpose of this function is to perform a loose insertion 
//              of an item of type Item into the set. This function
//              incorporates the first_greater() and insert_item() helper
//              functions. The function will return true if the item is 
//              successfully inserted, and false otherwise. 
template <class Item>
bool set<Item>::loose_insert(const Item &entry)
{
//    cout << "Entering loose_insert(" << entry << ")" << endl;
    //Find first index such that data[i] is not less than target. If there is 
    //no such index, then set i equal to data_count, indicating that all of 
    //the entries are less than the target.
    int i = first_greater(data, data_count, entry);
    
    //Entry already is in set
    if((i < data_count) && !(entry < data[i]))
    {
        return false;
    }
    
    else if(child_count == 0)//No children
    {
        //Add the new entry to the root at data[i]. (The original entries at 
        //data[i] and afterwards must be shifted right to make room for the 
        //new entry.) Return true to indicate that we added the entry.
        insert_item(data, i, data_count, entry);
        return true;
    }
    else
    {
        bool temp;
        //Save value of recursive call to temp
        temp = (subset[i]->loose_insert(entry)); ////WasEqualToTemp        
        //If too many entries, fix excess entries
        if((subset[i]->data_count) > MAXIMUM)
        {
            fix_excess(i);
        }
        //Return value of recursive call
        return temp;
    }
}

//--------------------------------------------------------------------------//

//Function:     loose_remove(const Item &target)
//Input:        const Item &target
//Output:       Return type bool
//
//Purpose:      The purpose of this function is to perform a loose removal of 
//              an item of type Item from the set. The function will return 
//              true if the item was removed, and false if it wasn't. This 
//              function incorporates the delete_item and first_greater helper 
//              functions.
template <class Item>
bool set<Item>::loose_remove(const Item &target)
{
    //Find first index such that data[i] is not less than target. If there is 
    //no such index, then set i equal to data_count, indicating that all of 
    //the entries are less than the target.
    int i;
    i = first_greater(data, data_count, target);
    
    bool found;
    found = contains(target);
    
    //Root has no children and target has not been found
    if(is_leaf() && !found)
    {
        //target not found in set
        return false;
    }
    //The root has no children and the target has been found
    //Target found in root
    else if(is_leaf() && found)
    {
        //Remove target from array
        // Index used to shift values in data[]
        int shift_index;
        
        // i contains index of item to be deleted
        // Copy the value of data[i] into entry so that it is not lost
//        target = data[i];
        
        // Shift values to the left by one for each index >i
        for (shift_index = i+1; shift_index < data_count; shift_index++)
            data[shift_index-1] = data[shift_index];
        
        // Decrement array size
        data_count--;
                
        //target found in set
        return true;
    }
    //The root has children and the target has not been found
    else if(!(is_leaf()) && !(found))
    {
        //Target not found in root, but still might appear in subset[i]
        //Recursively call loose erase on target
        bool temp = (subset[i]->loose_remove(target));
        
        //If current child contains one less data entry than allowed, call
        //fix_shortage function
        if(subset[i]->data_count < MINIMUM)
        {
            fix_shortage(i);
        }
        //Return value of recursive call
        return temp;
    }
    //The root has children and the target has been found
    else
    {
        //Target has been found in root, but cannot simply be removed from 
        //the data array because there are children below. Instead, enter 
        //subset[i], find the largest item and make a copy, then remove the 
        //largest item from the data array. This will be placed into data[i], 
        //which currently contains the target.
        
        //Enter subset, find largest Item, remove largest Item
        //Largest item is returned by reference
        subset[i]->remove_biggest(data[i]);
        
        //If the data of the child is less than minimum, there is a shortage
        //that needs to be fixed
        if(subset[i]->data_count < MINIMUM)
        {
            fix_shortage(i);
        }
        return true;    //Removed, return true
    }
}

//--------------------------------------------------------------------------//

//Function:     remove_biggest(Item &removed_entry)
//Input:        Item &removed_entry
//Output:       Return type void
//
//Purpose:      The purpose of this function is to remove the biggest item 
//              of type Item from the set. The function will recursively call
//              itself. It also incorporates the fix_shortage function.
template <class Item>
void set<Item>::remove_biggest(Item &removed_entry)
{
    //If no children, "delete" largest (last) element in data[] by 
    //decrementing data_count
    if(child_count == 0)
    {
        data_count--;
    }
    
    //Else, find largest element in B-Tree
    else
    {
        //Recursively call remove_biggest() to find largest element
        //In B-Tree to remove.
        subset[child_count - 1]->remove_biggest(removed_entry);
        
        //If the root of subset[child_count - 1] is less than the
        //MINIMUM required data, there is a shortage that needs to be fixed
        if((subset[child_count - 1]->data_count) < MINIMUM)
        {
            fix_shortage(child_count - 1);
        }
    }
}

//--------------------------------------------------------------------------//

//Function:     fix_excess(int i)
//Input:        int i
//Output:       Return type void
//
//Purpose:      The purpose of this function is to fix a B-Tree that has a 
//              root whose child contains one more entry than allowed. The 
//              middle entry is shifted upwards to the root set and the 
//              left and right portions of the remaining data and subset 
//              members are split accordingly.
template <class Item>
void set<Item>::fix_excess(int i)
{
    //Declare variable for use within function
    int count;

    //Shift elements of data[] array past i to create room for value 
    //to be passed upwards
    for(count = data_count; count > i; count--)
    {
        data[count] = data[count - 1];
    }
    
    //Insert item from subset into data (move upward)
    //Update data count
    data[i] = (subset[i]->data[MINIMUM]);
    data_count++;

    //Create two new subsets
    set *leftChild = new set;
    set *rightChild = new set;
    
    //Copy data from original subset into two separate subsets
    for(count = 0; count < MINIMUM; count++)
    {
        //Left "half"
        leftChild->data[count] = subset[i]->data[count];
        //Right "half"
        rightChild->data[count] = subset[i]->data[count + MINIMUM + 1];
    }
    
    leftChild->data_count = MINIMUM;
    rightChild->data_count = MINIMUM;
    
    //Copy pointers from original subset to two separate subsets
    //In order to do this, the middle child is determined by taking the 
    //child_count and performing integer division by two on the child_count.
    if((subset[i]->child_count) > 0)
    {
        int childIndex = ((subset[i]->child_count) / 2);
         //Using this index it is possible to copy pointers of original set
         //to have leftChild and rightChild point to the correct sets
        
        for(count = 0; count < childIndex; count++)
        {
            leftChild->subset[count] = subset[i]->subset[count];
            rightChild->subset[count] = subset[i]->subset[count + childIndex];
        }        
        //Update child_count for leftChild and rightChild
        leftChild->child_count = MINIMUM + 1;
        rightChild->child_count = MINIMUM + 1;
    }
    
    //Prevent possible memory leak
    for(count = 0; count < (subset[i]->child_count); count++)
    {
        subset[i]->subset[count] = nullptr;
    }
    
    //Shift values of current subset to accommodate updated subset 
    for (count = child_count; count > i; count--)
    {
        subset[count] = subset[count-1];
    }
    
    //Make root set point to new left and right child
    subset[i] = leftChild;
    subset[i+1] = rightChild; 
    child_count++;
}

//--------------------------------------------------------------------------//

//Function:     fix_shortage(int i)
//Input:        int i
//Output:       Return type void
//
//Purpose:      The purpose of this function is to fix a child set of a root 
//              set that may contain less than a MINIMUM number of entries. 
//              There are four options to fix a shortage. The first option is 
//              to transfer an extra entry from subset[i-1]. The second 
//              option is to transfer an extra entry from subset[i+1]. The 
//              third option is to combine subset[i] with subset[i-1]. The 
//              fourth option is to combine subset[i] with subset[i+1].
template <class Item>
void set<Item>::fix_shortage(int i)
{
    //CASE ONE: 
    //Transfer an extra entry from subset[i-1]
    if((subset[i-1]->data_count) > MINIMUM)
    {
        transfer_left(i);
    }
    
    //CASE TWO:
    //Transfer an extra entry from subset[i+1]
-   else if((subset[i+1]->data_count) > MINIMUM && i+1)
    {
        transfer_right(i);
    }
    
    //CASE THREE
    //Combine subset[i] with subset[i-1]
    else if((subset[i-1]->data_count) == MINIMUM && (i > 0))
    {
        merge_with_next_subset(--i);
   
    }//end else if
    
    //CASE FOUR
    //Combine subset[i] with subset[i+1]
    else
    {
        merge_with_next_subset(i);
        
    }//end else
    
}

//--------------------------------------------------------------------------//

//Function:     transfer_left(int i)
//Input:        int i
//Output:       Return type void
//
//Purpose:      
template <class Item>
void set<Item>::transfer_left(int i)
{
    int x;
    cout << "Entering transfer_left(" << i << ")" << endl;
        //STEP ONE
        //Shift entries to make room. Increment subset[i]->data_count.
        for(x = data_count; x > 0; x--)
        {
            subset[i]->data[x] = subset[i]->data[x-1];
        }
        //Transfer data[i-1] down to the front of subset[i]->data. 
        subset[i]->data[0] = data[i-1];
        
        //Decrement data_count
        data_count--;
        
        //Increment subset[i]->data_count
        (subset[i]->data_count)++;
        
        //STEP TWO
        //Transfer the final item of subset[i-1]->data up to replace data[i-1]
        data[i-1] = subset[i-1]->data[(subset[i-1]->data_count)-1];
        
        //Decrement subset[i-1]->data_count.
        (subset[i-1]->data_count)--;
        
        //Increment data_count
        data_count++;
        
        //STEP THREE
        //If subset[i-1] has children, transfer the final child of 
        //subset[i-1] over to the front of subset[i]. This involves shifting 
        //over the existing array subset[i]->subset[x] to make room for new 
        //child pointer at subset[i]->subset[0]. 
        
        //Shift elements of subset[i]->subset[]
        if(!(subset[i-1]->is_leaf()))
        {
            //Shift existing elements of subset[i]->subset[] over by one
            //to allow for insertion of final child of subset[i-1]. 
            for(x = child_count; x > 0; x--)
            {
                subset[i]->subset[x] = subset[i]->subset[x-1];
            }
            
            //Transfer final child of subset[i-1] to the front of subset[i]
            subset[i]->subset[0] = 
            subset[i-1]->subset[(subset[i-1]->child_count)];  
            
            //Increment subset[i]->child_count. 
            (subset[i]->child_count)++;
           
            //Decrement subset[i-1]->child_count.
            (subset[i-1]->child_count)--;
        }//end if
}

//--------------------------------------------------------------------------//

//Function:     transfer_right(int i)
//Input:        int i
//Output:       Return type void
//
//Purpose:      
template <class Item>
void set<Item>::transfer_right(int i)
{
    cout << "Entering transfer_right(" << i << ")" << endl;
    int x;
    
    //STEP ONE
    
    //Transfer data[i] down to the back of subset[i]->data. This 
    //represents taking the last item in data[], and moving it to the 
    //last item of data[] of subset[i]
    subset[i]->data[(subset[i]->data_count)] = data[i];

    //Increment subset[i] data_count
    (subset[i]->data_count)++;

    //Decrement data_count
    data_count--;

    //STEP TWO
    
    //Set data[i] to be replaced with the first item of the data array
    //(data[0] of subset[i+1]
    data[i] = subset[i+i]->data[0];
    
    //Increment data_count
    data_count++;

    //Decrement data_count of subset[i+1]
    (subset[i+1]->data_count)--;

    //Shift data members of subset[i+1] to the left
    for(x = 0; x < (subset[i+1]->data_count); x++)
    {
        subset[i+1]->data[x] = subset[i+1]->data[x+1];
    }

    //If subset[i+1] has children
    if(!(subset[i+1]->is_leaf()))
    {
        //Transfer the first child of subset[i+1] over to the end of 
        //subset[i]
        subset[i]->subset[subset[i]->child_count] = subset[i+1]->subset[0];

        //Increment subset[i]->child_count
        (subset[i]->child_count)++;

        //Decrement subset[i+1]->child_count
        (subset[i+1]->child_count)--;

        //Shift existing elements of subset[i+1] over by one to adjust 
        //for the removal of subset[i+1]->subset[0]
        for(x = 0; x < (subset[i+1]->child_count); x++)
        {
            subset[x] = subset[x+1];
        }
    }
}

//--------------------------------------------------------------------------//

//Function:     merge_with_next_subset(int i)
//Input:        int i
//Output:       Return type void
//
//Purpose:      The purpose of this function is to merge two subsets together.
//              This is implemented in the fix_shortage member function when
//              a child set contains less than MINIMUM entries, and a
//              "sibling" child set to either the left or right contains
//              exactly MINIMUM entries. These two sets will be merged into
//              one set.
template <class Item>
void set<Item>::merge_with_next_subset(int i)
{
    int x;
    int count = subset[i-1]->data_count;
    
    //Step One
    
    //Transfer data[i-1] down to end of subset[i-1]->data[]
    subset[i-1]->data[count] = data[i-1];
    
    //Decrement data count, increment subset[i-1]->data_count
    data_count--;
    (subset[i-1]->data_count)++;
    
    //Step Two
    
    count = subset[i-1]->data_count;
    for(x = 0; x < subset[i]->data_count; x++)
    {
        //Transfer data from subset[i] to end of subset[i-1]
        subset[i-1]->data[count + x] = subset[i]->data[i];
        //Increment subset[i-1]->data_count
        (subset[i-1]->data_count)++;
    }
    
    count = subset[i-1]->child_count;
    for(x = 0; x < subset[i]->child_count; x++)
    {
        //Transfer children from subset[i] to end of subset[i-1]
        subset[i-1]->subset[count + x] = subset[i]->subset[x];
        //Increment subset[i-1]->child_count
        (subset[i-1]->child_count)++;
    }
    
    //Set subset[i]->data_count and subset[i]->child_count to zero
    subset[i]->data_count = 0;
    subset[i]->child_count = 0;
    
    //Step Three
    delete subset[i];
    for(x = 0; x < child_count; x++)
    {
        subset[i] = subset[i+1];
    }
    
    //Decrement child_count by one
    child_count--;
}

//--------------------------------------------------------------------------//

#endif /* SET_H */



