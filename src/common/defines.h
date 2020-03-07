/* File: defines.h */

/* Purpose: global constants and macro definitions */


/*
 * Do not edit this file unless you know *exactly* what you are doing.
 *
 * Some of the values in this file were chosen to preserve game balance,
 * while others are hard-coded based on the format of old save-files, the
 * definition of arrays in various places, mathematical properties, fast
 * computation, storage limits, or the format of external text files.
 *
 * Changing some of these values will induce crashes or memory errors or
 * savefile mis-reads.  Most of the comments in this file are meant as
 * reminders, not complete descriptions, and even a complete knowledge
 * of the source may not be sufficient to fully understand the effects
 * of changing certain definitions.
 *
 * Lastly, note that the code does not always use the symbolic constants
 * below, and sometimes uses various hard-coded values that may not even
 * be defined in this file, but which may be related to definitions here.
 * This is of course bad programming practice, but nobody is perfect...
 *
 * For example, there are MANY things that depend on the screen being
 * 80x24, with the top line used for messages, the bottom line being
 * used for status, and exactly 22 lines used to show the dungeon.
 * Just because your screen can hold 46 lines does not mean that the
 * game will work if you try to use 44 lines to show the dungeon.
 *
 * You have been warned.
 */

/*
 * Define the maximum number of columns to use in many things
 */
#define MAX_COLS 80

/*
 * Define the maximum number of characters to use in strlcpy-styled
 * strings, where \0 terminator is *always* present (thus extra byte).
 */
#define MAX_CHARS (80+1)

/*
 * Maximum message length
 */
#define MSG_LEN 256

/*
 * Maximum number of messages to keep in player message history
 */
#define MAX_MSG_HIST 60

/*
 * Maximum number of events to keep in the character event history
 */
#define MAX_CHAR_HIST 300

/*
 * Maximum number of lines in 'special info' (*ID*, Self-Knowledge, Recalls)
 */
#define MAX_TXT_INFO 300

/*
 * Number of grids used to display the dungeon (vertically).
 * Must be a multiple of 11, probably hard-coded to 22.
 */
#define SCREEN_HGT	22

/*
 * Number of grids used to display the dungeon (horizontally).
 * Must be a multiple of 33, probably hard-coded to 66.
 */
#define SCREEN_WID	66


/*
 * Maximum dungeon height in grids, must be a multiple of SCREEN_HGT,
 * probably hard-coded to SCREEN_HGT * 3.
 */
#define MAX_HGT 	66

/*
 * Maximum dungeon width in grids, must be a multiple of SCREEN_WID,
 * probably hard-coded to SCREEN_WID * 3.
 */
#define MAX_WID 	198


/*
 * Hack -- This is used to make sure that every player that has a structure
 * dedicated to them is actually connected
 */
#define NOT_CONNECTED	(-1)

/*
 * Maximum length for names and passwords
 *
 */
#define MAX_NAME_LEN    	15
#define MAX_PASS_LEN    	40

/*
 * Maximum number of players playing at once.
 *
 * This limit has never been stretched, and it would be interesting to see
 * what happens when 100 or so players play at once.
 */
#define MAX_PLAYERS	1000

/*
 * Maximum amount of Angband windows.
 */
#define ANGBAND_TERM_MAX 8

/*
 * Maximum amount of starting equipment
 */
#define MAX_START_ITEMS 6





/*
 * Maximum array bounds for entity list arrays
 */
#define MAX_O_IDX	32768 /* Max size for "o_list[]" */
#define MAX_M_IDX	32768 /* Max size for "m_list[]" */

#define MAX_FLVR_IDX	330 /* Max size for flv_x_char[]/attr[] */

/*
 * Number of tval/min-sval/max-sval slots per ego_item
 */
#define EGO_TVALS_MAX 3

/*
 * Hack -- Maximum number of item testers and TVals in them (server/defines.h)
 */
#define MAX_ITEM_TESTERS	16
#define MAX_ITH_TVAL    	16

/*
 * Hack -- Maximum number of quests
 */
#define MAX_Q_IDX	4

/*
 * Maximum number of high scores in the high score file
 */
#define MAX_HISCORES	100


/*
 * Maximum dungeon level.  The player can never reach this level
 * in the dungeon, and this value is used for various calculations
 * involving object and monster creation.  It must be at least 100.
 * Setting it below 128 may prevent the creation of some objects.
 */
#define MAX_DEPTH	128

