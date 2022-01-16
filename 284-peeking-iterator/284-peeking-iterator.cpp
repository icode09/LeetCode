/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    bool peaked;
    int peakedValue;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    peaked = false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(!peaked){
            peaked = true;
            peakedValue = Iterator::next();
        }
        return peakedValue;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(!peaked) return Iterator::next();
        peaked = false;
        return peakedValue;
	}
	
	bool hasNext() const {
	    if(peaked) return true;
        return Iterator::hasNext();
	}
};