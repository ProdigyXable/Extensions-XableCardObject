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
		}
			
}
void Extension::create_deck(int decks, int home_deck)
{
	if(home_deck >= -1 && home_deck <= 15)
	{
		vector<int> & Deck = get_Deck(home_deck);
	
		for(int index = 0; index < (52 * decks); index++)
		{
			Deck.push_back(index % 52);
		}
	}

	else
	{
		Runtime.GenerateEvent(0);
	}


	
}
void Extension::shuffle_deck_small(int player_index)
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
			for(unsigned int index = 0; index < (Deck.size()/4); index++)
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

		else
		{
			Runtime.GenerateEvent(2);
		}
	}

	else
	{
		Runtime.GenerateEvent(0);
	}
}
void Extension::shuffle_deck_medium(int player_index)
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
			for(unsigned int index = 0; index < (Deck.size()); index++)
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

		else
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
void Extension::shuffle_deck_large(int player_index)
{
	if(player_index >= -1 && player_index <=15)
	{
		vector<int> & Deck = get_Deck(player_index);
		if(Deck.size() > 0)
		{
			int dummy_value = 0;
			int a = 0;
			int b = 0;
			srand(time(NULL));
			for(unsigned int index = 0; index < (Deck.size()*4); index++)
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
		
		else
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
				Deck_Gaining_A_Card.push_back(Deck_Losing_A_Card.at(Deck_Losing_A_Card_index));
				Deck_Losing_A_Card.erase(Deck_Losing_A_Card.begin()+ Deck_Losing_A_Card_index);

				if(player_index != player2_index)
					{
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

			else if(Deck_Losing_A_Card_index >= Deck_Losing_A_Card.size())
			{
				Runtime.GenerateEvent(1);
			}

			else if(Deck_Losing_A_Card.size() <= 0)
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

	else
	{
		// Invalid Deck ID Condition 
		Runtime.GenerateEvent(0);
	}
		
	
}
void Extension::give_multiple_cards(int player_index, int player2_index, int Deck_Losing_A_Card_index, int card_count)
{
	if(player_index >= -1 && player_index <= 15)
	{
		if(player2_index >= -1 && player2_index <=15)
		{
			vector<int> & Deck_Gaining_A_Card = get_Deck(player_index);
			vector<int> & Deck_Losing_A_Card = get_Deck(player2_index);
			if(Deck_Losing_A_Card_index < Deck_Losing_A_Card.size() && Deck_Losing_A_Card_index >= 0 && Deck_Losing_A_Card.size() > 0 &&
				card_count <= Deck_Losing_A_Card.size() && card_count > 0)
			{
				for(int loop_index = 0; loop_index < card_count; loop_index++)
				{
					Deck_Gaining_A_Card.push_back(Deck_Losing_A_Card.at(Deck_Losing_A_Card_index));
					Deck_Losing_A_Card.erase(Deck_Losing_A_Card.begin()+ Deck_Losing_A_Card_index);
					
					if(player_index != player2_index)
					{
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

			else if(Deck_Losing_A_Card_index >= Deck_Losing_A_Card.size() || card_count > Deck_Losing_A_Card.size())
			{
				Runtime.GenerateEvent(1);
			}

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

	else
	{
		Runtime.GenerateEvent(0);
	}
		
	
}
void Extension::split_deck_clockwise(int cards, int starting_number, int home_deck)
{
	if(starting_number < ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.size() && starting_number >= 0
		&& home_deck <= 15 && home_deck >=-1)
	{
		
		int loop_index = 0;
		int deck_index = 0;

		while(loop_index < cards)
		{
		
			give_single_card(((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.at(deck_index),home_deck,0);
			deck_index = ((deck_index + 1 ) % ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.size());
			loop_index++;

		}
	}

	else if(home_deck < -1 || home_deck > 15)
	{
		Runtime.GenerateEvent(0);
	}

	else 
	{
		Runtime.GenerateEvent(1);
	}
}
void Extension::split_deck_counterclockwise(int cards, int starting_number, int home_deck)
{
	if(starting_number < ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.size() && starting_number >= 0
		&& home_deck >= -1 && home_deck <= 15)
	{
		int loop_index = 0;
		int deck_index = starting_number;

	
		while(loop_index < cards)
		{
		
			Extension::give_single_card(((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.at(deck_index),home_deck,0);	
			deck_index = ((deck_index + ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.size() - 1 ) % ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.size());
			loop_index++;

		}
	}

	else if(home_deck < -1 || home_deck > 15)
	{
		Runtime.GenerateEvent(0);
	}

	else 
	{
		Runtime.GenerateEvent(1);
	}
	
}
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
		else
		{
			Runtime.GenerateEvent(2);
		}
	}

	else
	{
		Runtime.GenerateEvent(0);
	}
}
void Extension::AddQueue(int player_index)
{
	if(player_index >= -1 && player_index <= 15)
	{
		((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.push_back(player_index);
	}
	else
	{
		Runtime.GenerateEvent(0);
	}
}
void Extension::RemoveQueue(int Queue_index)
{
	if(Queue_index < ((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.size() && Queue_index > 0)
	{
		((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.erase(((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.begin()+ Queue_index);
		((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->DeckArrays.shrink_to_fit();
	}

	else
	{
		Runtime.GenerateEvent(1);
	}

}
void Extension::clear_all_decks()
{
	for(int index = -1; index <= 15; index++)
	{
		vector <int> & Deck = Extension::get_Deck(index);
		Deck.clear();
		Deck.shrink_to_fit();

	}
}
void Extension::Loop_Through_Deck(int player_index)
{
	if(player_index >= -1 && player_index <= 15)
	{
		vector <int> & Deck = Extension::get_Deck(player_index);
	
		for(int index = 0; index < Deck.size(); index++)
		{
			((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopDeck = player_index;
			((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopCardValue = Deck.at(index);
			((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopIndex = index;
			// Trigger to signify a loop has been activated
			Runtime.GenerateEvent(11);
		}

		((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopDeck = -100 ;
		((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopCardValue = -100;
		((Extension::CardDeck *)Runtime.ReadGlobal("GlobalCardData"))->LastLoopIndex = -100;

	}

	else
	{
		Runtime.GenerateEvent(0);
	}
		
}