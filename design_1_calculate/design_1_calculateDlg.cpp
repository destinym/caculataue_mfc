
// design_1_calculateDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "design_1_calculate.h"
#include "design_1_calculateDlg.h"
#include "afxdialogex.h"
#include "Operation.h";

const int MAX_LENGTH = 16;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��



	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cdesign_1_calculateDlg �Ի���




Cdesign_1_calculateDlg::Cdesign_1_calculateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cdesign_1_calculateDlg::IDD, pParent),m_result(),m_op1(),m_op2(),m_current(),
	  m_operator(),m_opStat(0),m_inputStat(true),m_isInt(true),m_dataLength(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cdesign_1_calculateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cdesign_1_calculateDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &Cdesign_1_calculateDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON4, &Cdesign_1_calculateDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &Cdesign_1_calculateDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cdesign_1_calculateDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cdesign_1_calculateDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &Cdesign_1_calculateDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Cdesign_1_calculateDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &Cdesign_1_calculateDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &Cdesign_1_calculateDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &Cdesign_1_calculateDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &Cdesign_1_calculateDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON16, &Cdesign_1_calculateDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON14, &Cdesign_1_calculateDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON13, &Cdesign_1_calculateDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON12, &Cdesign_1_calculateDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON15, &Cdesign_1_calculateDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON18, &Cdesign_1_calculateDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON5, &Cdesign_1_calculateDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// Cdesign_1_calculateDlg ��Ϣ�������

BOOL Cdesign_1_calculateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	CEdit* pEdit =  (CEdit*) GetDlgItem(IDC_EDIT1);
	pEdit->SetWindowText(_T("0"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cdesign_1_calculateDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cdesign_1_calculateDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cdesign_1_calculateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cdesign_1_calculateDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cdesign_1_calculateDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	refreshText(0);
}


void Cdesign_1_calculateDlg::refreshText(int input)
{
	if(m_inputStat && m_dataLength <= MAX_LENGTH)
	{
		CString str;
		str.Format(_T("%d"),input);
		m_current += str;
		CEdit* pEdit =  (CEdit*) GetDlgItem(IDC_EDIT1);
		pEdit->SetWindowText(m_current);

		if (m_opStat==0)
		{
			m_op1 = m_current;
		}
		else
		{
			m_op2 = m_current;
		}
		m_dataLength++;
	}

}

void Cdesign_1_calculateDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	refreshText(1);
}


void Cdesign_1_calculateDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	refreshText(2);
}


void Cdesign_1_calculateDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	refreshText(3);
}


void Cdesign_1_calculateDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	refreshText(4);
}


void Cdesign_1_calculateDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	refreshText(5);
}


void Cdesign_1_calculateDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	refreshText(6);
}


void Cdesign_1_calculateDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	refreshText(7);
}


void Cdesign_1_calculateDlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	refreshText(8);
}


void Cdesign_1_calculateDlg::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	refreshText(9);
}


void Cdesign_1_calculateDlg::OnBnClickedButton16()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	setOperator('+');
}


void Cdesign_1_calculateDlg::OnBnClickedButton14()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	setOperator('-');
}


void Cdesign_1_calculateDlg::OnBnClickedButton13()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	setOperator('*');
}


void Cdesign_1_calculateDlg::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	setOperator('/');
}

void Cdesign_1_calculateDlg::setOperator(char input)
{
	m_operator = input;
	m_opStat = 1;
	m_current.Empty();
	m_dataLength = 0;
	m_isInt = true;
}


void Cdesign_1_calculateDlg::OnBnClickedButton15()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (1 == m_opStat && true == m_inputStat)
	{
		double input1 = (double)_wtof(m_op1);
		double input2 = (double)_wtof(m_op2);
		if('/' == m_operator && (input2) < 1e-15 && (input2)> -1e15)
		{
			CEdit* pEdit =  (CEdit*) GetDlgItem(IDC_EDIT1);
			pEdit->SetWindowText(_T("��������Ϊ0"));
			m_inputStat = false;
			return;
		}

		Operation operation(input1,input2,m_operator);
		double result = operation.getResult();
		long long int intResult = static_cast<long long int>(result);
		double dif = result - intResult;

		if(dif <1e-15 && intResult < 1e16 && intResult > -1e16 )
			m_result.Format(_T("%ld"),intResult);
		else if (intResult>1e16 || intResult < -1e16)
			m_result.Format(_T("%g"),result);
		else
			m_result.Format(_T("%g"),result);

		CEdit* pEdit =  (CEdit*) GetDlgItem(IDC_EDIT1);
		pEdit->SetWindowText(m_result);

		m_op1 = m_result;
		m_current = m_result;

	}
}


void Cdesign_1_calculateDlg::OnBnClickedButton18()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_inputStat = true;
	m_opStat = 0;
	m_op1.Empty();
	m_op2.Empty();
	m_current.Empty();

	CEdit* pEdit =  (CEdit*) GetDlgItem(IDC_EDIT1);
	pEdit->SetWindowText(_T("0"));

}


void Cdesign_1_calculateDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_isInt)
	{
	    m_isInt = false;
		CString str;
		str.Format(_T("%c"),'.');
		m_current += str;
		CEdit* pEdit =  (CEdit*) GetDlgItem(IDC_EDIT1);
		pEdit->SetWindowText(m_current);
	}
}
