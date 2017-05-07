#include "GameEngine.h"
#include "DisplayableObject.h"

/* Sub-class should actually do something, if relevant
e.g. move the player or any other sprites */
void GameEngine::GameAction()
{
	// If too early to act then do nothing
	if (!IsTimeToActWithSleep())
		return;

	// Don't act for another 15 ticks
	SetTimeToAct(15);

	// Tell all objects to update themselves.
	// If they need the screen to redraw then they should say so, so that GameRender() will
	// call the relevant function later.
	if (m_bUpdateObjects) { UpdateAllObjects(GetTime()); }
}

/* Sets if objects should update */
void GameEngine::ShouldObjectsUpdate(bool updateObjects) {
	m_bUpdateObjects = updateObjects;
}

/* Used to avoid creating arbitrary colours and instead have a set of useful values  */
unsigned int GameEngine::GetColour(int iColourIndex) const {
	switch (iColourIndex) {
		case 0: return 0xf44336;  // Red
		case 1: return 0xe91e63;  // Pink
		case 2: return 0x9c27b0;  // Purple
		case 3: return 0x673ab7;  // Deep purple
		case 4: return 0x3f51b5;  // Indigo
		case 5: return 0x2196f3;  // Blue
		case 6: return 0x03a9f4;  // Light blue
		case 7: return 0x00bcd4;  // Cyan
		case 8:	return 0x009688;  // Teal
		case 9: return 0x4caf50;  // Green
		case 10: return 0x8bc34a; // Light green
		case 11: return 0xcddc39; // Lime
		case 12: return 0xffeb3b; // Yellow
		case 13: return 0xffc107; // Amber
		case 14: return 0xff9800; // Orange
		case 15: return 0xff5722; // Deep orange
		case 16: return 0x795548; // Brown
		case 17: return 0x9e9e9e; // Grey
		case 18: return 0x607d8b; // Blue Grey
		default: return 0x000000; // Black
	}
}


/* ------------ */
/* Object array */
/* ------------ */

/* Creates a new blank array with specified size */
void GameEngine::CreateObjectArray(int iNumberObjects) {
	m_pObjectArray.reallocate(iNumberObjects);
}

/* Stores object into the array at given index */
void GameEngine::StoreObjectInArray(int iIndex, DisplayableObject* pObject) {
	m_pObjectArray[iIndex] = pObject;
}

/* Removes all objects from array */
void GameEngine::DestoryOldObjects() {
	m_pObjectArray.erase();
}

/* Tell all displayable objects to update themselves. Calls DoUpdate on each displayable object. */
void GameEngine::UpdateAllObjects(int iCurrentTime) {
	m_iDrawableObjectsChanged = 0;

	for (int i = 0; i < m_pObjectArray.getLength(); i++) {
		if (m_pObjectArray[i] != NULL) { m_pObjectArray[i]->DoUpdate(iCurrentTime); }

		if (m_iDrawableObjectsChanged) { return; }
	}

	// if (m_pObjectArray[m_pObjectArray.getLength() - 1] != NULL) { m_pObjectArray[m_pObjectArray.getLength() - 1]->DoUpdate(iCurrentTime); }
}

/* Redraws the background behind each of the displayable objects, in their old positions. */
void GameEngine::UndrawObjects() {
	m_iDrawableObjectsChanged = 0;

	for (int i = 0; i < m_pObjectArray.getLength(); i++) {
		if (m_pObjectArray[i] != NULL) { m_pObjectArray[i]->RedrawBackground(); }

		if (m_iDrawableObjectsChanged) { return; }
	}
}

/* Draws draws the displayable objects in their new positions. */
void GameEngine::DrawObjects() {
	m_iDrawableObjectsChanged = 0;

	for (int i = 0; i < m_pObjectArray.getLength(); i++) {
		DisplayableObject* tmp = m_pObjectArray[i];
		if (tmp != NULL && tmp->IsVisible() == true) { tmp->Draw(); }

		if (m_iDrawableObjectsChanged) { return; }
	}
}

/*
Gets the specified displayable object.
You may need to dynamic_cast the resulting pointer to the correct type.
*/
DisplayableObject* GameEngine::GetDisplayableObject(int iIndex) {
	return m_pObjectArray[iIndex];
}

