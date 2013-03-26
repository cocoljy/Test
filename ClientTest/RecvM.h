#pragma once
#include "afxcmn.h"
#include "afxdtctl.h"
#include "afxwin.h"
#include "FileOperation.h"


// CSearchM 对话框

class CRecvM : public CDialogEx
{
	DECLARE_DYNAMIC(CRecvM)

public:
	CRecvM(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRecvM();

// 对话框数据
	enum { IDD = IDD_RECV_PANEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	CListCtrl contain_box;
	CListCtrl showBox;
	_ConnectionPtr m_pConnection;
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
private:
	char sql[512];
	int m_row, m_column;
	void OnOK();
public:
	CDateTimeCtrl dateBox;
	CDateTimeCtrl rulDateBox;
	afx_msg void OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit remarkBox;
	afx_msg void OnBnClickedButton2();
	CEdit CourierNumBox;
	CEdit CmpyNameBox;
	CEdit CsgBox;
	CEdit RecverBox;
	CComboBox ProductNumBox;
	int count;
	void updateListBox(CListCtrl &, CString);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	void InsertDetail(int, int);
	afx_msg void OnBnClickedButton4();
	int GetCurrentSelectedItemPosition(CListCtrl&);
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_listCtr;
	CEdit m_edit;
	afx_msg void OnEnKillfocusEdit8();
	CStatic m_groupBox;
};
