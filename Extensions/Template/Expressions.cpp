
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
TCHAR * Extension::reveal_Deck_CardName(int player_index, int index)
{
	int card_id = reveal_Deck_CardNumber(player_index, index);
	
	string card_name = "";
	switch(card_id/4)
	{
		case 0:
			card_name += "Two";	
			break;
		case 1:
			card_name += "Three";
			break;
		case 2:
			card_name += "Four";
			break;
		case 3:
			card_name += "Five";
			break;
		case 4:
			card_name += "Six";
			break;
		case 5:
			card_name += "Seven";
			break;
		case 6:
			card_name += "Eight";
			break;
		case 7:
			card_name += "Nine";
			break;
		case 8:
			card_name += "Ten";
			break;
		case 9:
			card_name += "Jack";
			break;
		case 10:
			card_name += "Queen";
			break;
		case 11:
			card_name += "King";
			break;
		case 12:
			card_name += "Ace";
			break;
	}

	if (card_id == -5)
	{
		card_name = "Error: Specified Deck Not Found";
	}

	else if(card_id == -2)
	{
		card_name = "Error: Specified Card Not Found";
	}

	else if(card_id == -4)
	{
		card_name = "Error: Unknown Error";
	}

	else if(card_id == -3)
	{
		card_name = "Error: Negative Card Index";
	}

	return Extension::Runtime.CopyString(card_name.c_str());
}
TCHAR * Extension::reveal_Deck_CardSuit(int player_index, int index)
{
	int card_id = reveal_Deck_CardNumber(player_index, index);
	
	string card_name = "";
	switch(card_id % 4)
	{
		case 0:
			card_name += "Diamond";
			break;
		case 1:
			card_name += "Club";
			break;
		case 2:
			card_name += "Heart";
			break;
		case 3:
			card_name += "Spade";
			break;
		
	}

	if (card_id == -5)
	{
		card_name = "Error: Specified Deck Not Found";
	}

	else if(card_id == -2)
	{
		card_name = "Error: Specified Card Not Found";
	}

	else if(card_id == -4)
	{
		card_name = "Error: Unknown Error";
	}

	else if(card_id == -3)
	{
		card_name = "Error: Negative Card Index";
	}

	return Extension::Runtime.CopyString(card_name.c_str());
}
TCHAR * Extension::reveal_Deck_Card(int player_index, int index)
{
	int card_id = reveal_Deck_CardNumber(player_index, index);
	
	string card_name = "";
	switch(card_id/4)
	{
		case 0:
			card_name += "Two";	
			break;
		case 1:
			card_name += "Three";
			break;
		case 2:
			card_name += "Four";
			break;
		case 3:
			card_name += "Five";
			break;
		case 4:
			card_name += "Six";
			break;
		case 5:
			card_name += "Seven";
			break;
		case 6:
			card_name += "Eight";
			break;
		case 7:
			card_name += "Nine";
			break;
		case 8:
			card_name += "Ten";
			break;
		case 9:
			card_name += "Jack";
			break;
		case 10:
			card_name += "Queen";
			break;
		case 11:
			card_name += "King";
			break;
		case 12:
			card_name += "Ace";
			break;
	}

	card_name += " of ";

	switch(card_id % 4)
	{
		case 0:
			card_name += "Diamonds";
			break;
		case 1:
			card_name += "Clubs";
			break;
		case 2:
			card_name += "Hearts";
			break;
		case 3:
			card_name += "Spades";
			break;
		
	}

	if (card_id == -5)
	{
		card_name = "Error: Specified Deck Not Found";
	}

	else if(card_id == -2)
	{
		card_name = "Error: Specified Card Not Found";
	}

	else if(card_id == -4)
	{
		card_name = "Error: Unknown Error";
	}

	else if(card_id == -3)
	{
		card_name = "Error: Negative Card Index";
	}

	return Extension::Runtime.CopyString(card_name.c_str());
}
TCHAR * Extension::convertCardID_Name(int card_id)
{
	string card_name = "";
	switch(card_id/4)
	{
		case 0:
			card_name += "Two";	
			break;
		case 1:
			card_name += "Three";
			break;
		case 2:
			card_name += "Four";
			break;
		case 3:
			card_name += "Five";
			break;
		case 4:
			card_name += "Six";
			break;
		case 5:
			card_name += "Seven";
			break;
		case 6:
			card_name += "Eight";
			break;
		case 7:
			card_name += "Nine";
			break;
		case 8:
			card_name += "Ten";
			break;
		case 9:
			card_name += "Jack";
			break;
		case 10:
			card_name += "Queen";
			break;
		case 11:
			card_name += "King";
			break;
		case 12:
			card_name += "Ace";
			break;
	}

	if(card_id < 0 || card_id > 51)
	{
		card_name = "Error: Invalid Card ID";
	}


	return Extension::Runtime.CopyString(card_name.c_str());

}
TCHAR * Extension::convertCardID_Suit(int card_id)
{
	string card_name = "";
	switch(card_id % 4)
	{
		case 0:
			card_name += "Diamond";
			break;
		case 1:
			card_name += "Club";
			break;
		case 2:
			card_name += "Heart";
			break;
		case 3:
			card_name += "Spade";
			break;
		
	}

	if(card_id < 0 || card_id > 51)
	{
		card_name = "Error: Invalid Card ID";
	}

	return Extension::Runtime.CopyString(card_name.c_str());

}
TCHAR * Extension::convertCardID(int card_id)
{
	string card_name = "";
	switch(card_id/4)
	{
		case 0:
			card_name += "Two";	
			break;
		case 1:
			card_name += "Three";
			break;
		case 2:
			card_name += "Four";
			break;
		case 3:
			card_name += "Five";
			break;
		case 4:
			card_name += "Six";
			break;
		case 5:
			card_name += "Seven";
			break;
		case 6:
			card_name += "Eight";
			break;
		case 7:
			card_name += "Nine";
			break;
		case 8:
			card_name += "Ten";
			break;
		case 9:
			card_name += "Jack";
			break;
		case 10:
			card_name += "Queen";
			break;
		case 11:
			card_name += "King";
			break;
		case 12:
			card_name += "Ace";
			break;
	}

	card_name += " of ";

	switch(card_id % 4)
	{
		case 0:
			card_name += "Diamonds";
			break;
		case 1:
			card_name += "Clubs";
			break;
		case 2:
			card_name += "Hearts";
			break;
		case 3:
			card_name += "Spades";
			break;
		
	}

	if(card_id < 0 || card_id > 51)
	{
		card_name = "Error: Invalid Card ID";
	}

	return Extension::Runtime.CopyString(card_name.c_str());
}
int Extension::deck_size(int player_index)
{
	vector<int> & Deck = Extension::get_Deck(player_index);
	return Deck.size();
}
int Extension::QueueIndex(int Queue_index)
{
	return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.at(Queue_index);
}
int Extension::QueueSize()
{
	return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.size();
}
int Extension::LastLoopedCard()
{
	return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopCardValue;
}
int Extension::LastLoopedDeck()
{
	return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopDeck;
}
int Extension::LastLoopedIndex()
{
	return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopIndex;
}