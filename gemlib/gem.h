
/*
 * gem.h - main header file for new gem-lib
 */

#ifndef _GEMLIB_H_
#define _GEMLIB_H_

#include <compiler.h>


#ifdef __GEMLIB_OLDBIND		/* Backward-compatibility */
#undef _GEMLIB_H_		/* For old bindings, these header had to be multi-included. */

#ifndef __GEMLIB_HAVE_DEFS	/* first include via aesbind/vdibind/gemfast */
#define __GEMLIB_HAVE_DEFS
#else
#undef __GEMLIB_DEFS
#endif

#else				/* New include scheme: one header defines all */
#define __GEMLIB_DEFS
#define __GEMLIB_AES
#define __GEMLIB_VDI
#endif

__BEGIN_DECLS


/*******************************************************************************
 * The version of the gem-lib
 */

/* Major and minor version number of the GEMLib package.  Use these macros 
   to test for features in specific releases.  */
#define __GEMLIB__		__GEMLIB_MAJOR__
#define	__GEMLIB_MAJOR__	0
#define	__GEMLIB_MINOR__	40
#define __GEMLIB_REVISION__	0
#define __GEMLIB_BETATAG__     ""


#ifdef __GEMLIB_DEFS

/*******************************************************************************
 * The AES specific stuff from old gemfast.h
 */

#define NIL 			0
#define DESKTOP_HANDLE		0
#define DESK			 	DESKTOP_HANDLE

		/* appl_getinfo modes */
#define AES_LARGEFONT		0
#define AES_SMALLFONT		1
#define AES_SYSTEM		2
#define AES_LANGUAGE 		3
#define AES_PROCESS		4
#define AES_PCGEM 		5
#define AES_INQUIRE		6
#define AES_MOUSE 		8
#define AES_MENU		9
#define AES_SHELL 		10
#define AES_WINDOW		11

		/* appl_getinfo return values */
#define SYSTEM_FONT		0
#define OUTLINE_FONT 		1

#define AESLANG_ENGLISH		0
#define AESLANG_GERMAN		1
#define AESLANG_FRENCH		2
#define AESLANG_SPANISH 	4
#define AESLANG_ITALIAN 	5
#define AESLANG_SWEDISH 	6

		/* appl_read modes */
#define APR_NOWAIT		-1

		/* appl_search modes */
#define APP_FIRST 		0
#define APP_NEXT		1

		/* appl_search return values*/
#define APP_SYSTEM		0x01
#define APP_APPLICATION		0x02
#define APP_ACCESSORY		0x04
#define APP_SHELL 		0x08

		/* appl_trecord types */
#define APPEVNT_TIMER	 	0
#define APPEVNT_BUTTON	 	1
#define APPEVNT_MOUSE	 	2
#define APPEVNT_KEYBOARD 	3

		/* struct used by appl_trecord and appl_tplay */
typedef struct pEvntrec
{
	long ap_event;
	long ap_value;
} EVNTREC;

		/* evnt_button flags */
#define LEFT_BUTTON		0x0001
#define RIGHT_BUTTON 		0x0002
#define MIDDLE_BUTTON		0x0004

#define K_RSHIFT		0x0001
#define K_LSHIFT		0x0002
#define K_CTRL 			0x0004
#define K_ALT			0x0008

		/* evnt_dclick flags */
#define EDC_INQUIRE		0
#define EDC_SET			1

		/* event message values */
#define MN_SELECTED	 	10
#define WM_REDRAW 	 	20
#define WM_TOPPED 	 	21
#define WM_CLOSED 	 	22
#define WM_FULLED 	 	23
#define WM_ARROWED	 	24
#define WM_HSLID		25
#define WM_VSLID		26
#define WM_SIZED		27
#define WM_MOVED		28
#define WM_NEWTOP		29
#define WM_UNTOPPED		30
#define WM_ONTOP		31
#define WM_BOTTOMED		33
#define WM_ICONIFY		34
#define WM_UNICONIFY		35
#define WM_ALLICONIFY		36
#define WM_TOOLBAR		37
#define AC_OPEN			40
#define AC_CLOSE		41
#define AP_TERM			50
#define AP_TFAIL		51
#define AP_RESCHG 		57

		/* Xcontrol messages */
#define CT_UPDATE		50
#define CT_MOVE			51
#define CT_NEWTOP		52
#define CT_KEY			53

#define SHUT_COMPLETED		60
#define RESCHG_COMPLETED	61
#define RESCH_COMPLETED		61
#define AP_DRAGDROP		63
#define SH_WDRAW		72
#define CH_EXIT			90

		/* evnt_mouse modes */
#define MO_ENTER		0
#define MO_LEAVE		1

		/* evnt_multi flags */
#define MU_KEYBD		0x0001
#define MU_BUTTON		0x0002
#define MU_M1			0x0004
#define MU_M2			0x0008
#define MU_MESAG		0x0010
#define MU_TIMER		0x0020

		/* form_dial opcodes */
#define FMD_START 		0
#define FMD_GROW		1
#define FMD_SHRINK		2
#define FMD_FINISH		3

		/* form_error modes */
#define FERR_FILENOTFOUND	 2
#define FERR_PATHNOTFOUND	 3
#define FERR_NOHANDLES		 4
#define FERR_ACCESSDENIED	 5
#define FERR_LOWMEM		 8
#define FERR_BADENVIRON 	10
#define FERR_BADFORMAT		11
#define FERR_BADDRIVE		15
#define FERR_DELETEDIR		16
#define FERR_NOFILES 		18

		/* fsel_(ex)input return values*/
#define FSEL_CANCEL		 0
#define FSEL_OK			 1

		/* menu_attach modes */
#define ME_INQUIRE		0
#define ME_ATTACH 		1
#define ME_REMOVE 		2

		/* menu_attach attributes */
#define SCROLL_NO 		0
#define SCROLL_YES		1

		/* menu_bar modes */
#define MENU_REMOVE		0
#define MENU_INSTALL		1
#define MENU_INQUIRE		-1

		/* menu_icheck modes */
