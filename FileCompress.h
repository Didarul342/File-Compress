#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "HuffmanTree.hpp"

#define _SIZE_ 1024
#define _FILE_NAME_SIZE_ 128

struct CodeInfo
{
	CodeInfo()
		: code()
		, cnt(0)
	{}

	friend bool operator>(const CodeInfo &left, const CodeInfo &right)
	{
		return left.cnt > right.cnt;
	}

	friend bool operator!=(const CodeInfo &left, const CodeInfo &right)
	{
		return left.cnt != right.cnt;
	}

	friend CodeInfo operator+(const CodeInfo &left, const CodeInfo &right)
	{
		CodeInfo ret;
		ret.cnt = left.cnt + right.cnt;
		return ret;
	}

	unsigned char ch;	// �ַ�
	std::string code;	// ����
	long long cnt;		// ���ִ���
};


class FileCompress
{
public:
	// ѹ��
	void Compress(const std::string &FilePath);

	// ��ѹ��
	void UnCompress(const std::string &FilePath);

private:
	// ��ȡ�ļ���
	void GetFileName(const std::string &FilePath, std::string &output);

	// ��ȡ��չ��
	void GetPostfixName(const std::string &FilePath, std::string &output);

	// ���info��Ϣ
	void FillInfo(FILE *src);

	// ��������Ϣ
	void FillCode(const HuffmanTreeNode<CodeInfo> *pRoot);

	// ����ѹ������
	void CompressCore(FILE *src, FILE *dst, const std::string &FilePath);

	// ���������Ϣ��ѹ���ļ��ײ�
	void SaveCode(FILE *dst, const std::string &FilePath);

	// ��ȡһ��Ԫ��
	void GetLine(FILE *src, unsigned char *buf, int size);

	// ��ȡͷ����Ϣ
	void GetHead(FILE *src, std::string &Postfix);
	
	// ���Ľ�ѹ����
	void UnCompressCore(FILE *input, FILE *output, HuffmanTreeNode<CodeInfo> * pRoot);
private:
	CodeInfo info[256];
};

