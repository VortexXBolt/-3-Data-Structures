#include <iostream>
using namespace std;

struct node {
  int data;
  node *next;
  node *prev;
  node *curr;
};

class linked_list {

private:
  node *head, *tail;

public:
  linked_list() {
    head = NULL;
    tail = NULL;
  }

  void add_node(int n) {
    node *tmp = new node;
    tmp->data = n;
    tmp->next = NULL;

    if (head == NULL) {
      head = tmp;
      tail = tmp;
    } else {
      tail->next = tmp;
      tmp->prev = tail;
      tail = tail->next;
    }
  }

  node *getHead() { return head; }

  void print_List() {
    node *tmp;
    tmp = head;
    while (tmp != NULL) {
      cout << tmp->data << " ";
      tmp = tmp->next;
    }
  }

  node *reverse_Groups(node *head, node *prev) {

    if (head == NULL) {
      return NULL;
    }

    node *tmp;
    node *curr;
    curr = head;

    while (curr != NULL && curr->data % 2 == 0) {
      tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }

    if (curr != head) {
      head->next = curr;
      curr = reverse_Groups(curr, NULL);
      return prev;
    } else {
      head->next = reverse_Groups(head->next, head);
      return head;
    }
  }
};

int main() {
  linked_list a;
  int numNodes, i, tempNode;

  cin >> numNodes;

  for (i = 0; i < numNodes; ++i) {
    cin >> tempNode;
    a.add_node(tempNode);
  }

  // a.print_List();
  a.reverse_Groups(a.getHead(), NULL);
  a.print_List();

  return 0;
}