#define UNCHECK			0
#define CHECK			1

		/* menu_ienable modes */
#define DISABLE			0
#define ENABLE 			1

		/* menu_istart modes */
#define MIS_GETALIGN 		0
#define MIS_SETALIGN 		1

		/* menu_popup modes */
#define SCROLL_LISTBOX		-1

		/* menu_register modes */
#define REG_NEWNAME		-1

/* menu_tnormal modes */
#define HIGHLIGHT		0
#define UNHIGHLIGHT		1

/* menu_settings uses a new structure for setting and inquiring the submenu
 * delay values and the menu scroll height.	The delay values are measured in
 * milliseconds and the height is based upon the number of menu items.
 */

typedef struct _mn_set 
{
	long  display;		/*  the submenu display delay */
	long  drag;		/*  the submenu drag delay */
	long  delay;		/*  the single-click scroll delay */
	long  speed;		/*  the continuous scroll delay */
	short height; 		/*  the menu scroll height */
} MN_SET;

/* shel_get modes */
#define SHEL_BUFSIZE (-1)

/* shel_write modes */
#define SWM_LAUNCH		0
#define SWM_LAUNCHNOW		1
#define SWM_LAUNCHACC		3
#define SWM_SHUTDOWN		4
#define SWM_REZCHANGE		5
#define SWM_BROADCAST		7
#define SWM_ENVIRON		8
#define SWM_NEWMSG		9
#define SWM_AESMSG		10

/* shel_write flags */
#define SW_PSETLIMIT		0x0100
#define SW_PRENICE		0x0200
#define SW_DEFDIR 		0x0400
#define SW_ENVIRON		0x0800

#define SD_ABORT		0
#define SD_PARTIAL		1
#define SD_COMPLETE		2

/* rsrc_gaddr structure types */
#define R_TREE			0
#define R_OBJECT		1
#define R_TEDINFO 		2
#define R_ICONBLK 		3
#define R_BITBLK		4
#define R_STRING		5
#define R_IMAGEDATA		6
#define R_OBSPEC		7
#define R_TEPTEXT 		8
#define R_TEPTMPLT		9
#define R_TEPVALID		10
#define R_IBPMASK		11
#define R_IBPDATA		12
#define R_IBPTEXT		13
#define R_BIPDATA		14
#define R_FRSTR			15
#define R_FRIMG			16



/* Window Attributes */
#define NAME			0x0001
#define CLOSER 			0x0002
#define FULLER 			0x0004
#define MOVER			0x0008
#define INFO			0x0010
#define SIZER			0x0020
#define UPARROW			0x0040
#define DNARROW			0x0080
#define VSLIDE 			0x0100
#define LFARROW			0x0200
#define RTARROW			0x0400
#define HSLIDE 			0x0800
#define BACKDROP		0x2000
#define SMALLER			0x4000

/* wind_create flags */
#define WC_BORDER 	 	0
#define WC_WORK		 	1

/* wind_get flags */
#define WF_KIND			  1
#define WF_NAME			  2
#define WF_INFO			  3
#define WF_WORKXYWH		  4
#define WF_CURRXYWH		  5
#define WF_PREVXYWH		  6
#define WF_FULLXYWH		  7
#define WF_HSLIDE 		  8
#define WF_VSLIDE 		  9
#define WF_TOP 			 10
#define WF_FIRSTXYWH 	 	 11
#define WF_NEXTXYWH		 12
#define WF_RESVD		 13
#define WF_NEWDESK		 14
#define WF_HSLSIZE		 15
#define WF_VSLSIZE		 16
#define WF_SCREEN 		 17
#define WF_COLOR		 18
#define WF_DCOLOR 		 19
#define WF_OWNER		 20
#define WF_BEVENT 		 24
#define WF_BOTTOM 		 25
#define WF_ICONIFY		 26
#define WF_UNICONIFY 		 27
#define WF_UNICONIFYXYWH	 28
#define WF_TOOLBAR		 30
#define WF_FTOOLBAR		 31
#define WF_NTOOLBAR		 32
#define WF_WINX			 22360
#define WF_WINXCFG		 22361

/* window elements */
#define W_BOX			0
#define W_TITLE			1
#define W_CLOSER		2
#define W_NAME 			3
#define W_FULLER		4
#define W_INFO 			5
#define W_DATA 			6
#define W_WORK 			7
#define W_SIZER			8
#define W_VBAR 			9
#define W_UPARROW		10
#define W_DNARROW		11
#define W_VSLIDE		12
#define W_VELEV			13
#define W_HBAR			14
#define W_LFARROW		15
#define W_RTARROW		16
#define W_HSLIDE		17
#define W_HELEV			18
#define W_SMALLER		19

/* arrow message */
#define WA_UPPAGE 		0
#define WA_DNPAGE 		1
#define WA_UPLINE 		2
#define WA_DNLINE 		3
#define WA_LFPAGE 		4
#define WA_RTPAGE 		5
#define WA_LFLINE 		6
#define WA_RTLINE 		7

/* wind_update flags */
#define END_UPDATE		0
#define BEG_UPDATE		1
#define END_MCTRL		2
#define BEG_MCTRL		3

/* graf_mouse mouse types */
#define ARROW			 0
#define TEXT_CRSR 		 1
#define BEE 			 2
#define BUSY_BEE	  BEE 	/* alias */
#define BUSYBEE		  BEE 	/* alias */
#define HOURGLASS 		 2
#define POINT_HAND		 3
#define FLAT_HAND 		 4
#define THIN_CROSS		 5
#define THICK_CROSS		 6
#define OUTLN_CROSS		 7
#define USER_DEF		  255
#define M_OFF			  256
#define M_ON			  257
#define M_SAVE 			  258
#define M_LAST 			  259
#define M_RESTORE 		  260
#define M_FORCE			0x8000

/* objects - general */
#define ROOT		 	0 	 /* index of ROOT */
#define MAX_LEN			81 	 /* max string length */
#define MAX_DEPTH		8 	 /* max depth of search or draw */

