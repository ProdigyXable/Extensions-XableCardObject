        ��  ��                  �      �� ��     0 	        �4   V S _ V E R S I O N _ I N F O     ���                                           S t r i n g F i l e I n f o   �   0 4 0 9 0 4 e 4   4 
  C o m p a n y N a m e     C l i c k t e a m   @   F i l e D e s c r i p t i o n     E d i f   O b j e c t   *   F i l e V e r s i o n     2 . 0 0     0   I n t e r n a l N a m e   E d i f E x t   Z   L e g a l C o p y r i g h t   C o p y r i g h t   �   2 0 1 2   C l i c k t e a m     @   O r i g i n a l F i l e n a m e   E d i f E x t . m f x   :   P r o d u c t V e r s i o n   1 ,   0 ,   0 ,   1     2 	  S p e c i a l B u i l d   0 0 0 0 0 0 0 1     D    V a r F i l e I n f o     $    T r a n s l a t i o n     	�       ��
 ���     0 	        %Y_  (   E D I F   ��e       0 	        �PNG

   IHDR           ���   tRNS      n��  IDATx����kAƿ�{�CQN	⡠�PH� A�B,b!�l�A��F<����H1^asE�Tﻳ������ޞw�U�3o�w�}�v�J��l���Be��JC��]�p���@D� U " D%^�8&���n|�{&,� i �`f H�W-�����P�3�;#8�kfF(M=����(*���Ͽ��ͧ�I���?�t�+/n���*��\����� k����j��s��޻�e�W�� ���"�����EU��h��hwz �6����VKU_n테\ 9Ypqc]o4D�&���w�2_� w���FI�I7����f�����y�E�����c��7)�D����ݫw1
