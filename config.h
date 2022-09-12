/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

/* Gaps */
static const int startwithgaps	     = 1;	 /* 1 means gaps are used by default */
static const unsigned int gappx     = 6;       /* default gap between windows in pixels */

/* Systray */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "noto:size=11" };
static const char dmenufont[]       = "monospace:size=10";

/* Theme */
#include "themes/mint.h"


static const char *colors[][3]      = {

	/*               fg         bg         border   */
	[SchemeNorm] = { c_txt, c_bg, c_bg },
	[SchemeSel]  = { c_stxt, c_fg_green,  c_bg  },
	[SchemeTitle]  = { c_txt, c_bg,  c_bg  },
};

/* tagging */

static const char *tags[] = { "" , "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "節",      tile },    /* first entry is default */
	{ "",      monocle },
	{ "",      NULL },    /* no layout function means floating behavior */
/* Defaults: "[]=" "><>" "[M]"*/
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *explorer[]  = {  ".local/share/slnxwm/scripts/selexecute", "-f", NULL };
static const char *editor[]  = {  ".local/share/slnxwm/scripts/selexecute", "-e", NULL };
static const char *console[]  = {  ".local/share/slnxwm/scripts/selexecute", "-t", NULL };
static const char *web[]  = {  ".local/share/slnxwm/scripts/selexecute", "-w", NULL };
static const char *music[]  = {  ".local/share/slnxwm/scripts/selexecute", "-m", NULL };
static const char *xkill[]  = {  "xkill", NULL };
static const char *print [] =  {  "~.local/share/slnxwm/scripts/selexecute", "-s", NULL };
static const char *rofi[] = {"rofi", "-show", "drun", NULL };
static const char *volup[] = {"pamixer", "-i", "5", NULL };
static const char *voldown[] = {"pamixer", "-d", "5", NULL };
static const char *volmute[] = {"pamixer", "-t", NULL };
static const char *logout[] = {".local/share/slnxwm/scripts/logout", NULL };
static const char *kdocker[] = {"kdocker", NULL };



static Key keys[] = {
    /* modifier                         key      function        argument */
    { MODKEY,                       XK_space,    spawn,          {.v = rofi } },
    { MODKEY,                       XK_c,    spawn,          {.v = editor } },
    { MODKEY,                       XK_e,        spawn,          {.v = explorer } },
    { MODKEY,                       XK_t,        spawn,          {.v = console } },
    { MODKEY,                       XK_w,        spawn,          {.v = web } },
    { MODKEY,                       XK_m,        spawn,          {.v = music } },
    { MODKEY,                       XK_k,        spawn,          {.v = kdocker } },
    { None,          XF86XK_AudioRaiseVolume,    spawn,          {.v = volup } },
    { None,          XF86XK_AudioLowerVolume,    spawn,          {.v = voldown } },
    { None,                  XF86XK_AudioMute,    spawn,          {.v = volmute } },
    { None,                 XK_Print,            spawn,          {.v = print } },
    { MODKEY|ControlMask,           XK_x,        spawn,          {.v = xkill } },
    { MODKEY,                       XK_b,        togglebar,      {0} },
	{ ShiftMask,                    XK_Tab,      focusstack,     {.i = +1 } },
	{ ShiftMask|ControlMask,       XK_Tab,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,        incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,        incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_Left,     setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_Right,    setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_Up,       zoom,           {0} }, 
	{ MODKEY,                       XK_Tab,      view,           {0} },
	{ MODKEY,                       XK_q,        killclient,     {0} },
	{ MODKEY,                       XK_F1,       setlayout,      {.v = &layouts[0]} }, // Tile
	{ MODKEY,                       XK_F2,       setlayout,      {.v = &layouts[1]} }, // Monocle
	{ MODKEY,                       XK_F3,       setlayout,      {.v = &layouts[2]} }, // Nothing
	{ MODKEY,                       XK_a,        setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,    togglefloating, {0} },
	{ MODKEY,                       XK_0,        view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,        tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,    focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,   focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,    tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,   tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,    setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_equal,    setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_minus,    setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,             XK_equal,    setgaps,        {.i = GAP_TOGGLE} },
	TAGKEYS(                        XK_1,                        0)
	TAGKEYS(                        XK_2,                        1)
	TAGKEYS(                        XK_3,                        2)
	TAGKEYS(                        XK_4,                        3)
	TAGKEYS(                        XK_5,                        4)
	TAGKEYS(                        XK_6,                        5)
	TAGKEYS(                        XK_7,                        6)
	TAGKEYS(                        XK_8,                        7)
	TAGKEYS(                        XK_9,                        8)
    { MODKEY|ControlMask|ShiftMask,              XK_Delete,      quit,           {0} },
    { MODKEY|ControlMask,                        XK_Delete,      spawn,          {.v = logout } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = console } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

