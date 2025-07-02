#include "Man.h"

void Man::init(Chess* chess)
{
	this->chess = chess;
}

void Man::go()
{
	MOUSEMSG msg;
	ChessPos pos;
	//ͨ��chess�������ж������Ƿ���Ч���Լ����ӹ���
	while (1) {
		//��ȡ�������Ϣ
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && chess->clickBoard(msg.x, msg.y, &pos)) {
			break;
		}
	}

	//printf("%d,%d\n", pos.row, pos.col);
	//����
	chess->chessDown(&pos, CHESS_BLACK);

}