#include <cstddef>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>

class linkedList {

public:
  struct Node {
    int data;
    Node *next_ptr;
  };

private:
  // 単方向リストの宣言
  Node *node;

public:
  // 実体を持たないので nullptr で初期化
  linkedList() { node = nullptr; }

  ~linkedList() {}

  void appendElement(int data);
  void appendHeadElement(int data);
  void removeTail();
  void removeHead();
  void displayList();
};

/*************************************
void appendElement(std::string data)
リストの最後に要素を追加する
1. 新しい要素を作成する
2. リストの最後に新しい要素を追加する
  - リストが空のとき
    - 新しい要素のポインタをセットする
  - そうでないとき
    - リストの最後までループする
    - 新しいノードを最後のノードの参照としてセットする
*************************************/
void linkedList::appendElement(int data) {
  // 新しいノード
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next_ptr = nullptr;
  // 先頭の要素が nullptr ならば先頭に挿入
  if (node == nullptr) {
    std::cout << "先頭に要素を設定します" << std::endl;
    // 先頭のアドレスに
    node = newNode;
    std::cout << node->data << std::endl;
  } else {
    Node *tailNode = node;
    // next_ptr が null になるまで進む
    while (tailNode->next_ptr != nullptr)
      tailNode = tailNode->next_ptr;
    tailNode->next_ptr = newNode;
  }
}

/*************************************
void appendHeadElement(std::string data)
リストの先頭にデータを追加する
*************************************/
void linkedList::appendHeadElement(int data) {
  // 挿入するノード
  Node *newHeadNode = new Node;
  newHeadNode->data = data;
  newHeadNode->next_ptr = nullptr;

  if (node == nullptr) {
    node = newHeadNode;
  } else {
    // 現在のノードの先頭
    newHeadNode->next_ptr = node;
    node = newHeadNode;
  }
}

/*************************************
void removeTail()
リストの先頭から探索し、末尾にきたら削除する
*************************************/
void linkedList::removeTail() {
  Node *rootNode = node;
  Node *preNode = nullptr;

  if (rootNode == nullptr) {
    return;
  }

  // 末尾になるまで進む
  while (rootNode->next_ptr != nullptr) {
    // 一つ前のノードを保持しておく
    preNode = rootNode;
    rootNode = rootNode->next_ptr;
  }
  // 一つ前の要素の next_ptr を nullptr で初期化
  // 初期化後に rootNode の指すポインタを削除
  preNode->next_ptr = nullptr;
  delete rootNode;
}

/*************************************
void removeHead()
リストの先頭から要素を削除する
*************************************/
void linkedList::removeHead() {
  Node *oldHead = node;

  // 先頭の要素が空のときは何もしない
  if (oldHead == nullptr) {
    return;
  }

  // 先頭の要素が一つなら nullptr を代入
  if (oldHead->next_ptr == nullptr) {
    oldHead = nullptr;
  } else {
    // 先頭の次のポインタを代入
    node = oldHead->next_ptr;
    delete oldHead;
  }
}

/*************************************
void linkedList::displayList()
*************************************/
void linkedList::displayList() {
  Node *displayNode = node;
  std::cout << "***現在のリスト***" << std::endl;

  // リストが空のときは表示しない
  if (displayNode == nullptr) {
    std::cout << "リストは空です" << std::endl;
    std::cout << "******************" << std::endl;
  } else {
    while (displayNode != nullptr) {
      std::cout << displayNode->data << " ";
      displayNode = displayNode->next_ptr;
    }
    std::cout << std::endl << "******************" << std::endl;
  }
}

int main() {
  linkedList lists;

  lists.removeTail();
  lists.displayList();

  lists.appendElement(1);
  lists.appendElement(2);
  lists.appendElement(3);
  lists.appendElement(4);
  lists.displayList();

  lists.removeTail();
  lists.removeTail();
  lists.displayList();

  lists.appendHeadElement(5);
  lists.appendHeadElement(6);
  lists.displayList();

  lists.removeHead();
  lists.displayList();

  std::cout << "実行終了" << std::endl;
}
