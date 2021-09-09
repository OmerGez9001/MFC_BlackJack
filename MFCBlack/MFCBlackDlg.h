#include "Player.h"
#include "Dealer.h"
// MFCBlackDlg.h : header file
//

#pragma once


// CMFCBlackDlg dialog
class CMFCBlackDlg : public CDialogEx
{
// Construction
public:
	CMFCBlackDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCBLACK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	static short cardsControl;
	static short Help_used;
	static short Stand_used;
	static short Clear_used;
	Player *you;
	Player *p[3];
	Dealer *d;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedp1();
	afx_msg void OnBnClickedbtn();
	afx_msg void OnBnClickedp2();
	afx_msg void OnBnClickedp3();
	afx_msg void OnBnClickedstand();
	afx_msg void OnEnChangep1cards();
	afx_msg void OnBnClickedhelp();
	afx_msg void OnEnChangescreen();
	afx_msg void OnBnClickedstart();
	afx_msg void OnEnChangescreen2();
	afx_msg void OnEnChangescreen3();
	afx_msg void OnEnChangescreen4();
	afx_msg void OnEnChangescreen5();
	afx_msg void OnEnChangeresult();
	afx_msg void OnEnChangeblackjack();
	afx_msg void OnEnChangeCards();
	afx_msg void OnBnClickedDeselect();
	afx_msg void OnBnClickedExit();
	afx_msg void OnEnChangeName();
};