�^�98������.��y���U���I�����R�����э�W���`"ck0���J�_M(`|89i�.���) c���/��ݩ)F�K�����������	O2�Pe��3������3���]^s �g�t��c�J���/�Yxc*��V~7�U}}�� >̩Gq�    IEND�B`� �#  (   E D I F   ��f       0 	        {
    "About": {
        "Name": "Xable Card Object",
        "Author": "Samuel Benton",
        "Copyright": "Copyright (C) 2013 Xable Enterprises",
        "Comment": "An extension primarily to aid the composition of card games",
        "URL": "http://www.xable.us",
        "Help": "http://www.xable.us/xable-card-object.html",
        "Identifier": "PXCE"
    },
    "ActionMenu": 
	[
		"Separator",	
        [0,"Create House Deck"],
        "Separator",
        ["Shuffle",
			[1,"Small Shuffle"],
			[2,"Medium Shuffle"],
			[3,"Large Shuffle"],
			[7,"Custom Shuffle"],
		],
		"Separator",
		["Split Decks",
			[4, "Split Deck Clockwise"],
			[5, "Split Deck Counter Clockwise"],
		],
		["Queues",
				[8,"Add Deck to Queue"],
				[9,"Remove Nth Deck from Queue"],
		],

		["Card Exchange",
			[6, "Pass Single Card"],
			[10,"Pass Several Cards"],
		],
		"Separator",
		[11, "Clear All Decks"],
		"Separator",
		[12, "Loop through All Cards in Deck"],
		"Separator",
		
    ],

    "ConditionMenu": 
	[
		"Separator",
		["Errors",
			[0,"Invalid Deck ID Chosen"],
			[1,"Index Out of Bounds"],
			[2,"Empty Deck Loses a Card"],
		],
		"Separator",
		["Deck Conditions",
			["Any Deck",
				[3, "Deck Just Emptied"],
				[4, "Deck Size Just Increased"],
				[5, "Deck Size Just Decreased"],
				[9, "Deck Just Shuffled"],
			],

			["Specific Deck",
				[6, "Specific Deck Just Emptied"],
				[7, "Specific Deck Size Just Increased"],
				[8, "Specific Deck Size Just Decreased"],
				[10, "Specific Deck Just Shuffled"],
			],
		],
		["Card Tests",
			["Suits",
				[12, "Card is a Club?"],
				[13, "Card is a Diamond?"],
				[14, "Card is a Heart?"],
				[15, "Card is a Spade?"],
				"Separator",
				[16, "Card is a Varied Suit?"],
				"Separator",
			],
			
			["Values",
				[17, "Card is a Certain Value?"],
			],
			"Separator",
			[18, "House Deck Exists?"],
		],
		"Separator",
		[11, "On Card Loop"],
	],

    "ExpressionMenu": 
	[
		"Separator",
		["Card Values",
			[0,"Show Card ID"],
		], 
		 
		["Card Name/Suit from Deck Position",
		    [1,"Show Card Name"],
			[2,"Show Card Suit"],
			[3,"Show Full Card"],
		],
		["Card Name/Suit from Card ID",
			[4,"Return Card Name"],
			[5,"Return Card Suit"],
			[6,"Return Full Card"],
		],
		
		"Separator",
		
		[7,"Deck Size"],
		
		"Separator",
		
		[8,"Deck at Queue Index 'N'"],
		[9,"Queue Size"],
		
		"Separator",
		["Loops",
			[10, "Last Looped Card"],
			[11, "Last Looped Deck"],
			[12, "Index of Current Loop"],
		],
		"Separator",
	],


    "Actions": [
        {"Title": "Create house deck with %0 total card decks",
            "Parameters": 
			[
				["Integer","Number of Decks"],
            ],
        },
		 {"Title": "Perform a small shuffle on deck %0",
            "Parameters": 
			[
				["Integer","Deck ID"],
            ],
		},
		 {"Title": "Perform a medium shuffle on deck %0",
            "Parameters": 
			[
				["Integer","Deck ID"],
            ],
		},
		 {"Title": "Perform a large shuffle on deck %0",
            "Parameters": 
			[
				["Integer","Deck ID"],
            ],
    },
	 {"Title": "Split the deck clockwise starting with deck %1, dealing %0 cards",
            "Parameters": 
			[
				["Integer","Total number of dealt cards"],
				["Integer","Intial Queue Index"],
            ],
    },
	{"Title": "Split the deck counter clockwise starting with deck %1, dealing %0 cards",
            "Parameters": 
			[
				["Integer","Total number of dealt cards"],
				["Integer","Intial Queue Index"],
            ],
    },
	{"Title": "Pass one card to deck %0 from the %2th card of deck %1",
            "Parameters": 
			[
				["Integer","Deck gaining a card"],
				["Integer","Deck losing a card"],
				["Integer","Index of passed card"],
            ],
    },
	{"Title": "Perform a custom shuffle on deck %0, exchanging cards %1 times",
            "Parameters": 
			[
				["Integer","Deck ID"],
				["Integer","Card exchange count"],
            ],
	},
	{"Title": "Add Deck %0 to Deck Queue",
            "Parameters": 
			[
				["Integer","Deck ID"],
            ],
	},
	{"Title": "Remove %0th Deck from the  Deck Queue",
            "Parameters": 
			[
				["Integer","Queue Index"],
            ],
	},
		{"Title": "Pass %3 cards to deck %0 from the %2th card of deck %1",
            "Parameters": 
			[
				["Integer","Deck gaining a card"],
				["Integer","Deck losing a card"],
				["Integer","Index of passed card"],
				["Integer","Amount of passed cards"],
            ],
    },
		{"Title": "Clear and Empty All Decks",
           
    },
	{"Title": "Perform a loop for deck %0",
            "Parameters": 
			[
				["Integer","Deck ID"],
            ],
		},
],
    "Conditions": 
	[
		{	"Title": "Invalid Deck ID chosen",
			
			"Triggered": true
		},
		{	"Title": "Index out of bounds",
			
			"Triggered": true
		},
		{	"Title": "Empty deck loses a card",
			
			"Triggered": true
		},
		{	"Title": "Any Deck has been emptied?",
			
			"Triggered": true
		},
		{	"Title": "Any Deck decreased in size?",
			
			"Triggered": true
		},
		{	"Title": "Any Deck increased in size?",
			
			"Triggered": true
		},
		{	"Title": "Deck %0 empty?",
       
         "Parameters": 
			[
				["Integer","Deck ID"],
            ],

			"Triggered": false
		},
		{	"Title": "Deck %0 decreased?",
       
         "Parameters": 
			[
				["Integer","Deck ID"],
            ],

			"Triggered": false
		},
		{	"Title": "Deck %0 increased?",
       
         "Parameters": 
			[
				["Integer","Deck ID"],
            ],

			"Triggered": false
		},
		{	"Title": "Any Deck has been shuffled?",
			
			"Triggered": true
		},

		{	"Title": "Deck %0 shuffled?",
       
         "Parameters": 
			[
				["Integer","Deck ID"],
            ],

			"Triggered": false
		},
		{	"Title": "On card loop for Deck %0?",
       
         "Parameters": 
			[
				["Integer","Deck ID"],
            ],

			"Triggered": true
		},
		{	"Title": "Card %0 is a club?",
       
         "Parameters": 
			[
				["Integer","Card Value"],
            ],

			"Triggered": false
		},
		{	"Title": "Card %0 is a diamond?",
       
         "Parameters": 
			[
				["Integer","Card Value"],
            ],

			"Triggered": false
		},
		{	"Title": "Card %0 is a heart?",
       
         "Parameters": 
			[
				["Integer","Card Value"],
            ],

			"Triggered": false
		},
		{	"Title": "Card %0 is a spade?",
       
         "Parameters": 
			[
				["Integer","Card Value"],
            ],

			"Triggered": false
		},
		{	"Title": "Card %0 is suit %1 ?",
       
         "Parameters": 
			[
				["Integer","Card Value"],
				["Integer","Suit ID"],
            ],

			"Triggered": false
		},
		{	"Title": "Card %0 is a %1 ?",
       
         "Parameters": 
			[
				["Integer","Card Value"],
				["Integer","Number Value"],
            ],

			"Triggered": false
		},
		{	"Title": "Does the House Deck exist?",
			
			"Triggered": false
		},
	],
    "Expressions": [
        {"Title": "ShowCardID(",
         "Returns": "Integer",
         "Parameters": 
			[
                ["Integer","Player Index"],
				["Integer","Card Index"],
            ]
        },
        {"Title": "ShowCardName_DP(",
         "Returns": "Text",
         "Parameters": 
			[
				["Integer","Player Index"],
                ["Integer","Card Index"],
            ]
        },
		{"Title": "ShowCardSuit_DP(",
         "Returns": "Text",
         "Parameters": 
			[
				["Integer","Player Index"],
                ["Integer","Card Index"],
            ]
        },
		{"Title": "ShowCard_DP(",
         "Returns": "Text",
         "Parameters": 
			[
				["Integer","Player Index"],
                ["Integer","Card Index"],
            ]
        },
        {"Title": "ReturnName_CI(",
         "Returns": "Text",
         "Parameters": 
			[
				["Integer","Card ID"],
            ]
        },
		{"Title": "ReturnSuit_CI(",
         "Returns": "Text",
         "Parameters": 
			[
				["Integer","Card ID"],
            ]
        },
		{"Title": "ReturnCard_CI(",
         "Returns": "Text",
         "Parameters": 
			[
				["Integer","Card ID"],
            ]
        },
		{"Title": "DeckSize(",
         "Returns": "Integer",
         "Parameters": 
			[
				["Integer","Deck ID"],
            ]
        },
		{"Title": "Queue(",
         "Returns": "Integer",
         "Parameters": 
			[
				["Integer","Queue Index"],
            ]
        },
		{"Title": "QueueSize(",
         "Returns": "Integer",
        },
		{"Title": "LastLoopedCard(",
         "Returns": "Integer",
        },
		{"Title": "LastLoopedDeck(",
         "Returns": "Integer",
        },
		{"Title": "LastLoopedIndex(",
         "Returns": "Integer",
        },
    ]
}  &       �� ��     0	           M F 2                               