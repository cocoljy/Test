
// ClientTestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "RecvM.h"
#include "SendM.h"
#include "SearchM.h"


// CClientTestDlg �Ի���
class CClientTestDlg : public CDialogEx
{
// ����
public:
	CClientTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CLIENTTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
