/* Basic Linked List class*/
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node() : data(0), next(NULL) {};
	Node(int x) : data(x), next(NULL) {};
};

//declaration
class LinkedListInt {
private:
	Node *head;
public:
	LinkedListInt(); //constructor

//	LinkedListInt(const LinkedListInt &list); //copy constructor

	~LinkedListInt(); //destructor

	void insertFront (Node* newNode);
	void removeTail ();
	void print() const;  // const function cannot change any value
};

//implementation
LinkedListInt::LinkedListInt() : head(NULL){
}


/*
LinkedListInt::LinkedListInt(const LinkedListInt &list){ //copy constructor
	cout<< "copy constructor called" << endl;

	if(list.head == NULL){
		head = NULL;
	}
	else{
		head = new Node (list.head->data);

		Node *temp1, *temp2;
		temp1 = list.head;
		temp2 = head;
		while(temp1->next != NULL){
			temp2->next = new Node(  temp1->next->data   );
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}

}
*/



LinkedListInt::~LinkedListInt() {    //destructor
	Node *current,*temp;
	current = head;
	temp = head;
	while(current != NULL) {
		current = current->next;
		delete temp;
		temp = current;
	}
}

void LinkedListInt::insertFront (Node* newNode){
	if (newNode == NULL) {		//check input
		cout<<"Warning! insertFront has newNode == NULL." <<endl;
		return;
	}

	if (head == NULL) { 	//special case: list is empty
		head = newNode;
	} else { 					// general case: non-empty list
		newNode->next = head;
		head = newNode;
	}
}

void LinkedListInt::removeTail (){
	if (head == NULL) { // check for NULL value
		cout<<"Warning! head == NULL. Nothing to remove." <<endl;
		return;
	}

	if(head->next == NULL){  //speical case: list with only one node
		delete head;
		head = NULL;
	}
	else{	// list with two or more nodes
		Node* secondLast = head;
		while(secondLast->next->next != NULL){
			secondLast = secondLast->next;
		}
		delete secondLast->next;
		secondLast->next = NULL;
	}
}

void LinkedListInt::print () const {
	if (head == NULL) {
		cout<<"Warning! head == NULL. Nothing to print." <<endl;
		return; // check for NULL values
	}

	//list not empty
	cout << "("; // start
	Node* temp;
	temp = head;
	while (temp != NULL) { // iterate until NULL
		cout << "[" << temp->data << "]"; // print node value
		temp = temp->next;
		if (temp != NULL) cout << "->"; // print -> symbol between nodes, if there is a next one.
	}
	cout << ")\n"; // end

}

int main () {
	LinkedListInt test = LinkedListInt();
	test.insertFront(new Node(1));
	test.insertFront(new Node(2));
	test.insertFront(new Node(3));
	test.print();

	LinkedListInt copy = LinkedListInt( test ); 	//or // LinkedListInt copy = test;
	test.removeTail();
	test.print();
	copy.print();

    //cout<< test.head << endl;
    //cout<< copy.head << endl;

	return 0;
}