
// MFCApplicationSPC2Dlg.cpp : 實作檔
//

#include "stdafx.h"
#include "MFCApplicationSPC2.h"
#include "MFCApplicationSPC2Dlg.h"
#include "afxdialogex.h"

#include <sstream>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
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


// CMFCApplicationSPC2Dlg 對話方塊



CMFCApplicationSPC2Dlg::CMFCApplicationSPC2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATIONSPC2_DIALOG, pParent)
	, m_historyText(_T(""))
	, m_output(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationSPC2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HISTORY, m_historyText);
	DDX_Text(pDX, IDC_EDIT1, m_output);
}

BEGIN_MESSAGE_MAP(CMFCApplicationSPC2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplicationSPC2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplicationSPC2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplicationSPC2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplicationSPC2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplicationSPC2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplicationSPC2Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplicationSPC2Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplicationSPC2Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplicationSPC2Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CMFCApplicationSPC2Dlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_divide, &CMFCApplicationSPC2Dlg::OnBnClickedButtondivide)
	ON_BN_CLICKED(IDC_BUTTON_muti, &CMFCApplicationSPC2Dlg::OnBnClickedButtonmuti)
	ON_BN_CLICKED(IDC_BUTTON_plus, &CMFCApplicationSPC2Dlg::OnBnClickedButtonplus)
	ON_BN_CLICKED(IDC_BUTTON_minus, &CMFCApplicationSPC2Dlg::OnBnClickedButtonminus)
	ON_BN_CLICKED(IDC_BUTTON_equal, &CMFCApplicationSPC2Dlg::OnBnClickedButtonequal)
	ON_BN_CLICKED(IDC_BUTTON_cancel, &CMFCApplicationSPC2Dlg::OnBnClickedButtoncancel)
END_MESSAGE_MAP()


// CMFCApplicationSPC2Dlg 訊息處理常式

BOOL CMFCApplicationSPC2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CFont *m_Font;
	m_Font = new CFont;
	m_Font->CreateFont(50, 20, 0, 0, 100,
		FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, L"Arial");
	CEdit *m_Edit = (CEdit *)GetDlgItem(IDC_EDIT1);
	m_Edit->SetFont(m_Font, FALSE);
	GetDlgItem(IDC_EDIT1)->SetFont(m_Font);
	GetDlgItem(IDC_STATIC)->SetFont(m_Font);


	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CMFCApplicationSPC2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CMFCApplicationSPC2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CMFCApplicationSPC2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplicationSPC2Dlg::OnEnChangeEdit2()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
}

void CMFCApplicationSPC2Dlg::addDigit(char digit)
{
	m_output += digit;
	UpdateData(FALSE);

}





void CMFCApplicationSPC2Dlg::OnBnClickedButton1()
{
	addDigit('1');
}



void CMFCApplicationSPC2Dlg::OnBnClickedButton2()
{
	addDigit('2');
}

void CMFCApplicationSPC2Dlg::OnBnClickedButton3()
{
	addDigit('3');
}

void CMFCApplicationSPC2Dlg::OnBnClickedButton4()
{
	addDigit('4');
}


void CMFCApplicationSPC2Dlg::OnBnClickedButton5()
{
	addDigit('5');
}



void CMFCApplicationSPC2Dlg::OnBnClickedButton6()
{
	addDigit('6');
}


void CMFCApplicationSPC2Dlg::OnBnClickedButton7()
{
	addDigit('7');
}



void CMFCApplicationSPC2Dlg::OnBnClickedButton8()
{
	addDigit('8');
}



void CMFCApplicationSPC2Dlg::OnBnClickedButton9()
{
	addDigit('9');
}



void CMFCApplicationSPC2Dlg::OnBnClickedButton0()
{
	addDigit('0');
}



void CMFCApplicationSPC2Dlg::OnBnClickedButtondivide()
{
	addDigit('/');
}



void CMFCApplicationSPC2Dlg::OnBnClickedButtonmuti()
{
	addDigit('*');
}



void CMFCApplicationSPC2Dlg::OnBnClickedButtonplus()
{
	addDigit('+');
}



void CMFCApplicationSPC2Dlg::OnBnClickedButtonminus()
{
	addDigit('-');
}



void CMFCApplicationSPC2Dlg::OnBnClickedButtonequal()
{
	addDigit('=');
}



void CMFCApplicationSPC2Dlg::OnBnClickedButtoncancel()
{
	 
}

