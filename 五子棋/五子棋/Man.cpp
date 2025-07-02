#include "Man.h"

void Man::init(Chess* chess)
{
	this->chess = chess;
}

void Man::go()
{
	MOUSEMSG msg;
	ChessPos pos;
	//通过chess对象来判断落子是否有效，以及落子功能
	while (1) {
		//获取鼠标点击消息
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && chess->clickBoard(msg.x, msg.y, &pos)) {
			break;
		}
	}

	//printf("%d,%d\n", pos.row, pos.col);
	//落子
	chess->chessDown(&pos, CHESS_BLACK);

}