/* inside fill patterns */
#define IP_HOLLOW		0
#define IP_1PATT		1
#define IP_2PATT		2
#define IP_3PATT		3
#define IP_4PATT		4
#define IP_5PATT		5
#define IP_6PATT		6
#define IP_SOLID		7

/* normal graphics drawing modes */
#define MD_REPLACE		1
#define MD_TRANS		2
#define MD_XOR			3
#define MD_ERASE		4

		/* bit blt rules */
#define ALL_WHITE		0
#define S_AND_D			1
#define S_AND_NOTD		2
#define S_ONLY			3
#define NOTS_AND_D		4
#define D_ONLY			5
#define S_XOR_D			6
#define S_OR_D			7
#define NOT_SORD		8
#define NOT_SXORD		9
#define D_INVERT		10
#define NOT_D			10
#define S_OR_NOTD		11
#define NOT_S			12
#define NOTS_OR_D		13
#define NOT_SANDD		14
#define ALL_BLACK		15

		/* font types */
#define GDOS_PROP		0
#define GDOS_MONO		1
#define GDOS_BITM		2
#define IBM			3
#define SMALL			5

/* object types */
#define G_BOX			20
#define G_TEXT			21
#define G_BOXTEXT		22
#define G_IMAGE			23
#define G_USERDEF		24
#define G_PROGDEF		G_USERDEF
#define G_IBOX			25
#define G_BUTTON		26
#define G_BOXCHAR		27
#define G_STRING		28
#define G_FTEXT			29
#define G_FBOXTEXT		30
#define G_ICON			31
#define G_TITLE			32
#define G_CICON			33

/* extended object types, MagiC only */
#define G_SWBUTTON		34	
#define G_POPUP			35
#define G_WINTITLE		36
#define G_EDIT			37
#define G_SHORTCUT		38


/* object flags */
#define OF_NONE		 	0x0000
#define OF_SELECTABLE		0x0001
#define OF_DEFAULT		0x0002
#define OF_EXIT			0x0004
#define OF_EDITABLE		0x0008
#define OF_RBUTTON		0x0010
#define OF_LASTOB		0x0020
#define OF_TOUCHEXIT		0x0040
#define OF_HIDETREE		0x0080
#define OF_INDIRECT		0x0100
#define OF_FL3DIND		0x0200	/* bit 9 */
#define OF_FL3DBAK		0x0400	/* bit 10 */
#define OF_FL3DACT		0x0600
#define OF_SUBMENU		0x0800	/* bit 11 */
#define OF_FLAG11		OF_SUBMENU
#define OF_FLAG12		0x1000
#define OF_FLAG13		0x2000
#define OF_FLAG14		0x4000
#define OF_FLAG15		0x8000

/* Object states */
#define OS_NORMAL		0x0000
#define OS_SELECTED		0x0001
#define OS_CROSSED		0x0002
#define OS_CHECKED		0x0004
#define OS_DISABLED		0x0008
#define OS_OUTLINED		0x0010
#define OS_SHADOWED		0x0020
#define OS_WHITEBAK		0x0040
#define OS_DRAW3D		0x0080
#define OS_STATE08		0x0100
#define OS_STATE09		0x0200
#define OS_STATE10		0x0400
#define OS_STATE11		0x0800
#define OS_STATE12		0x1000
#define OS_STATE13		0x2000
#define OS_STATE14		0x4000
#define OS_STATE15		0x8000

/* Object colors - default pall. */
#define OC_WHITE		0
#define OC_BLACK		1
#define OC_RED			2
#define OC_GREEN		3
#define OC_BLUE			4
#define OC_CYAN			5
#define OC_YELLOW		6
#define OC_MAGENTA		7
#define OC_LWHITE		8
#define OC_LBLACK		9
#define OC_LRED			10
#define OC_LGREEN		11
#define OC_LBLUE		12
#define OC_LCYAN		13
#define OC_LYELLOW		14
#define OC_LMAGENTA		15


#ifdef __GEMLIB_OLDNAMES

/* object flags */
#define NONE		 	0x0000
#define SELECTABLE		0x0001
#define DEFAULT			0x0002
#define EXIT			0x0004
#define EDITABLE		0x0008
#define RBUTTON			0x0010
#define LASTOB			0x0020
#define TOUCHEXIT		0x0040
#define HIDETREE		0x0080
#define INDIRECT		0x0100
#define FL3DIND			0x0200	/* bit 9 */
#define FL3DBAK			0x0400	/* bit 10 */
#define FL3DACT			0x0600
#define SUBMENU			0x0800	/* bit 11 */
#define FLAG11			SUBMENU
#define FLAG12			0x1000
#define FLAG13			0x2000
#define FLAG14			0x4000
#define FLAG15			0x8000

/* Object states */
#define NORMAL			0x0000
#define SELECTED		0x0001
#define CROSSED			0x0002
#define CHECKED			0x0004
#define DISABLED		0x0008
#define OUTLINED		0x0010
#define SHADOWED		0x0020
#define WHITEBAK		0x0040
#define DRAW3D			0x0080
#define STATE08			0x0100
#define STATE09			0x0200
#define STATE10			0x0400
#define STATE11			0x0800
#define STATE12			0x1000
#define STATE13			0x2000
#define STATE14			0x4000
#define STATE15			0x8000

/* Object colors - default pall. */
#define WHITE			0
#define BLACK			1
#define RED			2
#define GREEN			3
#define BLUE			4
#define CYAN			5
#define YELLOW			6
#define MAGENTA			7
#define LWHITE			8
#define LBLACK			9
#define LRED			10
#define LGREEN			11
#define LBLUE			12
#define LCYAN			13
#define LYELLOW			14
#define LMAGENTA		15

#endif


/* editable text field definitions */
#define EDSTART			0
#define EDINIT 			1
#define EDCHAR 			2
#define EDEND			3

