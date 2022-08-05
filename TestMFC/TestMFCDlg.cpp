
// TestMFCDlg.cpp : implementation file
//


#include "pch.h"
#include "framework.h"
#include "TestMFC.h"
#include "TestMFCDlg.h"
#include "afxdialogex.h"

#include <iostream>
#include <Windows.h>
#include <typeinfo>
#include <vector>
#include <stdexcept>
#include "Animal.h"
#include "Lion.h"
#include "TestPointers.h"
#include "GameTable.h"
#include "TestThreads.h"
#include "TestFiles.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "TestSQL.h"

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


// CTestMFCDlg dialog

BEGIN_DHTML_EVENT_MAP(CTestMFCDlg)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()


CTestMFCDlg::CTestMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDHtmlDialog(IDD_TESTMFC_DIALOG, IDR_HTML_TESTMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_UNIVAUE, Id1);
	DDX_Control(pDX, IDC_CHECK_FAST, CL_CheckFast);
	DDX_Control(pDX, IDC_UNIVAUE2, m_TargetEdit);
}

BEGIN_MESSAGE_MAP(CTestMFCDlg, CDHtmlDialog)
	ON_WM_SYSCOMMAND()
	ON_BN_CLICKED(IDC_TESTBUTTIN, &CTestMFCDlg::OnBnClickedTestbuttin)
	ON_BN_CLICKED(IDC_CHECK_FAST, &CTestMFCDlg::OnBnClickedCheckFast)
	ON_COMMAND(ID_FILE_NEW32771, &CTestMFCDlg::OnFileNew)
	ON_COMMAND(ID_FILE_SAVE32773, &CTestMFCDlg::OnFileSave)
	ON_COMMAND(ID_HELP_ABOUT, &CTestMFCDlg::OnHelpAbout)
	ON_COMMAND(ID_HELP_NOTEPAD, &CTestMFCDlg::OnHelpNotepad)
	ON_EN_CHANGE(IDC_UNIVAUE, &CTestMFCDlg::OnEnChangeUnivaue)
	ON_BN_CLICKED(IDC_CREATE_ANIMAL, &CTestMFCDlg::OnBnClickedCreateAnimal)
	ON_BN_CLICKED(IDC_TEST_POINTER, &CTestMFCDlg::OnBnClickedTestPointer)
	ON_BN_CLICKED(IDC_STATETABLE, &CTestMFCDlg::OnBnClickedStatetable)
	ON_BN_CLICKED(IDC_TEST_UNIQUE, &CTestMFCDlg::OnBnClickedTestUnique)
	ON_BN_CLICKED(IDC_TEST_FILE, &CTestMFCDlg::OnBnClickedTestFile)
	ON_BN_CLICKED(IDC_TEST_THREAD, &CTestMFCDlg::OnBnClickedTestThread)	
END_MESSAGE_MAP()



// CTestMFCDlg message handlers

BOOL CTestMFCDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// Add "About..." menu item to system menu.
	//menu.LoadMenuW(IDR_MENU1);
	//SetMenu(&menu);

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

	CreateConsole();
	//freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

	FILE* fDummy;
	freopen_s(&fDummy, "CONIN$", "r", stdin);
	freopen_s(&fDummy, "CONOUT$", "w", stderr);
	freopen_s(&fDummy, "CONOUT$", "w", stdout);



	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

HWND WINAPI CTestMFCDlg::GetConsoleWindowNT()
{
	return GetConsoleWindow();
}

void CTestMFCDlg::CreateConsole() {
	AllocConsole();
	HWND hWnd = GetConsoleWindow();
	::MoveWindow(hWnd, -880, 50, 800, 500, TRUE);
}

void CTestMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDHtmlDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestMFCDlg::OnPaint()
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
		CDHtmlDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HRESULT CTestMFCDlg::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;
}

HRESULT CTestMFCDlg::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;
}

void CTestMFCDlg::OnBnClickedTestbuttin()
{
	TestSQL ts;
	ts.Test();
}


void CTestMFCDlg::OnBnClickedCheckFast()
{
	int check = CL_CheckFast.GetCheck();
	std::cout << "is checked " << check << std::endl;
}


void CTestMFCDlg::OnFileNew()
{
	std::cout << "File New";
	//MessageBox("Hi", "File Menu");
	CFileDialog file(true);
	file.DoModal();
}


void CTestMFCDlg::OnFileSave()
{
	CFileDialog file(false);
	file.DoModal();
}


void CTestMFCDlg::OnHelpAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}


void CTestMFCDlg::OnHelpNotepad()
{
	try {
		//WinExec("notepad.exe", SW_SHOW);
		//CreateProcess("notepad.exe", "notepad.exe", NULL, NULL, FALSE, 0, NULL, NULL, NULL, NULL);
		system("notepad.exe");
	}
	catch (...) {
		std::exception_ptr p = std::current_exception();
		std::cout << &p << std::endl;
		//std::clog << (p ? p.__cxa_exception_type()->name() : "null") << std::endl;
	}
}


void CTestMFCDlg::OnEnChangeUnivaue()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDHtmlDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	UpdateData(TRUE);
	CString str;
	Id1.GetWindowTextA(str);
	std::cout << "edited " << str << std::endl;

	FString str2 = "Value:";

	static int i = 0;
	i++;
	//str.Format(_T("%i %s result"), i, str2);
	m_TargetEdit.SetWindowTextA(str);
}

void CTestMFCDlg::OnBnClickedCreateAnimal()
{
	Lion lion;
	std::cout << lion.dump() << std::endl;

	
	Lion* pLion = new Lion();
	delete pLion;

	std::cout << "-----" << std::endl;

	Animal* pAnimal = new Lion();
	delete pAnimal;

	//Animal ani = lion;
	//std::cout << ani.dump();
}

void CTestMFCDlg::OnBnClickedTestPointer()
{
	TestPointers ps;
	//Animal a("bob");
	ps.TestUniquePtr();
	//ps.TestSharedPtr(a);
	//ps.TestWeakPtr();
}

void CTestMFCDlg::OnBnClickedStatetable()
{
	GameTable st;
	std::make_unique<GameTable>();
	st.PrepareTable();
	st.Spin();
}


void CTestMFCDlg::OnBnClickedTestUnique()
{
	TestPointers ps;
	ps.TestUniquePtr();
}


void CTestMFCDlg::OnBnClickedTestFile()
{
	TestFiles tf;
	tf.Test();
}


void CTestMFCDlg::OnBnClickedTestThread()
{
	TestThreads tt;
	tt.Test();
}