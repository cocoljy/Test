#pragma once


// CSearchM �Ի���

class CSearchM : public CDialogEx
{
	DECLARE_DYNAMIC(CSearchM)

public:
	CSearchM(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSearchM();

// �Ի�������
	enum { IDD = IDD_SH_PANEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