/* The number of wilderness levels we have allocated.
*/
#define MAX_WILD        4096

/*
 * Maximum number of special pre-designed static levels.
 */
#define MAX_SPECIAL_LEVELS 10

/*
 * Maximum size of the "lite" array (see "cave.c")
 * Note that the "lite radius" will NEVER exceed 5, and even if the "lite"
 * was rectangular, we would never require more than 128 entries in the array.
 */
#define LITE_MAX 128

/*
 * Maximum size of the "view" array (see "cave.c")
 * Note that the "view radius" will NEVER exceed 20, and even if the "view"
 * was octagonal, we would never require more than 1520 entries in the array.
 */
#define VIEW_MAX 1536

/*
 * Maximum size of the "temp" array (see "cave.c")
 * We must be as large as "VIEW_MAX" and "LITE_MAX" for proper functioning
 * of "update_view()" and "update_lite()".  We must also be as large as the
 * largest illuminatable room, but no room is larger than 800 grids.  We
 * must also be large enough to allow "good enough" use as a circular queue,
 * to calculate monster flow, but note that the flow code is "paranoid".
 */
#define TEMP_MAX 1536


/*
 * OPTION: Maximum number of macros (see "io.c")
 * Default: assume at most 256 macros are used
 */
#define MACRO_MAX	256

/*
 * OPTION: Maximum number of "quarks" (see "io.c")
 * Default: assume at most 512 different inscriptions are used
 */
#define QUARK_MAX	5656

/*
 * OPTION: Maximum number of messages to remember (see "io.c")
 * Default: assume maximal memorization of 2048 total messages
 */
#define MESSAGE_MAX	2048

/*
 * OPTION: Maximum space for the message text buffer (see "io.c")
 * Default: assume that each of the 2048 messages is repeated an
 * average of three times, and has an average length of 48
 */
#define MESSAGE_BUF	32768


/*
 * Maximum value storable in a "byte" (hard-coded)
 */
#define MAX_UCHAR       255

/*
 * Maximum value storable in a "s16b" (hard-coded)
 */
#define MAX_SHORT       32767

/*
 * RLE encoding modes
 */
#define RLE_NONE 0
#define RLE_CLASSIC 1
#define RLE_LARGE 2
#define RLE_COLOR 3

/*
 * Party commands
 */
#define PARTY_CREATE	1
#define PARTY_ADD	2
#define PARTY_DELETE	3
#define PARTY_REMOVE_ME	4
#define PARTY_HOSTILE	5
#define PARTY_PEACE	6

/* 
 * Dungeon master commands
 */
#define MASTER_MAX_HOOKS	4 /* Total number of hooks per DM */

/*
 * Methods of leaving a level
 */
#define LEVEL_UP	0
#define LEVEL_DOWN	1
#define LEVEL_RAND	2
#define LEVEL_GHOST	3
#define	LEVEL_OUTSIDE   4
#define LEVEL_OUTSIDE_RAND 5

/*
 * Maximum channel name length
 */
#define MAX_CHAN_LEN 12

/*
 * Default chat channel
 */
#define DEFAULT_CHANNEL "#public"
#define MAX_CHANNELS 255

/*** Option Definitions ***/
#define MAX_OPTIONS 256

/*
 * Maximum possible number of stats.
 */
#define A_CAP	16


/*
 * Store constants
 */
#define STORE_INVEN_MAX	48		/* Max number of discrete objs in inven */
#define STORE_CHOICES	32		/* Number of items to choose stock from */
#define STORE_OBJ_LEVEL	7		/* Magic Level for normal stores */
#define STORE_TURNOVER	9		/* Normal shop turnover, per day */
#define STORE_MIN_KEEP	12		/* Min slots to "always" keep full */
#define STORE_MAX_KEEP	36		/* Max slots to "always" keep full */
#define STORE_SHUFFLE	35		/* 1/Chance (per day) of an owner changing */
#define STORE_TURNS	250		/* Number of turns between turnovers */
/* MAngband-specific: */
#define	STORE_NPC	0x01
#define	STORE_PC	0x02
#define	STORE_HOME	0x04
#define	STORE_OWN	0x08



/*
 * Maximum number of players spells
 */
#define PY_MAX_SPELLS 64


/*
 * Number of spells per book
 */
#define SPELLS_PER_BOOK 20

/*
 * Spell "realms"
 */
#define MAX_SPELL_REALMS 3

