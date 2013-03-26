#pragma once


// CSendM 对话框

class CSendM : public CDialogEx
{
	DECLARE_DYNAMIC(CSendM)

public:
	CSendM(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSendM();

// 对话框数据
	enum { IDD = IDD_SEND_PANEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
