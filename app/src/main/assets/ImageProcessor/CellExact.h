
#include <map>

enum PointPos
{
	start,
	center,
	end
};

struct TablePoint
{
	int Row;
	int Column;
	int type;
	bool Searched;
};

struct Cell
{
	int LeftTopRow;
	int LeftTopColumn;
	int RightBottomRow;
	int RightBottomColumn;
};

struct TrimCell
{
	int LeftTopRow;
	int LeftTopColumn;
	int RightBottomRow;
	int RightBottomColumn;

	int StartRow;  //��ʾ�ڼ��б��
	int EndRow;
	int StartColumn; //��ʾ�ڼ��б��
	int EndColumn;
};

void CellExact(std::vector<HorLine> AllHorLine, std::vector<VerLine> AllVerLine,TrimCell *CellResult);
Cell FindCell(std::vector<std::vector<TablePoint>> inersection_point,int i,int j);
TrimCell FindTrimCell(std::vector<std::vector<TablePoint>> inersection_point,int i,int j,std::map<int,int> MapHorLineNum,std::map<int,int> MapVerLineNum);