/*
 * Ghost spell "realm"
 */
#define GHOST_REALM	2


/*
 * Player constants
 */
#define PY_MAX_EXP	99999999L	/* Maximum exp */
#define PY_MAX_GOLD	999999999L	/* Maximum gold */
#define PY_MAX_LEVEL	50      	/* Maximum level */
/*
 * Flags for player_type.spell_flags[]
 */
#define PY_SPELL_LEARNED    0x01 /* Spell has been learned */
#define PY_SPELL_WORKED     0x02 /* Spell has been successfully tried */
#define PY_SPELL_FORGOTTEN  0x04 /* Spell has been forgotten */
/*
 * MAngband-specific spell_flags[]
 */
#define PY_SPELL_AIM    	0x10 /* Spell requires a target */
#define PY_SPELL_ITEM   	0x20 /* Spell requires an item */
#define PY_SPELL_PROJECT	0x40 /* Spell could be projected */

/* Offset for projected spells*/
#define SPELL_PROJECTED (PY_MAX_SPELLS*2)


/*
 * MAngband-specific item targeting flags
 */
#define ITEM_ASK_AIM	0x10 /* Object requires a target */
#define ITEM_ASK_ITEM	0x20 /* Object requires an item */


/*** Custom commands ***/
#define MAX_SCHEMES	30
#define MAX_CUSTOM_COMMANDS	63

#define COMMAND_TEST_ALIVE	0x00000001	/* Test if player is alive */
#define COMMAND_TEST_DEAD	0x00000002	/* Test if player is dead */
#define COMMAND_TEST_SPELL	0x00000004	/* Test if player class is spell-able (by TV) */
#define COMMAND_ITEM_QUICK	0x00000008	/* Do not interact with player, while selecting item */

#define COMMAND_ITEM_AMMOUNT	0x00000010	/* Allow player to specify ammount from item stack */
#define COMMAND_ITEM_INVEN	0x00000020	/* Select item from inventory */
#define COMMAND_ITEM_EQUIP	0x00000040	/* Select item from equipment */
#define COMMAND_ITEM_FLOOR	0x00000080	/* Select item from floor */

#define COMMAND_ITEM_RESET	0x00000100	/* Item sets its own "Second" and "Target" needs */
#define COMMAND_SECOND_INVEN	0x00000200	/* Select second item from inventory */
#define COMMAND_SECOND_EQUIP	0x00000400	/* Select second item from equipment */
#define COMMAND_SECOND_FLOOR	0x00000800	/* Select second item from floor */

#define COMMAND_TARGET_DIR	0x00001000	/* Pick direction */
#define COMMAND_TARGET_ALLOW	0x00002000	/* Pick direction OR target */
#define COMMAND_TARGET_FRIEND	0x00004000	/* Allow friendly targeting */
#define COMMAND_TARGET_XXX2	0x00008000	/* XXX Unused */

#define COMMAND_SPELL_BOOK	0x00010000	/* Choose a spell from TV book */
#define COMMAND_SPELL_CUSTOM	0x00020000	/* Choose a spell from an offset */
#define COMMAND_SPELL_RESET	0x00040000	/* Set its own "Second" and "Target" needs */
#define COMMAND_SPELL_INDEX	0x00080000	/* XXX Unused */
 
#define COMMAND_NEED_VALUE	0x00100000	/* Ask for s32b value */
#define COMMAND_NEED_CONFIRM	0x00200000	/* Ask for confirmation */
#define COMMAND_NEED_CHAR	0x00400000	/* Ask for "char" */
#define COMMAND_NEED_STRING	0x00800000	/* Ask for "string" (60 chars) */

#define COMMAND_NEED_SPELL		(COMMAND_SPELL_BOOK   | \
								 COMMAND_SPELL_CUSTOM | \
								 COMMAND_SPELL_RESET  | \
								 COMMAND_SPELL_INDEX)

#define COMMAND_NEED_ITEM	(COMMAND_ITEM_INVEN | \
								 COMMAND_ITEM_EQUIP | \
								 COMMAND_ITEM_FLOOR | \
								 COMMAND_ITEM_AMMOUNT)
#define COMMAND_NEED_SECOND     (COMMAND_SECOND_INVEN | \
								 COMMAND_SECOND_EQUIP | \
								 COMMAND_SECOND_FLOOR)
