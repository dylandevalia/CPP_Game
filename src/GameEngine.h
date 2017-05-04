#pragma once

#include "header.h"
#include "templates.h"

#include "BaseEngine.h"
#include "ObjectArray.h"

class GameEngine :
	public BaseEngine {
public:
	GameEngine(int iUnused = 0) : BaseEngine(iUnused), m_pObjectArray() {}
	~GameEngine() { DestroyOldObjects(); }

public:
	/* Syncronises object updates */
	void GameAction();
	/* Sets if objects should update */
	void ShouldObjectsUpdate(bool);

	// Object Array

	/* Creates a new blank array with specified size */
	void CreateObjectArray(int);
	/* Stores object into the array at given index */
	void StoreObjectInArray(int, DisplayableObject*);
	/* Removes all objects from array */
	void DestoryOldObjects();
	/* Tell all displayable objects to update themselves. Calls DoUpdate on each displayable object. */
	void UpdateAllObjects(int);
	/* Redraws the background behind each of the displayable objects, in their old positions. */
	void UndrawObjects();
	/* Draws draws the displayable objects in their new positions. */
	void DrawObjects();
	/* Gets the specified displayable object. */
	DisplayableObject* GetDisplayableObject(int);
	/* Send a specified notification value to all displayable objects */
	void NotifyAllObjects(int);
	/* Send a specified notification value to all displayable objects and count the number which give a non-zero response. */
	int NotifyAllObjectsGetCountNonZero(int);
	/* Send a specified notification value to all displayable objects and return the sum of the returned values. */
	int NotifyAllObjectsGetSum(int);
	/* Send a specified notification value to all displayable objects and return the largest of the returned values. */
	int NotifyAllObjectsGetMax(int);
	/* Send a specified notification value to all displayable objects and return the smallest of the returned values. */
	int NotifyAllObjectsGetMin(int);

	// Object Array - Extra

	/* Sets all objects' visibility */
	void SetObjectVisibility(bool);
	/* Resizes the object array (keeps data) */
	void ResizeObjectArray(int);
	/* Store object in array before given index */
	void StoreBeforeObjectInArray(int, DisplayableObject*);
	/* Store object at starts of object array */
	void StoreObjectInArrayAtBeginning(DisplayableObject*);
	/* Store object at end of object array */
	void StoreObjectInArrayAtEnd(DisplayableObject*);
	/* Remove object from array */
	void RemoveObjectFromArray(int);
	/* Removes multiple objects from array from given index */
	void RemoveMultipleObjectsFromArray(int, int);
	/* Returns the length of the object array */
	int GetLengthOfObjectArray();
	/* Get the index value of object from array */
	int GetIndexOfObjectFromArray(DisplayableObject*);


private:
	/* Array container class used to store DisplayableObject pointers */
	ObjectArray m_pObjectArray;
	/* Boolean which determines if all objects should update */
	bool m_bUpdateObjects = true;
};