#define ED_START		EDSTART
#define ED_INIT			EDINIT
#define ED_CHAR			EDCHAR
#define ED_END 			EDEND

#define ED_CRSR			100		/* MagiC only */
#define ED_DRAW			103		/* MagiC only */

/* editable text justification */
#define TE_LEFT			0
#define TE_RIGHT		1
#define TE_CNTR			2

/* objc_change modes */
#define NO_DRAW			0
#define REDRAW 			1

/* objc_order modes */
#define OO_LAST			-1
#define OO_FIRST		0

/* objc_sysvar modes */
#define SV_INQUIRE		0
#define SV_SET 			1

/* objc_sysvar values */
#define LK3DIND			1
#define LK3DACT			2
#define INDBUTCOL 		3
#define ACTBUTCOL 		4
#define BACKGRCOL 		5
#define AD3DVAL			6

		/* Mouse Form Definition Block */
typedef struct mouse_form
{
	short		mf_xhot;
	short		mf_yhot;
	short		mf_nplanes;
	short		mf_bg;
	short		mf_fg;
	short		mf_mask[16];
	short		mf_data[16];
} MFORM;

typedef struct graphic_rectangle
{
	short 		g_x;
	short 		g_y;
	short 		g_w;
	short 		g_h;
} GRECT;

typedef struct objc_colorword 
{
	unsigned	borderc : 4;
	unsigned	textc   : 4;
	unsigned	opaque  : 1;
	unsigned	pattern : 3;
	unsigned	fillc   : 4;
} OBJC_COLORWORD;

typedef struct text_edinfo
{
	char		*te_ptext;		/* ptr to text */
	char		*te_ptmplt;		/* ptr to template */
	char		*te_pvalid;		/* ptr to validation chrs. */
	short		te_font; 		/* font */
	short		te_fontid;		/* font id */
	short		te_just; 		/* justification */
	short		te_color;		/* color information word */
	short		te_fontsize;		/* font size */
	short		te_thickness;		/* border thickness */
	short		te_txtlen;		/* length of text string */
	short		te_tmplen;		/* length of template string */
} TEDINFO;

typedef struct icon_block
{
	short		*ib_pmask;
	short		*ib_pdata;
	char		*ib_ptext;
	short		ib_char;
	short		ib_xchar;
	short		ib_ychar;
	short		ib_xicon;
	short		ib_yicon;
	short		ib_wicon;
	short		ib_hicon;
	short		ib_xtext;
	short		ib_ytext;
	short		ib_wtext;
	short		ib_htext;
} ICONBLK;

typedef struct bit_block
{
	short		*bi_pdata;	/* ptr to bit forms data  */
	short		bi_wb;		/* width of form in bytes */
	short		bi_hl;		/* height in lines */
	short		bi_x; 		/* source x in bit form */
	short		bi_y; 		/* source y in bit form */
	short		bi_color;	/* fg color of blt */
} BITBLK;

typedef struct cicon_data
{
	short 		num_planes;
	short 		*col_data;
	short 		*col_mask;
	short 		*sel_data;
	short 		*sel_mask;
	struct cicon_data *next_res;
} CICON;

typedef struct cicon_blk
{
	ICONBLK		monoblk;
	CICON 		*mainlist;
} CICONBLK;

typedef struct
{
	 unsigned	character   :  8;
	 signed		framesize   :  8;
	 unsigned	framecol    :  4;
	 unsigned	textcol	    :  4;
	 unsigned	textmode    :  1;
	 unsigned	fillpattern :  3;
	 unsigned	interiorcol :  4;
} BFOBSPEC;

struct user_block;	/* forward declaration */

typedef union obspecptr
{
	long		index;
	union obspecptr	*indirect;
	BFOBSPEC 	obspec;
	TEDINFO		*tedinfo;
	BITBLK		*bitblk;
	ICONBLK		*iconblk;
	CICONBLK 	*ciconblk;
	struct user_block *userblk;
	char		*free_string;
} OBSPEC;

typedef struct object
{
	short 		ob_next;	/* -> object's next sibling */
	short 		ob_head; 	/* -> head of object's children */
	short 		ob_tail; 	/* -> tail of object's children */
	unsigned short	ob_type; 	/* type of object */
	unsigned short	ob_flags;	/* flags */
	unsigned short	ob_state;	/* state */
	OBSPEC		ob_spec; 	/* object-specific data */
	short 		ob_x; 		/* upper left corner of object */
	short 		ob_y; 		/* upper left corner of object */
	short 		ob_width;	/* width of obj */
	short 		ob_height;	/* height of obj */
} OBJECT;

typedef struct parm_block
{
	OBJECT		*pb_tree;
	short		pb_obj;
	short		pb_prevstate;
	short		pb_currstate;
	short		pb_x, pb_y, pb_w, pb_h;
	short		pb_xc, pb_yc, pb_wc, pb_hc;
	long		pb_parm;
} PARMBLK;

typedef struct user_block
{
	short __CDECL (*ub_code)(PARMBLK *parmblock);
	long ub_parm;
} USERBLK;


typedef struct rshdr
{
	short		rsh_vrsn;
	unsigned short	rsh_object;
	unsigned short	rsh_tedinfo;
	unsigned short	rsh_iconblk;		/* list of ICONBLKS */
	unsigned short	rsh_bitblk;
	unsigned short	rsh_frstr;
	unsigned short	rsh_string;
	unsigned short	rsh_imdata;		/* image data */
	unsigned short	rsh_frimg;
	unsigned short	rsh_trindex;
	short		rsh_nobs;		/* counts of various structs */
	short		rsh_ntree;
	short		rsh_nted;
	short		rsh_nib;
	short		rsh_nbb;
	short		rsh_nstring;
	short		rsh_nimages;
	unsigned short	rsh_rssize;		/* total bytes in resource */
} RSHDR;

typedef struct _menu
{
	OBJECT		*mn_tree;
	short		mn_menu;
	short		mn_item;
	short		mn_scroll;
	short		mn_keystate;
} MENU;

