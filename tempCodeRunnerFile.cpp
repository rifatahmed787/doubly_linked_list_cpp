void insert_at_head(Node *&head, Node *&tail, int v)
// {
//     Node *newNode = new Node(v);

//     if (head == NULL)
//     {
//         head = newNode;
//         tail = newNode;
//         return;
//     }
//     newNode->next = head;
//     head->prev = newNode;
//     head = newNode;
// }