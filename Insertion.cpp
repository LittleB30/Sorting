/**
 * This is a singly linked list implementation of insertion sort.
 * Each node contains two variables: a long and a pointer to the next node.
 *
 * @author Alex Smith
 */
 #include <iostream>
 #include <fstream>
 using namespace std;

 class LinkedList{
 public:
   LinkedList() {
     head = tail = nullptr;
   }

   void add(long val) {
     Node* temp = new Node(val);
     if (!head) {
       head = temp;
     }
     else {
       tail->next = temp;
     }
     tail = temp;
   }

   void insertionSort() {
     if (head) {
       Node* leftOfPartition = head; //the last node in the sorted chunk
       Node* rightOfPartition = head->next; //the first node in the unsorted chunk
       Node* insertNode; //the node to be inserted
       Node* prevTemp;
       Node* curTemp;
       while (rightOfPartition) {
         if (rightOfPartition->value < head->value) { //if the unsorted node is smaller than the head
           insertNode = rightOfPartition;
           rightOfPartition = rightOfPartition->next;
           leftOfPartition->next = rightOfPartition;
           //then insert the node at the head.
           insertNode->next = head;
           head = insertNode;
         }
         else if (rightOfPartition->value < leftOfPartition->value) { //if the unsorted node is smaller then the largest sorted node
           prevTemp = head;
           curTemp = head->next;
           while (curTemp->value < rightOfPartition->value) { //find where the node should go
             prevTemp = curTemp;
             curTemp = curTemp->next;
           }
           insertNode = rightOfPartition;
           rightOfPartition = rightOfPartition->next;
           leftOfPartition->next = rightOfPartition;
           //then insert the node in that spot.
           prevTemp->next = insertNode;
           insertNode->next = curTemp;
         }
         else { //otherwise the node is already in place so advance the partition.
           leftOfPartition = rightOfPartition;
           rightOfPartition = rightOfPartition->next;
         }
       }
       tail = leftOfPartition;
     }
   }

   void writeToFile(ofstream& file) {
     Node* temp = head;
     while (temp) {
       file << temp->value << endl;
       temp = temp->next;
     }
     file.close();
   }

 private:
   struct Node{
     long value;
     Node* next;

     Node(long val) {
       value = val;
       next = nullptr;
     }
   };

   Node* head;
   Node* tail;
 };

 int main(int argc, char** argv) {
   if (argc < 3) {
     cout << "Usage: " << argv[0] << " infile outfile\n";
     exit(1);
   }
   char* inFileName = argv[1];
   char* outFileName = argv[2];
   LinkedList list;

   long temp;
   ifstream infile(inFileName);
   while (infile >> temp) {
     list.add(temp);
   }
   infile.close();

   list.insertionSort();

   ofstream outfile(outFileName);
   list.writeToFile(outfile);
   return 0;
 }
