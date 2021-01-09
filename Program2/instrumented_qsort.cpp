// //-*-C++-*-

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int rec_depth = 0;

void quicksort(long* a, long left, long right)
{
  cout << "In Q w " << left << " " << right << endl;
  cout << "Recursive depth: " << rec_depth << endl;
  long i, j;
  long v;
  long temp;

  if (right - left > 0) { // there are at least two items in the partition
    v = a[right]; //v is the pivot
    i = left - 1; // 1 to the left of the begining
    j = right; // 1 to the right of where search should start

    while (1) { //we're going to tolerate an infinite loop here and use break
      while (a[++i] < v); // pre-increment i until a[i] is >= the pivot
      while (a[--j] > v); // post-decrement j until a[j] is <= the pivot
      if (i >= j) break; //if i and j have crossed -- get out of the loop
      // otherwise, swap a[i] and a[j]
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
    // i and j have crossed, so swap a[i] and the pivot
    a[right] = a[i];
    a[i] = v;
    // the pivot is now in place at i
    // now call quicksort on the two partitions
    rec_depth++;
    quicksort(a, left, i-1); // left partition
    quicksort(a, i+1, right);
    rec_depth--;
  }
}


main(int argc, char** argv) {

  if (argc < 3) {
    cout << "Usage: " << argv[0] << " infile outfile\n";
    exit(1);
  }
  char* inFileName = argv[1];
  char* outFileName = argv[2];
  long   dataArray[1000000];
  long   numItems = 0;
  
  ifstream infile(inFileName);

  long i = 0;
  long temp;
  while (infile >> temp)
    {
      dataArray[i] = temp;
      i++;
    }

  numItems = i;

  infile.close();

  quicksort(dataArray,0,numItems-1);
  cout << "ready to write" << endl;

  ofstream outFile(outFileName);

  for (i = 0; i < numItems; i++) {
    outFile << dataArray[i] << endl;
  }
  outFile.close();
}

  
