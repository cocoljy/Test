#pragma once


// CSearchM 对话框

class CSearchM : public CDialogEx
{
	DECLARE_DYNAMIC(CSearchM)

public:
	CSearchM(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSearchM();

// 对话框数据
	enum { IDD = IDD_SH_PANEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
