// SendM.cpp : 实现文件
//

#include "stdafx.h"
#include "ClientTest.h"
#include "SendM.h"
#include "afxdialogex.h"


// CSendM 对话框

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


// CSendM 消息处理程序


void CSendM::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}