/* Send a specified notification value to all displayable objects */
void GameEngine::NotifyAllObjects(int iSignalNumber) {
	for (int i = 0; i < m_pObjectArray.getLength(); i++) {
		if (m_pObjectArray[i] != NULL) { m_pObjectArray[i]->Notify(iSignalNumber); }
	}
}

/* Send a specified notification value to all displayable objects and count the number which give a non-zero response. */
int GameEngine::NotifyAllObjectsGetCountNonZero(int iSignalNumber) {
	int iReturn = 0;

	for (int i = 0; i < m_pObjectArray.getLength(); i++) {
		if (m_pObjectArray[i] != NULL) {
			if (m_pObjectArray[i]->Notify(iSignalNumber) != 0) {
				iReturn++;
			}
		}
	}

	return iReturn;
}

/* Send a specified notification value to all displayable objects and return the sum of the returned values. */
int GameEngine::NotifyAllObjectsGetSum(int iSignalNumber) {
	int iReturn = 0;

	for (int i = 0; i < m_pObjectArray.getLength(); i++) {
		if (m_pObjectArray[i] != NULL) {
			iReturn += m_pObjectArray[i]->Notify(iSignalNumber);
		}
	}

	return iReturn;
}

/* Send a specified notification value to all displayable objects and return the largest of the returned values. */
int GameEngine::NotifyAllObjectsGetMax(int iSignalNumber) {
	int iReturn = 0;

	for (int i = 0; i < m_pObjectArray.getLength(); i++) {
		if (m_pObjectArray[i] != NULL) {
			int iVal = m_pObjectArray[i]->Notify(iSignalNumber);
			if (iVal > iReturn) { iReturn = iVal; }
		}
	}

	return iReturn;
}

/* Send a specified notification value to all displayable objects and return the smallest of the returned values. */
int GameEngine::NotifyAllObjectsGetMin(int iSignalNumber) {
	int iReturn = INT_MAX;

	for (int i = 0; i < m_pObjectArray.getLength(); i++) {
		if (m_pObjectArray[i] != NULL) {
			int iVal = m_pObjectArray[i]->Notify(iSignalNumber);
			if (iVal < iReturn) { iReturn = iVal; }
		}
	}

	return iReturn;
}

/* Sets all objects' visibility */
void GameEngine::SetObjectVisibility(bool visible) {
	m_iDrawableObjectsChanged = 0;

	for (int i = 0; i < m_pObjectArray.getLength(); i++) {
		if (m_pObjectArray[i] != NULL) { m_pObjectArray[i]->SetVisible(visible); }

		if (m_iDrawableObjectsChanged) { return; }
	}
}

/* Resizes the object array (keeps data) */
void GameEngine::ResizeObjectArray(int iNewSize) {
	m_pObjectArray.resize(iNewSize);
}

/* Store object in array before given index */
void GameEngine::StoreBeforeObjectInArray(int iIndex, DisplayableObject* pObject) {
	m_pObjectArray.insertBefore(iIndex, pObject);
}

/* Store object at starts of object array */
void GameEngine::StoreObjectInArrayAtBeginning(DisplayableObject* pObject) {
	m_pObjectArray.insertAtBeginning(pObject);
}

/* Store object at end of object array */
void GameEngine::StoreObjectInArrayAtEnd(DisplayableObject* pObject) {
	m_pObjectArray.insertAtEnd(pObject);
}

/* Remove object from array */
void GameEngine::RemoveObjectFromArray(int iIndex) {
	m_pObjectArray.remove(iIndex);
}

/* Removes multiple objects from array from given index */
void GameEngine::RemoveMultipleObjectsFromArray(int iIndex, int iNoElements) {
	m_pObjectArray.remove(iIndex, iNoElements);
}

/* Returns the length of the object array */
int GameEngine::GetLengthOfObjectArray() {
	return m_pObjectArray.getLength();
}

/* Get the index value of object from array */
int GameEngine::GetIndexOfObjectFromArray(DisplayableObject* pObject) {
	return m_pObjectArray.getIndex(pObject);
}