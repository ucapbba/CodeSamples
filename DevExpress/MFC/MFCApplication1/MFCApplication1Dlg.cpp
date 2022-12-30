
// MFCApplication1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "SphInc/gui/SphEditElement.h"
#include "SpecificDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent), SpecificDialog()
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listBox);
	DDX_Control(pDX, IDC_LIST2, m_listCtrl);
	//fElementCount = 1;
 //  fElementList = new sophis::gui::CSRElement * [fElementCount];
 //  if (fElementList) 
 //  {
 //      fElementList[0] = new sophis::gui::CSREditDouble(this, IDC_EDIT1 -ID_ITEM_SHIFT, 2, 0, 1000000000., 10.0);
 //  } 
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCApplication1Dlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
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
	LoadListBox();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}

void CMFCApplication1Dlg::LoadListBox() {
	CString str = _T("");
	for (int i = 0; i < 10; i++) {

		str.Format(_T("Item %d"), i);
		m_listBox.AddString(str);
	}
}

void CMFCApplication1Dlg::LoadListCntrl() {
	//m_listCtrl.InsertColumn(0, "Page");
	m_listCtrl.SetColumnWidth(0, 60);
	//m_listCtrl.InsertColumn(1, "Last Modified");
	m_listCtrl.SetColumnWidth(1, 80);
	//m_listCtrl.InsertColumn(2, "Prioirty");
	m_listCtrl.SetColumnWidth(2, 50);
	m_listCtrl.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0,	LVS_EX_FULLROWSELECT);

	/*AddData(m_listCtrl, 0, 0, "First");
	AddData(m_listCtrl, 0, 1, "Jan 2011");
	AddData(m_listCtrl, 0, 2, "Medium");
	AddData(m_listCtrl, 1, 0, "Second");
	AddData(m_listCtrl, 1, 1, "Feb 2011");
	AddData(m_listCtrl, 1, 2, "High");*/
}

static void AddData(CListCtrl& ctrl, int row, int col, const char* str)

{
	LVITEM lv;
	lv.iItem = row;
	lv.iSubItem = col;
	lv.pszText = (LPWSTR)str;
	lv.mask = LVIF_TEXT;
	if (col == 0)

		ctrl.InsertItem(&lv);

	else

		ctrl.SetItem(&lv);
}