#define COMMAND_NEED_TARGET     (COMMAND_TARGET_DIR    | \
								 COMMAND_TARGET_ALLOW  | \
								 COMMAND_TARGET_FRIEND | \
								 COMMAND_TARGET_XXX2)

#define COMMAND_SPECIAL_FILE	0x01000000	/* Begin file perusal with mode "tval" */
#define COMMAND_INTERACTIVE	0x02000000	/* Begin interactive mode "tval" */
#define COMMAND_PROMPT_ITEM	0x04000000	/* Auto-modify prompt using "item" and "value" */
#define COMMAND_STORE   	0x08000000	/* This command will only work is stores */

#define COMMAND_ITEM_STORE	0x10000000	/* Select item from store */
#define COMMAND_SECOND_VALUE	0x20000000	/* Put second item into value */
#define COMMAND_SECOND_DIR	0x40000000	/* Put second item into dir */
#define COMMAND_SECOND_CHAR	0x80000000	/* Put second item into entry[0] */

/* Keen observer might notice that flags bellow collide with
 * the ones already defined above.
 * It's OK, as they are for the COMMAND_INTERACTIVE subset,
 * which is almost an it's own thing and ignores most of the
 * regular flags. */
#define COMMAND_INTERACTIVE_ANYKEY 0x10000000 /* Quit on anykey. */

/*
 * Max number of data streams
 */
#define MAX_STREAMS 20
/* Stream Flags */
#define SF_NONE 	0x00	/* No special flags */
#define SF_TRANSPARENT	0x01	/* Stream has secondary layer */
#define SF_OVERLAYED	0x02	/* Stream shouldn't be 'memorized' */
#define SF_NEXT_GROUP	0x04	/* Stream does not belong to previous group */
#define SF_AUTO 	0x08	/* Stream is auto-subscribed to */
#define SF_KEEP_X	0x10	/* Stream respects window's X offset */
#define SF_KEEP_Y	0x20	/* Stream respects window's Y offset */
#define SF_MAXBUFFER	0x40	/* Be prepared to receive max_rows */
#define SF_HIDE 	0x80	/* Hide stream subscription from UI */

/*** Indicators ***/
#define INDITYPE_TINY   	0
#define INDITYPE_NORMAL 	1
#define INDITYPE_LARGE  	2
#define INDITYPE_STRING 	3

#define IN_FILTER_SPELL_BOOK	0x10000000 /* Do not show if class is magic-less */

#define IN_STOP_ONCE        	0x01000000 /* Only display one value */
#define IN_STOP_STRIDE      	0x02000000 /* Stop parsing if striding test failed */
#define IN_STOP_EMPTY       	0x04000000 /* Stop parsing if coffer is empty */
#define IN_AUTO_CUT         	0x08000000 /* Squeeze indicator into terminal */

#define IN_STRIDE_EMPTY     	0x00100000 /* Step over empty values */
#define IN_STRIDE_LARGER    	0x00200000 /* Step over to next coffer it's lower then current */ 
#define IN_STRIDE_POSITIVE  	0x00400000 /* Step over values > 0 */
#define IN_STRIDE_NONZERO   	0x00800000 /* Step over values != 0 */

#define IN_STRIDE_LESSER    	0x00010000 /* Step over values < next coffer */
#define IN_STRIDE_NOT       	0x00080000 /* Invert ALL the tests ("if not") */

#define IN_VT_CR            	0x00000100 /* Do a carriage return on Vertical Tab */
#define IN_VT_LF            	0x00000200 /* Do a line feed  on Vertical Tab */
#define IN_VT_FF            	0x00000400 /* Do a form feed  on Vertical Tab */
#define IN_VT_COLOR_SET     	0x00000800 /* Readout next character as color on Vertical Tab */

#define IN_VT_COLOR_RESET   	0x00001000 /* Reset color on Vertical Tab */
#define IN_VT_STRIDE_FLIP   	0x00002000 /* Enable/Disable striding on Vertical Tab */
#define IN_VT_DEC_VALUE     	0x00004000 /* Decrease value on Vertical Tab */
#define IN_VT_XXX_XXX_1     	0x00008000 /* Unused effect of Vertical Tab */

#define IN_VT_COFFER_RESET  	0x00040000 /* Reset coffer back to 0 on Vertical Tab */

