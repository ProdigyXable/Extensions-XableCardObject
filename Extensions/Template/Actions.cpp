/* Actions.cpp
 * This is where you should define the
 * behavior of your actions. Make sure
 * the parameters match those in the JSON
 * exactly! Double check Extension.h
 * as well.
 */

#include "Common.h"
#include <time.h>

using namespace std;

// Takes a deck/player index (from -1 to 15) and returns the appropriate vector pointer to the specified index in the global memory
vector<int> & Extension::get_Deck(int player_index)
{
	
	switch(player_index)
		{
			case -1:
				return  ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->Deck;
			case 0:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerA;
			case 1:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerB;
			case 2:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerC;
			case 3:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerD;
			case 4:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerE;
			case 5:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerF;
			case 6:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerG;
			case 7:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerH;
			case 8:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerI;
			case 9:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerJ;
			case 10:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerK;
			case 11:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerL;
			case 12:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerM;
			case 13:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerN;
			case 14:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerO;
			case 15:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->PlayerP;

			// Defaulter returned deck. May need to be removed in case of future problems
			default:
				return ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->Deck;
		}
			
}

// Creates a deck of 52 cards a specified amount of times
void Extension::create_deck(int decks, int home_deck)
{
	// Check to see if correct deck index was chosen
	if(home_deck >= -1 && home_deck <= 15)
	{
		vector<int> & Deck = get_Deck(home_deck);
		
		// Creates one of each card in the standard 52 card deck
		for(int index = 0; index < (52 * decks); index++)
		{
			// Puts all of the cards in numerical order (0, 1 , 2 ... 49, 50, 51)
			Deck.push_back(index % 52);
		}
	}

	// Executes when incorrect player/deck index is chosen ( x < -1 or x >15)
	else
	{
		Runtime.GenerateEvent(0);
	}

}

