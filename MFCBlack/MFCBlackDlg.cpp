
// MFCBlackDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCBlack.h"
#include "MFCBlackDlg.h"
#include "afxdialogex.h"
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

short CMFCBlackDlg::cardsControl = 0;
short CMFCBlackDlg::Help_used = 0;
short CMFCBlackDlg::Stand_used = 1;
short CMFCBlackDlg::Clear_used = 1;
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCBlackDlg dialog



CMFCBlackDlg::CMFCBlackDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCBLACK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCBlackDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCBlackDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(start, &CMFCBlackDlg::OnBnClickedstart)
	ON_BN_CLICKED(radio_p1, &CMFCBlackDlg::OnBnClickedp1)
	ON_BN_CLICKED(hitme_btn, &CMFCBlackDlg::OnBnClickedbtn)
	ON_BN_CLICKED(radio_p2, &CMFCBlackDlg::OnBnClickedp2)
	ON_BN_CLICKED(radio_p3, &CMFCBlackDlg::OnBnClickedp3)
	ON_BN_CLICKED(Action_stand, &CMFCBlackDlg::OnBnClickedstand)
	ON_EN_CHANGE(txt_p1_cards, &CMFCBlackDlg::OnEnChangep1cards)
	ON_BN_CLICKED(Action_help, &CMFCBlackDlg::OnBnClickedhelp)
	ON_EN_CHANGE(Game_screen, &CMFCBlackDlg::OnEnChangescreen)
	ON_EN_CHANGE(Game_screen2, &CMFCBlackDlg::OnEnChangescreen2)
	ON_EN_CHANGE(Game_screen3, &CMFCBlackDlg::OnEnChangescreen3)
	ON_EN_CHANGE(Game_screen4, &CMFCBlackDlg::OnEnChangescreen4)
	ON_EN_CHANGE(Game_screen5, &CMFCBlackDlg::OnEnChangescreen5)
	ON_EN_CHANGE(Game_result, &CMFCBlackDlg::OnEnChangeresult)
	ON_EN_CHANGE(Gscreen_blackjack, &CMFCBlackDlg::OnEnChangeblackjack)
	ON_EN_CHANGE(Gscreen_CARDS, &CMFCBlackDlg::OnEnChangeCards)
	ON_BN_CLICKED(Players_Deselect, &CMFCBlackDlg::OnBnClickedDeselect)
	ON_BN_CLICKED(Exit, &CMFCBlackDlg::OnBnClickedExit)
	ON_EN_CHANGE(Box_Name, &CMFCBlackDlg::OnEnChangeName)
END_MESSAGE_MAP()


// CMFCBlackDlg message handlers

BOOL CMFCBlackDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	srand((unsigned int) (time(NULL)));
	d = new Dealer();
	you = new Player();
	p[0] = new Player();
	p[1] = new Player();
	p[2] = new Player();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCBlackDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCBlackDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCBlackDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






//--------------------------------------------------------My Functions----------------------------------------------

void CMFCBlackDlg::OnBnClickedstart()
{
	delete[] you;
	delete[] d;
	delete[] p[0];
	delete[] p[1];
	delete[] p[2];
	you = new Player();
	d = new Dealer();
	p[0] = new Player();	
	p[1] = new Player();
	p[2] = new Player();
	cardsControl = 2;
	Help_used = 0;
	Stand_used = 0;
	Clear_used = 0;
	CMFCBlackDlg::OnBnClickedp1();
	CMFCBlackDlg::OnBnClickedp2();
	CMFCBlackDlg::OnBnClickedp3();
	you->setTV(0);
	SetDlgItemText(Game_screen3, _T(""));
	SetDlgItemText(Game_screen4, _T(""));
	SetDlgItemText(Game_screen5, _T(""));
	SetDlgItemText(Game_result, _T(""));
	CString display, Second_Card;
	CMFCBlackDlg::GetDlgItemTextW(txt_p1_cards, display);
	SetDlgItemText(Game_screen, _T("Welcome to blackjack! The dealer begins to draw..."));
	SetDlgItemText(Game_screen2, _T("Your turn! Current sum of cards is placed below. Enter your action (on the left):"));

	you->setCard(d->Action_draw(), 0);
	you->setTV(you->getTV() + you->GetCardValue(0));
	display.Format(_T("%d"), you->GetCardValue(0));
	display = display + _T(", ");

	you->setCard(d->Action_draw(), 1);
	you->setTV(you->getTV() + you->GetCardValue(1));
	Second_Card.Format(_T("%d"), you->GetCardValue(1));
	display = display + Second_Card;

	SetDlgItemText(Gscreen_CARDS, display);
	display.Format(_T("%d"), you->getTV());
	SetDlgItemText(txt_p1_cards, display);
	if (you->getTV() == 12 && (you->GetCardValue(0) == 1 || you->GetCardValue(1) == 1)) {
		you->BlackJack(true);
		SetDlgItemText(Gscreen_blackjack, _T("true"));
	}
	else SetDlgItemText(Gscreen_blackjack, _T("false"));
}