typedef struct
{
	short 		m_out;
	short 		m_x;
	short 		m_y;
	short 		m_w;
	short		m_h;
} MOBLK;

typedef struct mouse_event_type
{
	short		*x;
	short		*y;
	short		*b;
	short		*k;
} MOUSE;

#endif 

#ifdef __GEMLIB_AES

/*******************************************************************************
 * The AES bindings from old aesbind.h
 */
	 
short	appl_bvset	(short bvdisk, short bvhard);
short	appl_control	(short ap_cid, short ap_cwhat, void *ap_cout);
short	appl_exit	(void);
short	appl_find	(const char *Name);
short	appl_getinfo	(short type, short *out1, short *out2, short *out3, short *out4);
short	appl_init	(void);
short	appl_read	(short ApId, short Length, void *ApPbuff);
short	appl_search	(short mode, char *fname, short *type, short *ap_id);
short	appl_tplay	(void *Mem, short Num, short Scale);
short	appl_trecord	(void *Mem, short Count);
short	appl_write	(short ApId, short Length, void *ApPbuff);
short 	appl_yield	(void);

short	evnt_button 	(short Clicks, short WhichButton, short WhichState, short *Mx, short *My, short *ButtonState, short *KeyState); 
short	evnt_dclick 	(short ToSet, short SetGet);
short	evnt_keybd 	(void);
short	evnt_mesag 	(short MesagBuf[]);
short	evnt_mouse 	(short EnterExit, short InX, short InY, short InW, short InH, short *OutX, short *OutY, short *ButtonState, short *KeyState); 
short 	evnt_multi 	(short Type, short Clicks, short WhichButton, short WhichState, 
			 short EnterExit1, short In1X, short In1Y, short In1W, short In1H,
			 short EnterExit2, short In2X, short In2Y, short In2W, short In2H,
			 short MesagBuf[], unsigned long Interval, short *OutX, short *OutY,
			 short *ButtonState, short *KeyState, short *Key, short *ReturnCount);
short	evnt_timer 	(unsigned long Interval);

short	form_alert	(short DefButton, const char *Str);
short	form_button	(OBJECT *, short Bobject, short Bclicks, short *Bnxtobj);
short	form_center	(OBJECT *, short *Cx, short *Cy, short *Cw, short *Ch);
short 	form_dial	(short Flag, short Sx, short Sy, short Sw, short Sh, short Bx, short By, short Bw, short Bh);
short	form_do		(OBJECT *, short StartObj);
short 	form_error	(short ErrorCode);
short	form_keybd	(OBJECT *, short Kobject, short Kobnext, short Kchar,
			 short *Knxtobject, short *Knxtchar);

short 	fsel_exinput	(char *Path, char *File, short *ExitButton, const char *title);
short 	fsel_input	(char *Path, char *File, short *ExitButton);

short	graf_dragbox	(short Sw, short Sh, short Sx, short Sy, short Bx, short By, short Bw, short Bh, short *Fw, short *Fh); 
short	graf_growbox	(short Sx, short Sy, short Sw, short Sh, short Fx, short Fy, short Fw, short Fh); 
short	graf_handle	(short *Wchar, short *Hchar, short *Wbox, short *Hbox);
short	graf_mbox	(short Sw, short Sh, short Sx, short Sy, short Dx, short Dy);
short	graf_mkstate	(short *Mx, short *My, short *ButtonState, short *KeyState); 
short	graf_mouse	(short Form, void *FormAddress);
short	graf_rubbbox	(short Ix, short Iy, short Iw, short Ih, short *Fw, short *Fh);
short	graf_shrinkbox	(short Fx, short Fy, short Fw, short Fh, short Sx, short Sy, short Sw, short Sh); 
short	graf_slidebox	(OBJECT *, short Parent, short Object, short Direction); 
short	graf_watchbox	(OBJECT *, short Object, short InState, short OutState);

/* the old names */
#define graf_movebox(a,b,c,d,e,f) graf_mbox(a,b,c,d,e,f)
#define graf_rubberbox(a,b,c,d,e,f) graf_rubbbox(a,b,c,d,e,f)

short 	menu_attach 	(short me_flag, OBJECT *me_tree, short me_item, MENU *me_mdata);
short 	menu_bar 	(void *Tree, short ShowFlag);
short	menu_click	(short click, short setit);
short 	menu_icheck 	(void *Tree, short Item, short CheckFlag);
short 	menu_ienable	(void *Tree, short Item, short EnableFlag);
short 	menu_istart 	(short me_flag, OBJECT *me_tree, short me_imenu, short me_item);
short 	menu_popup 	(MENU *me_menu, short me_xpos, short me_ypos, MENU *me_mdata);
short 	menu_register 	(short ApId, char *MenuText);
short 	menu_settings 	(short me_flag, MN_SET *me_values);
short 	menu_text 	(void *Tree, short Item, char *Text);
short 	menu_tnormal 	(void *Tree, short Item, short NormalFlag);
short	menu_unregister	(short id);

short	objc_add	(OBJECT *, short Parent, short Child);
short	objc_change	(OBJECT *, short Object, short Res,
			 short Cx, short Cy, short Cw, short Ch,
			 short NewState,short Redraw);
short	objc_delete	(OBJECT *, short Object);
short	objc_draw	(OBJECT *, short Start, short Depth,
			 short Cx, short Cy, short Cw, short Ch);
short	objc_edit	(OBJECT *, short Object, short Char, short *Index, short Kind); 
short	objc_find	(OBJECT *, short Start, short Depth, short Mx, short My);
short	objc_offset	(OBJECT *, short Object, short *X, short *Y);
short	objc_order	(OBJECT *, short Object, short NewPos);
short	objc_sysvar	(short mode, short which, short in1, short in2, short *out1, short *out2);

short	rsrc_free	(void);
short	rsrc_gaddr	(short Type, short Index, void *Address);
short	rsrc_load	(const char *Name);
short	rsrc_obfix	(OBJECT *, short Index);
short	rsrc_rcfix	(void *rc_header);
short	rsrc_saddr	(short Type, short Index, void *Address);

