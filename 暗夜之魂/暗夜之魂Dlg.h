// °µÒ¹Ö®»êDlg.h : header file
//

#if !defined(AFX_DLG_H__750C577F_9E86_4121_B4FC_8F9D69E7A2EF__INCLUDED_)
#define AFX_DLG_H__750C577F_9E86_4121_B4FC_8F9D69E7A2EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
private:
	CDC cdc1,cdc2,cdc3,cdc4,cdc5,cdc6,cdc7,cdc8,cdc9,cdc10,cdc11,cdc12;
	CBitmap temp,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11;
	BITMAP bm1;
	void zzysb();
	int i,a1,d,an,n,sn,x,y,random_choice;
public:
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
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__750C577F_9E86_4121_B4FC_8F9D69E7A2EF__INCLUDED_)
