#ifndef OBJECTARRAY_H
#define OBJECTARRAY_H

#include <cassert> 

class DisplayableObject;

class ObjectArray {
private:
	int m_nLength;
	DisplayableObject** m_pData;

public:
	/* Constructor */
	ObjectArray(int length) :
		m_nLength(length) {
		m_pData = new DisplayableObject*[m_nLength];
	}

	ObjectArray() :
		m_nLength(0), m_pData(nullptr)
	{
	}

	/* Deconstrutor */
	~ObjectArray() {
		delete[] m_pData;
	}
	


	/**
	Erases the array and sets the length to 0
	*/
	void erase() {
		delete[] m_pData;

		m_pData = nullptr;
		m_nLength = 0;
	}

	/**
	Overrides [] operator to allow access to the array
	Check bounds to validate the index is in bounds

	@param index Index of the array to get the data from

	@return The DisplayableObject pointer reference of the given index
	*/
	DisplayableObject*& operator[](int index) {
		assert(index >= 0 && index < m_nLength);
		return m_pData[index];
	}

	/**
	Returns the length of the array

	@return The current length of the array
	*/
	int getLength() { return m_nLength; }



	/**
	Reallocates the array
	Destorys all existing elements

	@param newLength The new length of the array
	*/
	void reallocate(int newLength) {
		erase();

		if (newLength <= 0) { return; }

		m_nLength = newLength;
		m_pData = new DisplayableObject*[m_nLength];
	}

	/**
	Resizes the array to the new given length

	If new length is same as existing length then nothing happens
	If new length is 0 (or negative) array is set null

	If there existing data as much that can fit into the new array will be copied over

	@param newLength The new length of the array to resize to
	*/
	void resize(int newLength) {
		if (newLength == m_nLength) {
			return; 
		} else if (newLength <= 0) {
			erase();
			return;
		}

		m_nLength = newLength;

		// New array
		DisplayableObject** data = new DisplayableObject*[m_nLength];

		if (m_nLength > 0) {
			// How many elements to copy - min(newLength, m_nLength)
			int noElements = (newLength > m_nLength) ? m_nLength : newLength;

			// Copy elements to new array
			for (int i = 0; i < noElements; data[i] = m_pData[i], i++);
		}

		// Delete old array
		delete[] m_pData;
		// Set new array
		m_pData = data;
	}

	/**
	Inserts the value before the given index

	@param value New value to go into the array
	@param index The index to add the value before

	@return Returns index of value in array
	*/
	int insertBefore(int index, DisplayableObject* value) {
		// Data validation
		assert(index >= 0 && index <= m_nLength);

		// New array to hold extra value
		DisplayableObject** data = new DisplayableObject*[m_nLength + 1];

		// Copy elements from before index
		for (int before = 0; before < index; before++) {
			data[before] = m_pData[before];
		}

		// Add new value
		data[index] = value;

		// Copy elements after index
		for (int after = index; after < m_nLength; after++) {
			data[after + 1] = m_pData[after];
		}

		// Replace old array
		delete[] m_pData;
		m_pData = data;
		++m_nLength;

		return index;
	}
	
	/* Insert value at beginning of object array */
	int insertAtBeginning(DisplayableObject* value) { return insertBefore(0, value); }
	/* Insert value at end of object array */
	int insertAtEnd(DisplayableObject* value) { return insertBefore(m_nLength, value); }



	/**
	Removes the a number of elements starting at given index

	@param index        The index of the first element to remove
	@param [noElements] Number of elements to remove - Default: 1 element
	*/
	void remove(int index, int noElements = 1) {
		// Data validation
		assert(index >= 0 && index < m_nLength);

		// If only one element in array
		if (m_nLength == 1) {
			erase();
			return;
		}

		// New array without given index
		DisplayableObject** data = new DisplayableObject*[m_nLength - noElements];

		// Copy values before index
		for (int before = 0; before < index; before++) {
			data[before] = m_pData[before];
		}

		// Copy values after index (skipping index itself)
		for (int after = index + noElements; after < m_nLength; after++) {
			data[after - 1] = m_pData[after];
		}

		// Replace old array
		delete[] m_pData;
		m_pData = data;
		m_nLength -= noElements;
	}

	/**
	Returns the index of the given value

	@param value Value to get index of

	@return Index of value, if not found NULL is returned
	*/
	int getIndex(DisplayableObject* value) {
		for (int i = 0; i < m_nLength; i++) {
			if (value == m_pData[i]) { return i; }
		}
		return NULL;
	}
};

#endif