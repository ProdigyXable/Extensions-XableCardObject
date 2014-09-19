
/* Expressions.cpp
 * This is where you should define the
 * behavior of your expressions. Make sure
 * the parameters and return types match those
 * in the JSON exactly! Double check Extension.h
 * as well.
 */

#include "Common.h"
#include <string>

using namespace std;

// Reveals the card_id in a specified deck at a specified deck position
int Extension::reveal_Deck_CardNumber(int player_index, int index)
{
	if(player_index >= -1 && player_index <= 15)
	{
		vector<int> & Deck = Extension::get_Deck(player_index);
		if((index + 1 <= Deck.size()) && (index >= 0))
		{
			return Deck.at(index);
		}

		else if((index + 1 > Deck.size()) && (index >= 0))
		{
			return -2;
		}

		else if(index < 0)
		{
			return -3;
		}

		else
		{
			return -4;
		}
	}

	return -5;
}

// Reveals the name of a card in a specified deck at a specified deck position
TCHAR * Extension::reveal_Deck_CardName(int player_index, int index)
{
	int card_id = reveal_Deck_CardNumber(player_index, index);
	
	TCHAR * card_name;
	
	if (card_id == -5)
	{
		card_name = _T("Error: Specified Deck Not Found");
	}

	else if(card_id == -2)
	{
		card_name = _T("Error: Specified Card Not Found");
	}

	else if(card_id == -4)
	{
		card_name = _T("Error: Unknown Error");
	}

	else if(card_id == -3)
	{
		card_name = _T("Error: Negative Card Index");
	}

	else
	{
		return Extension::convertCardID_Name(card_id);
	}
	
	TCHAR * error_string = (TCHAR *) Runtime.Allocate(_tcslen(card_name) + 1);
	_tcscpy(error_string,card_name);

	return error_string;
}

// Reveals the suit of a card in a specified deck at a specified deck position
TCHAR * Extension::reveal_Deck_CardSuit(int player_index, int index)
{
	int card_id = reveal_Deck_CardNumber(player_index, index);
	
	TCHAR * card_name;
	
	if (card_id == -5)
	{
		card_name = _T("Error: Specified Deck Not Found");
	}

	else if(card_id == -2)
	{
		card_name = _T("Error: Specified Card Not Found");
	}

	else if(card_id == -4)
	{
		card_name = _T("Error: Unknown Error");
	}

	else if(card_id == -3)
	{
		card_name = _T("Error: Negative Card Index");
	}

	else
	{
		return Extension::convertCardID_Suit(card_id);
	}
	
	TCHAR * error_string = (TCHAR *) Runtime.Allocate(_tcslen(card_name) + 1);
	_tcscpy(error_string,card_name);

	return error_string;
}

// Reveals the full name of a card (name + suit) in a specified deck at a specified deck position
TCHAR * Extension::reveal_Deck_Card(int player_index, int index)
{
	int card_id = reveal_Deck_CardNumber(player_index, index);
	
	TCHAR * card_name;
	
	if (card_id == -5)
	{
		card_name = _T("Error: Specified Deck Not Found");
	}

	else if(card_id == -2)
	{
		card_name = _T("Error: Specified Card Not Found");
	}

	else if(card_id == -4)
	{
		card_name = _T("Error: Unknown Error");
	}

	else if(card_id == -3)
	{
		card_name = _T("Error: Negative Card Index");
	}

	else
	{
		return Extension::convertCardID(card_id);
	}
	
	TCHAR * error_string = (TCHAR *) Runtime.Allocate(_tcslen(card_name) + 1);
	_tcscpy(error_string,card_name);

	return error_string;
}

