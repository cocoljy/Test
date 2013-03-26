#include "stdafx.h"
#include "FileOperation.h"


CFileOperation::CFileOperation(void)
{
	index = 0;
	count = 0;
}

CFileOperation::CFileOperation(CString path)
{
	mFile.Open(path, CFile::modeReadWrite, &mExcept);
	index = 0;
	count = 0;
}

CFileOperation::~CFileOperation(void)
{
	mFile.Close();
}

void CFileOperation::open(CString path)
{
	mFile.Open(path, CFile::modeReadWrite, &mExcept);
}

BOOL CFileOperation::addProductName(CString s)
{
	char* old_locale = _strdup( setlocale(LC_CTYPE,NULL) );

	mFile.SeekToEnd();
	AfxMessageBox(s);
	setlocale(LC_CTYPE, "chs");
	mFile.WriteString(s + "\n");
	setlocale( LC_CTYPE, old_locale );
	free(old_locale );
	count++;
	return TRUE;
}

CString CFileOperation::readProductName()
{
	char* old_locale = _strdup( setlocale(LC_CTYPE,NULL) );
	CString s;
	setlocale(LC_CTYPE, "chs");
	mFile.ReadString(s);
	setlocale( LC_CTYPE, old_locale );
	free(old_locale );
	count++;
	return s;
}