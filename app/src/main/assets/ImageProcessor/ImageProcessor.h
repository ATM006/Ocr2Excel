// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� IMAGEPROCESSOR_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// IMAGEPROCESSOR_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef IMAGEPROCESSOR_EXPORTS
#define IMAGEPROCESSOR_API __declspec(dllexport)
#else
#define IMAGEPROCESSOR_API __declspec(dllimport)
#endif

#define _Debug 0

// �����Ǵ� ImageProcessor.dll ������
class IMAGEPROCESSOR_API CImageProcessor {
public:
	CImageProcessor(void);
	// TODO: �ڴ�������ķ�����
};

extern IMAGEPROCESSOR_API int nImageProcessor;

extern "C"
{
	IMAGEPROCESSOR_API double fnImageTableRecognise(int *Image,int row,int column,TrimCell *CellResult);
}
