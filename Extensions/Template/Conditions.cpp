/* Conditions.cpp
 * This is where you should define the
 * behavior of your conditions. Make sure
 * the parameters and return types match those
 * in the JSON exactly! Double check Extension.h
 * as well.
 */

#include "Common.h"

bool Extension::InvalidDeckID()
{
	return true;
}

bool Extension::IndexOutOfBounds()
{
	return true;
}
bool Extension::NullDeckSize()
{
	return true;
}
bool Extension::JustEmptiedDeck()
{
	return true;
}
bool Extension::DeckIncrease()
{
	return true;
}
bool Extension::DeckDecrease()
{
	return true;
}

bool Extension::SpecificDeckEmptied(int Deck_index)
{
	if(((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->MostRecentEmptyDeck == Deck_index)
	{
		return true;
	}

	else
	{
		return false;
	}
}
bool Extension::SpecificDeckDecreased(int Deck_index)
{
	if(((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->MostRecentDecreasedDeck == Deck_index)
	{
		return true;
	}

	else
	{
		return false;
	}
}
bool Extension::SpecificDeckIncreased(int Deck_index)
{
	if(((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->MostRecentIncreasedDeck == Deck_index)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Extension::DeckShuffled()
{
	return true;
}

bool Extension::SpecificDeckShuffled(int Deck_index)
{
	if(((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->MostRecentShuffledDeck == Deck_index)
	{
		return true;
	}

	else
	{
		return false;
	}
}
bool Extension::Loop_Through_Deck_Immediate(int player_index)
{
	if(((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopDeck == player_index)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Extension::CardClub(int card_id)
{
	if(card_id % 4 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Extension::CardSpade(int card_id)
{
	if(card_id % 4 == 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Extension::CardHeart(int card_id)
{
	if(card_id % 4 == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Extension::CardDiamond(int card_id)
{
	if(card_id % 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Extension::CardSuit(int card_id, int suit_id)
{
	if(card_id % 4 == suit_id && card_id >=0 && card_id <=51)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Extension::CardValue(int card_id, int value)
{
	if((card_id / 4)  == value && card_id >= 0 && card_id <=51)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Extension::DeckSetExists()
{
	int count = 0;
	for(int index = -1; index <= 15; index++)
	{
		count += Extension::deck_size(index);
	}
	
	if(count == 0)
	{
		return false;
	}

	else
	{
		return true;
	}
}