#define IN_TEXT_LABEL       	0x00000001 /* Pick a string by value */
#define IN_TEXT_PRINTF      	0x00000002 /* Display value via sprintf format */
#define IN_TEXT_STAT        	0x00000004 /* Hack: Display in 18/XXX format */
#define IN_TEXT_CUT         	0x00000008 /* Display a string from prompt and cut it */
#define IN_TEXT_LIKERT      	0x00000010 /* Hack: Display in "likert" format */


/*
 * Number of keymap modes
 */
#define KEYMAP_MODES	2
#define KEYMAP_MODE_ORIG	0	/* Mode for original keyset commands */
#define KEYMAP_MODE_ROGUE	1	/* Mode for roguelike keyset commands */




/*** General flag values ***/

/*
 * Bit flags for the "target_set" function
 *
 *	KILL: Target monsters
 *	LOOK: Describe grid fully
 *	XTRA: Currently unused flag
 *	GRID: Select from all grids
 *  FRND: (MAngband-specific) Target friendly players
 *  READ: (MAngband-specific) Keep reading recalls
 */
#define TARGET_KILL		0x01
#define TARGET_LOOK		0x02
#define TARGET_XTRA		0x04
#define TARGET_GRID		0x08
#define TARGET_FRND		0x40
#define TARGET_READ		0x80





/*
 * Bit flags for the "p_ptr->notice" variable
 */
#define PN_COMBINE	0x00000001L	/* Combine the pack */
#define PN_REORDER	0x00000002L	/* Reorder the pack */
/* xxx (many) */


/*
 * Bit flags for the "p_ptr->update" variable
 */
#define PU_BONUS	0x00000001L	/* Calculate bonuses */
#define PU_TORCH	0x00000002L	/* Calculate torch radius */
/* xxx (many) */
#define PU_HP   	0x00000010L	/* Calculate chp and mhp */
#define PU_MANA 	0x00000020L	/* Calculate csp and msp */
#define PU_SPELLS	0x00000040L	/* Calculate spells */
/* xxx (many) */
/* xxx (many) */
#define PU_UN_VIEW	0x00010000L	/* Forget view */
#define PU_UN_LITE	0x00020000L	/* Forget lite */
/* xxx (many) */
#define PU_VIEW 	0x00100000L	/* Update view */
#define PU_LITE 	0x00200000L	/* Update lite */
/* xxx */
#define PU_MONSTERS	0x01000000L	/* Update monsters */
#define PU_DISTANCE	0x02000000L	/* Update distances */
/* xxx */
#define PU_FLOW		0x10000000L	/* Update flow */
/* xxx (many) */


/*
 * Bit flags for the "p_ptr->redraw" variable
 */
#define PR_MISC 	0x00000001L	/* Display Race/Class */
#define PR_TITLE	0x00000002L	/* Display Title */
#define PR_LEV  	0x00000004L	/* Display Level */
#define PR_EXP  	0x00000008L	/* Display Experience */
#define PR_STATS	0x00000010L	/* Display Stats */
#define PR_ARMOR	0x00000020L	/* Display Armor */
#define PR_HP   	0x00000040L	/* Display Hitpoints */
#define PR_MANA 	0x00000080L	/* Display Mana */
#define PR_GOLD 	0x00000100L	/* Display Gold */
#define PR_DEPTH	0x00000200L	/* Display Depth */
/* XXXX #define PR_HISTORY	0x00000400L	// Display History */
#define PR_HEALTH	0x00000800L	/* Display Health Bar */
#define PR_CUT  	0x00001000L	/* Display Extra (Cut) */
#define PR_STUN 	0x00002000L	/* Display Extra (Stun) */
#define PR_HUNGER	0x00004000L	/* Display Extra (Hunger) */
#define PR_VARIOUS	0x00008000L	/* Display Various info (age, etc.) */
#define PR_BLIND	0x00010000L	/* Display Extra (Blind) */
#define PR_CONFUSED	0x00020000L	/* Display Extra (Confused) */
#define PR_AFRAID	0x00040000L	/* Display Extra (Afraid) */
#define PR_POISONED	0x00080000L	/* Display Extra (Poisoned) */
#define PR_STATE	0x00100000L	/* Display Extra (State) */
#define PR_SPEED	0x00200000L	/* Display Extra (Speed) */
#define PR_STUDY	0x00400000L	/* Display Extra (Study) */
#define PR_PLUSSES	0x00800000L	/* Display Plusses to Hit/Damage */
/*xxx*/
#define PR_MAP  	0x04000000L	/* Display Map */
#define PR_WIPE 	0x08000000L	/* Hack -- Total Redraw */
#define PR_SKILLS	0x10000000L	/* Display Skills */
#define PR_OFLAGS	0x20000000L	/* Display Object/Resistance Flags  */
#define PR_EQUIPPY	0x20000000L	/* Display Equppy (Note! in MAngband it's same as OFLAGS)  */
#define PR_CURSOR	0x40000000L	/* Display Cursor  */
#define PR_FLOOR	0x80000000L	/* Display floor object */
/* xxx */
#define PR_OPPOSE_ELEMENTS	0x01000000L	/* Display temp. resists */
#define PR_LAG_METER	0x02000000L	/* Display lag meter */