short	scrp_clear 	(void);
short	scrp_read 	(char *Scrappath);
short	scrp_write 	(const char *Scrappath);

short	shel_envrn 	(char **result, const char *param);
short	shel_find 	(char *buf);
short 	shel_get 	(char *Buf, short Len);
short	shel_help	(short sh_hmode, const char *sh_hfile, const char *sh_hkey);
short 	shel_put	(const char *Buf, short Len);
short	shel_rdef	(char *lpcmd, char *lpdir);
short	shel_read 	(char *Command, char *Tail);
short	shel_wdef	(const char *lpcmd, const char *lpdir);
short	shel_write	(short Exit, short Graphic, short Aes, void *Command, char *Tail);

short	wind_calc 	(short Type, short Parts, short InX, short InY, short InW, short InH, short *OutX, short *OutY, short *OutW, short *OutH);	
short	wind_close 	(short WindowHandle);
short	wind_create 	(short Parts, short Wx, short Wy, short Ww, short Wh); 
short	wind_delete 	(short WindowHandle);
short	wind_find 	(short X, short Y);
short	wind_get 	(short WindowHandle, short What, short *W1, short *W2, short *W3, short *W4);
void	wind_new 	(void);
short	wind_open 	(short WindowHandle, short Wx, short Wy, short Ww, short Wh);
short	wind_set 	(short WindowHandle, short What, short W1, short W2, short W3, short W4);
short	wind_update 	(short Code);


/*
 * Some useful extensions
 */
short	wind_calc_grect	(short Type, short Parts, GRECT *In, GRECT *Out);  
short	wind_create_grect (short Parts, GRECT *r); 
void	wind_get_grect	(short WindowHandle, short What, GRECT *r);
short	wind_open_grect	(short WindowHandle, GRECT *r);
void	wind_set_grect	(short WindowHandle, short What, GRECT *r);
void	wind_set_str	(short WindowHandle, short What, char *str);

short	rc_copy 	(GRECT *src, GRECT *dst);
short	rc_equal 	(GRECT *src, GRECT *dst);
short 	rc_intersect 	(GRECT *r1, GRECT *r2);
short *	grect_to_array	(GRECT *area, short *array);
void	array_to_grect	(short *array, GRECT *area);


/*
 * aes trap interface
 */

/* Array sizes in aes control block */
#define AES_CTRLMAX		5
#define AES_GLOBMAX		16
#define AES_INTINMAX 		16
#define AES_INTOUTMAX		16
#define AES_ADDRINMAX		16
#define AES_ADDROUTMAX		16

typedef struct
{
	short	*control;
	short	*global;
	short	*intin;
	short	*intout;
	long	*addrin;
	long	*addrout;
} AESPB;

extern short	aes_global[];
extern short	aes_control[];
extern short	aes_intin[];
extern short	aes_intout[];
extern long 	aes_addrin[];
extern long	aes_addrout[];
extern AESPB	aes_params;
extern short	gl_apid, gl_ap_version;			/* initialized in appl_init */

void aes (AESPB *pb);

#endif /* AES */



#ifdef __GEMLIB_DEFS

/*******************************************************************************
 * The VDI specific stuff from old gemfast.h
 */

/* v_bez modes */
#define BEZ_BEZIER		0x01
#define BEZ_POLYLINE		0x00
#define BEZ_NODRAW		0x02

/* v_bit_image modes */
#define IMAGE_LEFT		0
#define IMAGE_CENTER		1
#define IMAGE_RIGHT		2
#define IMAGE_TOP 		0
#define IMAGE_BOTTOM		2

/* v_justified modes */
#define NOJUSTIFY		0
#define JUSTIFY			1

/* vq_color modes */
#define COLOR_REQUESTED		0
#define COLOR_ACTUAL		1

/* return values for vq_vgdos() inquiry */
#define GDOS_NONE		(-2L) 		 /* no GDOS installed */
#define GDOS_FSM		0x5F46534DL /* '_FSM' */
#define GDOS_FNT		0x5F464E54L /* '_FNT' */

/* vqin_mode & vsin_mode modes */
#define LOCATOR			1
#define VALUATOR		2
#define CHOICE			3
#define STRING			4

/* vqt_cachesize modes */
#define CACHE_CHAR		0
#define CACHE_MISC		1

/* vqt_devinfo return values */
#define DEV_MISSING		0
#define DEV_INSTALLED		1

/* vqt_name return values */
#define BITMAP_FONT		0

/* vsf_interior modes */
#define FIS_HOLLOW		0
#define FIS_SOLID		1
#define FIS_PATTERN		2
#define FIS_HATCH		3
#define FIS_USER		4

/* vsf_perimeter modes */
#define PERIMETER_OFF		0
#define PERIMETER_ON		1

/* vsl_ends modes */
#define SQUARE			0
#define ARROWED			1
#define ROUND			2

/* vsl_type modes */
#define SOLID			1
#define LDASHED			2
#define DOTTED			3
#define DASHDOT			4
#define DASH			5
#define DASHDOTDOT		6
#define USERLINE		7

/* vsm_type modes */
#define MRKR_DOT		1
#define MRKR_PLUS 		2
#define MRKR_ASTERISK		3
#define MRKR_BOX		4
#define MRKR_CROSS		5
#define MRKR_DIAMOND		6

/* vst_alignment modes */
#define TA_LEFT         	0 /* horizontal */
#define TA_CENTER       	1
#define TA_RIGHT        	2
#define TA_BASE         	0 /* vertical */
#define TA_HALF         	1
#define TA_ASCENT       	2
#define TA_BOTTOM       	3
#define TA_DESCENT      	4
#define TA_TOP          	5

/* vst_charmap modes */
#define MAP_BITSTREAM		0
#define MAP_ATARI		1