// Reveals the name of a card based on its card_id
TCHAR * Extension::convertCardID_Name(int card_id)
{
	TCHAR * card_name;
	switch(card_id/4)
	{
		case 0:
			card_name = _T("Two");	
			break;
		case 1:
			card_name = _T("Three");
			break;
		case 2:
			card_name = _T("Four");
			break;
		case 3:
			card_name = _T("Five");
			break;
		case 4:
			card_name = _T("Six");
			break;
		case 5:
			card_name = _T("Seven");
			break;
		case 6:
			card_name = _T("Eight");
			break;
		case 7:
			card_name = _T("Nine");
			break;
		case 8:
			card_name = _T("Ten");
			break;
		case 9:
			card_name = _T("Jack");
			break;
		case 10:
			card_name = _T("Queen");
			break;
		case 11:
			card_name = _T("King");
			break;
		case 12:
			card_name = _T("Ace");
			break;
	}

	if(card_id < 0 || card_id > 51)
	{
		card_name = _T("Error: Invalid Card ID");
	}

	TCHAR * correct_string = (TCHAR *) Runtime.Allocate(_tcslen(card_name) + 1);
	_tcscpy(correct_string, card_name);

	return correct_string;
}

// Reveals the suit of a card based on its card_id
TCHAR * Extension::convertCardID_Suit(int card_id)
{
	TCHAR * card_name;
	int length = 0;

	switch(card_id % 4)
	{
		case 0:
			card_name = _T("Diamond");
			length = 8;
			break;
		case 1:
			card_name = _T("Club");
			length = 5;
			break;
		case 2:
			card_name = _T("Heart");
			length = 6;
			break;
		case 3:
			card_name = _T("Spade");
			length = 6;
			break;
	}

	if(card_id < 0 || card_id > 51)
	{
		card_name = _T("Error: Invalid Card ID");
		length = 21;
	}

	TCHAR * correct_string = (TCHAR *) Runtime.Allocate(length);
	_tcscpy(correct_string, card_name);
	
	return correct_string;
}

// Reveals the full name (name + suit) of a card based on its card_id
TCHAR * Extension::convertCardID(int card_id)
{
	#ifdef _UNICODE
		wstring card_name;
	#else
		string card_name;
	#endif

	int length = 0;

	switch(card_id/4)
	{
		case 0:
			card_name = _T("Two of ");	
			 
			break;
		case 1:
			card_name = _T("Three of ");
			break;
		case 2:
			card_name = _T("Four of ");
			break;
		case 3:
			card_name = _T("Five of ");
			break;
		case 4:
			card_name = _T("Six of ");
			break;
		case 5:
			card_name = _T("Seven of ");
			break;
		case 6:
			card_name = _T("Eight of ");
			break;
		case 7:
			card_name = _T("Nine of ");
			break;
		case 8:
			card_name = _T("Ten of ");
			break;
		case 9:
			card_name = _T("Jack of ");
			break;
		case 10:
			card_name = _T("Queen of ");
			break;
		case 11:
			card_name = _T("King of ");
			break;
		case 12:
			card_name = _T("Ace of ");
			break;
	}

		length = _tcslen((const TCHAR *)card_name.c_str());

	switch(card_id % 4)
	{
		case 0:
			card_name.append(_T("Diamonds"));
			length += 9;
			break;
		case 1:
			card_name.append(_T("Clubs"));
			length += 6;
			break;
		case 2:
			card_name.append(_T("Hearts"));
			length += 7;
			break;
		case 3:
			card_name.append(_T("Spades"));
			length += 7;
			break;
		
	}

	if(card_id < 0 || card_id > 51)
	{
		card_name = _T("Error: Invalid Card ID");
		length = 23;
	}

	TCHAR * correct_string = (TCHAR *) Runtime.Allocate(length);
	_tcscpy(correct_string, (TCHAR *)card_name.c_str());
	return correct_string;
}

// Returns the size of a specified deck
int Extension::deck_size(int player_index)
{
	vector<int> & Deck = Extension::get_Deck(player_index);
	return Deck.size();
}

// Returns the deck_id at a specified Queue index
int Extension::QueueIndex(int Queue_index)
{
	return ExtensionData->DeckArrays.at(Queue_index);
}

// Returns the size of the queue
int Extension::QueueSize()
{
	return ExtensionData->DeckArrays.size();
}

// Returns the card_id of the last looped card in the last looped deck
int Extension::LastLoopedCard()
{
	return ExtensionData->LastLoopCardValue;
}

// Returns the deck_id of the last looped deck
int Extension::LastLoopedDeck()
{
	return ExtensionData->LastLoopDeck;
}

// Returns the card_index of the last looped card in the last looped deck
int Extension::LastLoopedIndex()
{
	return ExtensionData->LastLoopIndex;
}