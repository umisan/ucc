#include "ucc.h"

//入力プログラム
char *user_input;

Token *token; //現在着目しているトークン


int main(int argc, char **argv) {
  if(argc != 2) {
    fprintf(stderr, "引数の個数が正しくありません\n");
    return 1;
  }
  //入力文字列を保存する
  user_input = argv[1];

  //トークナイズする
  token = tokenize(user_input);
  Node *node = expr();

  //アセンブリ前半部分
  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n"); 

  gen(node);

  printf("  pop rax\n");
  printf("  ret\n");
  return 0;
}
