// SendM.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ClientTest.h"
#include "SendM.h"
#include "afxdialogex.h"


// CSendM �Ի���

IMPLEMENT_DYNAMIC(CSendM, CDialogEx)

CSendM::CSendM(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSendM::IDD, pParent)
{

}

CSendM::~CSendM()
{
}

void CSendM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSendM, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSendM::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSendM ��Ϣ�������


void CSendM::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
