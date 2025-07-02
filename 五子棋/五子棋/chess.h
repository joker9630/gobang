#pragma once
#include <graphics.h> //easuxͼ�ο��ͷ�ļ�

#include <vector>

using namespace std;

//��ʾ����λ��
struct ChessPos {
	int row;
	int col;
	ChessPos(int r = 0, int c = 0) :row(r), col(c) {}
};

typedef enum {
	CHESS_WHITE = -1, //����

	CHESS_BLACK = 1 //����
}chess_kind_t;
class Chess
{
public:
	Chess(int gradeSize, int marginX, int marginY, float chessSize);
	//���̵ĳ�ʼ�����������̵�ͼƬ��Դ����ʼ�����̵��������
	void init();

	//�ж���ָ�����꣨x,y��λ�ã��Ƿ�����Ч���
	//�������Ч���������Ч�����λ�ñ����ڲ���pos��
	bool clickBoard(int x, int y, ChessPos* pos);

	//�����̵�ָ��λ�ã�pos�������ӣ�kind��
	void chessDown(ChessPos* pos, chess_kind_t kind);

	//��ȡ���̵Ĵ�С��13,15,17,19��
	int getGradeSize();

	//��ȡ��ָ��λ���Ǻ��壬���ǰ��壬���ǿհ�
	int getChessData(ChessPos* pos);
	int getChessData(int row, int col);

	//����Ƿ����
	bool checkOver();


private:
	IMAGE chessBlackImg; //��������
	IMAGE chessWhiteImg;//��������
	int gradeSize; //���̵Ĵ�С
	int margin_x;//���̵��󲿱߽�
	int margin_y; //���̵Ķ����߽�
	float chessSize; //���ӵĴ�С������С����Ĵ�С)

	//�洢��ǰ��ֵ����ӷֲ�����
	// chessMap[3][5]��ʾ���̵ĵ����е����е�������� 0:�հ� 1:���� -1:����
	vector<vector<int>>chessMap;

	//viaŶ�����ڸ�˭���壨���ӣ�
	bool playerFlag; //true ������ false ������

	void updateGameMap(ChessPos* pos);
	bool checkWin();

	ChessPos lastPos;
};
