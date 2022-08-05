
// TestMFCDlg.h : header file
//

#pragma once


// CTestMFCDlg dialog
class CTestMFCDlg : public CDHtmlDialog
{
// Construction
public:
	CTestMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTMFC_DIALOG, IDH = IDR_HTML_TESTMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void CreateConsole();
	HWND WINAPI  GetConsoleWindowNT(void);
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	afx_msg void OnBnClickedTestbuttin();
	CEdit Id1;
	CButton CL_CheckFast;
	afx_msg void OnBnClickedCheckFast();
	afx_msg void OnFileNew();
	afx_msg void OnFileSave();
	afx_msg void OnHelpAbout();
	afx_msg void OnHelpNotepad();
	afx_msg void OnEnChangeUnivaue();
	CEdit m_TargetEdit;
	afx_msg void OnBnClickedCreateAnimal();
	afx_msg void OnBnClickedTestPointer();
	afx_msg void OnBnClickedStatetable();
	afx_msg void OnBnClickedTestUnique();
	afx_msg void OnBnClickedTestFile();
	afx_msg void OnBnClickedTestThread();	
};
