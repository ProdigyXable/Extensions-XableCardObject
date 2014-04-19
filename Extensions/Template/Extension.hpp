/* Extension.h
 * This is where you define your extension
 * class. Runtime variables and function
 * declarations go in here; A/C/E function
 * definitions go in their respective .cpp
 * files, other function definitions go in
 * Extension.cpp. This header is included
 * at the bottom of Common.h, so you have
 * access to everything included by it.
 */
#include <vector>

class Extension
{
public:
	/* rd
	 * This is a pointer to the classic
	 * RunData structure. Some things still
	 * have to be stored there for MMF2's
	 * sake, so you need to have acces to
	 * that data. You should not modify
	 * the rundata structure, however,
	 * as it is global to all extensions.
	 */
	RD *rd;

	/* rh
	 * This is a pointer to the RunHeader
	 * structure, which contains some
	 * application information.
	 */
	RunHeader *rh;

	/* Runtime
	 * This is EDIF's compendium of useful
	 * functions for every day life as an
	 * extension. You can trigger immediate
	 * events, read and write global data,
	 * etc. See the EDIF wiki for more
	 * information.
	 */
	Edif::Runtime Runtime;

	/* MinimumBuild
	 * Always set this to the latest build
	 * of MMF2 that has been released, unless
	 * you need to set it higher for a beta
	 * version of MMF2 to get access to some
	 * new SDK feature.
	 */
	static const int MinimumBuild = 254;

	/* Version
	 * This is the version of your extension
	 * that is stored in the editdata. You should
	 * only change this when your editdata structure
	 * changes, not just when you have a new version
	 * of your extension with new features.
	 */
	static const int Version = 1;

	/* OEFLAGS, OEPREFS
	 * These are settings for your extension
	 * that tell MMF2 how to treat your extension
	 * and what behaviors and responsibilities
	 * to add. Check the MMF2SDK Help file for
	 * more detailed information on the flags you
	 * can set and what they implicate.
	 */
	static const int OEFLAGS = OEFLAG_VALUES|OEFLAG_RUNBEFOREFADEIN|OEFLAG_NEVERKILL;
	static const int OEPREFS = 0;

	/* WindowProcPriority
	 * If your extension creates a Window
	 * and implements the WindowProc function,
	 * this is the priority for that stuff.
	 */
	static const int WindowProcPriority = 100;

	Extension(RD *rd, SerializedED *SED, createObjectInfo *COB);	//defined & documented in Extension.cpp
	~Extension();													//defined & documented in Extension.cpp


	/* Add any data you want to store in your
	 * extension to this class (eg. what you'd
	 * normally store in the rundata). Unlike
	 * other SDKs, you can store real C++
	 * objects with constructors and destructors,
	 * without having to call them manually or
	 * store a pointer.
	 */

	
	struct CardDeck
	{
		std::vector<int> Deck;
		std::vector<int> PlayerA;
		std::vector<int> PlayerB;
		std::vector<int> PlayerC;
		std::vector<int> PlayerD;
		std::vector<int> PlayerE;
		std::vector<int> PlayerF;
		std::vector<int> PlayerG;
		std::vector<int> PlayerH;
		std::vector<int> PlayerI;
		std::vector<int> PlayerJ;
		std::vector<int> PlayerK;
		std::vector<int> PlayerL;
		std::vector<int> PlayerM;
		std::vector<int> PlayerN;
		std::vector<int> PlayerO;
		std::vector<int> PlayerP;
		std::vector<int> DeckArrays;		
	//	static int TotalNumber;

		int MostRecentEmptyDeck;
		int MostRecentIncreasedDeck;
		int MostRecentDecreasedDeck;
		int MostRecentShuffledDeck;
		int LastLoopCardValue;
		int LastLoopDeck;
		int LastLoopIndex;

		CardDeck()
		{
			MostRecentEmptyDeck = -100;
			MostRecentDecreasedDeck = -100;
			MostRecentIncreasedDeck = -100;
			MostRecentShuffledDeck = -100;
			LastLoopDeck = -100;

			LastLoopCardValue = -100;
			LastLoopIndex = -100;

		}
	};

	//stdtstring MyString;
	//int MyInt;
	//std::vector<float> MyArray;


	/* Add your actions, conditions, and expressions
	 * as real class member functions here. The arguments
	 * (and return types for expressions/conditions)
	 * must match EXACTLY what you defined in the JSON.
	 * As a handy tip, all parameters will be either
	 * a pointer, an int, or a float (each only 4 bytes)
	 * and the same applies to return types. Remember to
	 * link the actions, conditions and expressions to their
	 * numeric IDs in the class constructor in Extension.cpp.
	 */

	//Actions - Defined in Actions.cpp
	void create_deck(int decks, int home_deck);

	void shuffle_deck_small(int player_index);
	void shuffle_deck_medium(int player_index);
	void shuffle_deck_large(int player_index);

	void shuffle_deck_custom(int player_index,int card_swaps);
	void split_deck_clockwise(int cards, int starting_number, int home_deck);
	void split_deck_counterclockwise(int cards, int starting_number, int home_deck);
	void give_single_card(int player_index, int player2_index, int Deck_Losing_A_Card_index);
	void AddQueue(int player_index);
	void RemoveQueue(int Queue_index);
	void give_multiple_cards(int player_index, int player2_index, int Deck_Losing_A_Card_index, int card_count);
	void clear_all_decks();
	void Loop_Through_Deck(int player_index);

	int reveal_Deck_CardNumber(int player_index, int index);
	int deck_size(int player_index);
	int QueueIndex(int Queue_index);
	int QueueSize();
	int LastLoopedCard();
	int LastLoopedDeck();
	int LastLoopedIndex();
	

	bool InvalidDeckID();
	bool IndexOutOfBounds();
	bool NullDeckSize();

	bool NewlyEmptiedDeck();
	bool DeckIncrease();
	bool DeckDecrease();
	bool DeckShuffled();

	bool SpecificDeckEmptied(int Deck_index);
	bool SpecificDeckIncreased(int Deck_index);
	bool SpecificDeckDecreased(int Deck_index);
	bool SpecificDeckShuffled(int Deck_index);

	bool Loop_Through_Deck_Immediate(int player_index);

	bool CardSpade(int card_id);
	bool CardHeart(int card_id);
	bool CardClub(int card_id);
	bool CardDiamond(int card_id);
	bool CardSuit(int card_id, int suit_id);
	bool CardValue(int card_id, int value);
	bool DeckSetExists();

	TCHAR * convertCardID_Name(int card_id);
	TCHAR * convertCardID_Suit(int card_id);
	TCHAR * convertCardID(int card_id);

	TCHAR *  reveal_Deck_CardName(int player_index, int index);		
	TCHAR *  reveal_Deck_CardSuit(int player_index, int index);		
	TCHAR *  reveal_Deck_Card(int player_index, int index);		

	std::vector<int> & get_Deck(int player_index);

	////

	short Handle();			//defined & documented in Extension.cpp
	short Display();		//defined & documented in Extension.cpp

	short Pause();			//defined & documented in Extension.cpp
	short Continue();		//defined & documented in Extension.cpp

	bool Save(HANDLE File);	//defined & documented in Extension.cpp
	bool Load(HANDLE File);	//defined & documented in Extension.cpp

	//defined & documented in Extension.cpp
	void Action(int ID, RD *rd, long param1, long param2);
	long Condition(int ID, RD *rd, long param1, long param2);
	long Expression(int ID, RD *rd, long param);
};
