#pragma once


// CSendM �Ի���

class CSendM : public CDialogEx
{
	DECLARE_DYNAMIC(CSendM)

public:
	CSendM(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSendM();

// �Ի�������
	enum { IDD = IDD_SEND_PANEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
