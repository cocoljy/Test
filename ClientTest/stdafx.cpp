
// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// ClientTest.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"


CString GetWndTextByCString(CWnd &CWnd)
{
	CString s;
	CWnd.GetWindowTextW(s);
	return s;
}