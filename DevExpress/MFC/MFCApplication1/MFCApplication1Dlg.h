
// MFCApplication1Dlg.h : header file
//

#pragma once
#include "SphInc/gui/SphDialog.h"
#include "SpecificDialog.h"

// CMFCApplication1Dlg dialog
class CMFCApplication1Dlg : public CDialogEx, public SpecificDialog
{
// Construction
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	void LoadListBox();
	void LoadListCntrl();

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// Control Variable
	CListBox m_listBox;
	CListCtrl m_listCtrl;
	afx_msg void OnLbnSelchangeList1();
};
