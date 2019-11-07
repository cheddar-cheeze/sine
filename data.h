/*
 * all game data is statically build 
 *
 * sections are divided as like paths in a traditional visual novel
 * v: voice line
 * q: question
 * g: goto section
 * i: (planned) accept information like the players name
 *
 * each section is terminated with NULL
 */

static const char *section0[] = 
{
		//this is a section
		//section 0
		"v Senpai:\nAre you free today sakura chan?",
		"q Yes;No",
		"g 1",//goes to section 1 if the answer is yes
		"g 2",//goes to section 2 if the answer is no
		NULL 
};

static const char *section1[] =
{
		//section 1
		"v Sakura:\nYes, is there something you wanted to do Senpai?",
		"v Senpai:\nI wanted to see if you wanted to go get coffee with me",
		NULL
};

static const char *section2[] =
{
		//section 2
		"v Sakura:\nNo, sorry I have something to do.",
		"v Senpai:\nIt's fine, see you tomorrow",
		NULL
};

static const char **sections[] = 
{
	section0,
	section1,
	section2,
};
