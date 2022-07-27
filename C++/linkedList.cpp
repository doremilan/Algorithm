#include <iostream>
using namespace std;

// node struct 구현
struct Node {
  int data;
  Node* nextNode;
}

// linkedList 클래스 생성
class LinkedList {
  private:
    Node* head;
    Node* tail;

  public:
    LinkedList() {
      // 초기화
      head = NULL;
      tail = NULL;
    }

	  //첫번째의 node 추가
	  void addFrontNode(int n);

    // 마지막 node 추가
    void addNode(int n)

	  // node 삽입
	  void insertNode(Node* prevNode, int n);
	
    // node 삭제
	  void deleteNode(Node* prevNode);

    // 첫번째 node 가져오기
    Node* getHead() {
      return head;
    }

    // LinkedList 출력
    void display(Node* head);
};



// 첫번째 node 추가
void LinkedList::addFrontNode(int n) {
  Node* temp = new Node;
  temp->data = n // temp의 데이터는 n

  // LinkedList가 비어있으면
  if (head == NULL) {
    head = temp; // 첫 node는 temp
    tail = temp; // 마지막 node는 temp
  } else {
    temp->nextNode = head; // temp의 nextNode는 head
    head = temp; // head는 temp
  };
}


// 마지막의 node 추가
void LinkedList::addNode(int n) {
	Node* temp = new Node;

	temp->data = n; // temp의 데이터는 n
	temp->nextNode = NULL; // temp의 nextNode = NULL 값

	// LinkedList가 비어있으면
	if (head == NULL) {
		head = temp; // 첫 node는 temp
		tail = temp; // 마지막 node는 temp
	}
	// LinkedList에 데이터가 있으면
	else {
		tail->nextNode = temp; // 현재 마지막 node의 nextNode는 temp
		tail = temp; // 마지막 node는 temp
	}
}


// node 삽입
void LinkedList::insertNode(Node* prevNode,int n) {
	Node* temp = new Node;
	temp->data = n; // temp의 데이터는 n

	// temp의 nextNode 저장
	// (삽입 할 앞 node의 nextNode를 temp의 nextNode에 저장)
	temp->nextNode = prevNode->nextNode;
	
	// temp 삽입
	// temp앞의 node의 nextNode를 temp로 저장
	prevNode->nextNode = temp;
}


// node 삭제
void LinkedList::deleteNode(Node* prevNode) {

	// 삭제할 node를 temp에 저장
	// (삭제할 node의 1단계 전 node의 nextNode) 
	Node* temp = prevNode->nextNode;

	// 삭제할 node를 제외
	// (삭제할 node의 nextNode를 1단계 전 node의 nextNode에 저장)
	prevNode->nextNode = temp->nextNode;

	//temp 삭제
	delete temp;
}


// LinkedList 출력
void LinkedList::display(Node* head) {
	if (head == NULL) {
		cout << "\n";
	} else {
		cout << head->data << " ";
		display(head->nextNode);
	}
	cout << endl; //
}


//메인 함수
int main() {
	LinkedList a;
	a.addNode(1);
	a.addNode(2);
	a.addNode(3);

	//display
	a.display(a.getHead());
  
	//0을 제일 앞에 추가
	a.addFrontNode(0);

	//1을 네번째에 추가
	a.insertNode(a.getHead()->nextNode->nextNode, 1);

	//세번째 노드 삭제
	a.deleteNode(a.getHead()->nextNode);

	//display
	a.display(a.getHead());
}