#pragma once


// CGW �Ի���

class CGW : public CDialogEx
{
	DECLARE_DYNAMIC(CGW)

public:
	CGW(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGW();

// �Ի�������
	enum { IDD = IDD_GWCONF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
