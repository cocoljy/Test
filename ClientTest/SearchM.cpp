// SearchM.cpp : 实现文件
//

#include "stdafx.h"
#include "ClientTest.h"
#include "SearchM.h"
#include "afxdialogex.h"


// CSearchM 对话框

IMPLEMENT_DYNAMIC(CSearchM, CDialogEx)

CSearchM::CSearchM(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSearchM::IDD, pParent)
{

}

CSearchM::~CSearchM()
{
}

void CSearchM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSearchM, CDialogEx)
END_MESSAGE_MAP()


// CSearchM 消息处理程序