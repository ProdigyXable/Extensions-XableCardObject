/* Conditions.cpp
 * This is where you should define the
 * behavior of your conditions. Make sure
 * the parameters and return types match those
 * in the JSON exactly! Double check Extension.h
 * as well.
 */

#include "Common.h"

// Executes when an action/expression uses an invalid deck id -> x <-1 or x > 15
bool Extension::InvalidDeckID()
{
	return true;
}

// Executes when an action/expression uses an invalid index value -> such as a negative index
bool Extension::IndexOutOfBounds()
{
	return true;
}

// Executes when a deck has 0 cards in it
bool Extension::NullDeckSize()
{
	return true;
}

// Executes when a deck has just lost its final card
bool Extension::NewlyEmptiedDeck()
{
	return true;
}

// Executes when a deck increases in size
bool Extension::DeckIncrease()
{
	return true;
}

// Executes when a deck decreases in size
bool Extension::DeckDecrease()
{
	return true;
}

// Executes when a specified deck lost its final card 
bool Extension::SpecificDeckEmptied(int Deck_index)
{
	if(ExtensionData->MostRecentEmptyDeck == Deck_index)
	{
		return true;
	}

	else
	{
		return false;
	}
}

// Executes when a specified deck has decreased in size
bool Extension::SpecificDeckDecreased(int Deck_index)
{
	if(ExtensionData->MostRecentDecreasedDeck == Deck_index)
	{
		return true;
	}

	else
	{
		return false;
	}
}

// Executes when a specified deck has increased in size
bool Extension::SpecificDeckIncreased(int Deck_index)
{
	if(ExtensionData->MostRecentIncreasedDeck == Deck_index)
	{
		return true;
	}

	else
	{
		return false;
	}
}

// Executes when any deck has just been shuffled
bool Extension::DeckShuffled()
{
	return true;
}

// Executes when a specified deck has just been shuffled
bool Extension::SpecificDeckShuffled(int Deck_index)
{
	if(ExtensionData->MostRecentShuffledDeck == Deck_index)
	{
		return true;
	}

	else
	{
		return false;
	}
}

// Executes if the specified deck was just looped through
bool Extension::Loop_Through_Deck_Immediate(int player_index)
{
	if(ExtensionData->LastLoopDeck == player_index)
	{
		return true;
	}

	else
	{
		return false;
	}
}

// Returns true if the specified card is a club
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

// Returns true if the specified card is a spade
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

// Returns true if the specified card is a heart
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

// Returns true if the specified card is a diamond
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

// Returns true if the specified card id matches the specified suit id
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


// Returns true if the specified card is a certain value, such as card_id 50 = Ace (14)
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

// Returns true if there are any cards in any deck
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
