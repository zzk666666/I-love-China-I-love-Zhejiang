// °µÒ¹Ö®»êDlg.h : header file
//

#if !defined(AFX_DLG_H__2B441415_9DBE_437C_9859_1D2FC3E2C70C__INCLUDED_)
#define AFX_DLG_H__2B441415_9DBE_437C_9859_1D2FC3E2C70C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction

public:
	BITMAP b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11;
	CBitmap temp bm1 
	CDC cdc1,cdc2,cdc3,cdc4,cdc5,cdc6,cdc7,cdc8,cdc9,cdc10,cdc11,cdc12;
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__2B441415_9DBE_437C_9859_1D2FC3E2C70C__INCLUDED_)
