// ImageProcessor.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "ImageProcessor.h"


// ���ǵ���������һ��ʾ��
IMAGEPROCESSOR_API int nImageProcessor=0;

// ���ǵ���������һ��ʾ����
extern "C"
{

IMAGEPROCESSOR_API double fnImageTableRecognise(int *Image,int row,int column,TrimCell *CellResult)
{
	
	//ͼ���ֵ��
	ImageBinaryzation(Image,row,column);
	//ͼ����бУ��
	double TiltAngle = TiltCorrection(Image,row,column);

	int *Lineimage = new int[row * column];
	//memset(Lineimage, 0, sizeof(int) * row * column);
	//�������ȡ
	TableLineDetect(Image,Lineimage,row,column);	

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			//Image[i * column + j] =  Lineimage[i * column + j];
			Image[i * column + j] = 255 - abs(Image[i * column + j] - Lineimage[i * column + j]);
		}
	}

	//�����У��
	ThiningTableLine(Lineimage,row,column);	
	
	std::vector<HorLine> AllHorLine;
	std::vector<VerLine> AllVerLine;
	TableLineCorrection(Lineimage,row,column,15,15,25,25,AllHorLine,AllVerLine);
	TableLineCorrection(Lineimage,row,column,row / 50,column / 50,row / 50,column / 50,AllHorLine,AllVerLine);
	
	//ɾ�����߶�
	for(int i = 0; i < AllHorLine.size();)
	{
		if((AllHorLine[i].EndColumn - AllHorLine[i].StartColumn) < 30)
		{
			AllHorLine.erase(AllHorLine.begin() + i);
			continue;
		}
		++i;
	}
	//ɾ�����߶�
	for(int i = 0; i < AllVerLine.size();)
	{
		if((AllVerLine[i].EndRow - AllVerLine[i].StartRow) < 30)
		{
			AllVerLine.erase(AllVerLine.begin() + i);
			continue;
		}
		++i;
	}	
	
	//��Ԫ����ȡ
	CellExact(AllHorLine, AllVerLine,CellResult);	

	//����ͼ����ת�Ƕ�
	return TiltAngle;
}

}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� ImageProcessor.h
CImageProcessor::CImageProcessor()
{
	return;
}
