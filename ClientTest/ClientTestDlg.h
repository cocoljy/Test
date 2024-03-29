
// ClientTestDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "RecvM.h"
#include "SendM.h"
#include "SearchM.h"


// CClientTestDlg 对话框
class CClientTestDlg : public CDialogEx
{
// 构造
public:
	CClientTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CLIENTTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CRecvM m_recvm;
	CSendM m_sendm;
	CSearchM m_searchm;
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	_CommandPtr m_pCommand;
};
