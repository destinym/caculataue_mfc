
// design_1_calculateDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持



	// 实现
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


// Cdesign_1_calculateDlg 对话框




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


// Cdesign_1_calculateDlg 消息处理程序

BOOL Cdesign_1_calculateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	CEdit* pEdit =  (CEdit*) GetDlgItem(IDC_EDIT1);
	pEdit->SetWindowText(_T("0"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cdesign_1_calculateDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cdesign_1_calculateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cdesign_1_calculateDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cdesign_1_calculateDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码

	refreshText(1);
}


void Cdesign_1_calculateDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	refreshText(2);
}


void Cdesign_1_calculateDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	refreshText(3);
}


void Cdesign_1_calculateDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	refreshText(4);
}


void Cdesign_1_calculateDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	refreshText(5);
}


void Cdesign_1_calculateDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	refreshText(6);
}


void Cdesign_1_calculateDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	refreshText(7);
}


void Cdesign_1_calculateDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	refreshText(8);
}


void Cdesign_1_calculateDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	refreshText(9);
}


void Cdesign_1_calculateDlg::OnBnClickedButton16()
{
	// TODO: 在此添加控件通知处理程序代码
	setOperator('+');
}


void Cdesign_1_calculateDlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	setOperator('-');
}


void Cdesign_1_calculateDlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	setOperator('*');
}


void Cdesign_1_calculateDlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	if (1 == m_opStat && true == m_inputStat)
	{
		double input1 = (double)_wtof(m_op1);
		double input2 = (double)_wtof(m_op2);
		if('/' == m_operator && (input2) < 1e-15 && (input2)> -1e15)
		{
			CEdit* pEdit =  (CEdit*) GetDlgItem(IDC_EDIT1);
			pEdit->SetWindowText(_T("除数不能为0"));
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
