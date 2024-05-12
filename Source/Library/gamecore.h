#pragma once

/////////////////////////////////////////////////////////////////////////////
// ?w?qCGame??CGameState????¢D????T?????A¡Ó`??
/////////////////////////////////////////////////////////////////////////////

enum GAME_STATES {
	GAME_STATE_INIT,
	GAME_STATE_RUN,
	GAME_STATE_OVER
};

/////////////////////////////////////////////////////////////////////////////
// Header for STL (Standard Template Library)
/////////////////////////////////////////////////////////////////////////////

#include <list>
#include <vector>
#include <map>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// ?^???{?????~¢D???macro
// ?????G?o????¢D?macro¢DH?K?O?d???¡Ñ?W?????????A¡±Q??debug?C
/////////////////////////////////////////////////////////////////////////////

#define GAME_ASSERT(boolexp,str)											\
		if (!(boolexp)) {													\
			int id;															\
			char s[300]="";													\
			sprintf(s,"Game fatal error:\n\n%s\n\nFile: %s\n\nLine: %d"		\
				"\n\n(Press Retry to debug the application, "				\
				"if it is executed in debug mode.)"							\
				"\n(Press Cancel otherwise.)",								\
				 str , __FILE__,__LINE__);									\
			id = AfxMessageBox(s, MB_RETRYCANCEL);							\
																			\
			if (id == IDCANCEL)												\
				exit(1);													\
			AfxDebugBreak();												\
		}

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// ?o??class?¢G???????B???~?¢D¡Ó¡Ó??
	// ?@?????C?????¢G????¡Ó???¡±@?o????¢D??A?]??¢Di¢DH?¢G???o??class????¢D????k
	/////////////////////////////////////////////////////////////////////////////

	class CSpecialEffect {
	public:
		static void  SetCurrentTime();					// ?x?s¢D??e????????ctime
		static DWORD GetEllipseTime();					// ????¢D??e?????? - ctime
		static int   GetCurrentTimeCount();				// ?????x?sctime??????
		static void  Delay(DWORD ms);					// ???? x ms
		static void  DelayFromSetCurrentTime(DWORD ms);	// ??ctime¢X_???A???? x ms
	private:
		static DWORD ctime;
		static int	 ctimeCount;
	};

	/////////////////////////////////////////////////////////////////////////////
	// ?o??class¡P|??¢D?DirectDraw??¢D??A¢DH?¢G????¢DLclass??¢D?
	// ?@?????C?????¢G????¡Ó???¡±@?o????¢D??A?]??¢Di¢DH?¢G???o??class????¢D????k
	/////////////////////////////////////////////////////////////////////////////

	class CDDraw {
		friend class CMovingBitmap;
	public:
		~CDDraw();
		static void  BltBackColor(DWORD);		// ¡ÓNBack plain¢D??????W???w???C??
		static void  BltBackToPrimary();		// ¡ÓNBack plain?K??Primary plain
		static CDC*  GetBackCDC();				// ??¡ÓoBack Plain??DC (device context)
		static void  GetClientRect(CRect &r);	// ??¡Óo?]?w?????R?¡Ñ
		static void  Init(int, int);			// Initialize direct draw
		static void  ReleaseBackCDC();			// ??¡Ó?Back Plain??DC (device context)
		static bool  SetFullScreen(bool);		// ?]?w?¢X¢D?????????/????????
		static bool  IsFullScreen();			// ?^???O¡±_?¢X¢D?????????/????????
	private:
		CDDraw();								// private constructor
		static void  BltBitmapToBack(unsigned SurfaceID, int x, int y);
		static void  BltBitmapToBack(unsigned SurfaceID, int x, int y, double factor);
		static void  BltBitmapToBitmap(unsigned SourceID, unsigned TargetID, int x, int y);
		static void	 CheckDDFail(char *s);
		static bool  CreateSurface();
		static bool  CreateSurfaceFullScreen();
		static bool  CreateSurfaceWindowed();
		static void  LoadBitmap(int i, int IDB_BITMAP);
		static void  LoadBitmap(int i, char *filename);
		static void  LoadBitmapFromExistHBITMAP(int i, HBITMAP bitmap);
		static DWORD MatchColorKey(LPDIRECTDRAWSURFACE lpDDSurface, COLORREF color);
		static int   RegisterBitmap(int IDB_BITMAP, COLORREF ColorKey);
		static int   RegisterBitmap(char *filename, COLORREF ColorKey);
		static int   RegisterBitmapWithHBITMAP(HBITMAP hbitmap);
		static void  ReleaseSurface();
		static void  RestoreSurface();
		static void  SetColorKey(unsigned SurfaceID, COLORREF color);
		static HDC					hdc;
		static CDC					cdc;
		static CView				*pCView;
		static LPDIRECTDRAW2		lpDD;
		static LPDIRECTDRAWCLIPPER	lpClipperPrimary;
		static LPDIRECTDRAWCLIPPER	lpClipperBack;
		static LPDIRECTDRAWSURFACE	lpDDSPrimary;
		static LPDIRECTDRAWSURFACE	lpDDSBack;
		static vector<LPDIRECTDRAWSURFACE>	lpDDS;
		static HRESULT				ddrval;
		static vector<int>			BitmapID;
		static vector<string>		BitmapName;
		static vector<CRect>		BitmapRect;
		static vector<COLORREF>		BitmapColorKey;
		static bool					fullscreen;
		static CDDraw				ddraw;
		static int					size_x, size_y;
	};

	/////////////////////////////////////////////////////////////////////////////
	// ??¡±i?|¢D??w?q??class
	/////////////////////////////////////////////////////////////////////////////

	class CGame;
	class CGameStateInit;
	class CGameStateRun;
	class CGameStateOver;

	/////////////////////////////////////////////////////////////////////////////
	// ?o??class?¢X?C?????U?????A?¡±Base class(?O?@??abstract class)
	// ?C??Public Interface??¢D??k?¢G?n???AImplementation¢Di¢DH?¢G??
	/////////////////////////////////////////////////////////////////////////////

	class CGameState {
	public:
		CGameState(CGame *g);
		void OnDraw();			// Template Method
		void OnCycle();			// Template Method
		//
		// virtual functions, ¢D??~?????¢G??implementation
		//
		virtual ~CGameState() {}								// virtual destructor
		virtual void OnBeginState() {}							// ?]?w?C???i?J?o?????A????????????
		virtual void OnInit() {}								// ???A??????????¡±??]?w
		virtual void OnKeyDown(UINT, UINT, UINT) {}				// ?B?z???LDown??¢X?¡±@
		virtual void OnKeyUp(UINT, UINT, UINT) {}				// ?B?z???LUp??¢X?¡±@
		virtual void OnLButtonDown(UINT nFlags, CPoint point) {}// ?B?z¡P?????¢X?¡±@
		virtual void OnLButtonUp(UINT nFlags, CPoint point) {}	// ?B?z¡P?????¢X?¡±@
		virtual void OnMouseMove(UINT nFlags, CPoint point) {}  // ?B?z¡P?????¢X?¡±@ 
		virtual void OnRButtonDown(UINT nFlags, CPoint point) {}// ?B?z¡P?????¢X?¡±@
		virtual void OnRButtonUp(UINT nFlags, CPoint point) {}	// ?B?z¡P?????¢X?¡±@
	protected:
		void GotoGameState(int state);							// ???D?????w??state
		void ShowInitProgress(int percent, string message);						// ??¢D????l?????i?¡Ñ
		//
		// virtual functions, ¢D??~?????¢G??implementation
		//
		virtual void OnMove() {}								// ??¢X??o?????A???C??????
		virtual void OnShow() = 0;								// ??¢D??o?????A???C???e?¡Ó
		CGame *game;
		CMovingBitmap loadingBitmap;
	};

	/////////////////////////////////////////////////////////////////////////////
	// ?o??class?O?C?????????A¡Ó¡Ó???C?????i??
	// ?@?????C?????¢G????¡Ó???¡±@?o????¢D??A?]??¢Di¢DH?¢G???o??class????¢D????k
	/////////////////////////////////////////////////////////////////////////////

	class CGame {
	public:
		CGame();										// Constructor
		~CGame();										// Destructor
		bool IsRunning();								// ?????C???O¡±_¢D??b?i????
		void OnDraw();									// ????CGameView??OnDraw()
		void OnFilePause();								// ?C????¢X¡Ó
		void OnInit();									// ?C?????????????????l??
		void OnInitStates();							// ?C???U???A??????????¡±??]?w
		bool OnIdle();									// ?C????¢DD¢Xj¢X?
		void OnKeyDown(UINT, UINT, UINT);				// ?B?z???LDown??¢X?¡±@
		void OnKeyUp(UINT, UINT, UINT);					// ?B?z???LUp??¢X?¡±@
		void OnKillFocus();								// ?C???Q?¢F??¢X¡Ó
		void OnLButtonDown(UINT nFlags, CPoint point);	// ?B?z¡P?????¢X?¡±@
		void OnLButtonUp(UINT nFlags, CPoint point);	// ?B?z¡P?????¢X?¡±@
		void OnMouseMove(UINT nFlags, CPoint point);    // ?B?z¡P?????¢X?¡±@ 
		void OnRButtonDown(UINT nFlags, CPoint point);	// ?B?z¡P?????¢X?¡±@
		void OnRButtonUp(UINT nFlags, CPoint point);	// ?B?z¡P?????¢X?¡±@
		void OnResume();								// ?B?z???u???R?v??????¢X?¡±@
		void OnSetFocus();								// ?B?zFocus
		void OnSuspend();								// ?B?z?u???R?v??¢X?¡±@
		void SetGameState(int);
		static CGame *Instance();
	private:
		bool			running;			// ?C???O¡±_¢D??b?i????(¢D??QPause)
		bool            suspended;			// ?C???O¡±_?Qsuspended
		const int		NUM_GAME_STATES;	// ?C???????A??(3?????A)
		CGameState		*gameState;			// pointer???V¢D??e???C?????A
		CGameState		*gameStateTable[3];	// ?C?????A??¢D???pointer
		static CGame	instance;			// ?C??¢X??@??instance
	};
}