void CMFCBlackDlg::OnBnClickedp1()
{
	CButton *ptr = (CButton*)GetDlgItem(radio_p1);
	if (!ptr->GetCheck() || Stand_used == 1 || Clear_used == 1) {
		return;
	}
	short sum = 0, i;
	for (i = 0; i < 5 && sum < 14; i++) {
		p[0]->setCard(d->Action_draw(), i);
		sum += p[0]->GetCardValue(i);
		if (i == 2) {
			if (sum == 12 && (p[0]->GetCardValue(0) == 1 || p[0]->GetCardValue(1))) p[0]->BlackJack(true);
		}
	}
	p[0]->setTV(sum <= 21 ? sum : 0);
}

void CMFCBlackDlg::OnBnClickedp2()
{
	CButton *ptr = (CButton*)GetDlgItem(radio_p1);
	if (!ptr->GetCheck() || Stand_used == 1 || Clear_used == 1) {
		return;
	}
	short sum = 0, i;
	for (i = 0; i < 5 && sum < 14; i++) {
		p[1]->setCard(d->Action_draw(), i);
		sum += p[1]->GetCardValue(i);
		if (i == 2) {
			if (sum == 12 && (p[1]->GetCardValue(0) == 1 || p[1]->GetCardValue(1))) p[0]->BlackJack(true);
		}
	}
	p[1]->setTV(sum <= 21 ? sum : 0);
	// TODO: Add your control notification handler code here
}


	void CMFCBlackDlg::OnBnClickedp3(){
	CButton *ptr = (CButton*)GetDlgItem(radio_p1);
	if (!ptr->GetCheck() || Stand_used == 1 || Clear_used == 1) {
		return;
	}
	short sum = 0, i;
	for (i = 0; i < 5 && sum < 14; i++) {
		p[2]->setCard(d->Action_draw(), i);
		sum += p[2]->GetCardValue(i);
		if (i == 2) {
			if (sum == 12 && (p[2]->GetCardValue(0) == 1 || p[2]->GetCardValue(1))) p[2]->BlackJack(true);
		}
	}
	p[2]->setTV(sum <= 21 ? sum : 0);

	// TODO: Add your control notification handler code here
}

//hit me button
void CMFCBlackDlg::OnBnClickedbtn()
{
	if (cardsControl == 5 || Stand_used == 1)
	{
		return;
	}
	CString hitMeAgain ,new_card;
	CMFCBlackDlg::GetDlgItemTextW(Gscreen_CARDS, hitMeAgain);
	you->setCard(d->Action_draw(), cardsControl);
	you->setTV(you->getTV() + you->GetCardValue(cardsControl));
	new_card.Format(_T("%d"), you->GetCardValue(cardsControl));
	hitMeAgain = hitMeAgain + _T(", ") + new_card;
	SetDlgItemText(Gscreen_CARDS, hitMeAgain);
	cardsControl++;

	CMFCBlackDlg::GetDlgItemTextW(Game_screen3, hitMeAgain);
	hitMeAgain.Format(_T("drew a card. Current sum has been updated below."));
	SetDlgItemText(Game_screen3, hitMeAgain);

	CMFCBlackDlg::GetDlgItemTextW(txt_p1_cards, hitMeAgain);
	hitMeAgain.Format(_T("%d"), you->getTV());
	SetDlgItemText(txt_p1_cards, hitMeAgain);

	// TODO: Add your control notification handler code here
}