/* Display Basic Info */
#define PR_BASIC \
	(PR_MISC | PR_TITLE | PR_STATS | PR_LEV |\
	 PR_EXP | PR_GOLD | PR_ARMOR | PR_HP |\
	 PR_MANA | PR_DEPTH | PR_HEALTH)

/* Display Extra Info */
#define PR_EXTRA \
	(PR_CUT | PR_STUN | PR_HUNGER | PR_BLIND |\
	 PR_CONFUSED | PR_AFRAID | PR_POISONED | PR_STATE |\
	 PR_SPEED | PR_STUDY | PR_OPPOSE_ELEMENTS)
	 
/* Display Status Line */
#define PR_STATUS \
	(PR_STUN | PR_HUNGER | PR_BLIND | PR_DEPTH |\
	 PR_CONFUSED | PR_AFRAID | PR_POISONED | PR_STATE |\
	 PR_SPEED | PR_STUDY | PR_OPPOSE_ELEMENTS)

/* Display Compact Player Info (Side Panel) */
#define PR_COMPACT \
	(PR_MISC | PR_TITLE | PR_STATS | PR_LEV |\
	 PR_EXP | PR_GOLD | PR_ARMOR | PR_HP |\
	 PR_MANA | PR_HEALTH | PR_CUT)

/*
 * Bit flags for the "p_ptr->window" variable (etc)
 */
#define PW_INVEN            0x00000001L /* Display inven/equip */
#define PW_EQUIP            0x00000002L /* Display equip/inven */
#define PW_PLAYER_0         0x00000004L /* Display player (basic) */
#define PW_PLAYER_1         0x00000008L /* Display player (extra) */
#define PW_PLAYER_2         0x00000010L /* Display player (compact) */
#define PW_MAP              0x00000020L /* Display dungeon map */
#define PW_MESSAGE          0x00000040L /* Display messages */
#define PW_OVERHEAD         0x00000080L /* Display overhead view */
#define PW_MONSTER          0x00000100L /* Display monster recall */
#define PW_OBJECT           0x00000200L /* Display object recall */
#define PW_MONLIST          0x00000400L /* Display monster list */
#define PW_STATUS           0x00000800L /* Display status */
#define PW_MESSAGE_CHAT     0x00001000L /* MAngband-specific: Chat */
#define PW_SPELL            0x00002000L /* Older angband: Spell list */
#define PW_BORG_1           0x00004000L /* Display borg messages */
#define PW_BORG_2           0x00008000L /* Display borg status */
#define PW_SPECIAL_INFO     0x00008000L /* Display special info (instead of borg status) */
#define PW_PLAYER_3         0x00004000L /* Display player (history) (instead of borg messages) */
#define PW_STORE            0x00010000L /* Display shop */
#define PW_ITEMLIST         0x00020000L /* Display item list */

#define PW_PLAYER           (PW_PLAYER_0 | PW_PLAYER_2) /* Display player (basic + compact) */




/*** Macro Definitions ***/

/*
 * Hack -- Old-style names
 */
#define term_screen	(ang_term[0])
#define term_mirror	(ang_term[1])
#define term_recall	(ang_term[2])
#define term_choice	(ang_term[3])


/* Is string empty? Beats calling strlen */
#define STRZERO(S) \
	((S)[0] == '\0')

/* Given an array, determine how many elements are in the array. */
#define N_ELEMENTS(a) (sizeof(a) / sizeof((a)[0]))


/*** Color constants ***/


/*
 * Angband "attributes" (with symbols, and base (R,G,B) codes)
 *
 * The "(R,G,B)" codes are given in "fourths" of the "maximal" value,
 * and should "gamma corrected" on most (non-Macintosh) machines.
 */
