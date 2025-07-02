#include "ChessGame.h"
 
ChessGame::ChessGame(Man* man, AI* ai, Chess* chess)
{
	this->man = man;
	this->ai = ai;
	this->chess = chess;
	man->init(chess);
	ai->init(chess);
}
 
//对局（开始五子棋游戏）
void ChessGame::play()
{
	chess->init();
	while (1) {
		//先由棋手走棋
		man->go();
		if (chess->checkOver()) {
			chess->init();
			continue;
		}
		//由AI走
		ai->go();
		if (chess->checkOver()) {
			chess->init();
			continue;
		}
	}
}