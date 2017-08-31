/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]        = "-*-*-medium-*-*-*-14-*-*-*-*-*-*-*";
static const char* normbgcolor  = "#222222";
static const char* normfgcolor  = "#d4d4d4";
static const char* selbgcolor   = "#6666ff";
static const char* selfgcolor   = "#eeeeee";
static const char* urgbgcolor   = "#111111";
static const char* urgfgcolor   = "#cc0000";
static const char before[]      = "<";
static const char after[]       = ">";
static const int  tabwidth      = 120;
static const Bool foreground    = True;

/*
 * Where to place a new tab when it is opened. When npisrelative is True,
 * then the current position is changed + newposition. If npisrelative
 * is False, then newposition is an absolute position.
 */
static int  newposition   = 1;
static Bool npisrelative  = True;

#define SETPROP(p) { \
	.v = (char *[]){ "/bin/sh", "-c", \
		"prop=\"`xwininfo -children -id $1 | grep '^     0x' | sed -e's@^ *\\(0x[0-9a-f]*\\) \"\\([^\"]*\\)\".*@\\1 \\2@' | xargs -0 printf %b | dmenu -l 10`\" &&" \
		"xprop -id $1 -f $0 8s -set $0 \"$prop\"", \
		p, winid, NULL \
	} \
}

#define MODKEY ControlMask
static Key keys[] = { \
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_t,      focusonce,      { 0 } },
	{ MODKEY|ShiftMask,             XK_t,      spawn,          { 0 } },
	/* { MODKEY,                       XK_t,      spawn,          SETPROP("_TABBED_SELECT_TAB") }, */

/*
	{ MODKEY,                       XK_Right,  rotate,         { .i = +1 } },
	{ MODKEY,                       XK_Left,   rotate,         { .i = -1 } },
	{ MODKEY|ShiftMask,             XK_Left,   movetab,        { .i = -1 } },
	{ MODKEY|ShiftMask,             XK_Right,  movetab,        { .i = +1 } },
*/
	{ MODKEY,                       XK_Next,   rotate,         { .i = +1 } },
	{ MODKEY,                       XK_Prior,  rotate,         { .i = -1 } },
	{ MODKEY|ShiftMask,             XK_Prior,  movetab,        { .i = -1 } },
	{ MODKEY|ShiftMask,             XK_Next,   movetab,        { .i = +1 } },
	{ MODKEY,                       XK_Tab,    rotate,         { .i = 0 } },
/*
	{ MODKEY,                       XK_1,      move,           { .i = 0 } },
	{ MODKEY,                       XK_2,      move,           { .i = 1 } },
	{ MODKEY,                       XK_3,      move,           { .i = 2 } },
	{ MODKEY,                       XK_4,      move,           { .i = 3 } },
	{ MODKEY,                       XK_5,      move,           { .i = 4 } },
	{ MODKEY,                       XK_6,      move,           { .i = 5 } },
	{ MODKEY,                       XK_7,      move,           { .i = 6 } },
	{ MODKEY,                       XK_8,      move,           { .i = 7 } },
	{ MODKEY,                       XK_9,      move,           { .i = 8 } },
	{ MODKEY,                       XK_0,      move,           { .i = 9 } },
*/
	{ MODKEY|ShiftMask,             XK_w,      killclient,     { 0 } },

	{ 0,                            XK_F11,    fullscreen,     { 0 } },
};