#define TERM_DARK		0	/* 'd' */	/* 0,0,0 */
#define TERM_WHITE		1	/* 'w' */	/* 4,4,4 */
#define TERM_SLATE		2	/* 's' */	/* 2,2,2 */
#define TERM_ORANGE		3	/* 'o' */	/* 4,2,0 */
#define TERM_RED		4	/* 'r' */	/* 3,0,0 */
#define TERM_GREEN		5	/* 'g' */	/* 0,2,1 */
#define TERM_BLUE		6	/* 'b' */	/* 0,0,4 */
#define TERM_UMBER		7	/* 'u' */	/* 2,1,0 */
#define TERM_L_DARK		8	/* 'D' */	/* 1,1,1 */
#define TERM_L_WHITE		9	/* 'W' */	/* 3,3,3 */
#define TERM_VIOLET		10	/* 'v' */	/* 4,0,4 */
#define TERM_YELLOW		11	/* 'y' */	/* 4,4,0 */
#define TERM_L_RED		12	/* 'R' */	/* 4,0,0 */
#define TERM_L_GREEN		13	/* 'G' */	/* 0,4,0 */
#define TERM_L_BLUE		14	/* 'B' */	/* 0,4,4 */
#define TERM_L_UMBER		15	/* 'U' */	/* 3,2,1 */


#define MSG_GENERIC		0
/* Angband, gameplay-specific, might be tied to sounds */
#define MSG_HIT              1
#define MSG_MISS             2
#define MSG_FLEE             3
#define MSG_DROP             4
#define MSG_KILL             5
#define MSG_LEVEL            6
#define MSG_DEATH            7
#define MSG_STUDY            8
#define MSG_TELEPORT         9
#define MSG_SHOOT           10
#define MSG_QUAFF           11
#define MSG_ZAP_ROD         12
#define MSG_WALK            13
#define MSG_TPOTHER         14
#define MSG_HITWALL         15
#define MSG_EAT             16
#define MSG_STORE1          17
#define MSG_STORE2          18
#define MSG_STORE3          19
#define MSG_STORE4          20
#define MSG_DIG             21
#define MSG_OPENDOOR        22
#define MSG_SHUTDOOR        23
#define MSG_TPLEVEL         24
#define MSG_BELL            25
#define MSG_NOTHING_TO_OPEN 26
#define MSG_LOCKPICK_FAIL   27
#define MSG_STAIRS_DOWN     28
#define MSG_HITPOINT_WARN   29
#define MSG_ACT_ARTIFACT    30
#define MSG_USE_STAFF       31
#define MSG_DESTROY         32
#define MSG_MON_HIT         33
#define MSG_MON_TOUCH       34
#define MSG_MON_PUNCH       35
#define MSG_MON_KICK        36
#define MSG_MON_CLAW        37
#define MSG_MON_BITE        38
#define MSG_MON_STING       39
#define MSG_MON_BUTT        40
#define MSG_MON_CRUSH       41
#define MSG_MON_ENGULF      42
#define MSG_MON_CRAWL       43
#define MSG_MON_DROOL       44
#define MSG_MON_SPIT        45
#define MSG_MON_GAZE        46
#define MSG_MON_WAIL        47
#define MSG_MON_SPORE       48
#define MSG_MON_BEG         49
#define MSG_MON_INSULT      50
#define MSG_MON_MOAN        51
#define MSG_RECOVER         52
#define MSG_BLIND           53
#define MSG_CONFUSED        54
#define MSG_POISONED        55
#define MSG_AFRAID          56
#define MSG_PARALYZED       57
#define MSG_DRUGGED         58
#define MSG_SPEED           59
#define MSG_SLOW            60
#define MSG_SHIELD          61
#define MSG_BLESSED         62
#define MSG_HERO            63
#define MSG_BERSERK         64
#define MSG_PROT_EVIL       65
#define MSG_INVULN          66
#define MSG_SEE_INVIS       67
#define MSG_INFRARED        68
#define MSG_RES_ACID        69
#define MSG_RES_ELEC        70
#define MSG_RES_FIRE        71
#define MSG_RES_COLD        72
#define MSG_RES_POIS        73
#define MSG_STUN            74
#define MSG_CUT             75
#define MSG_STAIRS_UP       76
#define MSG_STORE_ENTER     77
#define MSG_STORE_LEAVE     78
#define MSG_STORE_HOME      79
#define MSG_MONEY1          80
#define MSG_MONEY2          81
#define MSG_MONEY3          82
#define MSG_SHOOT_HIT       83
#define MSG_STORE5          84
#define MSG_LOCKPICK        85
#define MSG_DISARM          86
#define MSG_IDENT_BAD       87
#define MSG_IDENT_EGO       88
#define MSG_IDENT_ART       89
#define MSG_BR_ELEMENTS     90
#define MSG_BR_FROST        91
#define MSG_BR_ELEC         92
#define MSG_BR_ACID         93
#define MSG_BR_GAS          94
#define MSG_BR_FIRE         95
#define MSG_BR_CONF         96
#define MSG_BR_DISENCHANT   97
#define MSG_BR_CHAOS        98
#define MSG_BR_SHARDS       99
#define MSG_BR_SOUND        100
#define MSG_BR_LIGHT        101
#define MSG_BR_DARK         102
#define MSG_BR_NETHER       103
#define MSG_BR_NEXUS        104
#define MSG_BR_TIME         105
#define MSG_BR_INERTIA      106
#define MSG_BR_GRAVITY      107
#define MSG_BR_PLASMA       108
#define MSG_BR_FORCE        109
#define MSG_SUM_MONSTER     110
#define MSG_SUM_ANGEL       111
#define MSG_SUM_UNDEAD      112
#define MSG_SUM_ANIMAL      113
#define MSG_SUM_SPIDER      114
#define MSG_SUM_HOUND       115
#define MSG_SUM_HYDRA       116
#define MSG_SUM_DEMON       117
#define MSG_SUM_DRAGON      118
#define MSG_SUM_HI_UNDEAD   119
#define MSG_SUM_HI_DRAGON   120
#define MSG_SUM_HI_DEMON    121
#define MSG_SUM_WRAITH      122
#define MSG_SUM_UNIQUE      123
#define MSG_WIELD           124
#define MSG_CURSED          125
#define MSG_PSEUDOID        126
#define MSG_HUNGRY          127
#define MSG_NOTICE          128
#define MSG_AMBIENT_DAY     129
#define MSG_AMBIENT_NITE    130
#define MSG_AMBIENT_DNG1    131
#define MSG_AMBIENT_DNG2    132
#define MSG_AMBIENT_DNG3    133
#define MSG_AMBIENT_DNG4    134
#define MSG_AMBIENT_DNG5    135
#define MSG_CREATE_TRAP     136
#define MSG_SHRIEK          137
#define MSG_CAST_FEAR       138
#define MSG_HIT_GOOD        139
#define MSG_HIT_GREAT       140
#define MSG_HIT_SUPERB      141
#define MSG_HIT_HI_GREAT    142
#define MSG_HIT_HI_SUPERB   143
#define MSG_SPELL           144
#define MSG_PRAYER          145
#define MSG_KILL_UNIQUE     146
#define MSG_KILL_KING       147
#define MSG_DRAIN_STAT      148
#define MSG_MULTIPLY        149

