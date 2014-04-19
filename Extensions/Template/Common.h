/* Common.h
 * This is the common header file included
 * by almost all other *.cpp files in
 * the project. Anything that gets put or
 * included in here will be available to you
 * everywhere else. You shouldn't need to
 * change anything in this file except
 * to include headers that you want and
 * to change the edition of MMF2 you want
 * to support.
 */

#pragma once

//Only define one of these at once:
//	#define TGFEXT	//TGF2, MMF2, MMF2 Dev
	#define MMFEXT	//MMF2, MMF2 Dev
//	#define PROEXT	//MMF2 Dev only

// -- Custom Shortcuts --
#define BadDeckID 0
#define IndexError 1
#define EmptyDeck 2
#define JustEmptiedDeck 3
#define LostCard 4
#define GainedCard 5
#define Shuffled 9
#define NewLoop 11

// Pointer to the main data for the extension. This pointer houses all the data for the extension and is global to the MMF2/Clickteam Fusion application
#define ExtensionData ((Extension::CardDeck *)Runtime.ReadGlobal((const TCHAR *)"GlobalCardData"))

#include "Edif.h"
#include "Resource.h"

//#include <someheader>
//#include "YourHeader.hpp"

/* stdtstring
 * A std::string that knows if you're using
 * unicode or not. (Protip: strings passed
 * to your extension A/C/Es still need to be
 * const TCHAR *, and the same goes for strings
 * returned from expressions and conditions).
 */
typedef std::basic_string<TCHAR> stdtstring;

#include "EditData.hpp"
#include "Extension.hpp"