// Shuffles a deck by swapping cards 
// Small performs a swap (Deck size / 4) times
void Extension::shuffle_deck_small(int player_index)
{
	// Check to see if correct deck index was chosen
	if(player_index >= -1 && player_index <= 15)
	{
		// Finds the deck address from the specified player index
		vector<int> & Deck = get_Deck(player_index);

		// Ensures the specified deck has cards to shuffle
		if(Deck.size() > 0)
		{
			int dummy_value = 0, a = 0, b = 0;

			// Creates RNG number
			srand(time(NULL));
			for(unsigned int index = 0; index < (Deck.size()/4); index++)
			{
				// Gets generates two random deck indices
				a = (rand() % Deck.size());
				b = (rand() % Deck.size()); 		
			
				// Swaps cards at two random positions
				dummy_value = Deck.at(a);
				Deck.at(a) = Deck.at(b);
				Deck.at(b) = dummy_value;
			}

			((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->MostRecentShuffledDeck = player_index;
			
			// Immediate Condition to determine if a deck has just been shuffled
			Runtime.GenerateEvent(9);
		}

		// Executes when a deck is empty
		else
		{
			Runtime.GenerateEvent(2);
		}
	}

	// Executes when incorrect player/deck index is chosen ( x < -1 or x >15)
	else
	{
		Runtime.GenerateEvent(0);
	}
}

// Shuffles a deck by swapping cards 
// Medium performs a swap (Deck size) times
void Extension::shuffle_deck_medium(int player_index)
{
	if(player_index >= -1 && player_index <= 15)
	{
		vector<int> & Deck = get_Deck(player_index);
		if(Deck.size() > 0)
		{
			int dummy_value = 0, a = 0, b = 0;
			
			// Creates RNG number
			srand(time(NULL));
			for(unsigned int index = 0; index < (Deck.size()); index++)
			{
				// Gets generates two random deck indices
				a = (rand() % Deck.size());
				b = (rand() % Deck.size()); 		
			
				// Swaps cards at two random positions
				dummy_value = Deck.at(a);
				Deck.at(a) = Deck.at(b);
				Deck.at(b) = dummy_value;
			}

			// Immediate Condition to determine if a deck has just been shuffled
			((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->MostRecentShuffledDeck = player_index;
			Runtime.GenerateEvent(9);
		}

		// Executes when a deck is empty
		else
		{
			Runtime.GenerateEvent(2);
		}
	}
	
	// Executes when incorrect player/deck index is chosen ( x < -1 or x >15)
	else
	{
		Runtime.GenerateEvent(0);
	}

}

// Shuffles a deck by swapping cards 
// Large performs a swap (Deck size * 4) times
void Extension::shuffle_deck_large(int player_index)
{
	if(player_index >= -1 && player_index <=15)
	{
		vector<int> & Deck = get_Deck(player_index);
		if(Deck.size() > 0)
		{
			int dummy_value = 0, a = 0, b = 0;
			
			// Creates RNG number
			srand(time(NULL));
			for(unsigned int index = 0; index < (Deck.size()/4); index++)
			{
				// Gets generates two random deck indices
				a = (rand() % Deck.size());
				b = (rand() % Deck.size()); 		
			
				// Swaps cards at two random positions
				dummy_value = Deck.at(a);
				Deck.at(a) = Deck.at(b);
				Deck.at(b) = dummy_value;
			}

			// Immediate Condition to determine if a deck has just been shuffled
			((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->MostRecentShuffledDeck = player_index;
			Runtime.GenerateEvent(9);
		}
		
		// Executes when a deck is empty
		else
		{
			Runtime.GenerateEvent(2);
		}
	}

	// Executes when incorrect player/deck index is chosen ( x < -1 or x >15)
	else
	{
		Runtime.GenerateEvent(0);
	}
}

// Takes a specified card from one deck and places it at the end of another deck
void Extension::give_single_card(int player_index, int player2_index, int Deck_Losing_A_Card_index)
{
	if(player_index >= -1 && player_index <= 15)
	{
		if(player2_index >= -1 && player2_index <=15)
		{
			
			vector<int> & Deck_Gaining_A_Card = get_Deck(player_index);
			vector<int> & Deck_Losing_A_Card = get_Deck(player2_index);
			
			if(Deck_Losing_A_Card_index < Deck_Losing_A_Card.size() && Deck_Losing_A_Card_index >= 0 && Deck_Losing_A_Card.size() > 0)
			{
				// Adds card to end of augmented deck
				Deck_Gaining_A_Card.push_back(Deck_Losing_A_Card.at(Deck_Losing_A_Card_index));
				
				// Removes card from original deck
				Deck_Losing_A_Card.erase(Deck_Losing_A_Card.begin()+ Deck_Losing_A_Card_index);

				if(player_index != player2_index)
					{
						// Sets most recent values
						((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->MostRecentDecreasedDeck = player2_index;
						((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->MostRecentIncreasedDeck = player_index;
						
						// Called when a deck loses a card
						Runtime.GenerateEvent(4);

						// Called when a deck gains a card
						Runtime.GenerateEvent(5);	
					}

				// Immediate Condition to test if a Deck has just been emptied
				if(Deck_Losing_A_Card.size() == 0)
				{
					((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->MostRecentEmptyDeck = player2_index;
					Runtime.GenerateEvent(3);
					
				}
			}

			// Index out of Bounds Error [Negative Index]/[Index larger than deck size]
			else if(Deck_Losing_A_Card_index >= Deck_Losing_A_Card.size() || Deck_Losing_A_Card_index < 0)
			{
				Runtime.GenerateEvent(1);
			}


			// Executes when a deck is empty
			else if(Deck_Losing_A_Card.size() <= 0)
			{
				Runtime.GenerateEvent(2);
			}

		}

		// Executes when incorrect player/deck index is chosen ( x < -1 or x >15)
		else
		{
			Runtime.GenerateEvent(0);
		}
	}

	// Executes when incorrect player/deck index is chosen ( x < -1 or x >15)
	else
	{
		Runtime.GenerateEvent(0);
	}
		
	
}

// Takes a series of cards starting from one deck and places it at the end of another deck
void Extension::give_multiple_cards(int player_index, int player2_index, int Deck_Losing_A_Card_index, int card_count)
{
	if(player_index >= -1 && player_index <= 15)
	{
		if(player2_index >= -1 && player2_index <=15)
		{
			// Adds card to end of augmented deck
			vector<int> & Deck_Gaining_A_Card = get_Deck(player_index);
	
			
			vector<int> & Deck_Losing_A_Card = get_Deck(player2_index);

			if(Deck_Losing_A_Card_index < Deck_Losing_A_Card.size() && Deck_Losing_A_Card_index >= 0 && Deck_Losing_A_Card.size() > 0 &&
				card_count <= Deck_Losing_A_Card.size() && card_count > 0)
			{
				for(int loop_index = 0; loop_index < card_count; loop_index++)
				{
					// Adds card to end of augmented deck
					Deck_Gaining_A_Card.push_back(Deck_Losing_A_Card.at(Deck_Losing_A_Card_index));

					// Removes card from original deck
					Deck_Losing_A_Card.erase(Deck_Losing_A_Card.begin()+ Deck_Losing_A_Card_index);
					
					if(player_index != player2_index)
					{
						// Sets more recent values
						((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->MostRecentDecreasedDeck = player2_index;
						((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->MostRecentIncreasedDeck = player_index;
						
						// Called when a deck loses a card
						Runtime.GenerateEvent(4);

						// Called when a deck gains a card
						Runtime.GenerateEvent(5);
					}
				}

				// Immediate Condition to test if a Deck has just been emptied
				if(Deck_Losing_A_Card.size() == 0)
				{
					((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->MostRecentEmptyDeck = player2_index;
					Runtime.GenerateEvent(3);
				}
			}

			// Index out of Bounds Error [Negative Index]/[Index larger than deck size]
			else if(Deck_Losing_A_Card_index >= Deck_Losing_A_Card.size() || card_count > Deck_Losing_A_Card.size() || Deck_Losing_A_Card_index < 0)
			{
				Runtime.GenerateEvent(1);
			}


			// Executes when a deck is empty
			else if(Deck_Losing_A_Card.size() <= 0 || card_count < 0)
			{
				Runtime.GenerateEvent(2);
			}

		}

		else
		{
			// Invalid Deck ID Condition 
			Runtime.GenerateEvent(0);
		}
	}

	// Executes when incorrect player/deck index is chosen ( x < -1 or x >15)
	else
	{
		Runtime.GenerateEvent(0);
	}
		
	
}

// Distributes a specified amount of cards from one deck and to all decks in the deck queue
void Extension::split_deck_clockwise(int cards, int starting_number, int home_deck)
{
	if(starting_number < ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.size() && starting_number >= 0
		&& home_deck <= 15 && home_deck >=-1)
	{
		
		int loop_index = 0;
		int deck_index = 0;

		while(loop_index < cards)
		{
		
			// Correctly passes the card
			give_single_card(((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.at(deck_index),home_deck,0);
			
			// Initiates circular loop on the queue index
			deck_index = ((deck_index + 1 ) % ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.size());
			loop_index++;

		}
	}

	// Executes when incorrect player/deck index is chosen ( x < -1 or x >15)
	else if(home_deck < -1 || home_deck > 15)
	{
		Runtime.GenerateEvent(0);
	}

	// Index out of Bounds Error [Negative Index]/[Index larger than deck size]
	else
	{
		Runtime.GenerateEvent(1);
	}
}

// Distributes a specified amount of cards from one deck and to all decks in the deck queue (reversed in order)
void Extension::split_deck_counterclockwise(int cards, int starting_number, int home_deck)
{
	if(starting_number < ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.size() && starting_number >= 0
		&& home_deck >= -1 && home_deck <= 15)
	{
		int loop_index = 0;
		int deck_index = starting_number;

	
		while(loop_index < cards)
		{
			// Correctly passes cards
			give_single_card(((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.at(deck_index),home_deck,0);	
		
			// Initiates circular loop on queue index
			deck_index = ((deck_index + ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.size() - 1 ) % ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.size());
			loop_index++;

		}
	}

	// Executes when incorrect player/deck index is chosen ( x < -1 or x >15)
	else if(home_deck < -1 || home_deck > 15)
	{
		Runtime.GenerateEvent(0);
	}

	// Index out of Bounds Error [Negative Index]/[Index larger than deck size]
	else 
	{
		Runtime.GenerateEvent(1);
	}
	
}

// Shuffles a deck by swapping cards 
// Custom swaps cards the specified amount of times
void Extension::shuffle_deck_custom(int player_index,int card_swaps)
{
	if(player_index >= -1 && player_index <= 15)
	{
		vector<int> & Deck = get_Deck(player_index);
		if(Deck.size() > 0)
		{
			int dummy_value = 0;
			int a = 0;
			int b = 0;

			srand(time(NULL));
			for(unsigned int index = 0; index < (card_swaps); index++)
			{
				a = (rand() % Deck.size());
				b = (rand() % Deck.size()); 
		
				dummy_value = Deck.at(a);
				Deck.at(a) = Deck.at(b);
				Deck.at(b) = dummy_value;
			}

			// Immediate Condition to determine if a deck has just been shuffled
			((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->MostRecentShuffledDeck = player_index;
			Runtime.GenerateEvent(9);
			

		}

		// Executes when a deck is empty
		else
		{
			Runtime.GenerateEvent(2);
		}
	}

	// Executes when incorrect player/deck index is chosen ( x < -1 or x >15)
	else
	{
		Runtime.GenerateEvent(0);
	}
}

// Adds a deck/player index to the end of the deck queue
void Extension::AddQueue(int player_index)
{
	if(player_index >= -1 && player_index <= 15)
	{
		// Adds the deck to the specified queue
		((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.push_back(player_index);
	}

	// Executes when incorrect player/deck index is chosen ( x < -1 or x >15)
	else
	{
		Runtime.GenerateEvent(0);
	}
}

// Removes the deck at the specified deck queue form the deck queue
void Extension::RemoveQueue(int Queue_index)
{
	if(Queue_index < ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.size() && Queue_index > 0)
	{
		// Removes nth deck from the queue
		((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.erase(((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.begin()+ Queue_index);
		
		// Shrinks the queue index
		((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.shrink_to_fit();
	}
	// Index out of Bounds Error [Negative Index]/[Index larger than queue size]
	else
	{
		Runtime.GenerateEvent(1);
	}

}

// Removes all cards from all decks
void Extension::clear_all_decks()
{
	for(int index = -1; index <= 15; index++)
	{
		vector <int> & Deck = Extension::get_Deck(index);
		
		// Erases all contents of deck
		Deck.clear();

		// Shrinks each deck to its smallest size
		Deck.shrink_to_fit();

	}
}

// Used to loop through each card in a specified deck
void Extension::Loop_Through_Deck(int player_index)
{
	if(player_index >= -1 && player_index <= 15)
	{
		vector <int> & Deck = Extension::get_Deck(player_index);
	
		for(int index = 0; index < Deck.size(); index++)
		{
			// Sets LastLooped values
			((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopDeck = player_index;
			((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopCardValue = Deck.at(index);
			((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopIndex = index;
			
			// Trigger to signify a loop has been activated
			Runtime.GenerateEvent(11);
		}

		// Resets LastLooped Values
		((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopDeck = -100 ;
		((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopCardValue = -100;
		((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopIndex = -100;

	}

	// Executes when incorrect player/deck index is chosen ( x < -1 or x >15)
	else
	{
		Runtime.GenerateEvent(0);
	}
		
}