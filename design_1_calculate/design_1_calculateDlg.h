
// design_1_calculateDlg.h : ͷ�ļ�
//

#pragma once

//class CString;
// Cdesign_1_calculateDlg �Ի���
class Cdesign_1_calculateDlg : public CDialogEx
{
// ����
public:
	Cdesign_1_calculateDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DESIGN_1_CALCULATE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
private:
	CString m_result; //���յĽ��
	CString m_op1;    //��һ��������
	CString m_op2;    //�ڶ���������
	CString m_current;//��ǰ��Ļ��ʾ��
	char m_operator; // ������


	int m_opStat;//0 ��ʾ��ǰ�Ե�һ�����������룬1��ʾ��ǰ�Եڶ�������������
	bool m_inputStat;// ����״̬����������쳣����������0,�����������ȣ���ֹ�κβ���
	bool m_isInt;//�����Ƿ�Ϊ��������Ҫ��������.
	int m_dataLength;//���볤�ȣ����ܳ���1e17

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