void CMFCBlackDlg::OnBnClickedstand()
{
	if (Stand_used == 1) {
		return;
	}
	cardsControl = 5;
	Help_used = 1;
	Stand_used = 1;
	SetDlgItemText(Game_screen4, _T("Checking result..."));
	if (you->getTV() > 21) {
		SetDlgItemText(Game_result, _T("You have beyond 21. You lose :("));
	}
	else{
		SetDlgItemText(Game_screen5, _T("Dealer's turn..."));
		d->setCard(d->Action_draw(), 0);
		d->setTV(d->getTV() + d->GetCardValue(0));
		d->setCard(d->Action_draw(), 1);
		d->setTV(d->getTV() + d->GetCardValue(1));
		d->BlackJack((d->getTV() == 12 && (d->GetCardValue(0) == 1 || d->GetCardValue(1) == 1)) ? true : false);
		if (d->getTV() > 21) d->getHelp(1);
		else {
			d->setCard(d->Action_draw(), 2);
			d->setTV(d->getTV() + d->GetCardValue(2));
			if (d->getTV() > 21) d->getHelp(2);
			else {
				d->setCard(d->Action_draw(), 3);
				d->setTV(d->getTV() + d->GetCardValue(3));
				if (d->getTV() > 21) d->getHelp(3);
				else{
					d->setCard(d->Action_draw(), 4);
					d->setTV(d->getTV() + d->GetCardValue(4));
					if (d->getTV() > 21) d->getHelp(4);
				}
			}
		}
		if (d->getTV() > 21)d->setTV(0);
		if (you->getBlackJack() == false && d->getBlackJack() == true) {
			SetDlgItemText(Game_result, _T("The dealer has a better hand then you. You lose :("));
		}
		else if (you->getBlackJack() == true && d->getBlackJack() == true) {
			SetDlgItemText(Game_result, _T("BlackJack push between you and dealer"));
		}
		else if (you->getTV() == d->getTV()) {
			SetDlgItemText(Game_result, _T("Push between you and dealer"));
		}
		else if (you->getTV() < d->getTV() && you->getBlackJack() == false) {
			SetDlgItemText(Game_result, _T("The dealer has a better hand then you. You lose :("));
		}
		else {
			bool player_win = true;
			bool push = false;
			for (short i = 0; i < 3 && player_win == true; i++) {
				if (p[i]->getTV() > 21) player_win = true;
				else if (you->getTV() < p[i]->getTV() && you->getBlackJack() == false) player_win = false;
				else if (p[i]->getBlackJack() == true) {
					if (you->getBlackJack() == true) push = true;
					player_win = false;
				}
				else if (you->getTV() == p[i]->getTV() && you->getBlackJack() == false) {
					push = true;
					player_win = false;
				}
			}
			if (player_win == true) {
				CString player_win;
				CMFCBlackDlg::GetDlgItemTextW(Box_Name, player_win);
				player_win = player_win + _T(" won!");
				SetDlgItemText(Game_result, player_win);
			}
			else {
				if (push == true) {
					if (you->getBlackJack() == true) {
						SetDlgItemText(Game_result, _T("BlackJack push with one of the other players."));
					}
					else {
						SetDlgItemText(Game_result, _T("Push with one of the players."));
					}
				}
				else {
					SetDlgItemText(Game_result, _T("One of the players has a better hand then you. You lose :("));
				}
			}
		}
	}
}

void CMFCBlackDlg::OnBnClickedhelp(){
	if (Help_used == 1 || Stand_used == 1) {
		return;
	}
	CString new_sum, remove_card;
	you->getHelp(cardsControl - 1);
	SetDlgItemText(Game_screen3, _T("Help has been used"));
	new_sum.Format(_T("%d"), you->getTV());
	SetDlgItemText(txt_p1_cards, (_T("%d"), new_sum));

	CMFCBlackDlg::GetDlgItemTextW(Gscreen_CARDS, new_sum);
	new_sum.Format(_T("%d"), you->GetCardValue(0));
	for (short i = 1; i < cardsControl - 1; i++) {
		remove_card.Format(_T("%d"), you->GetCardValue(i));
		new_sum = new_sum + _T(", ") + remove_card;
	}
	SetDlgItemText(Gscreen_CARDS, new_sum);
	cardsControl--;
	Help_used = 1;
}

void CMFCBlackDlg::OnBnClickedDeselect()
{
	CButton *uncheck;
	uncheck = (CButton*)GetDlgItem(radio_p1);
	uncheck->SetCheck(0);
	uncheck = (CButton*)GetDlgItem(radio_p2);
	uncheck->SetCheck(0);
	uncheck = (CButton*)GetDlgItem(radio_p3);
	uncheck->SetCheck(0);
	if (Clear_used == 1) {
		return;
	}
	p[0]->setTV(0);
	p[1]->setTV(0);
	p[2]->setTV(0);
	Clear_used = 1;
}

void CMFCBlackDlg::OnBnClickedExit()
{
	delete[] you;
	delete[] d;
	delete[] p[0];
	delete[] p[1];
	delete[] p[2];
	EndDialog(-1);
}




//---------------------------------------------------txt misc-----------------------------------------------------





void CMFCBlackDlg::OnEnChangep1cards()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CMFCBlackDlg::OnEnChangescreen()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCBlackDlg::OnEnChangescreen2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCBlackDlg::OnEnChangescreen3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCBlackDlg::OnEnChangescreen4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCBlackDlg::OnEnChangescreen5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCBlackDlg::OnEnChangeresult()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCBlackDlg::OnEnChangeblackjack()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCBlackDlg::OnEnChangeCards()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCBlackDlg::OnEnChangeName()
{
	CString name;
	CMFCBlackDlg::GetDlgItemTextW(Box_Name, name);
	you->setName(name);
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
