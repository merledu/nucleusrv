//
//void main()
//{
//    int array1[11] = {11,29,83,109,90,112,98,67,77,45};
//    int array2[11] = {89,62,73,90,7,89,34,20,72,100};
//    int i, c = 0;
//
//    for(i = 0; i <=  ; i++)
//        c=array1[i] + array2[i];
//}

int main() {

  int i, n=10;

  // initialize first and second terms
  int t1 = 0, t2 = 1;

  // initialize the next term (3rd term)
  int nextTerm = t1 + t2;

  // print 3rd to nth terms
  for (i = 3; i <= n; ++i) {
    nextTerm;
    t1 = t2;
    t2 = nextTerm;
    nextTerm = t1 + t2;
  }

  return 0;
  }