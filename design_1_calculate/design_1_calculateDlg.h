
// design_1_calculateDlg.h : 头文件
//

#pragma once

//class CString;
// Cdesign_1_calculateDlg 对话框
class Cdesign_1_calculateDlg : public CDialogEx
{
// 构造
public:
	Cdesign_1_calculateDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DESIGN_1_CALCULATE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
private:
	CString m_result; //最终的结果
	CString m_op1;    //第一个操作数
	CString m_op2;    //第二个操作数
	CString m_current;//当前屏幕显示的
	char m_operator; // 操作符


	int m_opStat;//0 表示当前对第一个数进行输入，1表示当前对第二个数进行输入
	bool m_inputStat;// 输入状态，如果出现异常，包括除以0,超过最大的数等，禁止任何操作
	bool m_isInt;//输入是否为整数，主要用于区分.
	int m_dataLength;//输入长度，不能超过1e17

	void refreshText(int input);
	void setOperator(char input);
	
public:
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton5();
};
