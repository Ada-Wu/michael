#pragma once


// CSndCho �Ի���

class CSndCho : public CDialogEx
{
	DECLARE_DYNAMIC(CSndCho)

public:
	CSndCho(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSndCho();

// �Ի�������
	enum { IDD = IDD_SOUND_CHOICE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
