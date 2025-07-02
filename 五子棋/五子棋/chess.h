#pragma once
#include <graphics.h> //easux图形库的头文件

#include <vector>

using namespace std;

//表示落子位置
struct ChessPos {
	int row;
	int col;
	ChessPos(int r = 0, int c = 0) :row(r), col(c) {}
};

typedef enum {
	CHESS_WHITE = -1, //白子

	CHESS_BLACK = 1 //黑子
}chess_kind_t;
class Chess
{
public:
	Chess(int gradeSize, int marginX, int marginY, float chessSize);
	//棋盘的初始化：加载棋盘的图片资源，初始化棋盘的相关数据
	void init();

	//判断在指定坐标（x,y）位置，是否是有效点击
	//如果是有效点击，把有效点击的位置保存在参数pos中
	bool clickBoard(int x, int y, ChessPos* pos);

	//在棋盘的指定位置（pos），落子（kind）
	void chessDown(ChessPos* pos, chess_kind_t kind);

	//获取棋盘的大小（13,15,17,19）
	int getGradeSize();

	//获取其指定位置是黑棋，还是白棋，还是空白
	int getChessData(ChessPos* pos);
	int getChessData(int row, int col);

	//检查是否结束
	bool checkOver();


private:
	IMAGE chessBlackImg; //黑棋棋子
	IMAGE chessWhiteImg;//白棋棋子
	int gradeSize; //棋盘的大小
	int margin_x;//棋盘的左部边界
	int margin_y; //棋盘的顶部边界
	float chessSize; //棋子的大小（棋盘小方格的大小)

	//存储当前棋局的棋子分布数据
	// chessMap[3][5]表示棋盘的第三行第五列的落子情况 0:空白 1:黑子 -1:白子
	vector<vector<int>>chessMap;

	//via哦是现在该谁下棋（落子）
	bool playerFlag; //true 黑子走 false 白子走

	void updateGameMap(ChessPos* pos);
	bool checkWin();

	ChessPos lastPos;
};