/* vst_effects modes */
#define TXT_NORMAL		0x0000
#define TXT_THICKENED		0x0001
#define TXT_LIGHT		0x0002
#define TXT_SKEWED		0x0004
#define TXT_UNDERLINED		0x0008
#define TXT_OUTLINED		0x0010
#define TXT_SHADOWED		0x0020

/* vst_error modes */
#define APP_ERROR		0
#define SCREEN_ERROR		1

/* vst_error return values */
#define NO_ERROR		0
#define CHAR_NOT_FOUND		1
#define FILE_READERR 		8
#define FILE_OPENERR 		9
#define BAD_FORMAT		10
#define CACHE_FULL		11
#define MISC_ERROR		(-1)

/* vst_kern tmodes */
#define TRACK_NONE		0
#define TRACK_NORMAL 		1
#define TRACK_TIGHT		2
#define TRACK_VERYTIGHT		3

/* vst_kern pmodes */
#define PAIR_OFF		0
#define PAIR_ON			1

/* vst_scratch modes */
#define SCRATCH_BOTH		0
#define SCRATCH_BITMAP		1
#define SCRATCH_NONE		2

/* v_updwk return values */
#define SLM_OK			0x00
#define SLM_ERROR		0x02
#define SLM_NOTONER		0x03
#define SLM_NOPAPER		0x04

/* VDI Memory Form Definition Block */
typedef struct memory_form
{
	void	*fd_addr;
	short 	fd_w;		/* Form Width in Pixels */
	short 	fd_h; 		/* Form Height in Pixels */
	short 	fd_wdwidth;	/* Form Width in shorts(fd_w/sizeof(short) */
	short 	fd_stand;	/* Form format 0= device spec 1=standard */
	short 	fd_nplanes;	/* Number of memory planes */
	short 	fd_r1;		/* Reserved */
	short 	fd_r2;		/* Reserved */
	short 	fd_r3;		/* Reserved */
} MFDB;

#endif 

#ifdef __GEMLIB_VDI

/*******************************************************************************
 * The VDI bindings from old vdibind.h
 */

/*
 * attribute functions 
 */
void	vs_color		(short handle, short color_idx, short rgb[]);
short 	vswr_mode		(short handle, short mode);

short 	vsf_color 		(short handle, short color_idx);
short 	vsf_interior 		(short handle, short style);
short 	vsf_perimeter 		(short handle, short vis);
short 	vsf_style 		(short handle, short style);
void	vsf_udpat 		(short handle, short pat[], short planes);

short 	vsl_color 		(short handle, short color_idx);
void	vsl_ends 		(short handle, short begstyle, short endstyle);
short 	vsl_type 		(short handle, short style);
void	vsl_udsty 		(short handle, short pat);
short 	vsl_width 		(short handle, short width);

short 	vsm_color 		(short handle, short color_idx);
short 	vsm_height 		(short handle, short height);
short 	vsm_type 		(short handle, short symbol);

void	vst_alignment 		(short handle, short hin, short vin, short *hout, short *vout);
short 	vst_color	 	(short handle, short color_idx);
short 	vst_effects		(short handle, short effects);
void	vst_error		(short handle, short mode, short *errorvar);
short 	vst_font 		(short handle, short font);
short 	vst_height 		(short handle, short height,	short *charw, short *charh, short *cellw, short *cellh);
short 	vst_point 		(short handle, short point, short *charw, short *charh, short *cellw, short *cellh);
short 	vst_rotation 		(short handle, short ang);
void	vst_scratch 		(short handle, short mode);

/*
 * control functions
 */
void	v_clrwk			(short handle);
void	v_clsvwk		(short handle);
void	v_clswk			(short handle);
short	v_flushcache		(short handle);
short	v_loadcache		(short handle, const char *filename, short mode);
void	v_opnvwk		(short work_in[], short *handle, short work_out[]);
void	v_opnwk			(short work_in[], short *handle, short work_out[]);
short	v_savecache		(short handle, const char *filename);
void	v_set_app_buff		(short handle, void *buf_p, short size);
void	v_updwk			(short handle);
void	vs_clip			(short handle, short clip_flag, short pxyarray[]);
short	vst_load_fonts		(short handle, short select);
void	vst_unload_fonts	(short handle, short select);

/*
 * escape functions
 */
void	v_bit_image		(short handle, const char *filename, short aspect, short x_scale, short y_scale, short h_align, short v_align, short *pxyarray);
void	v_clear_disp_list	(short handle);
short	v_copies		(short handle, short count);
void	v_dspcur		(short handle, short x, short y);
void	v_form_adv		(short handle);
void	v_hardcopy		(short handle);
short	v_orient		(short handle, short orientation);
void	v_output_window		(short handle, short *pxyarray);
short	v_page_size		(short handle, short page_id);
void	v_rmcur			(short handle);
void	v_trays			(short handle, short input, short output, short *set_input, short *set_output);
short	vq_calibrate		(short handle, short *flag);
short	vq_page_name		(short handle, short page_id, const char *page_name, long *page_width, long *page_height);
void	vq_scan			(short handle, short *g_slice, short *g_page, short *a_slice, short *a_page, short *div_fac);
short	vq_tabstatus		(short handle);
void	vq_tray_names		(short handle, const char *input_name, const char *output_name, short *input, short *output);
short	vs_calibrate		(short handle, short flag, short *rgb);
short	vs_palette		(short handle, short palette);

void	vq_tdimensions		(short handle, short *xdimension, short *ydimension);
void	vt_alignment		(short handle, short dx, short dy);
void	vt_axis			(short handle, short xres, short yres, short *xset, short *yset);
void	vt_origin		(short handle, short xorigin, short yorigin);
void	vt_resolution		(short handle, short xres, short yres, short *xset, short *yset);

void	v_meta_extents		(short handle, short min_x, short min_y, short max_x, short max_y);
void	v_write_meta		(short handle, short numvdi_intin, short *avdi_intin, short num_ptsin, short *a_ptsin);
void	vm_coords		(short handle, short llx, short lly, short urx, short ury);
void	vm_filename		(short handle, const char *filename);
void	vm_pagesize		(short handle, short pgwidth, short pgheight);

