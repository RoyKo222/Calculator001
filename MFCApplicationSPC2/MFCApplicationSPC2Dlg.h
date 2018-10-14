
// MFCApplicationSPC2Dlg.h : ���Y��
//

#pragma once


// CMFCApplicationSPC2Dlg ��ܤ��
class CMFCApplicationSPC2Dlg : public CDialogEx
{
// �غc
public:
	CMFCApplicationSPC2Dlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATIONSPC2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
private:
	CString m_historyText;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton10();
private:
	CString m_output;
	void addDigit(char digit);
	void createHistoryText();
	
public:
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtondivide();
	afx_msg void OnBnClickedButtonmuti();
	afx_msg void OnBnClickedButtonplus();
	afx_msg void OnBnClickedButtonminus();
	afx_msg void OnBnClickedButtonequal();
	afx_msg void OnBnClickedButtoncancel();
};
