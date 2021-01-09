/**
 * This is a vector implementation of max heap sort for longs.
 *
 * @author Alex Smith
 */
 #include <iostream>
 #include <fstream>
 #include <vector>
 using namespace std;

 void percolateDown(vector<long>& v, long index) {
   long parent = index;
   long child = parent * 2;
   long largerChild;
   while (parent <= v[0] / 2) {
     if (child == v[0]) { //if there is only one child then that child is the largest
       largerChild = child;
     }
     else {
       if (v[child] > v[child + 1]) { //find which child is larger
         largerChild = child;
       }
       else {
         largerChild = child + 1;
       }
     }

     if (v[parent] < v[largerChild]) { //if the parent is smaller than the larger child then swap
       swap(v[parent], v[largerChild]);
       parent = largerChild;
       child = parent * 2;
     }
     else { //otherwise the parent is larger so stop percolating
       break;
     }
   }
 }

 void buildHeap(vector<long>& v) {
   for (long i = v[0] / 2; i > 0; --i) {
     percolateDown(v, i);
   }
 }

 void sortHeap(vector<long>& v) {
   while (v[0] > 1) {
     swap(v[v[0]], v[1]);
     v[0] -= 1;
     percolateDown(v, 1);
   }
 }

 void heapSort(vector<long>& v) {
   buildHeap(v);
   sortHeap(v);
 }

 int main(int argc, char** argv) {
   if (argc < 3) {
     cout << "Usage: " << argv[0] << " infile outfile\n";
     exit(1);
   }
   char* inFileName = argv[1];
   char* outFileName = argv[2];
   vector<long> list;

   long temp;
   ifstream inFile(inFileName);
   list.push_back(0);
   while (inFile >> temp) {
     list.push_back(temp);
   }
   inFile.close();

   long size = list.size() - 1;
   list[0] = size;

   heapSort(list);

   ofstream outFile(outFileName);
   for (long i = 1; i <= size; ++i) {
     outFile << list[i] << endl;
   }
   outFile.close();
   return 0;
 }
