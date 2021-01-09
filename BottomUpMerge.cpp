/**
 * This is a vector implementation of bottom-up merge sort for longs.
 *
 * @author Alex Smith
 */
 #include <iostream>
 #include <fstream>
 #include <vector>
 using namespace std;

 void merge(vector<long>& source, long maxLength, vector<long>& dest) {
   long left = 0; //the index of first element in the left chunk
   long right = maxLength; //the index of first element in the right chunk
   long next = maxLength * 2;
   long i, j, k; //current left index, current right index, current index in dest vector
   i = j = k = 0;
   while (k < source.size()) {
     if (right >= source.size()) { //if the right chunk is out of bounds
       while (left + i < source.size()) { //then add the rest of the left chunk
         dest[k++] = source[left + i];
         ++i;
       }
     }
     else { //otherwise both left and right are inbounds
       while (left + i < right && right - j > left) { //while left and right have not overlaped
         if (left + i >= source.size() || right + j >= source.size()) {
           break;
         }
         if (source[left + i] <= source[right + j]) { //if left's value is smaller than or equal to right's value then add left
           dest[k++] = source[left + i];
           ++i;
         }
         else { //otherwise right is smaller so add right
           dest[k++] = source[right + j];
           ++j;
         }
       }
       //only one of these loops will run
       while (left + i < right) { //add the rest of left
         dest[k++] = source[left + i];
         ++i;
       }
       while (right - j > left && right + j < source.size()) { //add the rest of right
         dest[k++] = source[right + j];
         ++j;
       }
       //prepare for the next iteration
       i = j = 0;
       left += next;
       right += next;
     }
   }
 }

 void mergeSort(vector<long>& original) {
   vector<long> temp;
   temp.resize(original.size());
   bool isSource = true; //true if the original vector is the source of the latest iteration of data
   for (long maxLength = 1; maxLength < original.size(); maxLength *= 2) {
     if (isSource) {
       merge(original, maxLength, temp); //merge the original vector into the temp vector
       isSource = false;
     }
     else {
       merge(temp, maxLength, original); //merge the temp vector into the original vector
       isSource = true;
     }
   }
   if (!isSource) {
     original = temp;
   }
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
   while (inFile >> temp) {
     list.push_back(temp);
   }
   inFile.close();

   mergeSort(list);

   ofstream outFile(outFileName);
   for (long i = 0; i < list.size(); ++i) {
     outFile << list[i] << endl;
   }
   outFile.close();
   return 0;
 }