void	vsc_expose		(short handle, short state);
void	vsp_film		(short handle, short color_idx, short lightness);

void	v_escape2000		(short handle, short times);

void	v_alpha_text		(short handle, const char *str);
void	v_curdown		(short handle);
void	v_curhome		(short handle);
void	v_curleft		(short handle);
void	v_curright		(short handle);
void	v_curtext		(short handle, const char *str);
void	v_curup			(short handle);
void	v_eeol			(short handle);
void	v_eeos			(short handle);
void	v_enter_cur		(short handle);
void	v_exit_cur		(short handle);
void	v_rvoff			(short handle);
void	v_rvon			(short handle);
void	vq_chcells		(short handle, short *n_rows, short *n_cols);
void	vq_curaddress		(short handle, short *cur_row, short *cur_col);
void	vs_curaddress		(short handle, short row, short col);
	

/*
 * inquiry functions
 */
void	vq_cellarray		(short handle, short pxyarray[], short row_len, short nrows, short *el_used, short *rows_used, short *status, short color[]);
short	vq_color		(short handle, short color_idx, short flag, short rgb[]);
void	vq_extnd		(short handle, short flag, short work_out[]);
void	vqf_attributes		(short handle, short atrib[]);
void	vqin_mode		(short handle, short dev, short *mode);
void	vql_attributes		(short handle, short atrib[]);
void	vqm_attributes		(short handle, short atrib[]);
void	vqt_attributes		(short handle, short atrib[]);
void	vqt_cachesize		(short handle, short which_cache, long *size);
void	vqt_extent		(short handle, const char *str, short extent[]);
void	vqt_fontinfo		(short handle, short *minade, short *maxade, short distances[], short *maxwidth, short effects[]);
void	vqt_get_table		(short handle, short **map);
short	vqt_name		(short handle, short element, char *name);
short	vqt_width		(short handle, short chr, short *cw, short *ldelta, short *rdelta);

short	vq_gdos 		(void);
long	vq_vgdos 		(void);


/*
 * input function
 */
void	v_hide_c		(short handle);
void	v_show_c		(short handle, short reset);
void	vex_butv		(short handle, void *pusrcode, void **psavcode);
void	vex_curv		(short handle, void *pusrcode, void **psavcode);
void	vex_motv		(short handle, void *pusrcode, void **psavcode);
void	vex_timv		(short handle, void *time_addr, void **otime_addr, short *time_conv);
void	vq_key_s		(short handle, short *state);
void	vq_mouse		(short handle, short *pstatus, short *x, short *y);
void	vrq_choice		(short handle, short cin, short *cout);
void	vrq_locator		(short handle, short x, short y, short *xout, short *yout, short *term);
void	vrq_string		(short handle, short len, short echo, short echoxy[], char *str);
void	vrq_valuator		(short handle, short in, short *out, short *term);
void	vsc_form		(short handle, short form[]);
short	vsin_mode		(short handle, short dev, short mode);
short	vsm_choice		(short handle, short *choice);
short	vsm_locator		(short handle, short x, short y, short *xout, short *yout, short *term);
short	vsm_string		(short handle, short len, short echo, short echoxy[], char *str);
void	vsm_valuator		(short handle, short in, short *out, short *term, short *status);


/*
 * output functions
 */
void	v_arc			(short handle, short x, short y, short radius, short begang, short endang);
void	v_bar			(short handle, short pxyarray[]);
void	v_cellarray		(short handle, short pxyarray[], short row_length, short elements, short nrows, short write_mode, short colarray[]);
void	v_circle		(short handle, short x, short y, short radius);
void	v_contourfill		(short handle, short x, short y, short color_idx);
void	v_ellarc		(short handle, short x, short y, short xrad, short yrad, short begang, short endang);
void	v_ellipse		(short handle, short x, short y, short xrad, short yrad);
void	v_ellpie		(short handle, short x, short y, short xrad, short yrad, short begang, short endang);
void	v_fillarea		(short handle, short count, short pxyarray[]);
void	v_gtext			(short handle, short x, short y, const char *str) ;
void	v_justified		(short handle, short x, short y, const char *str, short len, short word_space, short char_space);
void	v_pieslice		(short handle, short x, short y, short radius, short begang, short endang);
void	v_pline			(short handle, short count, short pxyarray[]);
void	v_pmarker		(short handle, short count, short pxyarray[]);
void	v_rbox			(short handle, short pxyarray[]);
void	v_rfbox			(short handle, short pxyarray[]);
void	vr_recfl		(short handle, short pxyarray[]);

/*
 * raster functions
 */
void	v_get_pixel		(short handle, short x, short y, short *pel, short *color_idx);
void	vr_trnfm		(short handle, MFDB *src, MFDB *dst);
void	vro_cpyfm		(short handle, short mode, short pxyarray[], MFDB *src, MFDB *dst);
void	vrt_cpyfm		(short handle, short mode, short pxyarray[], MFDB *src, MFDB *dst, short color[]);


/*
 * Some usefull extensions.
 */
void	vdi_array2str		(const short *src, char  *des, short len);
short	vdi_str2array		(const char  *src, short *des);


/*
 * vdi trap interface
 */

/* Array sizes in vdi control block */
#define VDI_CNTRLMAX		15
#define VDI_INTINMAX		1024
#define VDI_INTOUTMAX		256
#define VDI_PTSINMAX		256
#define VDI_PTSOUTMAX		256

typedef struct
{
	short	*control;
	short	*intin;
	short	*ptsin;
	short	*intout;
	short	*ptsout;
} VDIPB;

extern short	vdi_intin[];
extern short	vdi_intout[];
extern short	vdi_ptsin[];
extern short	vdi_ptsout[];
extern short	vdi_control[];
extern VDIPB	vdi_params;

void vdi (VDIPB *pb);

#endif /* VDI */


__END_DECLS

#endif /* _GEMLIB_H_ */
