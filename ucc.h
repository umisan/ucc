#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//抽象構文木のノードの種類
typedef enum {
  ND_ADD,
  ND_SUB,
  ND_MUL,
  ND_DIV,
  ND_NUM,
  ND_EQ,
  ND_NEQ,
  ND_LT,
  ND_LE,
  ND_GT,
  ND_GE,
} NodeKind;

typedef struct Node Node;

struct Node {
  NodeKind kind;
  Node *lhs;
  Node *rhs;
  int val;
};

// トークンの種類
typedef enum {
  TK_RESERVED, //記号
  TK_IDENT, //識別子
  TK_NUM, //整数トークン
  TK_EOF, //入力の終わりを表すトークン
} TokenKind;

typedef struct Token Token;

//トークン型
struct Token {
  TokenKind kind; //トークンの型
  Token *next;    //次の入力トークン
  int val;        //kindがTK_NUMの場合、その数値
  char *str;      //トークン文字列
  int len;         //トークンの長さ
};


//入力プログラム
extern char *user_input;

extern Token *token; //現在着目しているトークン

void gen(Node * node);

Token *tokenize(char *p);

Node *expr();