#define MSG_MAX_ANGBAND     150

/* MAngband-specific: */
#define MSG_TALK            151
#define MSG_YELL            152
#define MSG_SOCIAL          153
#define MSG_PY_SPELL        154
#define MSG_PY_PRAYER       155
#define MSG_PY_MISC         156
#define MSG_MON_OTHER       157

#define MSG_MAX             158

/* Client-side and system messages: */
#define MSG_LOCAL		255
#define MSG_WHISPER		256
#define MSG_CHAT		257


/*** Hack ***/

#define CURSOR_HACK 2

/*
 * Hack -- attempt to reduce various values
 */
#ifdef ANGBAND_LITE
# undef MACRO_MAX
# define MACRO_MAX	128
# undef QUARK_MAX
# define QUARK_MAX	128
# undef MESSAGE_MAX
# define MESSAGE_MAX	128
# undef MESSAGE_BUF
# define MESSAGE_BUF	4096
#endif


/** Pathfinder constants **/

/* Maximum size around the player to consider in the pathfinder */
#define MAX_PF_RADIUS 50

/* Maximum distance to consider in the pathfinder */
#define MAX_PF_LENGTH 250


/*** Monster blow constants ***/

#define MONSTER_BLOW_MAX 4


/*
 * Available graphic modes
 */
#define GRAPHICS_NONE           0
#define GRAPHICS_PLAIN          1
#define GRAPHICS_TRANSPARENT    2
#define GRAPHICS_LIGHTMAP       3

